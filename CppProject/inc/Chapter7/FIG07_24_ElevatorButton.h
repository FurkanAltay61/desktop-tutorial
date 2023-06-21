/*
 * FIG07_24_Button.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_ELEVATORBUTTON_H_
#define CHAPTER7_FIG07_24_ELEVATORBUTTON_H_

#include "Answers.h"

#if (FIG07_24)

class Elevator;

class ElevatorButton {

public:
	ElevatorButton(Elevator &);
	~ElevatorButton();

	void pressButton();
	void resetButton();

private:
	bool pressed;

	Elevator &elevatorRef;
};

#endif

#endif /* CHAPTER7_FIG07_24_ELEVATORBUTTON_H_ */
