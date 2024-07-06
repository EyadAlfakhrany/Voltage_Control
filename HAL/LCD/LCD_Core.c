/*
 * LCD_Core.c
 *
 * Created: 9/23/2023 12:04:14 PM
 * Author: EyadA
 */ 


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"

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
void LCD_Init(void)
{
	#if (LCD_OPERATION_MODE == 4)
	/*LCD 4 BIT MODE*/
	LCD_WriteCommand(0X33);
	LCD_WriteCommand(0X32);
	LCD_WriteCommand(0X28);
	/*?????????*/
	LCD_WriteCommand(0X0C);
	LCD_WriteCommand(0X01);
	LCD_WriteCommand(0X06);
	LCD_WriteCommand(0X02);
	
	#elif (LCD_OPERATION_MODE == 8)
	
	#endif
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
void LCD_WriteCommand(uint8 cmd)
{
	DIO_WriteChannel(LCD_RS_PIN , PIN_LOW);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(cmd , 4));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(cmd , 5));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(cmd , 6));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(cmd , 7));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);

	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(cmd , 0));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(cmd , 1));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(cmd , 2));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(cmd , 3));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);
	
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
void LCD_WriteChar(uint8 data)
{
	DIO_WriteChannel(LCD_RS_PIN , PIN_HIGH);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(data , 4));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(data , 5));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(data , 6));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(data , 7));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);

	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(data , 0));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(data , 1));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(data , 2));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(data , 3));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);	
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
void LCD_WriteString(uint8* str)
{
	uint8 i = 0;
	
	while(str[i] != '\0')
	{
      LCD_WriteChar(str[i]);
	  i++;	
    }

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
void LCD_WiteInteger(sint32 num)
{
uint32 Temp = 1;
/*if the number is zero*/
if(num == 0)
{
	
	LCD_WriteChar('0');
}
/*if the number is negative*/
if(num < 0)
{
	num *= -1;
	LCD_WriteChar('-');
}

/*Mirror the number*/
while(num != 0)
{
	Temp = (Temp * 10) + (num % 10);
	num /= 10;
}

/*Display Temp*/
while(Temp != 1)
{
	LCD_WriteChar((Temp%10) + 48);
	Temp /= 10;
}
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
void LCD_GoTo(uint8 Row , uint8 Col)
{
	uint8 LCD_Loc[2] = {0x80 , 0xc0};
	
	LCD_WriteCommand(LCD_Loc[Row] + Col );
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
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
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
void LCD_WriteCustomCharacter(void)
{
	uint8 Custom_Char_Row_Loc = 0;
	uint8 Custom_Char_Col_Loc = 0;
	
	LCD_WriteCommand(0X40);
	
	for(Custom_Char_Row_Loc = 0 ; Custom_Char_Row_Loc < 8 ; Custom_Char_Row_Loc++)
	{
	 for(Custom_Char_Col_Loc = 0 ; Custom_Char_Col_Loc < 8 ; Custom_Char_Col_Loc++)
	 {
		 LCD_WriteChar(LCD_CUSTOM_CHARACTERS_g[Custom_Char_Row_Loc][Custom_Char_Col_Loc]);
	 }	
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
