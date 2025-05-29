# Embedded Power Monitoring System Using ATmega32

This project implements a real-time power monitoring system using the ATmega32 microcontroller. It measures voltage and current through ADC inputs, calculates RMS values, applies calibration corrections, controls relays based on voltage thresholds, and displays measurements on an LCD screen. Additionally, it uses buzzer and LEDs for alerts.

---

## Features

- Real-time voltage and current sensing using ADC
- RMS calculation and error correction for accurate measurement
- Power calculation with configurable power factor
- Multi-stage relay control based on voltage thresholds
- Audible and visual alerts (buzzer and LEDs)
- User interaction via push buttons to toggle display modes
- Modular code architecture with separate drivers for peripherals

---

## Hardware Components

| Component           | Description                         |
|---------------------|-----------------------------------|
| ATmega32 MCU        | Main controller                   |
| Voltage Sensor      | Analog voltage measurement input  |
| Current Sensor      | Analog current measurement input  |
| 16x2 LCD Display    | Displays voltage, current, and power readings |
| Buzzer              | Audible alert device               |
| LEDs (Red & Blue)   | Visual indicators for warnings     |
| Push Buttons        | User interface for display toggling|
| Relays              | Controlled switching based on voltage thresholds |
| Power Supply        | 5V regulated                      |

---

## Software Overview

The system operates by:

1. Continuously sampling voltage and current sensor signals through ADC channels.
2. Computing RMS values from sampled data.
3. Applying error correction algorithms to improve measurement accuracy.
4. Controlling relay stages based on preset RMS voltage thresholds.
5. Providing user feedback through buzzer and LED signals on alarm conditions.
6. Allowing the user to switch between displaying voltage/current or power readings on the LCD via buttons.

---

## Key Functions

- `Fun_Safety()`: Activates buzzer and red LED when voltage exceeds critical levels.
- `Buz_LED()`: Blinks blue LED and buzzer for alert signals.
- `map()`: Maps ADC readings from one range to another for sensor calibration.
- `convertToCurrent()`: Converts ADC voltage readings to current values based on calibration.
- `Error_Solve_Voltage()` & `Error_Solve_Current()`: Apply corrections to measured voltage and current values to account for sensor or measurement inaccuracies.

---

## Development Environment

- Microcontroller: ATmega32 (8-bit AVR)
- Language: Embedded C (AVR-GCC)
- IDE: Atmel Studio / Microchip Studio
- Programmer: USBasp / AVR ISP
- Libraries: Custom hardware abstraction layers for peripherals (ADC, LCD, Buttons, Relay, etc.)

---

## How to Use

1. Connect voltage and current sensors to the designated ADC input channels.
2. Power the system with regulated 5V supply.
3. The LCD will display voltage and current readings by default.
4. Use the first push button to toggle between voltage/current display modes.
5. Use the second push button to switch the display to power measurement mode.
6. The system will sound buzzer and light LEDs on alarm conditions and switch relay stages accordingly.

---

## Future Improvements

- Integrate data logging to external memory or PC via UART
- Add communication interface (e.g., Bluetooth or Wi-Fi) for remote monitoring
- Implement more sophisticated power factor measurement
- Add calibration menu accessible via keypad input

---

## License

This project is licensed under the MIT License.

---

## Author

EyadA  
Embedded Systems Engineer  
[GitHub](#) | [LinkedIn](#)

---

