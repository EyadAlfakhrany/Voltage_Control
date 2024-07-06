/*
 * Relay.c
 *
 * Created: 6/28/2024 10:27:55 PM
 *  Author: eiadA
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Relay.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Relays_Init(void)
{
	DIO_WriteChannel(PORTB_PIN1  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN2  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN3  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN6  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN7  , PIN_HIGH);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Relay_Stage_One   (void)
{
	 DIO_WriteChannel(PORTB_PIN1  , PIN_LOW);
	 DIO_WriteChannel(PORTB_PIN2  , PIN_HIGH);
	 DIO_WriteChannel(PORTB_PIN3  , PIN_HIGH);
	 DIO_WriteChannel(PORTD_PIN6  , PIN_HIGH);
	 DIO_WriteChannel(PORTD_PIN7  , PIN_HIGH);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Relay_Stage_Two   (void)
{
	DIO_WriteChannel(PORTB_PIN1  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN2  , PIN_LOW);
	DIO_WriteChannel(PORTB_PIN3  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN6  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN7  , PIN_HIGH);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Relay_Stage_Three (void)
{
	DIO_WriteChannel(PORTB_PIN1  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN2  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN3  , PIN_LOW);
	DIO_WriteChannel(PORTD_PIN6  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN7  , PIN_HIGH);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Relay_Stage_Four  (void)
{
DIO_WriteChannel(PORTB_PIN1  , PIN_HIGH);
DIO_WriteChannel(PORTB_PIN2  , PIN_HIGH);
DIO_WriteChannel(PORTB_PIN3  , PIN_HIGH);
DIO_WriteChannel(PORTD_PIN6  , PIN_LOW);
DIO_WriteChannel(PORTD_PIN7  , PIN_HIGH);
	
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Relay_Stage_Five  (void)
{
	DIO_WriteChannel(PORTB_PIN1  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN2  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN3  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN6  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN7  , PIN_LOW);
	
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Relay_Stage_Six  (void)
{
	DIO_WriteChannel(PORTB_PIN1  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN2  , PIN_HIGH);
	DIO_WriteChannel(PORTB_PIN3  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN6  , PIN_HIGH);
	DIO_WriteChannel(PORTD_PIN7  , PIN_LOW);
	
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
