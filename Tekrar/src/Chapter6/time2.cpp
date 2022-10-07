/*
 * time1.cpp
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */



#include "time2.h"

#if (FIG06_12)

#include <iomanip>

using namespace std;

Time::Time(int h, int m , int s){
	setTime(h,m,s);
}

void Time::setTime(int h, int m ,int s){

	hour   = ( h > 0 && h < 24) ? h : 0;

	minute = ( m > 0 && m < 60) ? m : 0;

	second = ( s > 0 && s < 60) ? s : 0;
}

void Time::printStandard(void){
	 cout << " Standard time is : " << hour 	<< ":" << setw(2)
			 	 	 	 	 	 	<< minute	<< ":" << setw(2)
									<< second	<< endl;
}


void Time::printUniversal(void){
	 cout << " Universal time is : " << (( hour == 0 || hour == 12) ? 12 : hour%12) << ":" << setw(2)
			 	 	 	 	 	 	<< minute	<< ":" << setw(2)
									<< second	<< " " << setw(2)
									<< ((hour < 12) ? "AM" : "PM") << endl;
}


#endif
