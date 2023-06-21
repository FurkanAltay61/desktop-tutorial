/*
 * FIG07_06_Date.h
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_06_DATE_H_
#define CHAPTER7_FIG07_06_DATE_H_


#include "Answers.h"

#if ( FIG07_06 )

#include <iostream>

using namespace std;

class Date {

public:
	Date(int,int,int);
	void print() const;
	~Date();

private:
	int day;
	int month;
	int year;
	bool validityCheck(int,int,int);
};

#endif

#endif /* CHAPTER7_FIG07_06_DATE_H_ */
