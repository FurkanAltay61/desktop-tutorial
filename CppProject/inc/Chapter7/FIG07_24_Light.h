/*
 * FIG07_24_Light.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_LIGHT_H_
#define CHAPTER7_FIG07_24_LIGHT_H_

#include "Answers.h"

#if (FIG07_24)

class Light {

public:
	Light(int);
	~Light();

	void turnOn();
	void turnOff();

private:

	bool on;
	const int floorNumber;		//floor number that contains light
};

#endif

#endif /* CHAPTER7_FIG07_24_LIGHT_H_ */
