/*
 * matrix.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Guest_demo
 */

#ifndef INC_MATRIX_H_
#define INC_MATRIX_H_

#define MAX_LED_MATRIX 8

#include "main.h"

uint8_t matrix_buffer[8];

void getBuffer(uint8_t buffer);
void updateLedMatrix(int index);
void clearEnable();

#endif /* INC_MATRIX_H_ */
