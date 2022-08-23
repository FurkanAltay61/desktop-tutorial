/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "BlinkyButton.h"
#include "Bsp.h"
#include "stm32f407xx_gpio_driver.h"

void BlinkyButton_ctor(BlinkyButton * const me) {
    Active_ctor(&me->super, (DispatchHandler)&BlinkyButton_dispatch);
    TimeEvent_ctor(&me->te,TIMEOUT_SIG,&me->super);
    me->isLedOn = false;
    me->blink_time = INITIAL_BLINK_TIME;
}


void BlinkyButton_dispatch(BlinkyButton * const me, Event const * const e){

	switch(e->sig){
		case INIT_SIG:{
			BspLedOff();
		}
		case TIMEOUT_SIG:{
            if (!me->isLedOn) { /* LED not on */
            	BspLedOn();
            	me->isLedOn = true;
                TimeEvent_arm(&me->te, me->blink_time, 0U);
            }
            else {  /* LED is on */
            	BspLedOff();
            	me->isLedOn = false;
                TimeEvent_arm(&me->te, me->blink_time * 3U, 0U);
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





