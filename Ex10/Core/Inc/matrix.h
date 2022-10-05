/*
 * matrix.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Guest_demo
 */

#ifndef INC_MATRIX_H_
#define INC_MATRIX_H_

#define MAX_LED_MATRIX 8
#define MAX_LED_BUFFER 48

#include "main.h"

uint8_t matrix_buffer[MAX_LED_BUFFER];
int shifter;
int counter;

void getBuffer(uint8_t buffer);
void updateLedMatrix(int index);
void clearEnable();

#endif /* INC_MATRIX_H_ */
