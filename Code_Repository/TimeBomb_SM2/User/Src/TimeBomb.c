/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include <TimeBomb.h>
#include "Bsp.h"
#include "qassert.h"

Q_DEFINE_THIS_FILE;


State TimeBomb_initial(TimeBomb * const me, Event const * const e);
State TimeBomb_wait4button(TimeBomb * const me, Event const * const e);
State TimeBomb_blink(TimeBomb * const me, Event const * const e);
State TimeBomb_pause(TimeBomb * const me, Event const * const e);
State TimeBomb_boom(TimeBomb * const me, Event const * const e);

void TimeBomb_ctor(TimeBomb * const me) {
    Active_ctor(&me->super, (StateHandler)&TimeBomb_initial);
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);
}



State TimeBomb_initial(TimeBomb * const me, Event const * const e) {
	return TRAN(TimeBomb_wait4button);
}


State TimeBomb_wait4button(TimeBomb * const me, Event const * const e){
	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			BspLed1On();
			Status = HANDLED_STATUS;
			break;
		}
		case EXIT_SIG:{
			BspLed1Off();
			Status = HANDLED_STATUS;
			break;
		}
		case BUTTON_PRESSED_SIG:{
			me->blink_cntr = 10U;
			Status =TRAN(TimeBomb_blink);
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;
}


State TimeBomb_blink(TimeBomb * const me, Event const * const e) {

	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			BspLed2On();
			TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2,0U);
			Status = HANDLED_STATUS;
			break;
		}
		case EXIT_SIG:{
			BspLed2Off();
			Status = HANDLED_STATUS;
			break;
		}
		case TIMEOUT_SIG:{
			Status = TRAN(TimeBomb_pause);
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;


//	Entry:
//		BspLed2On();
//		TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2,0U);
//	Exit:
//		BspLed2Off();
//
//	TIMEOUT:
//		TRAN(TimeBomb_pause);

}



State TimeBomb_pause(TimeBomb * const me, Event const * const e){


	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2,0U);
			Status = HANDLED_STATUS;
			break;
		}
		case TIMEOUT_SIG:{
			--me->blink_cntr;
			if(me->blink_cntr > 0U){
				Status = TRAN(TimeBomb_blink);
			}
			else{
				Status = TRAN(TimeBomb_boom);
			}
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;



//	Entry:
//		TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2,0U);
//
//	TIMEOUT:
//		--me->blink_cntr;
//		if(me->blink_cntr > 0U){
//			TRAN(TimeBomb_blink);
//		}
//		else{
//			TRAN(TimeBomb_boom);
//		}
}


State TimeBomb_boom(TimeBomb * const me, Event const * const e){


	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			BspLed1On();
			BspLed2On();
			BspLed3On();
			Status = HANDLED_STATUS;
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;


//	Entry:
//		BspLed1On();
//		BspLed2On();
//		BspLed3On();

}





//void TimeBomb_dispatch(TimeBomb * const me, Event const * const e){
//
//	State Stat;
//	StateHandler prev_state = me->State;
//
//	Q_ASSERT(me->State != (StateHandler)0 && (e->sig < MAX_SIG));
//	Stat = (*me->State)(me,e);
//
//	if(Stat == TRAN_STATUS){
//		static Event const entryEvt = { ENTRY_SIG};
//		static Event const exitEvt = { EXIT_SIG};
//
//		Q_ASSERT(me->State != (StateHandler)0);
//
//		if(e->sig != INIT_SIG){
//			(*prev_state)(me,&exitEvt);
//		}
//
//		(*me->State)(me,&entryEvt);
//	}
//
//}



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



