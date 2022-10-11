/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include <FIG07_24_Person.h>

#if (FIG07_24)

#include "FIG07_24_Floor.h"
#include "FIG07_24_Elevator.h"

#include <iostream>

using namespace std;

int Person::personCount = 0;

Person::Person(int destFloor):ID(++personCount),destinationFloor(destFloor){
	cout << "person" << ID << "constructed" << endl;
}

Person::~Person(){
	cout << "person" << ID << "destructed" << endl;
}

int Person::getID() const {
	return ID;
}

void Person::stepOntoFloor(Floor &floor){
	cout << "person" << ID << "steps onto floor" << floor.getNumber() << endl;

	floor.personArrives(this);

	cout << "person" << ID << "presses onto floor button"
		 << floor.getNumber() << endl;

	floor.floorButton.pressButton();
}



#endif
