/*
 * QUE06_09.cpp
 *
 *  Created on: 5 Eki 2022
 *      Author: ALTAYSAN
 */


#include "QUE06_09.h"


#if ( QUE06_09 )

Date::Date(int d, int m , int y){
	setDate(d,m,y);
}

void Date::setDate(int d , int m , int y){
	day = d;
	month = m;
	year = y;
}

void Date::setDay(int d){
	day = (d > 0 && d <= 31) ? d : 1;
}

void Date::setMonth(int m){
	month = (m > 0 && m <= 12) ? m : 1;
}

void Date::setYear(int y){
	year = y;
}

int Date::getDay(){
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}

void Date::printDate(){

	cout << ((day < 10) ? "0" : "") << day << ":"
		 << ((month < 10) ? "0" : "") << month << ":"
		 << year << endl;
}

void Date::nextDay(){

	setDay(getDay() + 1);

	if(getDay() == 0){
		setMonth(getMonth() + 1);

		if(getMonth() == 0){
			setYear(getYear() + 1);
		}

	}

}

#endif
