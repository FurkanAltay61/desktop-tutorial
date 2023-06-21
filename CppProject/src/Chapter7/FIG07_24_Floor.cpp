/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include <FIG07_24_Floor.h>

#if (FIG07_24)

#include <iostream>

using namespace std;

#include "FIG07_24_Person.h"
#include "FIG07_24_Elevator.h"
#include "FIG07_24_Door.h"

const int Floor::FLOOR1 = 1;
const int Floor::FLOOR2 = 2;


Floor::Floor(int number,Elevator &elevatorHandle) :
		floorButton(number,elevatorHandle),
		floorNumber(number),
		elevatorRef(elevatorHandle),
		occupantPtr(0),
		light(floorNumber)
{
	cout << "Floor" << floorNumber << " constructed" << endl;
}

Floor::~Floor(){
	delete occupantPtr;
	cout << "Floor" << floorNumber << " destructed" << endl;
}


bool Floor::isOccupied() const {
	return (occupantPtr != 0);
}

int Floor::getNumber() const {
	return floorNumber;
}

void Floor::personArrives(Person * const personPtr){
	occupantPtr = personPtr;
}

Person *Floor::elevatorArrived(){
	cout << "Floor " << floorNumber <<
			"resets its button" << endl;

	floorButton.resetButton();

	light.turnOn();
	return occupantPtr;
}

void Floor::elevatorLeaving(){
	light.turnOff();
}

void Floor::personBoardingElevator(){
	occupantPtr = 0;
}

#endif
