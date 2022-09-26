/*
 * cppmain.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: furkan.altay
 */




#include "main.h"
#include "iostream"

using namespace std;

void CppMain(){

	int number1{0};


	while(1){


		cout << "Enter the first integer : ";
		cin >> number1;

		while(number1 == 0){
			cout << "Enter the first integer : ";
			cin >> number1;
		}
		cout << "\r\n Number1 is : " << number1 << "\r\n";


//		printf("Merhaba\r\n");
		HAL_Delay(1000);
		__NOP();
	}
}
