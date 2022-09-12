/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */





#include <stdio.h>
#include "assert.h"
#define BOYUT 10

int buNedir(int [ ], int);

int main( ){
	int toplam, a[BOYUT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	toplam = buNedir(a, BOYUT);
	while(1);
	return 0;
}

int buNedir(int b[], int boyut){
	if(boyut == 1)
	   return b[0];
	else
	   return b[boyut - 1] + buNedir(b,boyut - 1);
}





