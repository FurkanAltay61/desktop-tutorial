/*
 * Bsp.h
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */

#ifndef INC_BSP_H_
#define INC_BSP_H_

#include "main.h"

#define OS_TICKS_PER_SEC 1000
#define true 1
#define false 0

enum { INITIAL_BLINK_TIME = (OS_TICKS_PER_SEC / 4) };

_Bool BspGetButtonState(void);
void BspLed1On(void);
void BspLed1Off(void);
void BspLed2On(void);
void BspLed2Off(void);
void BspLed3On(void);
void BspLed3Off(void);




#endif /* INC_BSP_H_ */
