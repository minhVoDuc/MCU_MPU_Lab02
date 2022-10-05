/*
 * matrix.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Guest_demo
 */

#include "matrix.h"

uint8_t matrix_buffer[MAX_CHARACTER][8] = {{0x00, 0x7e, 0x04, 0x08, 0x08, 0x04, 0x7e, 0x00}, //M
											{0x00, 0x3e, 0x40, 0x40, 0x40, 0x40, 0x3e, 0x00}, //U
											{0x00, 0x00, 0x42, 0x4a, 0x4a, 0x7e, 0x00, 0x00}, //3
											{0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, //-
											{0x00, 0x00, 0x7e, 0x4a, 0x4a, 0x7a, 0x00, 0x00}, //6
											{0x00, 0x7e, 0x04, 0x08, 0x08, 0x04, 0x7e, 0x00}, //M
											{0x00, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00 } //C
										};
int shifter = -1;
int counter = 0;

void getBuffer(uint8_t buffer){ // assign matrix_buffer to row pin
	HAL_GPIO_WritePin(GPIOB, ROW_0_Pin, !(buffer&1)); //LSB of buffer equal to row 0
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_1_Pin, !(buffer&1));
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_2_Pin, !(buffer&1));
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_3_Pin, !(buffer&1));
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_4_Pin, !(buffer&1));
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_5_Pin, !(buffer&1));
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_6_Pin, !(buffer&1));
	buffer = buffer >> 1;
	HAL_GPIO_WritePin(GPIOB, ROW_7_Pin, !(buffer&1)); //MSB of buffer equal to row 7
}

void updateLedMatrix(int index){ // Enable column in matrix led
	switch(index){
		case 0:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 0);
			if (counter==0) shifter = (shifter + 1) % MAX_CHARACTER;
			break;
		case 1:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 0);
			break;
		case 2:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 0);
			break;
		case 3:;
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 0);
			break;
		case 4:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 0);
			break;
		case 5:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 0);
			break;
		case 6:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 0);
			break;
		case 7:
			clearEnable();
			HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 0);
			counter = (counter + 1) % 5;
			break;
		default:
			break;
	}
	getBuffer(matrix_buffer[shifter][index]);
}

void clearEnable(){ //clear all enable for column matrix led
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin |
			ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin, 1);
}
