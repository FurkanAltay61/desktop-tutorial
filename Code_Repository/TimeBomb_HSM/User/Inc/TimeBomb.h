/*
 * BlinkyButton.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_TIMEBOMB_H_
#define INC_TIMEBOMB_H_


#include <freertos_ao.h>


enum EventSignals {
	BUTTON_PRESSED_SIG = USER_SIG,
	BUTTON_RELEASED_SIG,
	BUTTON2_PRESSED_SIG,
	BUTTON2_RELEASED_SIG,
	TIMEOUT_SIG,
	/********/
	MAX_SIG
};

typedef struct TimeBomb TimeBomb;   /*forward declaration*/

struct TimeBomb{
	Active super; /* inherit active base class */
    TimeEvent te;
    uint32_t blink_cntr;
};



void TimeBomb_ctor(TimeBomb * const me);
void App_TimeTickHook(void);

#endif /* INC_TIMEBOMB_H_ */
