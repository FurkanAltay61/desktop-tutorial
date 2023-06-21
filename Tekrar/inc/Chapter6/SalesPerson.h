/*
 * SalesPerson.h
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef SALESPERSON_H_
#define SALESPERSON_H_

#include "Answers.h"

#if (FIG06_10)

class SalesPerson {

public:
	SalesPerson();					//constructor
	void setSales(int,double);		//input sales from thekeyboard
	void getSales();				//set sales for a month
	void printSales();				//summarize and print sales

private:
	double totalAnnualSales();		//utility function
	double Sales[12];				//12 monthly sales figures
};

#endif


#endif /* SALESPERSON_H_ */
