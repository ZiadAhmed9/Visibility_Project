/*
 * SEV_SEG.h
 *
 * Created: 10/26/2023 2:25:02 PM
 *  Author: COMPUMARTS
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_
#include "SEV_SEG_Cfg.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
typedef enum{
	DISP1,
	DISP2,
	DISP3,
	DISP4
	}SEV_SEG_t;

void SEV_SEG_Write(SEV_SEG_t channel,u8 number);



#endif /* SEV_SEG_H_ */