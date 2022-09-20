/*
 * Structure_Examples.c
 *
 *  Created on: 20 Eyl 2022
 *      Author: furkan.altay
 */


#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define TRUE  1
#define FALSE 0


#define FIG10_3			TRUE


#if(FIG10_3	== TRUE)

struct kart {
	const char *taraf;
	const char *takim;
};

typedef struct kart Kart;

void desteyiDoldur(Kart * const,const char *[],const char *[]);
void desteyiKar(Kart * const);
void dagit(const Kart * const);

#endif

int main(){

#if(FIG10_3	== TRUE)


#endif

	return 0;
}


#if(FIG10_3	== TRUE)

void desteyiDoldur(Kart * const,const char *[],const char *[]){

}
void desteyiKar(Kart * const);
void dagit(const Kart * const);


#endif
