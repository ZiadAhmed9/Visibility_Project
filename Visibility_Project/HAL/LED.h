/*
 * LED.h
 *
 * Created: 10/28/2023 11:05:26 PM
 *  Author: COMPUMARTS
 */ 


#ifndef LED_H_
#define LED_H_
#include "DIO_Interface.h"
#include "StdTypes.h"
#include "LED_CFG.h"
#include "EX_Interrupt.h"
void LED_ON(DIO_Pin_type pin);
void LED_OFF(DIO_Pin_type pin);
void LED_AllOff(void);
void LED_AllOn(void);
void LED_OnMultiple(u8 first_LED,u8 n);
void LED_OffMultiple(u8 first_led,u8 n_leds);
void LED_Init_interrupts(void);
#endif /* LED_H_ */