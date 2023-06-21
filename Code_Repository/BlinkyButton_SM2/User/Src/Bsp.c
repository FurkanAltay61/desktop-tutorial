/*
 * Bsp.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#include "Bsp.h"



_Bool BspGetButtonState(void){
	return HAL_GPIO_ReadPin(USER_Btn_GPIO_Port,USER_Btn_Pin);
}

void BspLedOn(void){
	HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_SET);
}
void BspLedOff(void){
	HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_RESET);
}


