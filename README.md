# Purpose
Sense sound using Arduino.

# References
http://learn.adafruit.com/adafruit-microphone-amplifier-breakout/overview

# Equipment
## Hardware
Arduino Duemilanove w/ ATmega328 (Duemilanove="2009")

Electret Microphone Amplifier - MAX4466 with Adjustable Gain
Adafruit ID: 1063

## Software
Measuring Sound Levels by Bill Earl
http://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels

# Results
Copied file from Adafruit and modified to log bar graph.

## Hardware Connect

| Sensor | Arduino Duemilanove Pin | Arduino Leonardo Pin | Arduino Due Pin  |
| ------ | ----------------------- | -------------------- | ---------------- |
| VCC    | 3.3V                    | 3.3V                 | 3.3V             |
| GND    | GND                     | GND                  | GND              |
| OUT    | AIN0                    | AIN0                 | AIN0             |
http://arduino.cc/en/Reference/Wire
