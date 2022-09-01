/*
 * TimeBomb.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_TIMEBOMB_H_
#define INC_TIMEBOMB_H_


#include "freertos_ao.h"


enum EventSignals {
	BUTTON_PRESSED_SIG = USER_SIG,
	BUTTON_RELEASED_SIG,
	TIMEOUT_SIG,
	/********/
	MAX_SIG
};


typedef struct TimeBomb TimeBomb;

typedef enum {
	TRAN_STATUS,
	HANDLED_STATUS,
	IGNORED_STATUS,
	INIT_STATUS
}State;

typedef State (*StateHandler)(TimeBomb * const me, Event const * const e);

#define TRAN(target_) (me->state = (target_) , TRAN_STATUS)

struct TimeBomb{
	Active super; /* inherit active base class */
    /* add private data for the AO... */

	StateHandler state;

    TimeEvent te;
    uint32_t blink_cntr;
};








/*********************************************************************
 * @fn      		  - TimeBomb_dispatch
 *
 * @brief             -	TimeBomb Dispatch Function
 *
 * @param_type		  - TimeBomb *  : TimeBomb Structure
 * @param_name	      -	me 		 	: TimeBomb Instance
 *
 * @param_type		  - Event 		: Event Enumarations
 * @param_name        - e 			: Event Instance
 *
 * @return            - void
 *
 * @Note              - This function dispatch events on message queue
 */
void TimeBomb_dispatch(TimeBomb * const me, Event const * const e);

/*********************************************************************
 * @fn      		  -  TimeBomb_ctor
 *
 * @brief             -	TimeBomb Constructor Function
 *
 * @param_type		  -  TimeBomb 	: TimeBomb Structure
 * @param_name	      -	me 		 	: TimeBomb Strcuture Instance
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of TimeBomb Structure
 */
void  TimeBomb_ctor( TimeBomb * const me);


/*********************************************************************
 * @fn      		  - App_TimeTickHook
 *
 * @brief             -	Time Tick Hook Function
 *
 * @param_type		  - void 	 	:
 * @param_name	      -	- 		 	:
 *
 * @return            - void
 *
 * @Note              - This function handles tick interrupt events.
 */
void App_TimeTickHook(void);

#endif /* INC_TIMEBOMB_H_ */
