/*
 * PORT_LCfg.c
 *
 * Created: 9/16/2023 12:15:59 PM
 * Author: EyadA
 */ 
#include "PORT_LCfg.h"


PIN_PARAMETERS PORT_Intialization[DEFINED_PINS] = 
{
	/*LCD Pins*/
	{  PORTA_PIN1    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN2    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN4    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN5    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN6    ,  PIN_DIR_OUTPUT   },
	{  PORTC_PIN6	 ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN3    ,  PIN_DIR_OUTPUT   },

	/*KeyPad Pins
	{  PORTB_PIN4    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN5    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN6    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN7    ,  PIN_DIR_OUTPUT   },
	{  PORTD_PIN2    ,  PIN_DIR_INPUT    },
	{  PORTD_PIN3    ,  PIN_DIR_INPUT    },
	{  PORTD_PIN4    ,  PIN_DIR_INPUT    },
	{  PORTD_PIN5    ,  PIN_DIR_INPUT    }*/
	{  PORTC_PIN4    ,  PIN_DIR_OUTPUT   },
	{  PORTC_PIN3    ,  PIN_DIR_OUTPUT   },
	
	//{  PORTB_PIN0    ,  PIN_DIR_OUTPUT   },
		/*RELAYS*/
	{  PORTB_PIN1    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN2    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN3    ,  PIN_DIR_OUTPUT   },
	{  PORTD_PIN6    ,  PIN_DIR_OUTPUT   },
	{  PORTD_PIN7    ,  PIN_DIR_OUTPUT   },
	
	/*{  PORTD_PIN4    ,  PIN_DIR_OUTPUT   },
	{  PORTD_PIN6    ,  PIN_DIR_INPUT    },
	{  PORTB_PIN0    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN1    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN2    ,  PIN_DIR_OUTPUT   },*/
		/*
	{  PORTB_PIN4    ,  PIN_DIR_INPUT   },	
	{  PORTB_PIN5    ,  PIN_DIR_INPUT   },
    {  PORTB_PIN6    ,  PIN_DIR_OUTPUT  },
	{  PORTB_PIN7    ,  PIN_DIR_INPUT   }*/
	{  PORTB_PIN0    ,  PIN_DIR_INPUT   },
	//red led
	{  PORTC_PIN0    ,  PIN_DIR_OUTPUT  },
	//blue led	
	{  PORTC_PIN1    ,  PIN_DIR_OUTPUT  },
	/*ADC*/
	{  PORTA_PIN0    ,  PIN_DIR_INPUT   },
	{  PORTA_PIN3    ,  PIN_DIR_INPUT   },	
	{  PORTA_PIN7    ,  PIN_DIR_INPUT   }
			
				
			
};