/*
 * time1.cpp
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */





#include <FIG06_19.h>

#if (FIG06_19)

#include <iostream>
using namespace std;
#include <iomanip>

Time::Time(int hr,int min, int sec){
	SetTime( hr , min , sec );
}

void Time::SetTime(int h, int m , int s){

	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int h){

	hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m){

	minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s){

	second = (s >= 0 && s < 60) ? s : 0;
}


int Time::getHour(){
	return hour;
}

int Time::getMinute(){
	return minute;
}


int Time::getSecond(){
	return second;
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


