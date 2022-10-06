/*
 * QUE06_08.h
 *
 *  Created on: 5 Eki 2022
 *      Author: furkan.altay
 */

#ifndef QUE06_08_H_
#define QUE06_08_H_

#include "Answers.h"

#if ( QUE06_08 )

class Time {
public:
	Time(int,int,int,int);
	void setTime(int,int,int,int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void setDay(int);

	int getHour();
	int getMinute();
	int getSecond();
	int getDay();

	void tickEvent();

	void printTime();

private:
	int hour;
	int minute;
	int second;
	int day;
};

#endif

#endif /* QUE06_08_H_ */
