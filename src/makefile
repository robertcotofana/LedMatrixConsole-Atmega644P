help:
	@echo 'Help details:'
	@echo 'hex: compile hex file'
	@echo 'flash: install hex file'
	@echo 'default: compile hex and install'

default: hex flash	
	
hex:
	avr-gcc -Os -DF_CPU=16000000 -mmcu=atmega644p -c console.c
	avr-gcc -DF_CPU=16000000 -mmcu=atmega644p -o console.elf console.o
	avr-objcopy -O ihex console.elf console.hex
	del console.o
	del console.elf
	
flash:
	avrdude -c usbasp-clone -p m644p -U flash:w:console.hex
	
