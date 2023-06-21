/*
 * FIG07_06.h
 *
 *  Created on: 6 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_06_DATE_H_
#define CHAPTER7_FIG07_06_DATE_H_

#include "Answers.h"

#if ( FIG07_06 )

class Date{
public:
	Date(int = 1,int = 1 , int = 1900);
	void print() const;
	~Date();
private:
	int month;
	int day;
	int year;
	int checkDay(int) const;
};

#endif


#endif /* CHAPTER7_FIG07_06_DATE_H_ */
