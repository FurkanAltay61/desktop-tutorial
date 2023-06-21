/*
 * FIG07_14.h
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_14_H_
#define CHAPTER7_FIG07_14_H_

#include "Answers.h"

#if (FIG07_14)

class Time {

public:
	Time(int = 0 , int = 0, int = 0);	//Constructor


	/*---------------------------------*/
	Time &setTime(int,int,int);			//set hour,minute,second
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);
	/*---------------------------------*/

	int getHour(void);
	int getMinute(void);
	int getSecond(void);

	void printUniversal();				//print time uinversal time
	void printStandard();				//print	standard-time format

private:
	int hour;					//0 - 23 (25 hour clock format)
	int minute;					//0 - 59
	int second;					//0 - 59

};

#endif

#endif /* CHAPTER7_FIG07_14_H_ */
