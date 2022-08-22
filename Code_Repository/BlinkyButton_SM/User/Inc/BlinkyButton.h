/*
 * BlinkyButton.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_BLINKYBUTTON_H_
#define INC_BLINKYBUTTON_H_


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
		OFF_STATE,
		ON_STATE
	}state;

    TimeEvent te;
    _Bool isLedOn;
    uint32_t blink_time;
}BlinkyButton;


static void BlinkyButton_dispatch(BlinkyButton * const me, Event const * const e);
void BlinkyButton_ctor(BlinkyButton * const me);
void App_TimeTickHook(void);

#endif /* INC_BLINKYBUTTON_H_ */
