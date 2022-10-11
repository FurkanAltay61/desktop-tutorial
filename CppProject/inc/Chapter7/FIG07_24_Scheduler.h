/*
 * FIG07_24_Scheduler.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_SCHEDULER_H_
#define CHAPTER7_FIG07_24_SCHEDULER_H_

#include "Answers.h"

#if (FIG07_24)

class Floor;

class Scheduler {

public:
	Scheduler(Floor &, Floor &);
	~Scheduler();
	void processTime(int);

private:
	/* Schedule arrival to a floor */
	void scheduleTime(const Floor &);

	void delayTime(const Floor &);

	void createNewPerson( Floor &);

	void handleArrivals(Floor &, int);

	int currentClockTime;

	Floor &floor1Ref;

	Floor &floor2Ref;

	int floor1ArrivalTime;

	int floor2ArrivalTime;
};

#endif

#endif /* CHAPTER7_FIG07_24_SCHEDULER_H_ */
