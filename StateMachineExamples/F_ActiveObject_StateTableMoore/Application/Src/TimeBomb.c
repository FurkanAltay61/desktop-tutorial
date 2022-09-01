/*
 * TimeBomb.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "TimeBomb.h"
#include "Bsp.h"
#include "stm32f407xx_gpio_driver.h"


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
    me->state = WAIT4BUTTON_STATE;
}


static Status TimeBomb_ignore(TimeBomb * const me, Event const * const e){
	(void)0;
	return IGNORED_STATUS;
}

static Status TimeBomb_init(TimeBomb * const me, Event const * const e){
	me->state = WAIT4BUTTON_STATE;
	return TRAN_STATUS;
}



static Status TimeBomb_wait_for_button_ENTRY(TimeBomb * const me, Event const * const e){
	BspLedOn12();
	return HANDLED_STATUS;
}

static Status TimeBomb_wait_for_button_EXIT(TimeBomb * const me, Event const * const e){
	BspLedOff12();
	return HANDLED_STATUS;
}


static Status TimeBomb_wait_for_button_PRESSED(TimeBomb * const me, Event const * const e){
	me->blink_cntr = 3;
	me->state = BLINK_STATE;
	return TRAN_STATUS;
}



static Status TimeBomb_blink_ENTRY(TimeBomb * const me, Event const * const e){
	BspLedOn13();
	TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
	return HANDLED_STATUS;
}

static Status TimeBomb_blink_EXIT(TimeBomb * const me, Event const * const e){
	BspLedOff13();
	return HANDLED_STATUS;
}

static Status TimeBomb_blink_TIMEOUT(TimeBomb * const me, Event const * const e){
	me->state = PAUSE_STATE;
	return TRAN_STATUS;
}



static Status TimeBomb_pause_ENTRY(TimeBomb * const me, Event const * const e){
	TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
	return HANDLED_STATUS;
}

static Status TimeBomb_pause_TIMEOUT(TimeBomb * const me, Event const * const e){
	--me->blink_cntr;
	if(me->blink_cntr > 0U){
		me->state = BLINK_STATE;
		return TRAN_STATUS;
	}
	else{
		me->state = BOOM_STATE;
		return TRAN_STATUS;
	}
}

static Status TimeBomb_boom_ENTRY(TimeBomb * const me, Event const * const e){
	BspLedOn12();
	BspLedOn13();
	BspLedOn14();
	BspLedOn15();
	return HANDLED_STATUS;
}



typedef Status (*TimeBombAction)(TimeBomb * const me, Event const * const e);

static TimeBombAction const TimeBomb_Table[MAX_STATE][MAX_SIG]={
					    /* INIT              		|ENTRY							   |EXIT            						| PRESSED                          | RELEASED        	| TIMEOUT */

	/* wait-for-button*/ { &TimeBomb_init,   		&TimeBomb_wait_for_button_ENTRY,   &TimeBomb_wait_for_button_EXIT,     		&TimeBomb_wait_for_button_PRESSED, &TimeBomb_ignore, 	&TimeBomb_ignore       },
	/* blink          */ { &TimeBomb_ignore,   		&TimeBomb_blink_ENTRY,        	   &TimeBomb_blink_EXIT, 					&TimeBomb_ignore,				   &TimeBomb_ignore,	&TimeBomb_blink_TIMEOUT},
	/* pause          */ { &TimeBomb_ignore, 		&TimeBomb_pause_ENTRY,        	   &TimeBomb_ignore, 						&TimeBomb_ignore,				   &TimeBomb_ignore,	&TimeBomb_pause_TIMEOUT},
	/* boom           */ { &TimeBomb_ignore, 		&TimeBomb_boom_ENTRY,        	   &TimeBomb_ignore, 						&TimeBomb_ignore,       		   &TimeBomb_ignore,	&TimeBomb_ignore,	   }
};


void TimeBomb_dispatch(TimeBomb * const me, Event const * const e){
	Status stat;
	int prev_state = me->state;	/*save for later*/

	Q_ASSERT((me->state < MAX_STATE) && (e->sig < MAX_SIG));
	stat = (*TimeBomb_Table[me->state][e->sig])(me,e);

	if(stat == TRAN_STATUS){		/*transition taken?*/
		Q_ASSERT((me->state < MAX_STATE));
		(*TimeBomb_Table[prev_state][EXIT_SIG])(me,(Event *)0);
		(*TimeBomb_Table[me->state][ENTRY_SIG])(me,(Event *)0);
	}
	else if(stat == INIT_STATUS){	/*initial transition*/
		(*TimeBomb_Table[me->state][ENTRY_SIG])(me,(Event *)0);
	}
}





