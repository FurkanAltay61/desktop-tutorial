/*
 * FIG07_06_Date.cpp
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */


#include "FIG07_06_Date.h"

#if ( FIG07_06 )

Date::Date(int dy,int mn,int yr){

	cout << "Date object constructor :" ;
	if(validityCheck(dy,mn,yr))
		print();
}

void Date::print(void) const{
	cout << day << "/" << month << "/" << year << endl;
}

Date::~Date(void){
	cout << "Date object destrcutor :" << day << "/" << month << "/" << year << endl;
}

bool Date::validityCheck(int dy,int mn,int yr){

	int daysofMonths[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31, 30 , 31 };

	bool result = false;

	if(yr > 1900){

		if(mn >0 && mn <= 12){

			if(dy > 0 && dy < daysofMonths[mn - 1]){

				year = yr;
				month = mn;
				day = dy;

				result = true;
			}
			else{
				cout << "Invalid day is entered " << endl;
			}
		}
		else{
			cout << "Invalid month is entered " << endl;
		}
	}
	else{
		cout << "Invalid year is entered " << endl;
	}

	return result;
}

#endif
