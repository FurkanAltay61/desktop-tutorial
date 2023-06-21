/*
 * FIG07_24_Door.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_DOOR_H_
#define CHAPTER7_FIG07_24_DOOR_H_

#include "Answers.h"

#if (FIG07_24)

class Person;
class Floor;
class Elevator;

class Door {

public:
	Door();
	~Door();

	void openDoor(Person * const, Person * const, Floor &, Elevator &);
	void closeDoor(const Floor &);
private:
	bool open;
};

#endif

#endif /* CHAPTER7_FIG07_24_DOOR_H_ */
