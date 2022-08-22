/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stdlib.h"
#include "FreeRTOS.h"
#include "task.h"



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


void tempTask(void *arg);


void  TaskStart (void *pdata);

int main(void)
{

	xTaskCreate(tempTask,"Temp_Task",configMINIMAL_STACK_SIZE,NULL,1,NULL);

	vTaskStartScheduler();

    /* Loop forever */
	for(;;);
}



void tempTask(void *arg){

	static uint8_t a=0;

	while(1){

		a=1;
	}
}

