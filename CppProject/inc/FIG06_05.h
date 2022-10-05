/*
 * time1.h
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef FIG06_05_H_
#define FIG06_05_H_

#include "Answers.h"

#if	(FIG06_05 == true)

class Time {

public:
	Time();						//Constructor
	void SetTime(int,int,int);	//set hour,minute,second
	void printUniversal();		//print time uinversal time
	void printStandard();		//print	standard-time format

private:
	int hour;					//0 - 23 (25 hour clock format)
	int minute;					//0 - 59
	int second;					//0 - 59

};

#endif

#endif /* FIG06_05_H_ */
