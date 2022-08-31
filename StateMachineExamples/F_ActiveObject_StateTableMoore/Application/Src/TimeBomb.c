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


static void TimeBomb_ignore(TimeBomb * const me, Event const * const e){
	(void)0;
}

static void TimeBomb_init(TimeBomb * const me, Event const * const e){
	BspLedOn12();
	me->state = WAIT4BUTTON_STATE;
}

static void TimeBomb_wait_for_button_PRESSED(TimeBomb * const me, Event const * const e){
	BspLedOff12();
	BspLedOn13();
	TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
	me->blink_cntr = 3;
	me->state = BLINK_STATE;
}

static void TimeBomb_blink_TIMEOUT(TimeBomb * const me, Event const * const e){
	BspLedOff13();
	TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
	me->state = PAUSE_STATE;
}

static void TimeBomb_pause_TIMEOUT(TimeBomb * const me, Event const * const e){
	--me->blink_cntr;
	if(me->blink_cntr > 0U){
		BspLedOn13();
		TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
		me->state = BLINK_STATE;
	}
	else{
		BspLedOn12();
		BspLedOn13();
		BspLedOn14();
		BspLedOn15();
		me->state = BOOM_STATE;
	}
}



typedef void (*TimeBombAction)(TimeBomb * const me, Event const * const e);

static TimeBombAction const TimeBomb_Table[MAX_STATE][MAX_SIG]={
					    /* INIT              | PRESSED                          | RELEASED        | TIMEOUT */

	/* wait-for-button*/ { &TimeBomb_init,   &TimeBomb_wait_for_button_PRESSED, &TimeBomb_ignore, &TimeBomb_ignore       },
	/* blink          */ { &TimeBomb_ignore, &TimeBomb_ignore,        			&TimeBomb_ignore, &TimeBomb_blink_TIMEOUT},
	/* pause          */ { &TimeBomb_ignore, &TimeBomb_ignore,        			&TimeBomb_ignore, &TimeBomb_pause_TIMEOUT},
	/* boom           */ { &TimeBomb_ignore, &TimeBomb_ignore,        			&TimeBomb_ignore, &TimeBomb_ignore       }
};


void TimeBomb_dispatch(TimeBomb * const me, Event const * const e){
	Q_ASSERT((me->state < MAX_STATE) && (e->sig < MAX_SIG));
	(*TimeBomb_Table[me->state][e->sig])(me,e);
}





