/*
 * KeyPad.c
 *
 * Created: 10/3/2023 8:12:55 PM
 * Author: EyadA
 */ 

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyPad_Core.h"

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
void Keypad_Init(void)
{
	DIO_WriteChannel( KEYPAD_ROW_0, PIN_HIGH);
	DIO_WriteChannel( KEYPAD_ROW_1, PIN_HIGH);
	DIO_WriteChannel( KEYPAD_ROW_2, PIN_HIGH);
	DIO_WriteChannel( KEYPAD_ROW_3, PIN_HIGH);
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
uint8 Keypad_GetValue(void)
{
	uint8 ROW_LOC = 0 , COL_LOC = 0 , Button_Val = 0 , Temp_Val = 0;
	
	for(ROW_LOC = KEYPAD_ROW_START ; ROW_LOC <= KEYPAD_ROW_END ; ROW_LOC++)
	{
		DIO_WriteChannel(ROW_LOC , PIN_LOW);
		
		for(COL_LOC = KEYPAD_COL_START ; COL_LOC <= KEYPAD_COL_END ; COL_LOC++)
		{
			Temp_Val = DIO_ReadChannel(COL_LOC);
			
			if(Temp_Val == 0)
			{
				Button_Val = Keypad_Values[ROW_LOC - KEYPAD_ROW_START][COL_LOC - KEYPAD_COL_START];
				
				while(Temp_Val == 0)
				{
					Temp_Val = DIO_ReadChannel(COL_LOC);
				}
				_delay_ms(10);
			}
		}
		DIO_WriteChannel(ROW_LOC , PIN_HIGH);
	}
	
	return Button_Val;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
