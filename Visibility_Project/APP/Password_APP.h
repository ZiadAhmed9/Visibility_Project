/*
 * Visbility.h
 *
 * Created: 10/29/2023 10:55:12 PM
 *  Author: COMPUMARTS
 */ 


#ifndef VISBILITY_H_
#define VISBILITY_H_

#include "LCD_Interface.h"
#include "KEYPAD.h"
#include "MOTOR.h"
#include <util/delay.h>
typedef enum{
	PASSWORD_SET,
	PASSWORD_NOT_SET,
	PASSWORD_NOT_ENTERED,
	PASSWORD_CORRECT,
	PASSWORD_WRONG,
	MAIN_MENU,
	DRIVING_AND_CONTROL,
	CHANGE_PASSWORD
	}APP_state;

APP_state Check_Password(void);
APP_state Take_Password(void);
APP_state Change_Password(void);
APP_state Welcome_message(void);
void Ignite_Motor(void);
#endif /* VISBILITY_H_ */