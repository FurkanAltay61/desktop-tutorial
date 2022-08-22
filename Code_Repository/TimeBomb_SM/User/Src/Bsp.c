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
