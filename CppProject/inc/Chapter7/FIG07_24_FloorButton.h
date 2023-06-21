/*
 * FIG07_24_FloorButton.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_FLOORBUTTON_H_
#define CHAPTER7_FIG07_24_FLOORBUTTON_H_

#include "Answers.h"

#if ( FIG07_24 )

class Elevator;

class FloorButton {

public:
	FloorButton(int , Elevator &);
	~FloorButton();

	void pressButton();
	void resetButton();

private:
	const int floorNumber;
	bool pressed;

	Elevator &elevatorRef;
};

#endif

#endif /* CHAPTER7_FIG07_24_FLOORBUTTON_H_ */
