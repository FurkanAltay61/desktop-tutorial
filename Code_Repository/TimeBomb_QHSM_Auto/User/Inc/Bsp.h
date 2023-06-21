/*
 * Bsp.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_BSP_H_
#define INC_BSP_H_

#define BSP_TICKS_PER_SEC 100
#define true 1
#define false 0

enum { INITIAL_BLINK_TIME = (BSP_TICKS_PER_SEC / 4) };

_Bool BspGetButtonState(uint8_t);
void BspLed1On(void);
void BspLed1Off(void);
void BspLed2On(void);
void BspLed2Off(void);
void BspLed3On(void);
void BspLed3Off(void);

enum EventSignals {
	BUTTON_PRESSED_SIG = Q_USER_SIG,
	BUTTON_RELEASED_SIG,
	BUTTON2_PRESSED_SIG,
	BUTTON2_RELEASED_SIG,
	TIMEOUT_SIG,
	/********/
	MAX_SIG
};


/*Active objects */
extern QActive *AO_TimeBomb;


void App_TimeTickHook(void);

#endif /* INC_BSP_H_ */
