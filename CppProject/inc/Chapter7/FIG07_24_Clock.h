/*
 * FIG07_24_1.h
 *
 *  Created on: 11 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_24_CLOCK_H_
#define CHAPTER7_FIG07_24_CLOCK_H_

#include "Answers.h"

#if ( FIG07_24 )

class Clock {

public:
	Clock();
	~Clock();
	void tick();
	int getTime() const;
private:
	int time;

};

#endif


#endif /* CHAPTER7_FIG07_24_CLOCK_H_ */
