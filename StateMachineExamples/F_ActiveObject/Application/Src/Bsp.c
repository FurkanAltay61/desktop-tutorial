/*
 * Bsp.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "BlinkyButton.h"
#include "stm32f407xx_gpio_driver.h"
#include "Bsp.h"

_Bool BspGetButtonState(void){
//	return HAL_GPIO_ReadPin(USER_Btn_GPIO_Port,USER_Btn_Pin);

	return GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0);
}

void BspLedOn(void){
//	HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_SET);

	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_SET);
}
void BspLedOff(void){
//	HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_RESET);

	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
}


extern Active *AO_BlinkyButton;

/* uCOS-II application hooks ===============================================*/
void App_TimeTickHook(void) {
    /* state of the button debouncing, see below */
    static struct ButtonsDebouncing {
        uint32_t depressed;
        uint32_t previous;
    } buttons = { 0U, 0U };
    uint32_t current;
    uint32_t tmp;

    TimeEvent_tick(); /* process all uC/AO time events */

    /* Perform the debouncing of buttons. The algorithm for debouncing
    * adapted from the book "Embedded Systems Dictionary" by Jack Ganssle
    * and Michael Barr, page 71.
    */
    current = BspGetButtonState(); /* read SW1 */
    tmp = buttons.depressed; /* save the debounced depressed buttons */
    buttons.depressed |= (buttons.previous & current); /* set depressed */
    buttons.depressed &= (buttons.previous | current); /* clear released */
    buttons.previous   = current; /* update the history */
    tmp ^= buttons.depressed;     /* changed debounced depressed */

    if ((tmp & BspGetButtonState()) != 0U) {  /* debounced SW1 state changed? */
        if ((buttons.depressed & BspGetButtonState()) != 0U) { /* is SW1 depressed? */
            /* post the "button-pressed" event from ISR */
            static Event const buttonPressedEvt = {BUTTON_PRESSED_SIG};
            Active_post(AO_BlinkyButton, &buttonPressedEvt);
        }
        else { /* the button is released */
            /* post the "button-released" event from ISR */
            static Event const buttonReleasedEvt = {BUTTON_RELEASED_SIG};
            Active_post(AO_BlinkyButton, &buttonReleasedEvt);
        }
    }
}


void Q_onAssert(char const *module, int loc) {
    /* TBD: damage control */
    (void)module; /* avoid the "unused parameter" compiler warning */
    (void)loc;    /* avoid the "unused parameter" compiler warning */
//    NVIC_SystemReset();
}


