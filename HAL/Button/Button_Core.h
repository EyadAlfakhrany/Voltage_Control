/*
 * Button_Core.h
 *
 * Created: 9/15/2023 10:05:32 AM
 * Author: EyadA
 */ 


#ifndef BUTTON_CORE_H_
#define BUTTON_CORE_H_

#include "BIT_MATH.h"
#include "MCU.h"
#define F_CPU 16000000U
#include <util/delay.h>


#define  BUTTON_PRE_RELEASED  0

void Button_Init_1(void);
void Button_Init_2(void);
void Button_Init_3(void);
void Button_Init_4(void);

uint8 Button_GetValue_1(void);
uint8 Button_GetValue_2(void);
uint8 Button_GetValue_3(void);
uint8 Button_GetValue_4(void);



#endif /* BUTTON_CORE_H_ */