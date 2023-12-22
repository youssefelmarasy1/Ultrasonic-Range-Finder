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

## Getting Started

1. Clone the repository.
2. Set up the ATMega328P microcontroller and connect the HC-SR04 ultrasonic sensor, WC1602A LCD display, and push button as per the provided circuit.
3. Compile and upload the code to the ATMega328P microcontroller.
4. Run the system and observe real-time distance measurements on the WC1602A LCD screen.

## Usage

- Press the push button to update and display the maximum and minimum distances.
- Ensure that the measured distance is within the accurate range of 3 cm to 70 cm.

## License

This project is licensed under the [MIT License](LICENSE).
