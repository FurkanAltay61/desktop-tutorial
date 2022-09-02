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

struct TimeBomb{
	Active super; /* inherit active base class */
    /* add private data for the AO... */

    TimeEvent te;
    uint32_t blink_cntr;
    char *p_msg;
};



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
