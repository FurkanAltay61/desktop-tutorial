/*
 * Veri_Yapilari.c
 *
 *  Created on: 21 Eyl 2022
 *      Author: furkan.altay
 */


#include "stdlib.h"
#include "stdio.h"

#define __NOP()                        __asm volatile ("nop")

#define TRUE  1
#define FALSE 0

#define FIG12_3		TRUE

#if(FIG12_3 == TRUE)

struct listeDugumu{
	char veri;
	struct listeDugumu *sonrakiPtr;
};


typedef struct listeDugumu ListeDugumu;
typedef ListeDugumu *ListeDugumuPtr;

void ekle(ListeDugumuPtr *,char);
char sil(ListeDugumuPtr *,char);
int bosMu(ListeDugumuPtr);
void listeyiYazdir(ListeDugumuPtr);
void menu(void);

#endif

int main(){

#if(FIG12_3 == TRUE)
	ListeDugumuPtr baslangicPtr = NULL;

	ekle(&baslangicPtr,'1');
	ekle(&baslangicPtr,'6');
	ekle(&baslangicPtr,'3');
	ekle(&baslangicPtr,'4');

	sil(&baslangicPtr,'A');
	sil(&baslangicPtr,'E');
	sil(&baslangicPtr,'B');
	sil(&baslangicPtr,'C');

	__NOP();
#endif

	while(1){ };

	return 0;
}


#if(FIG12_3 == TRUE)

void ekle(ListeDugumuPtr *sPtr,char deger){

	ListeDugumuPtr yeniPtr,oncekiPtr,suandakiPtr;

	yeniPtr = malloc(sizeof(ListeDugumu));

	if(yeniPtr != NULL){ /*bos alan var mi */
		yeniPtr->veri = deger;
		yeniPtr->sonrakiPtr = NULL;

		oncekiPtr = NULL;
		suandakiPtr = *sPtr;

		while((suandakiPtr != NULL) && (deger > suandakiPtr->veri)){
			oncekiPtr = suandakiPtr;
			suandakiPtr = suandakiPtr->sonrakiPtr;
		}

		if(oncekiPtr == NULL){
			yeniPtr->sonrakiPtr = *sPtr;
			*sPtr = yeniPtr;
		}
		else{
			oncekiPtr->sonrakiPtr = yeniPtr;
			yeniPtr->sonrakiPtr = suandakiPtr;
		}
	}
	else{
		//Listede bos alan yok
		__NOP();

	}
}

char sil(ListeDugumuPtr *sPtr,char deger){
	ListeDugumuPtr oncekiPtr,suandakiPtr,geciciPtr;

	if(deger == (*sPtr)->veri){
		geciciPtr = *sPtr;
		*sPtr = (*sPtr)->sonrakiPtr;
		free(geciciPtr);
		return deger;
	}
	else{
		oncekiPtr = *sPtr;
		suandakiPtr = (*sPtr)->sonrakiPtr;

		while(suandakiPtr != NULL && suandakiPtr->veri != deger){
			oncekiPtr = suandakiPtr;
			suandakiPtr = suandakiPtr->sonrakiPtr;
		}

		if(suandakiPtr != NULL){
			geciciPtr = suandakiPtr;
			oncekiPtr->sonrakiPtr = suandakiPtr->sonrakiPtr;
			free(geciciPtr);
			return deger;
		}
	}

	return 0;
}

int bosMu(ListeDugumuPtr sPtr){
	return sPtr == NULL;
}

void listeyiYazdir(ListeDugumuPtr sPtr){

}

void menu(void){

}

#endif
