/*
 * time1.cpp
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */





#include "time2.h"




#if (FIG06_12 == true)

#include <iostream>
using namespace std;
#include <iomanip>

Time::Time(int hr,int min, int sec){
	SetTime(hr,min,sec);
}

void Time::SetTime(int h, int m , int s){

	hour   = (h > 0  && h < 24) ? h : 0;
	minute = (m > 0  && m < 60) ? m : 0;
	second = (s > 0  && s < 60) ? s : 0;
}


void Time::printUniversal(){
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard(){
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) <<
			":" << setfill('0') << setw(2) << minute << ":" << setw(2) << second
				<< (hour < 12 ? "AM" : "PM");
}


#endif





