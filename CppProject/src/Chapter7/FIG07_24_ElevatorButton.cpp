/*
 * FIG07_24_4.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */


#include "FIG07_24_ElevatorButton.h"

#if (FIG07_24)

#include <iostream>

using namespace std;

ElevatorButton::ElevatorButton(Elevator &elevatorHandle) :
		pressed(false), elevatorRef(elevatorHandle)
{
	cout << "Elevator Button constructed " << endl;
}

ElevatorButton::~ElevatorButton()
{
	cout << "Elevator Button destructed " << endl;
}

void ElevatorButton::pressButton(){
	pressed = true;
	cout << "elevator button tells elevator to prepare to leave" << endl;
	elevatorRef.prepareToLeave(true);
}

void ElevatorButton::resetButton(){
	pressed = false;
}
#endif
