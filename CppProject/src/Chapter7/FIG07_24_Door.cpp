/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include "FIG07_24_Door.h"

#if (FIG07_24)

#include "FIG07_24_Person.h"
#include "FIG07_24_Floor.h"
#include "FIG07_24_Elevator.h"

#include <iostream>

using namespace std;

Door::Door():open(false){
	cout << "door constructed" << endl;
}


Door::~Door(){
	cout << "door destructed" << endl;
}

void Door::openDoor(Person * const passengerPtr,Person * const nextPassengerPtr,
				    Floor &currentFloor,Elevator &elevator)
{
	if(!open){
		open = true;

		cout << "elevator opens its door on floor"
			 << currentFloor.getNumber() << endl;

		if(passengerPtr != 0){
			passengerPtr->exitElevator(currentFloor,elevator);
			delete passengerPtr;
		}

		if(nextPassengerPtr != 0)
			passengerPtr->enterElevator(elevator,currentFloor);
	}
}


void Door::closeDoor(const Floor &currentFloor){
	if(open){
		open = false;
		cout << "elevator closes its door on floor" << currentFloor.getNumber() << endl;
	}
}

#endif
