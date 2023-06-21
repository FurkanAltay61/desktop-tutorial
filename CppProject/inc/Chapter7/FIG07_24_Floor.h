/*
 * FIG07_24_2.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_FLOOR_H_
#define CHAPTER7_FIG07_24_FLOOR_H_

#include "Answers.h"

#if ( FIG07_24 )

#include "FIG07_24_FloorButton.h"
#include "FIG07_24_Light.h"

class Elevator;
class Person;

class Floor {

public:
	Floor(int, Elevator &);
    ~Floor();
    bool isOccupied() const;
    int getNumber() const;

    void personArrives(Person * const);

    Person *elevatorArrived();

    void elevatorLeaving();

    void personBoardingElevator();

    static const int FLOOR1;
    static const int FLOOR2;

    FloorButton floorButton;

private:
    const int floorNumber;
    Elevator &elevatorRef;
    Person	*occupantPtr;
    Light light;

};


#endif

#endif /* CHAPTER7_FIG07_24_FLOOR_H_ */
