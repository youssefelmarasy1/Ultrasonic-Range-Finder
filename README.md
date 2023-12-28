# Ultrasonic Range Finder Project

This project implements an ultrasonic range finder using the ATMega328P microcontroller, the HC-SR04 ultrasonic sensor, and the WC1602A LCD display. The main purpose of this system is to measure the distance between the ultrasonic sensor and an object in front of it. The measured distance is then displayed on the WC1602A LCD screen in real-time.

## Features

- Utilizes the ATMega328P microcontroller, HC-SR04 ultrasonic sensor, and WC1602A LCD display to measure distances.
- Displays the measured distance on the WC1602A LCD screen.
- Captures both rising and falling edges to calculate the time period of the ultrasonic wave.
- Provides a feature to dynamically update and display the maximum and minimum distances when a push button is pressed.
- Ensures accurate distance calculations within the range of 3 cm to 70 cm.

## Hardware Requirements

- ATMega328P Microcontroller
- HC-SR04 Ultrasonic Sensor
- WC1602A LCD Display
- Push Button
## Table of Contents
- [Prerequisites](#prerequisites)
- [How It Works](#how-it-works)
- [Circuit Setup](#circuit-setup)
- [AVR Microcontroller Configuration](#avr-microcontroller-configuration)
- [Compiling and Flashing](#compiling-and-flashing)
- [Author](#author)
- [License](#license)

## Prerequisites
- AVR Microcontroller: ATMega328P
- MPLABX IDE
- AVR Programmer (e.g., USBasp)
- Ultrasonic Sensor
- Push Button
- LCD Display
- Resistors and jumper wires

## How It Works
The program initializes the necessary hardware peripherals, including the ultrasonic sensor, push button, and LCD display. It utilizes the Timer/Counter1 module to capture the time between the rising and falling edges of the ultrasonic pulse. The distance is then calculated based on the time of flight. The LCD displays the measured distance and updates the maximum and minimum values when a push button is pressed.

## Circuit Setup
1. Connect the ATMega328P to the ultrasonic sensor, push button, and LCD display.
2. Connect the ultrasonic sensor's trigger and echo pins to appropriate ATMega328P pins.
3. Connect the push button to an ATMega328P pin.
4. Connect the LCD display to the ATMega328P pins.
5. Add resistors and wires as needed.

## AVR Microcontroller Configuration
- **Clock Frequency:** 14.7456 MHz (defined by `F_CPU`)
- **Used Pins:**
  - PB0 (Pin 14): Echo (Ultrasonic Sensor)
  - PB1 (Pin 15): Trigger (Ultrasonic Sensor)
  - PB2 (Pin 16): Push Button
  - PB3 (Pin 17): LCD Data
  - PB4 (Pin 18): LCD Register Select
  - PB5 (Pin 19): LCD Enable

## Compiling and Flashing
1. Open the MPLABX IDE project.
2. Compile the C code using the IDE.
3. Program the ATMega328P using an AVR programmer.
4. Power up the circuit and observe the measured distance on the LCD.

## Getting Started

1. Clone the repository.
2. Set up the ATMega328P microcontroller and connect the HC-SR04 ultrasonic sensor, WC1602A LCD display, and push button as per the provided circuit.
3. Compile and upload the code to the ATMega328P microcontroller.
4. Run the system and observe real-time distance measurements on the WC1602A LCD screen.

## Usage

- Press the push button to update and display the maximum and minimum distances.
- Ensure that the measured distance is within the accurate range of 3 cm to 70 cm.

## License

This project is licensed under the [Apache License](LICENSE).
