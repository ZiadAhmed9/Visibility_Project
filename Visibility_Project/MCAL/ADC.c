/*
 * ADC.c
 *
 * Created: 5/13/2023 2:56:02 PM
 *  Author: COMPUMARTS
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC_Interface.h"


//With this function we use register REFS1 and REFS0 to decide which VREF will we use
void ADC_Init(ADC_Voltage_type vref,ADC_Prescaler_type scaler)
{
	//choosing the vreff
	switch(vref)
	{
		
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case VREF_VCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
			}
		
		//CLOCK
		// in this method instead of doing a long switch case
		//we first make sure the bits are initialized by zero at the start
		//by anding the first 3 bits of the register with 0s and the rest with ones
		//then we OR the scaler value (predefined enum with each value in it carrying the value that must be
		//entered in the first 3 register ti write the value in it
		//for example if we need the first prescaler, scaler=ADC_Scaler_2 which is =1
		//to get this prescaling value we write 1 in the first 3 bits
		ADCSRA=ADCSRA&0xf8; //0b11111000
		scaler=scaler&0x07; // this step makes sure that the value entered won't affect any other register other than the first three
		ADCSRA=ADCSRA|scaler;
		
		//ADC ENABLE BIT
		SET_BIT(ADCSRA,ADEN);
}

//This function takes the channel enum type and starts conversion then return the value of the conversion
u16 ADC_Read(ADC_Channel_type channel)
{
	/* select ch using mux*/
	
	ADMUX=ADMUX&0xe0;
	ADMUX|=channel;
	/* start conversion*/
	SET_BIT(ADCSRA,ADSC);
	/*wait until end     busy wait or blocking*/
	while(READ_BIT(ADCSRA,ADSC));

	/* get reading from 2 registers*/
	return ADC;
	
}

u16 ADC_ReadVolt(ADC_Channel_type channel)
{
	u16 adc=ADC_Read(channel);
	u16 volt=((u32)5000*adc)/1024;
	return volt;
}

