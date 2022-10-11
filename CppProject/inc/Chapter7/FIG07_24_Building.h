/*
 * FIG07_24_Building.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_BUILDING_H_
#define CHAPTER7_FIG07_24_BUILDING_H_

#include "Answers.h"

#if (FIG07_24)

#include "FIG07_24_Elevator.h"
#include "FIG07_24_Floor.h"
#include "FIG07_24_Clock.h"
#include "FIG07_24_Scheduler.h"

class Building {
public:
	Building();
	~Building();
	void runSimulation(int);

private:
	Floor floor1;		//floor1 object
	Floor floor2;		//floor2 object
	Elevator elevator;  //elevator object
	Clock clock;		//clock object
	Scheduler scheduler;//scheduler object
};

#endif
#endif /* CHAPTER7_FIG07_24_BUILDING_H_ */
