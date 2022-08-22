/*
 * Bsp.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include "qpc.h"
#include "Bsp.h"
#include "main.h"




/* Qpc application hooks ===============================================*/
void App_TimeTickHook(void) {
    /* state of the button debouncing, see below */
    static struct ButtonsDebouncing {
        uint32_t depressed;
        uint32_t previous;
    } buttons = { 0U, 0U };
    uint32_t current;
    uint32_t tmp;

    QF_TICK_X(0U,(void *)0);

    /* Perform the debouncing of buttons. The algorithm for debouncing
    * adapted from the book "Embedded Systems Dictionary" by Jack Ganssle
    * and Michael Barr, page 71.
    */
    current = BspGetButtonState(1U) | BspGetButtonState(2U); /* read SW1/SW2 */
    tmp = buttons.depressed; /* save the debounced depressed buttons */
    buttons.depressed |= (buttons.previous & current); /* set depressed */
    buttons.depressed &= (buttons.previous | current); /* clear released */
    buttons.previous   = current; /* update the history */
    tmp ^= buttons.depressed;     /* changed debounced depressed */

    if ((tmp & BspGetButtonState(1U)) != 0U) {  /* debounced SW1 state changed? */
        if ((buttons.depressed & BspGetButtonState(1U)) != 0U) { /* is SW1 depressed? */
            /* post the "button-pressed" event from ISR */
            static QEvt const buttonPressedEvt = {BUTTON_PRESSED_SIG};
            QACTIVE_POST(AO_TimeBomb, &buttonPressedEvt,0U);
        }
        else { /* the button is released */
            /* post the "button-released" QEvt from ISR */
            static QEvt const buttonReleasedEvt = {BUTTON_RELEASED_SIG};
            QACTIVE_POST(AO_TimeBomb, &buttonReleasedEvt,0U);
        }
    }


    if ((tmp & BspGetButtonState(2U)) != 0U) {  /* debounced SW1 state changed? */
        if ((buttons.depressed & BspGetButtonState(2U)) != 0U) { /* is SW1 depressed? */
            /* post the "button-pressed" QEvt from ISR */
            static QEvt const button2PressedEvt = {BUTTON2_PRESSED_SIG};
            QACTIVE_POST(AO_TimeBomb, &button2PressedEvt,0U);
        }
        else { /* the button is released */
            /* post the "button-released" QEvt from ISR */
            static QEvt const button2ReleasedEvt = {BUTTON2_RELEASED_SIG};
            QACTIVE_POST(AO_TimeBomb, &button2ReleasedEvt,0U);
        }
    }
}



void QV_onIdle(void){
#ifndef NDEBUG
	QV_CPU_SLEEP();
#else
	QF_INT_ENABLE();
#endif
}


void QF_onStartup(void){
	HAL_SYSTICK_Config(SystemCoreClock / BSP_TICKS_PER_SEC);
	HAL_NVIC_SetPriority(SysTick_IRQn,QF_AWARE_ISR_CMSIS_PRI+1U,0);
}

_Bool BspGetButtonState(uint8_t ButtonNum){

	_Bool ButtonStatus;

	switch(ButtonNum){
		case 1:
			ButtonStatus = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port,USER_Btn_Pin);
			break;
		case 2:
			ButtonStatus = HAL_GPIO_ReadPin(BUTON1_GPIO_Port,BUTON1_Pin);
			break;
		case 3:
			ButtonStatus = HAL_GPIO_ReadPin(BUTON2_GPIO_Port,BUTON2_Pin);
			break;
	}

	return ButtonStatus;
}

void BspLed1On(void){
	HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_SET);
}
void BspLed1Off(void){
	HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_RESET);
}

void BspLed2On(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_SET);
}
void BspLed2Off(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_RESET);
}

void BspLed3On(void){
	HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_SET);
}
void BspLed3Off(void){
	HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_RESET);
}
