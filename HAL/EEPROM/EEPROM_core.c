/*
 * EEPROM_core.c
 *
 * Created: 12/1/2023 11:43:24 AM
 *  Author: eiadA
 */ 

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EEPROM_core.h"

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
void EEPROM_WriteByte(uint8 Data , uint8 Addresss , uint8 Byte_Loc)
{
    I2C_StartCndition();
	
	I2C_SlaveAddress_WriteOperation(Addresss);
	
	I2C_WriteByte(Byte_Loc);
	
	I2C_WriteByte(Data);
	
	I2C_StopCondition();
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
void EEPROM_WriteMultipleByte(uint8 *Data,uint8 Data_Size  , uint8 Addresss , uint8 Byte_Loc)
{
	uint8 Data_cnt = 0;
	
	 I2C_StartCndition();
	 
	 I2C_SlaveAddress_WriteOperation(Addresss);
	 
	 I2C_WriteByte(Byte_Loc);
	 
	 while (Data_cnt < Data_Size)
	 {
		 

      	 I2C_WriteByte(Data[Data_cnt]);
		  
		 Data_cnt ++;

	 }
	 
	 I2C_StopCondition();
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
uint8 EEPROM_ReadByte( uint8 Addresss , uint8 Byte_Loc)
{
	uint8 data =0;
	
	 I2C_StartCndition();
	 
	 I2C_SlaveAddress_WriteOperation(Addresss);
	 
	 I2C_WriteByte(Byte_Loc);
	 
	 I2C_RpeatedStart();
	  
	 I2C_SlaveAddress_ReadOperation(Addresss);
	 
	 data =I2C_ReadByte();
	  
	 I2C_StopCondition();
	 
     return data ;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
