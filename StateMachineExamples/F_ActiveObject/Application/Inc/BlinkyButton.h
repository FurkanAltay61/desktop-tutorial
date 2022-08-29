/*
 * BlinkyButton.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_BLINKYBUTTON_H_
#define INC_BLINKYBUTTON_H_


#include "freertos_ao.h"


enum EventSignals {
	BUTTON_PRESSED_SIG = USER_SIG,
	BUTTON_RELEASED_SIG,
	TIMEOUT_SIG
	/********/
};



typedef struct {
	Active super; /* inherit active base class */
    /* add private data for the AO... */
    TimeEvent te;
    _Bool isLedOn;
    uint32_t blink_time;
}BlinkyButton;



/*********************************************************************
 * @fn      		  - BlinkyButton_dispatch
 *
 * @brief             -	Blinky Button Dispatch Function
 *
 * @param_type		  - BlinkyButton *  : Blinky Button Structure
 * @param_name	      -	me 		 		: Blinky Button Instance
 *
 * @param_type		  - Event 			: Event Enumarations
 * @param_name        - e 				: Event Instance
 *
 * @return            - void
 *
 * @Note              - This function dispatch events on message queue
 */
void BlinkyButton_dispatch(BlinkyButton * const me, Event const * const e);

/*********************************************************************
 * @fn      		  - BlinkyButton_ctor
 *
 * @brief             -	Blinky Button Constructor Function
 *
 * @param_type		  - BlinkyButton 	: Blinky Button Structure
 * @param_name	      -	me 		 		: Blinky Button Strcuture Instance
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of Blinky Button Structure
 */
void BlinkyButton_ctor(BlinkyButton * const me);

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

#endif /* INC_BLINKYBUTTON_H_ */
