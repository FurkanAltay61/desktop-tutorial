/*
 * QUE06_09.h
 *
 *  Created on: 5 Eki 2022
 *      Author: ALTAYSAN
 */

#ifndef QUE06_09_H_
#define QUE06_09_H_


#include "Answers.h"

#if ( QUE06_09 )

#include <iostream>

using namespace std;

class Date {
public:
	Date(int,int,int);
	void setDate(int,int,int);

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay();
	int getMonth();
	int getYear();

	void nextDay();

	void printDate();

private:
	int day;
	int month;
	int year;
};

#endif


#endif /* QUE06_09_H_ */
