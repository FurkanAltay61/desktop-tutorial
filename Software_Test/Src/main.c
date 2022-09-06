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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define MAX_CAPACITY 10

static uint8_t mPool[MAX_CAPACITY] = {0};



typedef struct {
	uint32_t start_addr;
	uint32_t mem_size;
	uint32_t end_add;
}Pool;

typedef struct {
	uint8_t Sig;
}Event;

typedef struct {
	Event Qevt;
	char TextMsg[20];
}Text;


_Bool Alan_Tara(Text Fmsg , Pool *fPool);

int main(void)
{

	Text a1;
	Pool p1;
    /* Loop forever */

	_Bool result = Alan_Tara(a1,&p1);
	for(;;);
}

_Bool Alan_Tara(Text Fmsg , Pool *fPool){
	uint32_t m_count=0;
	_Bool durum=1;

	if(sizeof(Fmsg) < MAX_CAPACITY){
		for(uint32_t i=0;i<MAX_CAPACITY;i++){

			if(mPool[i] == 0){
				m_count++;
			}
			else{
				if(m_count > sizeof(Fmsg)){
					break;
				}
				else{
					durum = 0;
				}

				m_count = 0;
			}

		}
	}
	else{
		durum = 0;
	}

	return durum;
}

