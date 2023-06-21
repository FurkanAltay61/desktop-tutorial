/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */


#include <stdio.h>


#define  STUDENTS	4
#define  NOTES		3

uint8_t FindMinNote(uint8_t [][NOTES]);
uint8_t FindMaxNote(uint8_t [][NOTES]);
double Average(uint8_t [][NOTES]);

int main(){

	uint8_t min_note = 0,max_note = 0;
	double average_note = 0;
	uint8_t Arr[STUDENTS][NOTES] = {{40,50,60},{65,23,56},{45,9,12},{45,76,34}};

	min_note = FindMinNote(Arr);
	max_note = FindMaxNote(Arr);
	average_note = Average(Arr);

	while(1);
}



uint8_t FindMinNote(uint8_t _Arr[][NOTES]){

	uint8_t temp_note = 100;

	for(uint8_t i=0;i<STUDENTS;i++){
		for(uint8_t j=0;j<NOTES;j++){
			if(_Arr[i][j] < temp_note){
				temp_note = _Arr[i][j];
			}
		}
	}

	return temp_note;
}

uint8_t FindMaxNote(uint8_t _Arr[][NOTES]){

	uint8_t temp_note = 0;

	for(uint8_t i=0;i<STUDENTS;i++){
		for(uint8_t j=0;j<NOTES;j++){
			if(_Arr[i][j] > temp_note){
				temp_note = _Arr[i][j];
			}
		}
	}

	return temp_note;
}

double Average(uint8_t _Arr[][NOTES]){

	double temp_note = 0;

		for(uint8_t i=0;i<STUDENTS;i++){
			for(uint8_t j=0;j<NOTES;j++){
				temp_note += _Arr[i][j];
			}
		}

	return (double)(temp_note/(STUDENTS * NOTES));

}



