/*
 * led7seg.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Guest_demo
 */

#include "led7seg.h"

void display7Seg(int num){
	switch (num){
		case 0:{ // display 0 using leds: a, b, c, d, e, f
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_B_Pin | SEG_C_Pin |
									SEG_D_Pin | SEG_E_Pin | SEG_F_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, 1);
			break;
		}
		case 1:{ // display 1 using leds: b, c
			HAL_GPIO_WritePin(GPIOB, SEG_B_Pin | SEG_C_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_D_Pin | SEG_E_Pin |
									SEG_F_Pin | SEG_G_Pin, 1);
			break;
		}
		case 2:{ // display 2 using leds: a, b, d, e, g
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_B_Pin | SEG_D_Pin |
									SEG_E_Pin | SEG_G_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_C_Pin | SEG_F_Pin, 1);
			break;
		}
		case 3:{ // display 3 using leds: a, b, c, d, g
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_B_Pin | SEG_C_Pin |
									SEG_D_Pin | SEG_G_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_E_Pin | SEG_F_Pin, 1);
			break;
		}
		case 4:{ // display 4 using leds: b, c, f, g
			HAL_GPIO_WritePin(GPIOB, SEG_B_Pin | SEG_C_Pin | SEG_F_Pin |
									SEG_G_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_D_Pin | SEG_E_Pin, 1);
			break;
		}
		case 5:{ // display 5 using leds: a, c, d, f, g
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_C_Pin | SEG_D_Pin |
									SEG_F_Pin | SEG_G_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_B_Pin | SEG_E_Pin, 1);
			break;
		}
		case 6:{ // display 6 using leds: a, c, d, e, f, g
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_C_Pin | SEG_D_Pin |
									SEG_E_Pin | SEG_F_Pin | SEG_G_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, 1);
			break;
		}
		case 7:{ // diplay 7 using leds: a, b, c
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_B_Pin | SEG_C_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_D_Pin | SEG_E_Pin | SEG_F_Pin |
									SEG_G_Pin, 1);
			break;
		}
		case 8:{ // display 8 using leds: a, b, c, d, e, f, g
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_B_Pin | SEG_C_Pin |
									SEG_D_Pin | SEG_E_Pin | SEG_F_Pin |
									SEG_G_Pin, 0);
			break;
		}
		case 9:{ // display 9 using leds: a, b, c, d, f, g
			HAL_GPIO_WritePin(GPIOB, SEG_A_Pin | SEG_B_Pin | SEG_C_Pin |
									SEG_D_Pin | SEG_F_Pin | SEG_G_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, 1);
			break;
		}
	}
}

const int MAX_LED = 4;
int led_buffer[4] = {0, 0, 0, 0};
void update7Seg(int index){
	switch (index){
		case 0:{
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
			display7Seg(led_buffer[index]);
			break;
		}
		case 1:{
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
			display7Seg(led_buffer[index]);
			break;
		}
		case 2:{
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN0_Pin | EN3_Pin, SET);
			display7Seg(led_buffer[index]);
			break;
		}
		case 3:{
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN0_Pin, SET);
			display7Seg(led_buffer[index]);
			break;
		}
		default: break;
	}
}
