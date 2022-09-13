/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */

#include <stdio.h>
#include <ctype.h>
#include "stdlib.h"
#include "time.h"

#define FALSE 0
#define TRUE  1

#define CAPITAL_TRANSFORM	FALSE
#define PRINT_CHARACTERS	FALSE
#define STRING_COPY_EXAMPLE FALSE
#define CONST_POINTER_USAGE	FALSE
#define KART_DAGITMA_PROG	FALSE



#if (CAPITAL_TRANSFORM == TRUE)
void TransformToCapitalLetter(char *);
#endif

#if (PRINT_CHARACTERS == TRUE)
void PrintCharacters(const char *);
#endif

#if (CONST_POINTER_USAGE == TRUE)
void PointerConstExample(void);
void PointerConstExample2(void);
#endif

#if (STRING_COPY_EXAMPLE == TRUE)
void Copy1(char *,const char *);
void Copy2(char *,const char *);

	char string1[10], *string2 = "Hello",
		 string3[10], string4[] = "GoodBye";
#endif


#if (KART_DAGITMA_PROG == TRUE)
void kar(int [][13]);
void dagit(const int [][13],const char *[],const char *[]);
#endif

int main(){

	char string[] = "characters and $32.98";

#if (CAPITAL_TRANSFORM == TRUE)
	TransformToCapitalLetter(string);
#endif

#if (PRINT_CHARACTERS == TRUE)
	PrintCharacters(string);
#endif

#if (CONST_POINTER_USAGE == TRUE)
	PointerConstExample();
	PointerConstExample2();
#endif

#if (STRING_COPY_EXAMPLE == TRUE)
	Copy1(string1,string2);
	Copy2(string3,string4);
#endif

#if (KART_DAGITMA_PROG == TRUE)
	const char *takim[4] = {"Kupa","Karo","Sinek","Maca"};
	const char *taraf[13] = {"As","Iki","Uc","Dort","Bes","Alti","Yedi","Sekiz","Dokuz","On","Vale","Kiz","Papaz"};

	int deste[4][13] = {0};

	srand(time(NULL));

	kar(deste);
	dagit(deste,taraf,takim);

#endif

	while(1){ }

}

#if (CAPITAL_TRANSFORM == TRUE)
void TransformToCapitalLetter(char *f_Str)
{
	while(*f_Str != '\0'){
		if(islower(*f_Str))
			*f_Str = toupper(*f_Str);

		++f_Str;
	}
}
#endif

#if (PRINT_CHARACTERS == TRUE)
void PrintCharacters(const char *f_Ptr){

	for(;*f_Ptr != '\0';f_Ptr++){
		//Printf the characters on console
	}
}
#endif

#if (CONST_POINTER_USAGE == TRUE)
void PointerConstExample(void){

	int x=0,y=0;

	int * const ptr = &x; //ptr, constant pointer points to integer
						  //its value can be changed with ptr but ptr always points same memory location.

	*ptr = 7; 			  //value can be changed
	// ptr = &y;			  //Error: memory location can not be changed.
}


void PointerConstExample2(void){

	int x=5,y=0;

	const int * const ptr = &x; //ptr, constant pointer points to CONST integer
						  	    //its value  and memory location can not be changed with ptr

	//*ptr = 7; 			  //value can not be changed
	// ptr = &y;			  //Error: memory location can not be changed.
}
#endif

#if (STRING_COPY_EXAMPLE == TRUE)

/*This Function copies context of s2 char array to the s1
 * by using array index notation
 * In for loop, condition copies s2 content to s1 until it
 * reaches '\0' character
 */
void Copy1(char *s1,const char *s2){
	int i=0;
	for(i=0;(s1[i] = s2[i])!= '\0';i++){ }
}

/*This Function copies context of s2 char array to the s1
 * by using array POINTER notation
 * In for loop, condition copies s2 content to s1 until it
 * reaches '\0' character
 */
void Copy2(char *s1,const char *s2){
	for(;(*s1 = *s2) != '\0';s1++,s2++){ }
}
#endif


#if (KART_DAGITMA_PROG == TRUE)
void kar(int _deste[][13]){

	int satir=0,sutun=0,kart=0;

	for(kart = 1; kart <= 52; kart++){
		do{
			satir = rand() % 4;
			sutun = rand() % 13;
		}while(_deste[satir][sutun] != 0);

		_deste[satir][sutun] = kart;
	}

}

void dagit(const int _deste[][13],const char *_taraf[],const char *_takim[]){

	int satir=0,sutun=0,kart=0;
	char *taraf = 0, *takim = 0;

	for(kart = 1; kart <= 52; kart++){

		for(satir = 0; satir <= 3; satir++){

			for(sutun = 0; sutun <= 12; sutun++){

				if(_deste[satir][sutun] == kart){

					takim = _takim[satir];
					taraf = _taraf[sutun];
				}

			}

		}

	}
}
#endif
