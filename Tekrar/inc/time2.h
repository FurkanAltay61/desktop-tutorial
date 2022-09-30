/*
 * time1.h
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef TIME1_H_
#define TIME1_H_

#include "Answers.h"

#if (FIG06_12)

class Time {

public:
	Time(int = 0, int = 0, int = 0);
	void setTime(int,int,int);
	void printStandard(void);
	void printUniversal(void);

private:
	int hour;
	int minute;
	int second;

};

#endif

#endif /* TIME1_H_ */
