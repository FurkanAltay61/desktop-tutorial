/*
 * Tekrar.c
 *
 *  Created on: 14 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef TEKRAR_C_
#define TEKRAR_C_


#include "stdio.h"
#include "stdint.h"
#include "ctype.h"
#include "time.h"
#include "stdlib.h"


#define TRUE 	1
#define FALSE   0

#define STRING_COPY  		FALSE
#define STR_TRANSFORM 		FALSE
#define CONST_POINTER_USAGE FALSE
#define CARD_PROGRAM		FALSE
#define FUNCTION_POINTER    TRUE

#if	(STRING_COPY == TRUE)
void StringCopy(char *,const char *);
void StringCopy2(char *,const char *);
#endif

#if (STR_TRANSFORM == TRUE)
void StrTransform(char *);
#endif

#if (CONST_POINTER_USAGE == TRUE)
void ConstPointFunc1(void);
void ConstPointFunc2(void);
#endif


#if (CARD_PROGRAM == TRUE)
#define TEAM 13
#define SIDE 4
#define TOTAL_CARD (TEAM * SIDE)
void Shuffle(char [][TEAM]);
void Distribute(char const [][TEAM],const char * const [],const char * const[]);
#endif

#if (FUNCTION_POINTER == TRUE)

#endif

int main(){

#if	(STRING_COPY == TRUE)
	char string1[10]={0},string2[] = "Merhaba",
		 string3[10]={0},string4[] = "GoodOne";

	StringCopy(string1,string2);
	StringCopy(string3,string4);
#endif

#if (STR_TRANSFORM == TRUE)
	char str5[] = "AsdmdslfsdkmVGFGmsdcER";
	StrTransform(str5);
#endif

#if (CONST_POINTER_USAGE == TRUE)
	//Function & Variable Here

#endif

#if (CARD_PROGRAM == TRUE)

	srand(time(NULL));
	const char * const Team[TEAM] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Joker","Queen","King"};
	const char * const Side[SIDE] = {"Club","Heart","Spade","Diamond"};
	char xDeck[SIDE][TEAM] = {0};

	Shuffle(xDeck);
	Distribute(xDeck,Team,Side);

#endif

#if (FUNCTION_POINTER == TRUE)

#endif

	while(1){

	}
	return 0;
}

#if	(STRING_COPY == TRUE)
void StringCopy(char *_str1,const char *_str2){

	for(;(*_str1 = *_str2) != '\0';_str1++,_str2++){
		//Do Nothing
	}
}

void StringCopy2(char *_str3,const char *_str4){
	for(uint8_t i=0;(_str3[i] = _str4[i]) != '\0';i++){
		//Do Nothing
	}
}
#endif


#if (STR_TRANSFORM == TRUE)

void StrTransform(char *_str5){
	for(uint8_t i=0;_str5[i] != '\0';i++){
		if(islower(_str5[i])){
			_str5[i] = toupper(_str5[i]);
		}
	}
}

#endif

#if (CONST_POINTER_USAGE == TRUE)
	//Function Body Here
void ConstPointFunc1(void){
	uint8_t y = 5;
	uint8_t * const yPTr = 0;

	*yPTr = y;
	yPTr = &y;
}
void ConstPointFunc2(void){

	uint8_t y = 5;
	const uint8_t * const yPTr = 0; //Constant pointer to points an CONSTANT integer.

	*yPTr = y;
	yPTr = &y;
}
#endif

#if (CARD_PROGRAM == TRUE)

void Shuffle(char _deck[SIDE][TEAM]){
	uint8_t __team = 0, __side = 0, card = 0;
	while(card <=TOTAL_CARD){
		__team = rand() % 13;
		__side = rand() % 4;

		if(_deck[__side][__team] == 0){
			_deck[__side][__team] = card;
			card++;
		}
	}
}
void Distribute(char const _deck[SIDE][TEAM],const char * const _team[],const char *const _side[]){
	uint8_t __team = 0, __side = 0, card = 0;
	static const char *___side = 0, *___team = 0;

	for(card = 1; card <= TOTAL_CARD; card++){
		for(__side = 0; __side < SIDE ; __side++){
			for(__team = 0; __team < TEAM ; __team++){
				if(_deck[__side][__team] == card){
					___side = _side[__side];
					___team = _team[__team];
				}
			}
		}
	}
}
#endif


#if (FUNCTION_POINTER == TRUE)

#endif


#endif /* TEKRAR_C_ */
