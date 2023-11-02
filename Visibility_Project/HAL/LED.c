/*
 * LED.c
 *
 * Created: 10/28/2023 11:07:53 PM
 *  Author: COMPUMARTS
 */ 
#include "LED.h"
void LED_Init_interrupts(void)
{
	EXI_Enable(EX_INT0);
	EXI_Enable(EX_INT1);
	EXI_Enable(EX_INT2);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_TriggerEdge(EX_INT1,RISING_EDGE);
	EXI_TriggerEdge(EX_INT2,RISING_EDGE);
}
void LED_ON(DIO_Pin_type pin)
{
	DIO_WritePin(pin,HIGH);
}

void LED_OFF(DIO_Pin_type pin)
{
	DIO_WritePin(pin,LOW);
}

void LED_AllOn(void)
{
	for(DIO_Pin_type i=LED0;i<LED0+N_LEDS;i++)
	{
		LED_ON(i);
	}
}

void LED_OnMultiple(u8 first_LED,u8 n_leds)
{
		for(DIO_Pin_type i=first_LED;i<LED0+n_leds;i++)
		{
			LED_ON(i);
		}
}
void LED_OffMultiple(u8 first_led,u8 n_leds)
{
	for(DIO_Pin_type i=first_led;i<LED0+n_leds;i++)
	{
		LED_OFF(i);
	}
}
void LED_AllOff(void)
{
	for(DIO_Pin_type i=LED0;i<LED0+N_LEDS;i++)
	{
		LED_OFF(i);
	}
}