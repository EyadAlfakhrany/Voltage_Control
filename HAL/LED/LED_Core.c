/*
 * LED_Core.c
 *
 * Created: 9/15/2023 10:03:12 AM
 * Author: EyadA
 */ 

#include "LED_Core.h"


void LED_Init(void)
{
	SET_BIT(DDRC , 0);
	SET_BIT(DDRC , 1);
	SET_BIT(DDRC , 2);
}
void LED_Red_ON(void)
{
	SET_BIT(PORTC , 0);
}
void LED_Green_ON(void)
{
	SET_BIT(PORTC , 1);
}
void LED_Blue_ON(void)
{
	SET_BIT(PORTC , 2);
}

void LED_Red_OFF(void)
{
	CLR_BIT(PORTC , 0);
}
void LED_Green_OFF(void)
{
	CLR_BIT(PORTC , 1);
}
void LED_Blue_OFF(void)
{
	CLR_BIT(PORTC , 2);
}


void LED_Toggle(void)
{
	TOGGLE_BIT(PORTC , 0);
}