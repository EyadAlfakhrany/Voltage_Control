/*
 * Button_Core.c
 *
 * Created: 9/15/2023 10:06:59 AM
 * Author: EyadA
 */ 

#include "Button_Core.h"

void Button_Init_1(void)
{
	CLR_BIT(DDRD , 2);
}

uint8 Button_GetValue_1(void)
{
	uint8 Button = 1 ;
	uint8 Temp = 0;
	
	Button = GET_BIT(PIND , 2);
	
	/*while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 2);
	}
	
	//_delay_ms(200);
	*/
	return Button;
}
void Button_Init_2(void)
{
	CLR_BIT(DDRD , 3);
}

uint8 Button_GetValue_2(void)
{
	uint8 Button = 1 ;
	uint8 Temp = 0;
	
	Button = GET_BIT(PIND , 3);
	
/*	while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 3);
	}
	
//_delay_ms(200);*/
	
	return Button;
}
void Button_Init_3(void)
{
	CLR_BIT(DDRD , 4);
}

uint8 Button_GetValue_3(void)
{
	uint8 Button = 1 ;
	uint8 Temp = 0;
	
	Button = GET_BIT(PIND , 4);
	/*
	while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 4);
	}
	
	_delay_ms(200);*/
	
	return Button;
}
void Button_Init_4(void)
{
	CLR_BIT(DDRD , 5);
}

uint8 Button_GetValue_4(void)
{
	uint8 Button = 1 ;
	uint8 Temp = 0;
	
	Button = GET_BIT(PIND , 5);
	/*
	while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 5);
	}
	
	_delay_ms(200);*/
	
	return Button;
}