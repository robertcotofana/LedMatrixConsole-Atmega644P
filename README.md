# Led matrix console w/ Atmega644P
 This is a game console with a red/green led matrix controlled by a microcontroller.
 ICs used: ATmega644P running at 16 MHz, SN74HC595 and ULN2803 for driving the LEDs. 
 Other parts used: current limiting resistors, buttons for controlling the games and a buzzer for sound feedback.

# Code
The code is written in C compiled with avr-gcc and uploaded to the board with avrdude and usbasp.
A makefile is provided to ease the compilation and upload process.

# KiCad schematic
Latest snapshot of the schematic:
![schematic](https://github.com/robertcotofana/LedMatrixConsole-Atmega644P/blob/dev/schematic/schematic.png)

# CAD model
![enclosure](https://github.com/robertcotofana/LedMatrixConsole-Atmega644P/blob/dev/enclosure/enclosure.png)
