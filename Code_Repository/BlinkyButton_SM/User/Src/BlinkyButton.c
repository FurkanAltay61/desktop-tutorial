/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "BlinkyButton.h"
#include "Bsp.h"



//Q_DEFINE_THIS_FILE;

void BlinkyButton_ctor(BlinkyButton * const me) {
    Active_ctor(&me->super, (DispatchHandler)&BlinkyButton_dispatch);
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);
    me->isLedOn = false;
    me->blink_time = INITIAL_BLINK_TIME;
}


static void BlinkyButton_dispatch(BlinkyButton * const me, Event const * const e){

	if(e->sig == INIT_SIG){
		BspLedOff();
		TimeEvent_arm(&me->te, me->blink_time * 3U, 0U);
		me->state = OFF_STATE;
		return;
	}


	switch(me->state){
		case OFF_STATE:{
			switch(e->sig){
				case TIMEOUT_SIG:{
					BspLedOn();
					TimeEvent_arm(&me->te,me->blink_time,0U);
					me->state = ON_STATE;
					break;
				}
				case BUTTON_PRESSED_SIG:{
					BspLedOn();
					me->blink_time >>=1; /*Shorten the blink time bythe factor of 2*/
					if(me->blink_time == 0){
						me->blink_time = INITIAL_BLINK_TIME;
					}
					break;
				}
				case BUTTON_RELEASED_SIG:{
					BspLedOff();
					break;
				}
			}
			break;
		}
		case ON_STATE:{
			switch(e->sig){
				case TIMEOUT_SIG:{
					BspLedOff();
					TimeEvent_arm(&me->te,me->blink_time * 3U, 0U);
					me->state = OFF_STATE;
					break;
				}
				case BUTTON_PRESSED_SIG:{
					BspLedOn();
					me->blink_time >>=1; /*Shorten the blink time bythe factor of 2*/
					if(me->blink_time == 0){
						me->blink_time = INITIAL_BLINK_TIME;
					}
					break;
				}
				case BUTTON_RELEASED_SIG:{
					BspLedOff();
					break;
				}
			}
			break;
		}
		default: {
//			Q_ASSERT(0);
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



