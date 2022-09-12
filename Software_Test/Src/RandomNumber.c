/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */





#include <stdio.h>
#include "assert.h"


int random_number_gen(int min_range, int max_range);

int main(){


	while(1){
		int a = random_number_gen(-10,-20);
	}

}

int random_number_gen(int min_range, int max_range){
	assert(min_range < max_range);
    static int rand_number = 199198; // any random number
    rand_number = ((rand_number * rand_number) / 10 ) % 9890;
    return rand_number % (max_range+1-min_range) + min_range ;
}


