/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include <TimeBomb.h>
#include "Bsp.h"



//Q_DEFINE_THIS_FILE;

void TimeBomb_ctor(TimeBomb * const me) {
    Active_ctor(&me->super, (DispatchHandler)&TimeBomb_dispatch);
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);
}


static void TimeBomb_dispatch(TimeBomb * const me, Event const * const e){

	if(e->sig == INIT_SIG){
		BspLed1On();
		me->state = WAIT4BUTTON_STATE;
		return;
	}


	switch(me->state){
		case WAIT4BUTTON_STATE:{
			switch(e->sig){
				case BUTTON_PRESSED_SIG:{
					BspLed1Off();
					BspLed2On();
					TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
					me->blink_cntr = 10U;
					me->state = BLINK_STATE;
					break;
				}
			}
			break;
		}
		case BLINK_STATE:{
			switch(e->sig){
				case TIMEOUT_SIG:{
					BspLed2Off();
					TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
					me->state = PAUSE_STATE;
					break;
				}
			}
			break;
		}
		case PAUSE_STATE:{
			switch(e->sig){
				case TIMEOUT_SIG:{
					--me->blink_cntr;
					if(me->blink_cntr > 0U){
						BspLed2On();
						TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
						me->state = BLINK_STATE;
					}
					else{
						BspLed1On();
						BspLed2On();
						BspLed3On();
						me->state = BOOM_STATE;
					}
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
            Active_post(AO_TimeBomb, &buttonPressedEvt);
        }
        else { /* the button is released */
            /* post the "button-released" event from ISR */
            static Event const buttonReleasedEvt = {BUTTON_RELEASED_SIG};
            Active_post(AO_TimeBomb, &buttonReleasedEvt);
        }
    }
}



