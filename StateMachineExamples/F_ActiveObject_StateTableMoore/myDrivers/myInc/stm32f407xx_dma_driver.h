/*
 * stm32f4xx_dma_driver.h
 *
 *  Created on: Aug 1, 2022
 *      Author: ALTAYSAN
 */

#ifndef MYINC_STM32F407XX_DMA_DRIVER_H_
#define MYINC_STM32F407XX_DMA_DRIVER_H_

#include "stm32f407xx.h"


typedef struct {

	uint32_t Channel;

	uint32_t Direction;

	uint32_t PeriphInc;

	uint32_t MemInc;

	//uint32_t PeriphDataAlignment;

	//uint32_t MemDataAlignment;

	uint32_t Mode;

	uint32_t Priority;

	uint32_t FIFOMode;

	uint32_t FIFOThreshold;

}DMA_Config_t;




typedef struct {

	DMA_RegDef_t *pDMAReg;
	DMA_Config_t pDMAConfig;
	DMA_Stream_t *pDMAStream;
	uint8_t      *TxData;

}DMA_Handle_t;



void DMA_Init(DMA_Handle_t *pDMAHandle);


#endif /* MYINC_STM32F4XX_DMA_DRIVER_H_ */
