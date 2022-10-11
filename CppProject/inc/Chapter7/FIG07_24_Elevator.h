/*
 * FIG07_24_Elevator.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_ELEVATOR_H_
#define CHAPTER7_FIG07_24_ELEVATOR_H_


#include "Answers.h"

#if (FIG07_24)

class Floor;
class Person;

class Elevator {

public:
	Elevator(Floor &, Floor &);
	~Elevator();

	void summonElevator(int);	//request to service floor
	void prepareToLeave(bool);
	void processTime(int);		//give current time to elevator
	void passengerEnters(Person * const); //board a passenger
	void passengerExits();

	ElevatorButton	elevatorButton;

private:
	void processPossibleArrival();
	void processPossibleDeparture();
	void arriveAtFloor(Floor &);
	void move();

	static const int ELEVATOR_TRAVEL_TIME;
	static const int UP;
	static const int DOWN;

	int currentBuildingClockTime; //current time
	bool moving;					  //elevator state
	int direction;				  //current direction
	int currentFloor;			  //current location
	int arrivalTime;			  //time to arrive at floor
	bool floor1NeedsService;	  //floor1 service flag
	bool floor2NeedsService;	  //floor2 service flag

	Floor &floor1Ref;
	Floor &floor2Ref;

	Person	*passengerPtr;

	Door door;
	Bell bell;
};

#endif

#endif /* CHAPTER7_FIG07_24_ELEVATOR_H_ */
