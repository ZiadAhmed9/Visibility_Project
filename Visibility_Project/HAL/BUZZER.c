/*
 * BUZZER.c
 *
 * Created: 10/28/2023 10:32:02 AM
 *  Author: COMPUMARTS
 */ 
#include "DIO_Interface.h"
#include "BUZZER.h"
#include "BUZZER_Cfg.h"
void BUZZER_ON(void)
{
	DIO_WritePin(BUZZER_PIN,HIGH);
}

void BUZZER_OFF(void)
{
	DIO_WritePin(BUZZER_PIN,LOW);
}