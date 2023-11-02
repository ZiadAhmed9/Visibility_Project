#include "StdTypes.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "Sensors.h"
#include "Sensors_cfg.h"

u8 POT_Read(void)
{
	u16 adc=ADC_Read(POT_CH);
	u8 pot=(adc*(u32)100)/1023;
	return pot;
}


u16 TEMP_Read(void)
{
	u16 volt=ADC_ReadVolt(TEMP_CH);
	u16 temp=volt/10;
	return temp;
}

