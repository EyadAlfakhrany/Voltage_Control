# Voltage_Control

This project implements a **capacitor bank voltage control system** using the ATmega32 microcontroller. The system monitors voltage and current using sensors, controls capacitor bank stages to stabilize voltage, and displays real-time measurements on an LCD screen.

---

## Project Description

The main goal of this project is to maintain a stable voltage across capacitors by controlling switching stages of a capacitor bank. This is achieved by continuously measuring the system's RMS voltage and current, calculating power, and activating the appropriate relay stages.

Two sensors are used:

- **LV25 Voltage Sensor** for voltage measurement
- **YHDC SCT-013-100 Current Transformer (CT)** for current measurement

The user can interact with the system using two push buttons:

- **Button 1:** Toggles the LCD display between RMS voltage and RMS current.
- **Button 2:** Switches the LCD display to show calculated power.

---

## Features

- Real-time RMS voltage and current measurement.
- Power calculation with configurable power factor.
- Multi-stage relay activation for capacitor bank switching.
- Audible buzzer and LED indicators for alarms and warnings.
- User-friendly interface with two buttons to switch display modes.

---

## Hardware Components

| Component                   | Description                         |
|-----------------------------|-----------------------------------|
| ATmega32 Microcontroller    | Main controller                    |
| LV25 Voltage Sensor         | Voltage sensing                    |
| YHDC SCT-013-100 CT         | Current sensing                   |
| 16x2 LCD Display            | Shows voltage, current, and power readings |
| Push Buttons (x2)           | For display mode selection         |
| Relay Modules               | Controls capacitor bank stages     |
| Buzzer                     | Audible alarm                      |
| LEDs (Red and Blue)         | Visual alarm indicators            |

---

## Software Overview

- Continuously samples analog voltage and current signals via ADC.
- Calculates RMS values and applies error correction.
- Controls capacitor bank relay stages based on voltage thresholds.
- Provides audible and visual alarms when necessary.
- Allows user to toggle display information on the LCD.

---

## Usage

1. Connect sensors to designated ADC input pins.
2. Power the system and initialize.
3. Use **Button 1** to toggle between displaying RMS voltage and RMS current.
4. Use **Button 2** to view power consumption.
5. System automatically switches capacitor stages to maintain stable voltage.

---

## Development Environment

- Microcontroller: ATmega32
- Language: Embedded C (AVR GCC)
- IDE: Atmel Studio / Microchip Studio
- Programmer: USBasp or AVR ISP

---

## Author

Eyad Alfakhrany  
Tanta University - 2024  
Embedded Systems Engineer

---

