/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include <FIG07_24_Bell.h>

#if (FIG07_24)

#include <iostream>

using namespace std;


Bell::Bell(){
	cout << "Bell constructed " << endl;
}

Bell::~Bell(){
	cout << "Bell destructed " << endl;
}

void Bell::ringBell() const {
	cout << "Elevator rings its bell" << endl;
}



#endif
