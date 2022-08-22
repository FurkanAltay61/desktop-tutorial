/*
 * BlinkyButton.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_TIMEBOMB_H_
#define INC_TIMEBOMB_H_

#include "qpc.h"
#include "Bsp.h"


typedef struct TimeBomb TimeBomb;   /*forward declaration*/


struct TimeBomb{
	QActive super; /* inherit QActive base class */
    QTimeEvt te;
    uint32_t blink_cntr;
};



void TimeBomb_ctor(TimeBomb * const me);


#endif /* INC_TIMEBOMB_H_ */
