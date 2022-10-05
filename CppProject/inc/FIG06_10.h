/*
 * Salesp.h
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef FIG06_10_H_
#define FIG06_10_H_

#include "Answers.h"

#if(FIG06_10 == true)

class SalesPerson {

public:
	SalesPerson();				//constructor of class
	void getSalesFromUser();	//input sales from keyboard
	void setSales(int,double);	//set sales for a month
	void printAnnualSales();	//summarize and print sales

private:
	/****************************************************/
	/**/double totalAnnualSales();	//Utility Function/**/
	/****************************************************/

	double sales[ 12 ];			//12 monthly sales figures

};

#endif

#endif /* FIG06_10_H_ */
