/*
* Visibility_Project.c
*
* Created: 10/29/2023 8:25:14 PM
* Author : COMPUMARTS
*/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD.h"
#include "Password_APP.h"
#include "Lighting_APP.h"
#include "Timers.h"
#include "Timers_Services.h"
u32 x=0;
//void test(void)
//{
	//x++;
	////DIO_TogglePin(PINB7);
	//if(x==1000)
	//{
		//x=0;
		//DIO_TogglePin(PINB7);
	//}
//}
APP_state state=PASSWORD_NOT_SET;
void Menu_Back(void)
{
	state=MAIN_MENU;
}

int main(void)
{
	sei();
	DIO_Init();
	EXI_Enable(EX_INT2);
	EXI_TriggerEdge(EX_INT2,FALLING_EDGE);
	EXI_SetCallBack(EX_INT2,Menu_Back);
	KEYPAD_Init();
	LCD_Init();
	Lighting_Init();
	u8 flag=0;
	//Timer1_Count_1ms(test);
	while (1)
	{
		
		while(state==PASSWORD_NOT_SET)
		{
			state=Take_Password();
			
		}
		while(state==PASSWORD_SET)
		{
			LCD_Clear();
			LCD_WriteString("Enter The Password");
			LCD_SetCursor(1,0);
			state=Check_Password();
		}
		if(state==PASSWORD_CORRECT)
		{
			Ignite_Motor();
			state=MAIN_MENU;
		}
		while(state==MAIN_MENU)
		{
			state=Main_Menu();
		}
		if(state==DRIVING_AND_CONTROL)
		{
			LCD_Clear();
			LCD_WriteString("To exit press back");
		}
		while(state==DRIVING_AND_CONTROL)
		{
			
			Back_Light_Check();
			FRONT_Light_Check();
			LEFT_Light_Check();
			RIGHT_Light_Check();
			Start_Lighting();
		}
		while(state==CHANGE_PASSWORD)
		{
			state=Take_Password();
		}
		
	}
}

