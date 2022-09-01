/*
 * TimeBomb.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "TimeBomb.h"
#include "Bsp.h"
#include "stm32f407xx_gpio_driver.h"

State TimeBomb_Initial(TimeBomb * const me, Event const * const e);
State TimeBomb_WaitForButton(TimeBomb * const me, Event const * const e);
State TimeBomb_Blink(TimeBomb * const me, Event const * const e);
State TimeBomb_Pause(TimeBomb * const me, Event const * const e);
State TimeBomb_Boom(TimeBomb * const me, Event const * const e);


State TimeBomb_Initial(TimeBomb * const me, Event const * const e) {
	return TRAN(TimeBomb_WaitForButton);
}


State TimeBomb_WaitForButton(TimeBomb * const me, Event const * const e) {

	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			BspLedOn12();
			Status = HANDLED_STATUS;
			break;
		}
		case EXIT_SIG:{
			BspLedOff12();
			Status = HANDLED_STATUS;
			break;
		}
		case BUTTON_PRESSED_SIG:{
			me->blink_cntr = 3;
			Status = TRAN(TimeBomb_Blink);
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;
}

State TimeBomb_Blink(TimeBomb * const me, Event const * const e) {

	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			BspLedOn13();
			TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
			Status = HANDLED_STATUS;
			break;
		}
		case EXIT_SIG:{
			BspLedOff13();
			Status = HANDLED_STATUS;
			break;
		}
		case TIMEOUT_SIG:{
			Status= TRAN(TimeBomb_Pause);
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;
}


State TimeBomb_Pause(TimeBomb * const me, Event const * const e) {

	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
			Status = HANDLED_STATUS;
			break;
		}
		case TIMEOUT_SIG:{
			--me->blink_cntr;
			if(me->blink_cntr > 0U){
				Status = TRAN(TimeBomb_Blink);
			}
			else{
				Status = TRAN(TimeBomb_Boom);
			}
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;
}


State TimeBomb_Boom(TimeBomb * const me, Event const * const e) {

	State Status;

	switch(e->sig){
		case ENTRY_SIG:{
			BspLedOn12();
			BspLedOn13();
			BspLedOn14();
			BspLedOn15();
			Status = HANDLED_STATUS;
			break;
		}
		default:{
			Status = IGNORED_STATUS;
			break;
		}
	}

	return Status;
}



/*********************************************************************
 * @fn      		  - TimeBomb_ctor
 *
 * @brief             -	TimeBomb Constructor Function
 *
 * @param_type		  - TimeBomb 	: TimeBomb Structure
 * @param_name	      -	me 		 	: TimeBomb Strcuture Instance
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of TimeBomb Structure
 */
void TimeBomb_ctor(TimeBomb * const me) {
    Active_ctor(&me->super, (DispatchHandler)&TimeBomb_dispatch); /*Initiliase the active object structure */
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);				  /*Initiliase the TimeoutEvent structure */
    me->state = TimeBomb_Initial;
}



void TimeBomb_dispatch(TimeBomb * const me, Event const * const e){
	State stat;
	StateHandler prev_state = me->state;	/*save for later*/

	Q_ASSERT((me->state < (StateHandler)0) && (e->sig < MAX_SIG));
	stat = (*me->state)(me,e);

	if(stat == TRAN_STATUS){		/*transition taken?*/

		static Event const entryEvt = {ENTRY_SIG};
		static Event const exitEvt =  {EXIT_SIG};

		Q_ASSERT((me->state < (StateHandler)0));

		if(e->sig != INIT_SIG){
			(*prev_state)(me,&exitEvt);
		}

		(*me->state)(me,&entryEvt);

	}
}





