/*
* Visibility.c
*
* Created: 10/29/2023 10:54:57 PM
*  Author: COMPUMARTS
*/


#include "Password_APP.h"

static u8 password[3]={NO_KEY,NO_KEY,NO_KEY};


APP_state Welcome_message(void)
{
	LCD_Clear();
	LCD_WriteString("SET PASSWORD");
	LCD_SetCursor(1,0);

}

APP_state Take_Password(void)
{
	Welcome_message();
	u8 x;
	for(int i=0;i<3;i++)
	{
		x=NO_KEY;
		while(x==NO_KEY)
		{
			x=KEYPAD_GetKey();
		}
		LCD_WriteChar(x);
		password[i]=x;
	}
	if(password[2]!=NO_KEY)
	{
		LCD_Clear();
		LCD_WriteString("New Password Set");
		_delay_ms(100);
		return PASSWORD_SET;
	}

	return PASSWORD_NOT_SET;
	
}


APP_state Check_Password(void)
{
	u8 temp[3]={NO_KEY,NO_KEY,NO_KEY},x=NO_KEY,flag=0;
	for(int i=0;i<3;i++)
	{
		x=NO_KEY;
		while(x==NO_KEY)
		{

			x=KEYPAD_GetKey();
		}

		LCD_WriteChar(x);
		temp[i]=x;
	}
	if(temp[2]==NO_KEY)
	{
		return PASSWORD_NOT_SET;
	}
	for(int i=0;i<3;i++)
	{
		if(temp[i]!=password[i])
		{
			LCD_Clear();
			LCD_WriteString("Invalid");
			_delay_ms(100);
			return PASSWORD_SET;
		}
	}
	return PASSWORD_CORRECT;
}
APP_state Change_Password(void)
{
	u8 temp[3]={NO_KEY,NO_KEY,NO_KEY},x=NO_KEY,flag=0;
	for(int i=0;i<3;i++)
	{
		x=NO_KEY;
		while(x==NO_KEY)
		{

			x=KEYPAD_GetKey();
		}

		LCD_WriteChar(x);
		temp[i]=x;
	}
	if(temp[2]==NO_KEY)
	{
		return CHANGE_PASSWORD;
	}
	for(int i=0;i<3;i++)
	{
		if(temp[i]!=password[i])
		{
			LCD_Clear();
			LCD_WriteString("Invalid");
			_delay_ms(100);
			return MAIN_MENU;
		}
	}
	return PASSWORD_CORRECT;
}
void Ignite_Motor(void)
{
	LCD_Clear();
	LCD_WriteString("CORRECT!");
	
	Motor_Clock();
	_delay_ms(100);
}