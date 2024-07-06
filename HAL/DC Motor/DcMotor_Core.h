/*
 * DcMotor_Core.h
 *
 * Created: 10/27/2023 11:07:57 AM
 * Author: EyadA
 */ 


#ifndef DCMOTOR_CORE_H_
#define DCMOTOR_CORE_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PWM_Core.h"
#include "DIO_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  CLOCKWISE           1
#define  COUNTER_CLOCKWISE   0

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
void DcMotor_Init(void);

void DcMotor_SetSpeed(uint8 Speed);

void DcMotor_SetDirection(uint8 Dir);

void DcMotor_Stop(void);
 

#endif /* DCMOTOR_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


