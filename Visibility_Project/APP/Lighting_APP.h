/*
* Lighting_APP.h
*
* Created: 10/30/2023 10:46:50 PM
*  Author: COMPUMARTS
*/


#ifndef LIGHTING_APP_H_
#define LIGHTING_APP_H_
#include "StdTypes.h"
#include "LED.h"
#include "DIO_Interface.h"
#include "LED_Cfg.h"
#include "EX_Interrupt.h"
#include "BUTTON_Cfg.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "Password_APP.h"
#define RIGHT_LIGHT_PIN LED0
#define FRONT_LIGHT_PIN LED1
#define LEFT_LIGHT_PIN LED2
#define BACK_LIGHT_PIN LED3
#define BACKLIGHT_BUTTON BUTTON0
#define FRONTLIGHT_BUTTON BUTTON1
#define RIGHTLIGHT_BUTTON BUTTON2
#define LEFTLIGHT_BUTTON BUTTON3
#define PRESSED LOW
#define NOT_PRESSED HIGH
void Lighting_Init(void);
void Lighting_Right(void);
void Lighting_Left(void);
void Lighting_Front(void);
void Lighting_Back(void);
void Back_Light_Check(void);
void FRONT_Light_Check(void);
void LEFT_Light_Check(void);
void RIGHT_Light_Check(void);
void Start_Lighting(void);
APP_state Main_Menu(void);
typedef enum{
	FRONT_LIGHT_OFF,
	FRONT_LIGHT_ON,
	FRONT_LIGHT_SLOW_BLINK,
	FRONT_LIGHT_FAST_BLINK
}FRONT_LIGHT_State;
typedef enum{
	BACK_LIGHT_OFF,
	BACK_LIGHT_ON,
	BACK_LIGHT_SLOW_BLINK,
	BACK_LIGHT_FAST_BLINK
}BACK_LIGHT_State;
typedef enum{
	LEFT_LIGHT_OFF,
	LEFT_LIGHT_ON,
	LEFT_LIGHT_SLOW_BLINK,
	LEFT_LIGHT_FAST_BLINK
}LEFT_LIGHT_State;
typedef enum{
	RIGHT_LIGHT_OFF,
	RIGHT_LIGHT_ON,
	RIGHT_LIGHT_SLOW_BLINK,
	RIGHT_LIGHT_FAST_BLINK
}RIGHT_LIGHT_State;
#endif /* LIGHTING_APP_H_ */