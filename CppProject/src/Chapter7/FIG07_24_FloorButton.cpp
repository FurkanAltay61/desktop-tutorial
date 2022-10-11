/*
 * FIG07_24_4.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */


#include "FIG07_24_FloorButton.h"

#if (FIG07_24)

#include "FIG07_24_Elevator.h"

#include <iostream>

using namespace std;

FloorButton::FloorButton(int floor, Elevator &elevatorHandle) :
		elevatorRef(floor),
		pressed(false),
		elevatorRef(elevatorHandle)
{
	cout << "floor" << floorNumber << "button constructed" << endl;
}

FloorButton::~FloorButton()
{
	cout << "floor" << floorNumber << "button destructed" << endl;
}

void FloorButton::pressButton(){
	pressed = true;

	cout << "floor" << floorNumber << "button summons elevator" << endl;

	elevatorRef.summonElevator(floorNumber);
}

void FloorButton::resetButton(){
	pressed = false;
}
#endif
