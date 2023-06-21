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
}


/*********************************************************************
 * @fn      		  - TimeBomb_dispatch
 *
 * @brief             -	TimeBomb Dispatch Function
 *
 * @param_type		  - TimeBomb *      : TimeBomb Structure
 * @param_name	      -	me 		 		: TimeBomb Instance
 *
 * @param_type		  - Event 			: Event Enumarations
 * @param_name        - e 				: Event Instance
 *
 * @return            - void
 *
 * @Note              - This function dispatch events on message queue
 */
void TimeBomb_dispatch(TimeBomb * const me, Event const * const e){



	if(e->sig == INIT_SIG){
		BspLedOn12();
		me->state = WAIT4BUTTON_STATE;
	}


	switch(me->state){

		case WAIT4BUTTON_STATE:{

			switch(e->sig){

				case BUTTON_PRESSED_SIG:{

					BspLedOff12();
					BspLedOn13();
					TimeEvent_arm(&me->te,OS_TICKS_PER_SEC/2, 0U);
					me->blink_cntr = 3;
					me->state = BLINK_STATE;
					break;

				}

			}

			break;
		}

		case BLINK_STATE:{

			switch(e->sig){

				case TIMEOUT_SIG:{
					BspLedOff13();
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

					break;
				}

			}

			break;
		}


		case BOOM_STATE:{
			break;
		}

		default: {
			Q_ASSERT(0);
			break;
		}

	}

}






