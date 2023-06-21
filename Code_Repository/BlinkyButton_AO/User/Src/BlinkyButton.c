/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "BlinkyButton.h"
#include "Bsp.h"

void BlinkyButton_ctor(BlinkyButton * const me) {
    Active_ctor(&me->super, (DispatchHandler)&BlinkyButton_dispatch);
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);
    me->isLedOn = false;
    me->blink_time = INITIAL_BLINK_TIME;
}


static void BlinkyButton_dispatch(BlinkyButton * const me, Event const * const e){
	switch(e->sig){
		case INIT_SIG:{
			BspLedOff();
		}
		case TIMEOUT_SIG:{
            if (!me->isLedOn) { /* LED not on */
            	BspLedOn();
            	me->isLedOn = true;
                TimeEvent_arm(&me->te, me->blink_time, 0U);
            }
            else {  /* LED is on */
            	BspLedOff();
            	me->isLedOn = false;
                TimeEvent_arm(&me->te, me->blink_time * 3U, 0U);
            }
			break;
		}
		case BUTTON_PRESSED_SIG:{
			HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_SET);

            me->blink_time >>= 1; /* shorten the blink time by factor of 2 */
            if (me->blink_time == 0U) {
                me->blink_time = INITIAL_BLINK_TIME;
            }
			break;
		}
		case BUTTON_RELEASED_SIG:{
			HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_RESET);
			break;
		}
		default: {
			break;
		}
	}
}


/* uCOS-II application hooks ===============================================*/
void App_TimeTickHook(void) {
    /* state of the button debouncing, see below */
    static struct ButtonsDebouncing {
        uint32_t depressed;
        uint32_t previous;
    } buttons = { 0U, 0U };
    uint32_t current;
    uint32_t tmp;

    TimeEvent_tick(); /* process all uC/AO time events */

    /* Perform the debouncing of buttons. The algorithm for debouncing
    * adapted from the book "Embedded Systems Dictionary" by Jack Ganssle
    * and Michael Barr, page 71.
    */
    current = BspGetButtonState(); /* read SW1 */
    tmp = buttons.depressed; /* save the debounced depressed buttons */
    buttons.depressed |= (buttons.previous & current); /* set depressed */
    buttons.depressed &= (buttons.previous | current); /* clear released */
    buttons.previous   = current; /* update the history */
    tmp ^= buttons.depressed;     /* changed debounced depressed */

    if ((tmp & BspGetButtonState()) != 0U) {  /* debounced SW1 state changed? */
        if ((buttons.depressed & BspGetButtonState()) != 0U) { /* is SW1 depressed? */
            /* post the "button-pressed" event from ISR */
            static Event const buttonPressedEvt = {BUTTON_PRESSED_SIG};
            Active_post(AO_BlinkyButton, &buttonPressedEvt);
        }
        else { /* the button is released */
            /* post the "button-released" event from ISR */
            static Event const buttonReleasedEvt = {BUTTON_RELEASED_SIG};
            Active_post(AO_BlinkyButton, &buttonReleasedEvt);
        }
    }
}



