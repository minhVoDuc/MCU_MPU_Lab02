/*
 * digital_clock.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Guest_demo
 */

#ifndef INC_DIGITAL_CLOCK_H_
#define INC_DIGITAL_CLOCK_H_

#include "led7seg.h"

void configLedSystem(int state);
void updateClockBuffer();

int hour = 15, minute = 8, second = 50;
int state = 0; //0: Led 0 ON - 1: Led 1 ON

#endif /* INC_DIGITAL_CLOCK_H_ */
