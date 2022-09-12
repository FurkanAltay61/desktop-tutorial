/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */





#include <stdio.h>
#include <time.h>
#include "assert.h"
#include "stdlib.h"

void You_Won(void);
void You_Lost(void);
int random_number_gen(int min_range, int max_range);

int main(){

	uint8_t dice1=0,dice2=0,total_dice=0,players_number = 0;

	srand(time(NULL));

	while(1){

		dice1 = random_number_gen(1,6);
		dice2 = random_number_gen(1,6);

		total_dice = dice1 + dice2;

		if(players_number != 0){
			if(players_number == 7){
				You_Lost();
			}
		}

		if(total_dice == 7 || total_dice == 11){
			You_Won();
		}
		else if(total_dice == 2 || total_dice == 3 || total_dice == 12){
			You_Lost();
		}
		else{
			players_number = total_dice;
		}



	}

}

void You_Won(void){
	while(1);
}

void You_Lost(void){
	while(1);
}

int random_number_gen(int min_range, int max_range){
	assert(min_range < max_range);
    static int rand_number = 199198; // any random number
    rand_number = ((rand_number * rand_number) / 10 ) % 9890;
    return rand_number % (max_range+1-min_range) + min_range ;
}

