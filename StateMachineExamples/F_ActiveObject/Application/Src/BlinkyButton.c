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
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super); /*Initiliase the TimeoutEvent structure */
    me->isLedOn = false;							/*Assign led status as "false" */
    me->blink_time = INITIAL_BLINK_TIME;			/*Led blink time period is chosen */
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


	switch(e->sig){
		case INIT_SIG:{
			BspLedOff();		/*Turn Off the Led */
		}
		case TIMEOUT_SIG:{
            if (!me->isLedOn) { /* LED not on */
            	BspLedOn();										/*Turn On the Led*/
            	me->isLedOn = true;								/*Assign the led status as "true" */
                TimeEvent_arm(&me->te, me->blink_time, 0U);		/*Arm the timer */
            }
            else {  /* LED is on */
            	BspLedOff();           							 /*Turn Off the Led */
            	me->isLedOn = false;   							 /*Assign the led status as "true" */
                TimeEvent_arm(&me->te, me->blink_time * 3U, 0U); /*Arm the timer */
             }
			break;
		}
		case BUTTON_PRESSED_SIG:{
			GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_SET);

            me->blink_time >>= 1; /* shorten the blink time by factor of 2 */
            if (me->blink_time == 0U) {
                me->blink_time = INITIAL_BLINK_TIME;
            }
			break;
		}
		case BUTTON_RELEASED_SIG:{
			GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
			break;
		}
		default: {
			break;
		}
	}
}






