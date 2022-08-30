/*
 * stm32f4xx_rcc_driver.h
 *
 *  Created on: Aug 1, 2022
 *      Author: ALTAYSAN
 */

#ifndef MYINC_STM32F407XX_RCC_DRIVER_H_
#define MYINC_STM32F407XX_RCC_DRIVER_H_

#include "stm32f407xx.h"


uint32_t RCC_GetPCLK1Value(void);
uint32_t RCC_GetPCLK2Value(void);
uint32_t  RCC_GetPLLOutputClock();

#endif /* MYINC_STM32F4XX_RCC_DRIVER_H_ */
