/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */


#include <stdio.h>


#define LENGTH	20

void Sort(uint8_t [],uint8_t, uint8_t *);
void Replace(uint8_t *,uint8_t *);

int main(){

	uint8_t Arr[LENGTH] = {87,23,65,9,34,65,76,12,43,54,65,87,34,23,76,12,23,65,98,56};
	uint8_t total_iteration = 0;
	Sort(Arr,LENGTH,&total_iteration);
	while(1);
}



void Sort(uint8_t _Arr[],uint8_t _Len,uint8_t *_tot_iter){

	uint8_t swap = 0;

//	for(uint8_t i=0;i<=_Len-1;i++){
//		for(uint8_t j=0;j<=_Len-2;j++){
//			if(_Arr[j] > _Arr[j+1]){
//				Replace(&_Arr[j],&_Arr[j+1]);
//			}
//		}
//		(*_tot_iter)++;
//	}

	for(int8_t i=1;i<_Len;i++){
		swap = 0;
		for(int8_t j=0;j<_Len-i;j++){
			if(_Arr[j] > _Arr[j+1]){
				swap = 1;
				Replace(&_Arr[j],&_Arr[j+1]);
			}
		}
		(*_tot_iter)++;

		if(!swap)
			break;
	}


}

void Replace(uint8_t *_val1,uint8_t *_val2){
	uint8_t temp;
	temp = *_val1;
	*_val1 = *_val2;
	*_val2 = temp;
}




