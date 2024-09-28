## Timer-Control-Relay

## Overview

This project demonstrates how to control a relay module using a timer on an Arduino. The system includes a Liquid Crystal I2C Display to show the countdown, push buttons to start/stop the timer, and a relay to control a load (like a light bulb). The buzzer is used to alert when the timer reaches zero.

## Components Used
- Arduino Nano/Uno
- Liquid Crystal I2C Display (16x2)
- Relay Module
- Buzzer
- Push Buttons (2x)
- Breadboard
- Bulb Holder Socket
- Wires
  
## Wiring

- **Relay Module**:
  - `VCC` -> 5V
  - `GND` -> GND
  - `IN` -> Pin 7 (to control the relay)

- **I2C LCD Display**:
  - `SDA` -> A4
  - `SCL` -> A5
  - `VCC` -> 5V
  - `GND` -> GND

- **Push Buttons**:
  - **Start Button**: One side to Pin 2 (digital input), the other to GND.
  - **Stop Button**: One side to Pin 3 (digital input), the other to GND.

- **Buzzer**:
  - `VCC` -> Pin 6
  - `GND` -> GND

- **Bulb Holder Socket**:
  - Connect the relay output to the bulb socket to control the bulb based on the timer.

## How It Works

1. The **Start button** initiates the timer. The timer is set to run for 5 seconds (this can be modified).
2. When the timer starts, the relay is activated to power the bulb or any connected device.
3. When the timer reaches zero, the relay is turned off, and the buzzer is activated to signal the end of the timer.
4. The **Stop button** can halt the timer at any point, turning off both the relay and buzzer.
5. The remaining time is displayed on the LCD in seconds during the countdown.

## Code Explanation

- The **`LiquidCrystal_I2C`** library is used to control the I2C LCD display.
- A simple timer mechanism is implemented using the **millis()** function to measure elapsed time.
- The relay is controlled based on the timer status, and the buzzer is activated when the timer ends.
- Two push buttons are used to start and stop the timer.

## Setup Instructions

1. Connect the components according to the wiring instructions provided.
2. Upload the provided code to the Arduino using the Arduino IDE.
3. Power up the system, and you can control the timer using the push buttons. The LCD will display the timer status.

## Customization

- **Timer Duration**: Modify the `timerDuration` variable in the code to change the length of the timer.
- **Relay Load**: Connect any device to the relay (like a light bulb or fan) that needs to be controlled by the timer.

## Application Ideas

- **Appliance Timer**: Use this project to create an automatic shutoff timer for lights or fans.
- **Cooking Timer**: This system can be used as a kitchen timer for controlling appliances like ovens or microwaves.
- **Home Automation**: Integrate the relay system into a smart home to automate lights or other devices.

## Libraries Required

- **LiquidCrystal_I2C** library: For controlling the I2C-based LCD display.

## License

This project is licensed under the MIT License.
