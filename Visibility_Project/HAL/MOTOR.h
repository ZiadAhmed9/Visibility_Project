/*
 * MOTOR.h
 *
 * Created: 10/26/2023 4:56:37 PM
 *  Author: COMPUMARTS
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum{
	STOPPED,
	CLOCKWISE,
	COUNTER_CLOCKWISE
	}MOTOR_state_t;
MOTOR_state_t MOTOR_Stop(void);
MOTOR_state_t Motor_Clock(void);
MOTOR_state_t MOTOR_CounterClock(void);
#endif /* MOTOR_H_ */