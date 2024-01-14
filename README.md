# Arduino Solar Tracker

## Project Overview
This Arduino Solar Tracker project is designed to automatically adjust the position of a solar panel (or any object requiring optimal sun exposure) to maximize its exposure to sunlight. Utilizing four Light Dependent Resistors (LDRs) and two servo motors, the system dynamically tracks the sun's position and aligns the panel for maximum efficiency.

![circuit](./circuit.png)

## Components
- Arduino Uno (or similar Arduino board)
- 2 x Servo Motors
- 4 x Light Dependent Resistors (LDRs)
- Assorted Wires
- Breadboard
- Solar Panel (or a proxy object for demonstration)

## Circuit Connections
1. **Servo Motors**: Connect the horizontal servo to digital pin 9 and the vertical servo to digital pin 10 of the Arduino.
2. **LDRs**: Connect the four LDRs to the analog pins A0, A1, A2, and A3. Ensure each LDR is connected with a pull-down resistor.

## Installation
1. Assemble the circuit as per the above connections.
2. Attach the solar panel or object to the servo motors ensuring unrestricted movement.
3. Upload the provided code to the Arduino.

## Code Overview
The Arduino code continuously reads the light intensity from the four LDRs. Based on these readings, it adjusts the angles of the two servos to position the panel towards the highest light source. The code consists of two main parts:
- `setup()`: Initializes servo positions and attaches them to their respective pins.
- `loop()`: Continuously reads LDR values, calculates average light intensity on different sides, and adjusts servo positions accordingly.

## Usage
After uploading the code to the Arduino, the system will automatically start tracking the light source. Ensure the LDRs are unobstructed to accurately detect the light.

## Customization
- Adjust the `servohLimitHigh`, `servohLimitLow`, `servovLimitHigh`, and `servovLimitLow` variables to set the range of motion for the servos.
- Modify the `tol` variable to set the sensitivity of the tracker.