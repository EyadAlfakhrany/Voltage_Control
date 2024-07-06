/*
 * millis.h
 *
 * Created: 4/27/2024 8:08:01 PM
 *  Author: eiadA
 */ 


#ifndef MILLIS_H_
#define MILLIS_H_

#include "BIT_MATH.h"
#include "MCU.h"

void millis_init();
unsigned long millis();
volatile unsigned long milliseconds = 0;


#endif /* MILLIS_H_ */