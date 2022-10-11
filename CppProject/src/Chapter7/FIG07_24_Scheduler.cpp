/*
 * FIG07_24_2.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */



#include <FIG07_24_Scheduler.h>

#if (FIG07_24)

#include <FIG07_24_Floor.h>
#include "FIG07_24_Person.h"

#include <iostream>
#include <new>
#include <cstdlib>
#include <ctime>

using namespace std;

Scheduler::Scheduler(Floor &firstFloor,Floor &secondFloor)
		  :currentClockTime(0),
		   floor1Ref(firstFloor),
		   floor2Ref(secondFloor)
{
	srand(time(0));
	cout << "scheduler constructed" << endl;

	scheduleTime(floor1Ref);
	scheduleTime(floor2Ref);
}

Scheduler::~Scheduler(){
	cout << "Scheduler destructed" << endl;
}



void Scheduler::scheduleTime(const Floor &floor){
	int floorNumber = floor.getNumber();
	int arrivalTime = currentClockTime + ( 5 + rand()%16);

	floorNumber = Floor::FLOOR1 ?
			floor1ArrivalTime = arrivalTime :
			floor2ArrivalTime = arrivalTime;

	cout << "(scheduler schedules next person for floor "
		 << floorNumber << " at time " << arrivalTime << ')' << endl;
}

void Scheduler::processTime(int time)
{
	currentClockTime = time;

	handleArrivals(floor1Ref,currentClockTime);

	handleArrivals(floor2Ref,currentClockTime);
}

void Scheduler::createNewPerson(Floor &floor){
	int destinationFloor = floor.getNumber() == Floor::FLOOR1 ?
												Floor::FLOOR2 : Floor::FLOOR1;

	Person *newPersonPtr = new Person(destinationFloor);

	cout << "Scheduler creates person " << newPersonPtr->getID() << endl;

	newPersonPtr->stepOntoFloor(floor);

	scheduleTime(floor);
}

void Scheduler::handleArrivals (Floor &floor, int time){

	int floorNumber = floor.getNumber();

	int arrivalTime = (floorNumber == Floor::FLOOR1) ? floor1ArrivalTime : floor2ArrivalTime;

	if(arrivalTime == time){

		if(floor.isOccupied() )
			delayTime(floor);
		else
			createNewPerson(floor);
	}
}



#endif
