/*
 * FIG07_24_Person.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_PERSON_H_
#define CHAPTER7_FIG07_24_PERSON_H_


#include "Answers.h"

#if ( FIG07_24 )

class Floor;
class Elevator;

class Person {

public:
	Person(int);
	~Person();
	int getID() const;
	void stepOntoFloor ( Floor &);
	void enterElevator(Elevator &, Floor &);
	void exitElevator(const Floor &, Elevator &) const;

private:
	static int personCount;
	const int ID;
	const int destinationFloor;
};

#endif

#endif /* CHAPTER7_FIG07_24_PERSON_H_ */
