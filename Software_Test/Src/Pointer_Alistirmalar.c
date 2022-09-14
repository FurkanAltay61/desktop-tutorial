/*
 * Pointer_Alistirmalar.c
 *
 *  Created on: 14 Eyl 2022
 *      Author: furkan.altay
 */


#include "stdio.h"
#include "stdint.h"

#define __NOP()                        __asm volatile ("nop")

#define TRUE	1
#define FALSE   0

#define Q7_9   FALSE
#define Q7_12  TRUE

#if (Q7_9 == TRUE)

#define BOYUT 5
const unsigned int degerler[BOYUT] = {2,4,6,8,10};
const unsigned int *vPtr = 0, *newPtr  = 0 , *newPtr2  = 0;

void PrintArrayIndexMethod( const unsigned int [], const unsigned int );
void PrintPointerOffsetMethod( const unsigned int *, const unsigned int );

#endif

#if (Q7_12 == TRUE)

#endif

int main(){

#if (Q7_9 == TRUE)
	/*Answer : 7.9-c */
	PrintArrayIndexMethod(degerler,BOYUT);

	vPtr = &degerler[0];

	/*Answer : 7.9-e */
	PrintPointerOffsetMethod(degerler,BOYUT);

	/*Answer : 7.9-i */
	newPtr = vPtr+3;

	vPtr = &degerler[4];
	vPtr -= 4;

#endif


#if (Q7_12 == TRUE)

#endif

	while(1){};
	return 0;
}


#if (Q7_9 == TRUE)
/*Answer : 7.9-c */
void PrintArrayIndexMethod( const unsigned int _arr[] , const unsigned int _len){
	unsigned int val = 0;
	for(uint8_t i = 0; i < _len ; i++){
//		val = _arr[i];
		val = *(_arr + i);
		__NOP();
	}
}

/*Answer : 7.9-e */
void PrintPointerOffsetMethod( const unsigned int *pArr, const unsigned int _len){

	unsigned int val = 0;
	for(uint8_t i = 0; i < _len ; i++){
		val = *(pArr + i);
		__NOP();
	}
}

#endif

#if (Q7_12 == TRUE)

#endif
