/*
 * SalesPerson.cpp
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */



#include "SalesPerson.h"

#if (FIG06_10)

using namespace std;

SalesPerson::SalesPerson(){

	for(uint8_t i=0; i < 12 ; i++)
		Sales[i] = 0;
}

void SalesPerson::getSales(void){

	for(uint8_t i=0; i < 12 ; i++){
		cout << "Enter the month " << i+1 << " sales :" ;
		cin >> Sales[i];
	}
}

double SalesPerson::totalAnnualSales(void){

	double totalSale = 0;

	for(uint8_t i=0; i < 12 ; i++){
		totalSale += Sales[i];
	}

	return totalSale;
}


void SalesPerson::printSales(void){

	cout << "Total annual sale is : " << totalAnnualSales() << endl;
}

#endif
