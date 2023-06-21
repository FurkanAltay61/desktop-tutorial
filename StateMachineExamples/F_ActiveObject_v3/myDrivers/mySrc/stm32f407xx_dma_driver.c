


//#include "stm32f407xx_dma_driver.h"

#include <stm32f407xx_dma_driver.h>





void DMA_Init(DMA_Handle_t *pDMAHandle){

	uint32_t tmp=0;

	DMA1_PCLK_EN();

	tmp = pDMAHandle->pDMAStream->CR;


	tmp &= ((uint32_t) ~ (DMA_SCR_CHSEL | DMA_SCR_MBURST | DMA_SCR_PBURST |
						  DMA_SCR_PL    | DMA_SCR_MSIZE  | DMA_SCR_PSIZE  |
						  DMA_SCR_MINC  | DMA_SCR_PINC   | DMA_SCR_CIRC   |
						  DMA_SCR_DIR 	| DMA_SCR_CT	 | DMA_SCR_DBM));

	tmp |= pDMAHandle->pDMAConfig.Channel   | pDMAHandle->pDMAConfig.Direction |
		   pDMAHandle->pDMAConfig.PeriphInc | pDMAHandle->pDMAConfig.MemInc  |
		   pDMAHandle->pDMAConfig.Mode 	 	| pDMAHandle->pDMAConfig.Priority ;

	pDMAHandle->pDMAStream->CR = (uint32_t)tmp;

}
