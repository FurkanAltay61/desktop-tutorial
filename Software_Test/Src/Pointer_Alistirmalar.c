/*
 * Pointer_Alistirmalar.c
 *
 *  Created on: 14 Eyl 2022
 *      Author: furkan.altay
 */


#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "time.h"



#define TRUE	1
#define FALSE   0

#define Q7_9   FALSE
#define Q7_12  FALSE

#if (Q7_9 == TRUE)

#define BOYUT 5
const unsigned int degerler[BOYUT] = {2,4,6,8,10};
const unsigned int *vPtr = 0, *newPtr  = 0 , *newPtr2  = 0;

void PrintArrayIndexMethod( const unsigned int [], const unsigned int );
void PrintPointerOffsetMethod( const unsigned int *, const unsigned int );

#endif

#if (Q7_12 == TRUE)

#define LENGTH 	5
#define TEAM	13
#define SIDE	4

void Shuffle(uint8_t (*)[SIDE], uint8_t *);
void Distribute(uint8_t (*)[SIDE],uint8_t *,char * const [],char * const []);
void SearchForTwos(uint8_t const [],const uint8_t);
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

char * const team[TEAM] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Joker","Queen","King"};
char * const side[SIDE] = {"Club","Heart","Spade","Diamond"};
uint8_t xDeck[TEAM][SIDE]={0};
uint8_t totalCard = 5;

srand(time(NULL));

Shuffle(xDeck,&totalCard);
Distribute(xDeck,&totalCard,team,side);


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
void Shuffle(uint8_t (*_deck)[SIDE],uint8_t *_totalcard){

	uint8_t card = 0;
	uint8_t _side = 0 , _team = 0;

	while(card < *_totalcard){

		_side = rand()%4;
		_team = rand()%13;

		if(_deck[_team][_side] == 0){
			_deck[_team][_side] = card;
			card++;
		}
	}

}

void Distribute(uint8_t (*deck)[SIDE],uint8_t *_totalcard,char * const _team[],char * const _side[]){

	char *___side = 0, *___team = 0;
	uint8_t ____side[5] = {0};

	for(uint8_t _card = 0;_card < LENGTH ; _card++){

		for(uint8_t __side = 0;__side < SIDE ; __side++){

			for(uint8_t __team = 0; __team < TEAM ; __team++){

				if(deck[__team][__side] == _card){

					___side = _side[__side];
					___team = _team[__team];

					____side[_card] = __side;
					__NOP();
				}

			}

		}

	}

	SearchForTwos(____side,LENGTH);
}

void SearchForTwos(uint8_t const _side[],const uint8_t _len){

	uint8_t twosFreq = 0;

	for(uint8_t i=1;i<=LENGTH;i++){
		if((_side[i] % 2) == 0){
			twosFreq++;
		}
	}

	__NOP();

}
#endif
