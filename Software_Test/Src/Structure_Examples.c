/*
 * Structure_Examples.c
 *
 *  Created on: 20 Eyl 2022
 *      Author: furkan.altay
 */


#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define __NOP()                        __asm volatile ("nop")

#define TRUE  1
#define FALSE 0


#define FIG10_3			FALSE
#define FIG10_5			FALSE
#define FIG10_18		TRUE


#if(FIG10_3	== TRUE)
#define TOTAL_CARD 	52
struct kart {
	const char *taraf;
	const char *takim;
};

typedef struct kart Kart;

void desteyiDoldur(Kart * const,const char *[],const char *[]);
void desteyiKar(Kart * const);
void dagit(const Kart * const);

#endif

#if(FIG10_5	== TRUE)
union sayi {
	int x;
	double y;
};


#endif

#if(FIG10_18 == TRUE)
enum aylar { OCA = 1, SUB, MAR , NIS , MAY , HAZ , TEM , AGU , EYL , EKI , KAS , ARA };
#endif

int main(){

#if(FIG10_3	== TRUE)
 Kart deste[52];

 const char *taraf[] = {"As","Iki","Uc","Dort","Bes","Alti","Yedi","Sekiz","Dokuz","On","Jilet","Kiz","Papaz" };
 const char *takim[] = {"Kupa","Kiz","Maça","Sinek" };

 srand(time(NULL));

 desteyiDoldur(deste,taraf,takim);
 desteyiKar(deste);
 dagit(deste);

#endif

#if(FIG10_5	== TRUE)
 union sayi deger;

 deger.x = 100;
 deger.y = 100.0;

 __NOP();
#endif

#if(FIG10_18 == TRUE)
enum aylar ay;

const char *Ayismi[] = { " " ,"Ocak", "Subat" , "Mart" , "Nisan" , "Mayis" , "Haziran" ,
						 "Temmuz" , "Agustos" , "Eylul", "Ekim" , "Kasim" , "Aralik" };

char *tempAy = 0;

for(ay = OCA ; ay <= ARA ; ay++){
	tempAy = Ayismi[ay];
	__NOP();
}
#endif

	return 0;
}


#if(FIG10_3	== TRUE)

void desteyiDoldur(Kart * const wDeste,const char *wTaraf[],const char *wTakim[]){
	for(uint8_t i=0;i<TOTAL_CARD;i++){
		wDeste[i].taraf = wTaraf[i % 13];
		wDeste[i].takim = wTakim[i / 13];
	}
}

void desteyiKar(Kart * const wDeste){
	int i,j;
	Kart gecici;

	for(i=0;i<TOTAL_CARD;i++){
		j = rand() % 52;
		gecici = wDeste[i];
		wDeste[i] = wDeste[j];
		wDeste[j] = gecici;
	}
}
void dagit(const Kart * const wDeste){

	int i=0;
	char  *_taraf = 0 ,* _takim=0;

	for(i=0;i<TOTAL_CARD;i++){
		_takim = wDeste[i].takim;
		_taraf = wDeste[i].taraf;
		__NOP();
	}
}


#endif


#if(FIG10_18 == TRUE)

#endif

