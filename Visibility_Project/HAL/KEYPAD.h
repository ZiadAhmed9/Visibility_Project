/*
 * KEYPAD.h
 *
 * Created: 10/29/2023 8:54:53 PM
 *  Author: COMPUMARTS
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"


#define  NO_KEY   'T'

void KEYPAD_Init(void);

u8 KEYPAD_GetKey(void);

#endif /* KEYPAD_H_ */