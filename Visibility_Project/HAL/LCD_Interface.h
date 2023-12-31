/*
 * LCD.h
 *
 * Created: 5/18/2023 12:40:33 PM
 *  Author: COMPUMARTS
 */ 




#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "StdTypes.h"
void LCD_Init(void);

void LCD_Print_Bar(u8 n);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_WriteNumber(s32 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_SetCursor(u8 line,u8 cell);
void LCD_Clear(void);
void LCD_WriteNumber_4D(u16 num);

void LCD_CustomChar(u8 loc,u8*pattern);




#endif /* LCD_INTERFACE_H_ */