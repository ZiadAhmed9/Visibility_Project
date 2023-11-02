/*
 * SEV_SEG.c
 *
 * Created: 10/26/2023 2:25:14 PM
 *  Author: COMPUMARTS
 */ 

#include "SEV_SEG.h"
#include "SEV_SEG_Cfg.h"
#include "MemMap.h"
const u8 segmentARR[10]={0b00000000,0b00000001,0b00000010,
								0b00000011,0b00000100,0b00000101,
								0b00000110,0b00000111,0b00010000,0b00010001};
void SEV_SEG_Write(SEV_SEG_t channel,u8 number)
{
	switch(channel)
	{
		case DISP1:
		DIO_WritePin(PINB5,HIGH);
		DIO_WritePin(PINB6,LOW);
		DIO_WritePin(PINA2,LOW);
		DIO_WritePin(PINA3,LOW);
		SEV_SEG_PORT&=(0b11100000);
		SEV_SEG_PORT|=segmentARR[number];
		
		break;
		case DISP2:
		DIO_WritePin(PINB6,HIGH);
		DIO_WritePin(PINB5,LOW);
		DIO_WritePin(PINA2,LOW);
		DIO_WritePin(PINA3,LOW);
		SEV_SEG_PORT&=(0b11100000);
		SEV_SEG_PORT|=segmentARR[number];
		break;
		case DISP3:
		DIO_WritePin(PINB6,LOW);
		DIO_WritePin(PINB5,LOW);
		DIO_WritePin(PINA3,HIGH);
		DIO_WritePin(PINA4,LOW);
		SEV_SEG_PORT&=(0b11100000);
		SEV_SEG_PORT|=segmentARR[number];
		break;
		case DISP4:
		DIO_WritePin(PINB6,LOW);
		DIO_WritePin(PINB5,LOW);
		DIO_WritePin(PINA3,LOW);
		DIO_WritePin(PINA4,HIGH);
		SEV_SEG_PORT&=(0b11100000);
		SEV_SEG_PORT|=segmentARR[number];
		break;
	}
	
}
