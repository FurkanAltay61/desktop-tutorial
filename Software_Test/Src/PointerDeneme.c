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
#define FUNCTION_POINTER    FALSE
#define FUNCTION_ARRAY		FALSE



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

#if (FUNCTION_POINTER == TRUE)
#define LENGTH 10
/*kabarcikSiralama fonksiyonu,
bir tamsayı dizisi ve bu dizinin büyüklüğü yanında fonksiyon gösteren (artan ya da azalan
fonksiyonlarından birini) bir göstericiyi argüman olarak almaktadır. Program, kullanıcının
sıralamanın artan mı yoksa azalan bir şekilde mi yapılacağını seçmesini isteyen, bir ileti
yazdırmaktadır.*/
void bubble(int [],const int, int(*)(int,int));

int increase(int,int);
int decrease(int,int);
#endif

#if (FUNCTION_ARRAY == TRUE)
void func1(int);
void func2(int);
void func3(int);
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

#if (FUNCTION_POINTER == TRUE)
	int choice=0,a[LENGTH] = {2,6,4,8,10,12,89,68,45,37};

	if(choice == 1){
		bubble(a,LENGTH,increase);
	}
	else{
		bubble(a,LENGTH,decrease);
	}
#endif


#if (FUNCTION_ARRAY == TRUE)
	void (*f[3])(int) = {func1,func2,func3};
	uint8_t choice = 0;
	(*f[choice])(choice);
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
	static char *taraf = 0, *takim = 0;

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

#if (FUNCTION_POINTER == TRUE)

/*NOTE : int(*compare)(int,int)
Bu, kabarcik fonksiyonuna iki tamsayı parametresi alan ve bir tamsayı sonucu döndüren bir
fonksiyonu gösteren bir gösterici alacağını söyler. *karsilastir etrafındaki parantezler
gereklidir, çünkü * fonksiyon parametrelerini içine alan parantezlere göre daha düşük
önceliğe sahiptir. Eğer parantezleri dahil etmeseydik, bildirim "int *compare(int,int)"
biçiminde olacaktı ve iki tamsayı parametresi alan ve bir tamsayıyı gösteren bir gösterici
döndüren bir fonksiyon bildirilmiş olacaktı. */

void bubble(int is[],const int length, int(*compare)(int,int)){
	int round=0,counter=0;
	void Swap(int *,int *);

	for(round = 1; round < length;round++){
		for(counter = 0; counter < length - 1 ; counter++){
			if((*compare)(is[counter],is[counter+1])){
				Swap(&is[counter],&is[counter+1]);
			}
		}
	}

}

void Swap(int *val1,int *val2){
	int temp_val=0;

	temp_val = *val1;
	*val1 = *val2;
	*val2 = temp_val;
}

int increase(int a,int b){
	return b < a;
}

int decrease(int a,int b){
	return b > a;
}

#endif


#if (FUNCTION_ARRAY == TRUE)
void func1(int a){

}
void func2(int a){

}
void func3(int a){

}
#endif
