/*
 * time1.h
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef TIME1_H_
#define TIME1_H_

#include "Answers.h"

#if	( FIG06_19 )

class Time {

public:
	Time(int = 0 , int = 0, int = 0);	//Constructor
	void SetTime(int,int,int);			//set hour,minute,second

	/*---------------------------------*/
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	int getHour(void);
	int getMinute(void);
	int getSecond(void);

	/*---------------------------------*/
	void printUniversal();				//print time uinversal time
	void printStandard();				//print	standard-time format

private:
	int hour;					//0 - 23 (25 hour clock format)
	int minute;					//0 - 59
	int second;					//0 - 59

};

#endif

#endif /* TIME1_H_ */
