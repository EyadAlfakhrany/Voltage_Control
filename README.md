# Analysis and Control of a Standalone Synchronous Generator Driven by Wind

This project focuses on the **analysis and control of a standalone synchronous generator** powered by wind energy. The system aims to monitor and regulate the generator's output parameters such as voltage, current, and power, ensuring stable and reliable performance.

---

## Project Description

The project implements a control system using the ATmega32 microcontroller to manage a standalone synchronous generator driven by wind. It includes real-time measurement of electrical parameters using sensors, displaying these parameters on an LCD, and controlling load or generator operation via relays based on measured values.

Key functionalities include:

- Monitoring RMS voltage and current from the generator.
- Calculating power output with consideration of power factor.
- Controlling switching stages to maintain optimal generator operation.
- Providing visual and audible alarms for abnormal conditions.
- User interaction through push buttons to toggle display modes on the LCD.

---

## Hardware Components

| Component                    | Description                        |
|-----------------------------|----------------------------------|
| ATmega32 Microcontroller     | Core controller                  |
| LV25 Voltage Sensor          | Voltage measurement              |
| YHDC SCT-013-100 Current Transformer (CT) | Current measurement            |
| 16x2 LCD Display             | Visual feedback                  |
| Push Buttons (2 units)       | User input for display control   |
| Relay Modules               | Load or capacitor bank control   |
| Buzzer                      | Audible alarm                    |
| Status LEDs (Red and Blue)   | Visual alarm indicators          |

---

## Software Features

- Acquisition of voltage and current through ADC.
- RMS value calculations with calibration and error compensation.
- Power computation considering the power factor.
- Multi-stage relay control to protect and optimize generator performance.
- Alarm signaling through buzzer and LEDs.
- User interface to switch between RMS voltage, RMS current, and power display modes.

---

## Usage Instructions

1. Connect sensors and actuators to the microcontroller as specified.
2. Power the system to begin measurements and control.
3. Use **Button 1** to toggle the LCD between RMS voltage and RMS current.
4. Use **Button 2** to display the calculated power output.
5. The system automatically controls relays to maintain safe and efficient operation.

---

## Development Environment

- Microcontroller: ATmega32
- Programming Language: Embedded C
- IDE: Atmel Studio / Microchip Studio
- Programmer: USBasp or AVR ISP

---

## Author

Eyad Alfakhrany  
Tanta University - 2024  
Embedded Systems Engineer

---

