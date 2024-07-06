/*
 * First LED Lab.c
 *
 * Created: 9/9/2023 1:43:45 PM
 * Author: EyadA
 */ 

/*.........................................................*/
/* Include necessary header files */
#include "LED_Core.h"
#include "Button_Core.h"
#include "SevSeg_Core.h"
#include "PORT_Core.h"
#include "DIO_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "IRQH_Core.h"
#include "ADC_Core.h"
#include "GPT_Core.h"
#include "PWM_Core.h"
#include "DcMotor_Core.h"
#include "Ultrasonic_Core.h"
#include "ICU_Core.h"
#include "UART_Core.h"
#include "SPI_Core.h"
#include "EEPROM_core.h"
#include "Relay.h"

/*.........................................................*/
/* External variable declarations */
extern uint32 Capture_Flag_g;
extern volatile uint32 Capture_Readings_1_g;
extern volatile uint32 Capture_Readings_2_g;
extern volatile uint32 Capture_Readings_3_g;
extern uint32 ADC_Vin_Value_mv;
extern uint8 UART_TRANSMITE_DATA[TX_BUFFER_SIZE];
extern uint8 UART_RECEIVED_DATA[7];

/*.........................................................*/
/* Function to ensure safety by activating buzzer and LED if voltage is critical */
void Fun_Safety(void) {
    if (ADC_Vin_Value_mv == 1023) {
        while (ADC_Vin_Value_mv >= 1020) {
            //ADC_Read(ADC_CHANNEL_0);
            //ADC_Read(ADC_CHANNEL_3);
            buz_ON();
            LED_Red_ON();
            _delay_ms(100);
            buz_OFF();
            LED_Red_ON();
        }
    }
}

/* Function to blink blue LED and activate buzzer */
void Buz_LED(void) {
    LED_Blue_ON();
    buz_ON();
    _delay_ms(100);
    buz_OFF();
    _delay_ms(100);
    buz_ON();
    _delay_ms(100);
    buz_OFF();
    LED_Blue_OFF();
}

/* Function to map input value from one range to another */
long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* Function to convert ADC voltage reading to current */
float convertToCurrent(long Voltage_ssensor, int adc_min, int adc_max, sint32 volt_multi_n, float volt_multi_p) {
    long volt_inst = map(Voltage_ssensor, adc_min, adc_max, volt_multi_n, volt_multi_p);
    return volt_inst;
}

/* Function to correct voltage measurement errors */
uint32 Error_Solve_Voltage(uint32 Voltage_Inst) {
    uint32 Rms_Voltage = 0;
    if (Voltage_Inst >= 95 && Voltage_Inst < 105) {
        Rms_Voltage = Voltage_Inst + 7;
    } else if (Voltage_Inst >= 115 && Voltage_Inst < 125) {
        Rms_Voltage = Voltage_Inst + 6;
    } else if (Voltage_Inst >= 125 && Voltage_Inst < 135) {
        Rms_Voltage = Voltage_Inst + 5;
    } else if (Voltage_Inst >= 135 && Voltage_Inst < 155) {
        Rms_Voltage = Voltage_Inst + 4;
    } else if (Voltage_Inst >= 155 && Voltage_Inst < 175) {
        Rms_Voltage = Voltage_Inst + 3;
    } else if (Voltage_Inst >= 175 && Voltage_Inst < 185) {
        Rms_Voltage = Voltage_Inst + 2;
    } else if (Voltage_Inst >= 185 && Voltage_Inst > 195) {
        Rms_Voltage = Voltage_Inst + 2;
    } else if (Voltage_Inst >= 225 && Voltage_Inst > 230) {
        Rms_Voltage = Voltage_Inst - 2;
    } else if (Voltage_Inst >= 232 && Voltage_Inst > 240) {
        Rms_Voltage = Voltage_Inst - 5;
    }
    return Rms_Voltage;
}

/* Function to correct current measurement errors */
uint32 Error_Solve_Current(uint32 Current_Inst) {
    uint32 Current_Voltage = 0;
    if (Current_Inst >= 95 && Current_Inst < 105) {
        Current_Voltage = Current_Inst + 7;
    } else if (Current_Inst >= 115 && Current_Inst < 125) {
        Current_Voltage = Current_Inst + 6;
    } else if (Current_Inst >= 125 && Current_Inst < 135) {
        Current_Voltage = Current_Inst + 5;
    } else if (Current_Inst >= 135 && Current_Inst < 155) {
        Current_Voltage = Current_Inst + 4;
    } else if (Current_Inst >= 155 && Current_Inst < 175) {
        Current_Voltage = Current_Inst + 3;
    } else if (Current_Inst >= 175 && Current_Inst < 185) {
        Current_Voltage = Current_Inst + 2;
    } else if (Current_Inst >= 185 && Current_Inst > 195) {
        Current_Voltage = Current_Inst + 2;
    } else if (Current_Inst >= 225 && Current_Inst > 230) {
        Current_Voltage = Current_Inst - 2;
    } else if (Current_Inst >= 232 && Current_Inst > 240) {
        Current_Voltage = Current_Inst - 5;
    }
    return Current_Voltage;
}

extern uint32 millis_return; // External variable to track milliseconds

int main(void) {
    // Initialize peripherals and variables
    PORT_Init();
    IRQH_SetGlobalInterrupts(INTERRUPT_ENABLE);
    GPT_Init();
    GPT_SetTime();
    ADC_Init();
    LCD_Init();
    Button_Init_1();
    Button_Init_2();
    buz_Init();
    LED_Init();
    Relays_Init();
    uint8 Switch_VoltageAndCurrent = 0;
    uint8 Switch_Power = 0;
    sint32 Apperant_power = 0;
	sint8 Power_Factor =0.8;
    uint8 Alarm = 0;
    uint16 counter_Adc = 0;
    uint32 Counter_Current_Average = 0;
    sint32 Voltage_Inst = 0;
    sint32 Current_Inst = 0;
    uint32 Sum_Current_Average = 0;
    uint32 Rms_Voltage = 0;
    uint32 Rms_Current = 0;
    float64 sumSquaredValues = 0.0;
    uint16 adc_max = 1023;
    uint16 adc_min = 0;
    uint32 sensorValueVoltage = 0;
    uint32 sensorValueCurrent = 0;
    float64 volt_multi = 1470.0;
    float64 volt_multi_p = volt_multi * 1.4142;
    float64 volt_multi_n = -volt_multi_p;

    while (1) {
        

		while(millis_return < 1){
			// Read current sensor value
			ADC_Read(3);
			sensorValueCurrent = ADC_Vin_Value_mv;
			Current_Inst = convertToCurrent(sensorValueCurrent, adc_min, adc_max, volt_multi_n, volt_multi_p);
			Sum_Current_Average += (Current_Inst * Current_Inst);
			Counter_Current_Average++;
			//ADC_Vin_Value_mv = 0;
			_delay_ms(1);
		}


        // Calculate RMS current
        Rms_Current = (sqrt(Sum_Current_Average / Counter_Current_Average));
        Counter_Current_Average = 0;
        Sum_Current_Average = 0;
        millis_return = 0;
		adc_max = 0;
		while (millis_return < 1) {
			// Read voltage sensor value
			ADC_Read(7);
			sensorValueVoltage = ADC_Vin_Value_mv;
			if (sensorValueVoltage > adc_max) {
				adc_max = sensorValueVoltage; // Update the maximum value if a new maximum is found
			}

			// Fun_Safety(); // Ensure safety conditions
			_delay_ms(1);

			
		}
		// Calculate RMS voltage
		Voltage_Inst = (adc_max / 4.42896);
		Rms_Voltage = Error_Solve_Voltage(Voltage_Inst);

		millis_return = 0;

        // Control relays based on RMS voltage
        if (Rms_Voltage <= 140) {
            if (Alarm != 1) {
                Buz_LED();
                Alarm = 1;
                _delay_ms(1000);
            }
            Relay_Stage_One();
        } else if (Rms_Voltage > 140 && Rms_Voltage <= 160) {
            if (Alarm != 1) {
                Buz_LED();
                Alarm = 1;
                _delay_ms(1000);
            }
            Relay_Stage_Two();
        } else if (Rms_Voltage > 160 && Rms_Voltage <= 180) {
            if (Alarm != 2) {
                Buz_LED();
                Alarm = 2;
                _delay_ms(1000);
            }
            Relay_Stage_Three();
        } else if (Rms_Voltage > 180 && Rms_Voltage <= 200) {
            if (Alarm != 2) {
                Buz_LED();
                Alarm = 2;
                _delay_ms(1000);
            }
            Relay_Stage_Four();
        } else if (Rms_Voltage > 200 && Rms_Voltage <= 220) {
            if (Alarm != 3) {
                Buz_LED();
                Alarm = 3;
                _delay_ms(1000);
            }
            Relay_Stage_Five();
        } else if (Rms_Voltage > 220) {
            if (Alarm != 3) {
                Buz_LED();
                Alarm = 3;
                _delay_ms(1000);
            }
            Relay_Stage_Six();
        }

        // Manage button presses for display switching
        if (Button_GetValue_1() == BUTTON_PRE_RELEASED) {
            LCD_Clear();
            buz_ON();
            Switch_VoltageAndCurrent++;
            _delay_ms(10);
            if(Switch_VoltageAndCurrent==2){
            Switch_VoltageAndCurrent=0;
			}
            Switch_Power = 0; // Reset power display switch
            buz_OFF();
        }

        if (Button_GetValue_2() == BUTTON_PRE_RELEASED) {
            LCD_Clear();
            buz_ON();
            Switch_Power=1;
            _delay_ms(10);
            buz_OFF();
        }
LCD_Clear();
        // Update LCD display based on current mode
        if (Switch_Power == 0) {
            switch (Switch_VoltageAndCurrent) {
                case 0:
                    LCD_GoTo(0, 0);
                    LCD_WriteString((uint8*)"Voltage: ");
                    LCD_WiteInteger(Rms_Voltage);
						LCD_GoTo(1,9);

						LCD_WiteInteger(Rms_Current);
                    break;
                case 1:
                   	LCD_GoTo(0,2);
                   	LCD_WriteString("Rms Current");
                   	LCD_GoTo(1,6);
                   	LCD_WiteInteger(Rms_Current);
                   	LCD_WriteString("mA");
                    break;
                default:
                    break;
            }
        } else if (Switch_Power == 1) {
            Apperant_power = ((Rms_Voltage * Rms_Current * Power_Factor)/1000);
            LCD_GoTo(0, 0);
            LCD_WriteString((uint8*)"Power: ");
            LCD_WiteInteger(Apperant_power);
        }
    }
}
