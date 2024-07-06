/*
 * KeyPad_Core.h
 *
 * Created: 10/3/2023 8:13:15 PM
 * Author: EyadA
 */ 

#ifndef KEYPAD_CORE_H_
#define KEYPAD_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "KeyPad_Cfg.h"
#include "DIO_Core.h"
#define  F_CPU 16000000U
#include "util/delay.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Keypad_Init(void);

uint8 Keypad_GetValue(void);
 

#endif /* KEYPAD_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/





