/*
 * MOTOR.c
 *
 * Created: 10/26/2023 4:56:25 PM
 *  Author: COMPUMARTS
 */ 
#include "DIO_Interface.h"
#include "MOTOR.h"
#include "MOTOR_Cfg.h"
MOTOR_state_t MOTOR_Stop(void)
{
	DIO_WritePin(MOTOR_PIN1,LOW);
	DIO_WritePin(MOTOR_PIN2,LOW);
	return STOPPED;
}

MOTOR_state_t Motor_Clock(void)
{
	DIO_WritePin(MOTOR_PIN1,HIGH);
	DIO_WritePin(MOTOR_PIN2,LOW);
	return CLOCKWISE;
}
MOTOR_state_t MOTOR_CounterClock(void)
{
	DIO_WritePin(MOTOR_PIN1,LOW);
	DIO_WritePin(MOTOR_PIN2,HIGH);
	return COUNTER_CLOCKWISE;
}