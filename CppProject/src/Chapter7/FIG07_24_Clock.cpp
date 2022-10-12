/*
 * FIG07_24_1.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */


#include <FIG07_24_Clock.h>

#if (FIG07_24)

#include <iostream>

using namespace std;


Clock::Clock():time(0){
	cout << "clock is constructed" << endl;
}


Clock::~Clock(){
	cout << "clock is destructed" << endl;
}

void Clock::tick(){
	time++;
}

int Clock::getTime() const {
	return time;
}

#endif
