/*
 * BlinkyButton.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_TIMEBOMB_H_
#define INC_TIMEBOMB_H_


#include "uc_ao.h"


enum EventSignals {
	BUTTON_PRESSED_SIG = USER_SIG,
	BUTTON_RELEASED_SIG,
	TIMEOUT_SIG
	/********/
};



typedef struct {
	Active super; /* inherit active base class */
    /* add private data for the AO... */
	enum {
		WAIT4BUTTON_STATE,
		BLINK_STATE,
		PAUSE_STATE,
		BOOM_STATE
	}state;

    TimeEvent te;
    uint32_t blink_cntr;
}TimeBomb;


static void TimeBomb_dispatch(TimeBomb * const me, Event const * const e);
void TimeBomb_ctor(TimeBomb * const me);
void App_TimeTickHook(void);

#endif /* INC_TIMEBOMB_H_ */
