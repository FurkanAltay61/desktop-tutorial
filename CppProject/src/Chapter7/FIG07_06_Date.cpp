/*
 * FIG07_06.cpp
 *
 *  Created on: 6 Eki 2022
 *      Author: furkan.altay
 */


#include <FIG07_06_Date.h>

#if ( FIG07_06 )

#include <iostream>

using namespace std;

Date::Date(int mn, int dy, int yr){
	if ( mn > 0 && mn <= 12)		//validate month
		month = mn;
	else{
		month = 1;					//invalid month set to 1
		cout << "Month" << mn << "invalid. Set to month 1.\n";
	}

	year = yr;						//should validate yr
	day = checkDay(dy);				//validate th day

	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

Date::~Date(){
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

void Date::print() const {
	cout << month << '/' << day << '/' << year;
}

int Date::checkDay( int testDay) const
{
	static const int daysPerMonth[ 13 ] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};

	if( testDay > 0 && testDay <= daysPerMonth[month] )
		return testDay;

	// February 29 check for leap year
	if( month == 2 && testDay == 29 && (year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0)))
		return testDay;

	cout << "Day" << testDay << "invalid. Set to day 1. \n";

	return 1;
}



#endif

