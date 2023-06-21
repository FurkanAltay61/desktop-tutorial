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
#include <assert.h>
#include "mem_pool.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


/* TEMP PROG */

#define OGRENCI_SAYISI 16
#define PUAN_ARALIK	   10

int main(void)
{

	uint8_t Cevaplar[OGRENCI_SAYISI]={1,2,2,3,3,5,5,5,7,3,2,8,3,9,8,8};
	uint8_t Puanlar[PUAN_ARALIK]={0};

	for(uint8_t i=0;i<OGRENCI_SAYISI;i++){
		++Puanlar[Cevaplar[i]];
	}

	for(;;);
}



