/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "BlinkyButton.h"
#include "Bsp.h"
#include "stm32f407xx_gpio_driver.h"


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

void BlinkyButton_ctor(BlinkyButton * const me) {
    Active_ctor(&me->super, (DispatchHandler)&BlinkyButton_dispatch); /*Initiliase the active object structure */
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);					  /*Initiliase the TimeoutEvent structure */
    me->blink_time = INITIAL_BLINK_TIME;							  /*Led blink time period is chosen */
}


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
void BlinkyButton_dispatch(BlinkyButton * const me, Event const * const e){



	if(e->sig == INIT_SIG){
		BspLedOff12();
		TimeEvent_arm(&me->te, me->blink_time * 3U, 0U);
		me->state = OFF_STATE;
		return;
	}


	switch(me->state){

		case OFF_STATE:{
			switch(e->sig){

				case TIMEOUT_SIG:{
					BspLedOn13();
					TimeEvent_arm(&me->te, me->blink_time, 0U);
					me->state = ON_STATE;
					break;
				}

				case BUTTON_PRESSED_SIG:{

					BspLedOn12();

					me->blink_time >>= 1; /*shorten the blink time by factor of 2*/
					if(me->blink_time == 0){
						me->blink_time = INITIAL_BLINK_TIME;
					}
					break;
				}

				case BUTTON_RELEASED_SIG:{
					BspLedOff12();

					break;
				}

				break;
			}
			break;
		}

		case ON_STATE:{

			switch(e->sig){

				case TIMEOUT_SIG:{
					BspLedOff13();
					TimeEvent_arm(&me->te,me->blink_time * 3U, 0U);
					me->state = OFF_STATE;
					break;
				}

				case BUTTON_PRESSED_SIG:{

					BspLedOn13();

					me->blink_time >>= 1; /*shorten the blink time by factor of 2*/
					if(me->blink_time == 0){
						me->blink_time = INITIAL_BLINK_TIME;
					}
					break;
				}

				case BUTTON_RELEASED_SIG:{
					BspLedOff13();
					break;
				}

				break;
			}

			break;
		}

		default: {
			Q_ASSERT(0);
			break;
		}

	}

}






