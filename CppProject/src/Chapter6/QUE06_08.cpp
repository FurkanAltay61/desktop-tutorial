/*
 * QUE06_08.cpp
 *
 *  Created on: 5 Eki 2022
 *      Author: furkan.altay
 */



#include "QUE06_08.h"


#if ( QUE06_08 )

#include "iostream"

using namespace std;

Time::Time(int d,int h, int m, int s){

	setTime(d,h,m,s);
}

void Time::setTime(int d ,int h, int m, int s){

	day    = (d < 31) ? d : 1;
 	hour   = (h < 24) ? h : 0;
	minute = (m < 60) ? m : 0;
	second = (s < 60) ? s : 0;
}

void Time::setDay(int d){
	if(day == d) return;
	day =   (d <= 31) ? d : 0;
}

void Time::setHour(int h){
	if(hour == h) return;
	hour =   ( h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m){
	if(minute == m) return;
	minute = (m>= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s){
	if(second == s) return;
	second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getDay(){
	return day;
}

int Time::getHour(){
	return hour;
}

int Time::getMinute(){
	return minute;
}

int Time::getSecond	(){
	return second;
}

void Time::tickEvent(void){

	setSecond(getSecond()+ 1);

	if(getSecond() == 0){
		setMinute(getMinute() + 1);

		if(getMinute() == 0){
			setHour(getHour() + 1);

			if(getHour() == 0)
				setDay(getDay()+ 1);

		}

	}

}


void Time::printTime(void){

	cout << "The date is " 	<< ((day < 10) ? "0" : "")  << day << ":"
							<< ((hour % 12 == 0) ? 12 : hour % 12) << ":"
							<< (minute < 10 ? "0" : "") << minute << ":"
							<< (second < 10 ? "0" : "") << second << " " <<
							   (hour < 12 ? "AM" : "PM")<< endl;
}


#endif
