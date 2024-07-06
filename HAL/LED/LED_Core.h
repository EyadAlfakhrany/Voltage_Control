/*
 * LED_Core.h
 *
 * Created: 9/15/2023 10:04:13 AM
 * Author: EyadA
 */ 


#ifndef LED_CORE_H_
#define LED_CORE_H_

#include "BIT_MATH.h"
#include "MCU.h"

void LED_Init(void);

void LED_Red_ON(void);

void LED_Green_ON(void);

void LED_Blue_ON(void);

void LED_Red_OFF(void);

void LED_Green_OFF(void);

void LED_Blue_OFF(void);

void LED_Toggle(void);


#endif /* LED_CORE_H_ */