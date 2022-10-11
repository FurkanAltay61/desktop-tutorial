/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include "FIG07_24_Light.h"

#if (FIG07_24)

#include <iostream>

using namespace std;

Light::Light(int number):on(false),floorNumber(number){
	cout << "floor" << floorNumber << "Light constructed " << endl;
}

Light::~Light(){
	cout << "floor" << floorNumber << "Light destructed " << endl;
}

void Light::turnOn(){
	if(!on){
		on=true;
		cout << "floor" << floorNumber << "light turns on " << endl;
	}
}

void Light::turnOff(){
	if(!on){
		on = false;
		cout << "floor" << floorNumber << "light turns off " << endl;
	}
}


#endif
