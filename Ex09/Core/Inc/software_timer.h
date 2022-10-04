/*
 * software_timer.h
 *
 *  Created on: 4 thg 10, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMECYCLE 10

extern int timer0_flag;
extern int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
