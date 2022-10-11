/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include "FIG07_24_Elevator.h"

#if (FIG07_24)

#include <FIG07_24_Floor.h>
#include "FIG07_24_Person.h"


#include <iostream>

using namespace std;

const int Elevator::ELEVATOR_TRAVEL_TIME = 5;
const int Elevator::UP = 0;
const int Elevator::DOWN = 1;


Elevator::Elevator(Floor &firstFloor,Floor &secondFloor)
		 :elevatorButton(*this),
		  currentBuildingClockTime(0),
		  moving(false),
		  direction(UP),
		  currentFloor(Floor::FLOOR1),
		  arrivalTime(0),
		  floor1NeedsService(false),
		  floor2NeedsService(false),
		  floor1Ref(firstFloor),
		  floor2Ref(secondFloor),
		  passengerPtr(0)
{
	cout << "Elevator constructed" << endl;
}


Elevator::~Elevator(){
	delete passengerPtr;
	cout << "Elevator destructed" << endl;
}


Elevator::processTime(int time){
	currentBuildingClockTime = time;

	if(moving)
		processPossibleArrival();
	else
		processPossibleDeparture();

	if(!moving)
		cout << "Elevator at rest on floor" << currentFloor << endl;
}

void Elevator::processPossibleArrival(){

	if(currentBuildingClockTime == arrivalTime){

		currentFloor = (currentFloor == Floor::FLOOR1 ?
										Floor::FLOOR2 : Floor::FLOOR1);

		direction = (currentFloor == Floor::FLOOR1 ? UP : DOWN);

		cout << "elevator arrives on floor" << currentFloor << endl;

		arriveAtFloor(currentFloor == Floor::FLOOR1 ?
									  floor1Ref : floor2Ref);

		return;
	}

	cout << "elevator moving" << (direction == UP ? "up" : "down") << endl;
}

void Elevator::processPossibleDeparture()
{
	bool currentFloorNeedsService =
			currentFloor == Floor::FLOOR1 ?
					floor1NeedsService : floor2NeedsService;

	bool otherFloorNeedsService =
				currentFloor == Floor::FLOOR1 ?
						floor1NeedsService : floor2NeedsService;

	if( currentFloorNeedsService ){
		arriveAtFloor(currentFloor == Floor::FLOOR1 ? floor1Ref : floor2Ref);
		return;
	}

	if(otherFloorNeedsService)
		prepareToLeave(true);

}

void Elevator::arriveAtFloor(Floor &arrivalFloor){

	moving = false;

	cout << "Elevator resets its button" << endl;

	elevatorButton.resetButton();

	bell.ringBell();

	Person *floorPersonPtr = arrivalFloor.elevatorArrived();

	door.openDoor(passengerPtr, floorPersonPtr, arrivalFloor, *this);
}

#endif
