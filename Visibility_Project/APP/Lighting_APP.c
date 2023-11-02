/*
* Lighting_APP.c
*
* Created: 10/30/2023 10:45:52 PM
*  Author: COMPUMARTS
*/

#include "Lighting_APP.h"
u32 time_in_seconds;
BACK_LIGHT_State back_light_state=BACK_LIGHT_OFF;
FRONT_LIGHT_State front_light_state=FRONT_LIGHT_OFF;
LEFT_LIGHT_State left_light_state=LEFT_LIGHT_OFF;
RIGHT_LIGHT_State right_light_state=RIGHT_LIGHT_OFF;
u8 Back_buttons_state=NOT_PRESSED;
void seconds(void)
{
	time_in_seconds++;
	//DIO_TogglePin(PINB7);
}

void Lighting_Init(void)
{
	//LED_Init_interrupts();
	LED_OFF(RIGHT_LIGHT_PIN);
	LED_OFF(FRONT_LIGHT_PIN);
	LED_OFF(BACK_LIGHT_PIN);
	LED_OFF(LEFT_LIGHT_PIN);
	Timer1_Count_1ms(seconds);
}


//BACK_LIGHT_PIN
//PRESSED
void measure_time(void)
{
	time_in_seconds=0;
	Timer1_reset();
}
void Back_Light_Check(void)
{
	if(DIO_ReadPin(BACKLIGHT_BUTTON)==PRESSED)
	{
		Back_buttons_state==PRESSED;
		measure_time();
		//DIO_TogglePin(BACK_LIGHT_PIN);
		
		while(DIO_ReadPin(BACKLIGHT_BUTTON)==PRESSED);

		if(time_in_seconds<1000)
		{
			//back_light_state=BACK_LIGHT_OFF;
			//DIO_TogglePin(BACK_LIGHT_PIN);
			
			switch(back_light_state)
			{
				case BACK_LIGHT_OFF:
				back_light_state=BACK_LIGHT_ON;
				LED_ON(BACK_LIGHT_PIN);
				break;
				case BACK_LIGHT_ON:
				LED_OFF(BACK_LIGHT_PIN);
				back_light_state=BACK_LIGHT_OFF;
				break;
				default:
				LED_OFF(BACK_LIGHT_PIN);
				back_light_state=BACK_LIGHT_OFF;
				break;
			}
		}
		else if(time_in_seconds>=1000&&time_in_seconds<2500)
		{
			back_light_state=BACK_LIGHT_SLOW_BLINK;
		}
		else if(time_in_seconds>=2500)
		{
			back_light_state=BACK_LIGHT_FAST_BLINK;
		}
		Back_buttons_state=NOT_PRESSED;
	}
}


void FRONT_Light_Check(void)
{
	if(DIO_ReadPin(FRONTLIGHT_BUTTON)==PRESSED)
	{
		measure_time();
		//DIO_TogglePin(BACK_LIGHT_PIN);
		
		while(DIO_ReadPin(FRONTLIGHT_BUTTON)==PRESSED);

		if(time_in_seconds<1000)
		{
			//back_light_state=BACK_LIGHT_OFF;
			//DIO_TogglePin(BACK_LIGHT_PIN);
			
			switch(front_light_state)
			{
				case FRONT_LIGHT_OFF:
				front_light_state=FRONT_LIGHT_ON;
				LED_ON(FRONT_LIGHT_PIN);
				break;
				case FRONT_LIGHT_ON:
				LED_OFF(FRONT_LIGHT_PIN);
				front_light_state=FRONT_LIGHT_OFF;
				break;
				default:
				LED_OFF(FRONT_LIGHT_PIN);
				front_light_state=FRONT_LIGHT_OFF;
				break;
			}
		}
		else if(time_in_seconds>=1000&&time_in_seconds<2500)
		{
			front_light_state=FRONT_LIGHT_SLOW_BLINK;
		}
		else if(time_in_seconds>=2500)
		{
			front_light_state=FRONT_LIGHT_FAST_BLINK;
		}
	}
}

void LEFT_Light_Check(void)
{
	if(DIO_ReadPin(LEFTLIGHT_BUTTON)==PRESSED)
	{
		measure_time();
		//DIO_TogglePin(BACK_LIGHT_PIN);
		
		while(DIO_ReadPin(LEFTLIGHT_BUTTON)==PRESSED);

		if(time_in_seconds<1000)
		{
			//back_light_state=BACK_LIGHT_OFF;
			//DIO_TogglePin(BACK_LIGHT_PIN);
			
			switch(left_light_state)
			{
				case LEFT_LIGHT_OFF:
				left_light_state=LEFT_LIGHT_ON;
				LED_ON(LEFT_LIGHT_PIN);
				break;
				case LEFT_LIGHT_ON:
				LED_OFF(LEFT_LIGHT_PIN);
				left_light_state=LEFT_LIGHT_OFF;
				break;
				default:
				LED_OFF(LEFT_LIGHT_PIN);
				left_light_state=LEFT_LIGHT_OFF;
				break;
			}
		}
		else if(time_in_seconds>=1000&&time_in_seconds<2500)
		{
			left_light_state=LEFT_LIGHT_SLOW_BLINK;
		}
		else if(time_in_seconds>=2500)
		{
			left_light_state=LEFT_LIGHT_FAST_BLINK;
		}
	}
}


void RIGHT_Light_Check(void)
{
	if(DIO_ReadPin(RIGHTLIGHT_BUTTON)==PRESSED)
	{
		measure_time();
		//DIO_TogglePin(BACK_LIGHT_PIN);
		
		while(DIO_ReadPin(RIGHTLIGHT_BUTTON)==PRESSED);

		if(time_in_seconds<1000)
		{
			//back_light_state=BACK_LIGHT_OFF;
			//DIO_TogglePin(BACK_LIGHT_PIN);
			
			switch(right_light_state)
			{
				case RIGHT_LIGHT_OFF:
				right_light_state=RIGHT_LIGHT_ON;
				LED_ON(RIGHT_LIGHT_PIN);
				break;
				case RIGHT_LIGHT_ON:
				LED_OFF(RIGHT_LIGHT_PIN);
				right_light_state=RIGHT_LIGHT_OFF;
				break;
				default:
				LED_OFF(RIGHT_LIGHT_PIN);
				right_light_state=RIGHT_LIGHT_OFF;
				break;
			}
		}
		else if(time_in_seconds>=1000&&time_in_seconds<2500)
		{
			right_light_state=RIGHT_LIGHT_SLOW_BLINK;
		}
		else if(time_in_seconds>=2500)
		{
			right_light_state=RIGHT_LIGHT_FAST_BLINK;
		}
	}
}

APP_state Main_Menu(void)
{
	int choice=NO_KEY;
	LCD_Clear();
	LCD_WriteString("1) Edit Password");
	LCD_SetCursor(1,0);
	LCD_WriteString("2) Control mode");
	while(choice==NO_KEY)
	{
		choice=KEYPAD_GetKey();
	}
	switch (choice)
	{
		case '1':
			return CHANGE_PASSWORD;
			break;
		case '2':
			return DRIVING_AND_CONTROL;
			break;
		default:
			return MAIN_MENU;
	}
}

void Start_Lighting(void)
{
	if(time_in_seconds%1000==0)
	{
		if(back_light_state==BACK_LIGHT_SLOW_BLINK)
		DIO_TogglePin(PINB7);
		if(front_light_state==FRONT_LIGHT_SLOW_BLINK)
		DIO_TogglePin(PINA1);
		if(left_light_state==LEFT_LIGHT_SLOW_BLINK)
		{
			DIO_TogglePin(PINA2);
		}
		if(right_light_state==RIGHT_LIGHT_SLOW_BLINK)
		DIO_TogglePin(RIGHT_LIGHT_PIN);
	}
	if(time_in_seconds%100==0)
	{
		if(back_light_state==BACK_LIGHT_FAST_BLINK)
		DIO_TogglePin(PINB7);
		if(front_light_state==FRONT_LIGHT_FAST_BLINK)
		DIO_TogglePin(PINA1);
		if(left_light_state==LEFT_LIGHT_FAST_BLINK)
		{
			DIO_TogglePin(PINA2);
		}
		if(right_light_state==RIGHT_LIGHT_FAST_BLINK)
		DIO_TogglePin(RIGHT_LIGHT_PIN);
	}
}

