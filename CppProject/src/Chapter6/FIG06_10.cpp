/*
 * Salesp.cpp
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */


#include <FIG06_10.h>
#include "Answers.h"

#if(FIG06_10 == true)

#include "iostream"
#include "iomanip"

using namespace std;


SalesPerson::SalesPerson(){
	for(int i=0; i < 12 ; i++)
		sales[i] = 0.0;
}

void SalesPerson::getSalesFromUser(void){
	double SalesFigure;

	for(int i= 1 ; i <= 12; i++){
		cout << "Enter the sales amount for month " << i << " : ";
		cin >> SalesFigure;
		setSales(i,SalesFigure);
	}
}

void SalesPerson::setSales(int month , double amount){
	if(month >= 1 && month <= 12 && amount > 0)
		sales[month - 1] = amount;
	else
		cout << "Invalid month or sales figure" << endl;
}

void SalesPerson::printAnnualSales(){
	cout << setprecision(2) << fixed <<" \n The total annual sales are : $ " <<
		 totalAnnualSales()	<< endl;
}

double SalesPerson::totalAnnualSales(){
	double total = 0.0;
	for (int i= 0; i < 12 ; i++){
		total += sales[i];
	}

	return total;
}

#endif
