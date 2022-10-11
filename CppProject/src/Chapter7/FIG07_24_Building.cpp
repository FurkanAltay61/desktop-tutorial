/*
 * FIG07_24_3.cpp
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */


#include "FIG07_24_Building.h"


#if (FIG07_24)


#include <iostream>

using namespace std;

Building::Building()
		:floor1(Floor::FLOOR1,elevator),
		 floor2(Floor::FLOOR2,elevator),
		 elevator(floor1,floor2),
		 scheduler(floor1,floor2)
{
	cout << "Building constructed" << endl;
}

Building::~Building(){
	cout << "Building destructed" << endl;
}

void Building::runSimulation(int totalTime){
	int currentTime = 0;

	while(currentTime < totalTime){
		clock.tick();
		currentTime = clock.getTime();
		cout << "TIME: " << currentTime << endl;

		scheduler.processTime(currentTime);

		elevator.processTime(currentTime);

		cin.get();
	}
}



#endif
