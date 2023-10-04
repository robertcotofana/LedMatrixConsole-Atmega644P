#include <avr/io.h>
#include <util/delay.h>

#define LedPort 		PORTD
#define LedDDR  		DDRD

#define ColPort 		PORTA
#define ColDDR  		DDRA

#define LedData 		PD0
#define ShRegClk 		PD1 
#define ShRegClear 		PD2 // keep HIGH
#define Latch 			PD3
#define EN 				PD4 // keep LOW

#define Bz 				PD7

#define BtnPort			PORTC
#define BtnDDR			DDRC

#define UpBtn			PC2
#define LeftBtn			PC3
#define RightBtn		PC4
#define DownBtn			PC5
#define OkBtn			PC6
#define EscBtn			PC7

void main() {
	//init ports
	
	BtnDDR = 0b00000011;
	
	ColDDR = 0b11111111;
	ColPort = 0b10000000;
	
	LedDDR = (1 << LedData)|(1 << ShRegClk)|(1 << ShRegClear)|(1 << Latch)|(1 << EN)|(1 << Bz);
	
	LedPort |= 1 << ShRegClear;
	LedPort &= (~(1 << EN));
	/*
	while(1) {
		LedPort |= (1 << Bz);
		_delay_us(100);
		LedPort &= (~(1 << Bz));
		_delay_us(50);	
	}
	*/
	
	while(1) {
		uint8_t red = 0b10101010;
		uint8_t green = 0b01010101;
		
		for (uint8_t i = 0; i < 8; i++) {
			if (red & 0b10000000) {
				// output high
				LedPort |= 1 << LedData;
			} else {
				//output low
				LedPort &= (~(1 << LedData));
			}
			
			// toggle the clock
			LedPort |= (1 << ShRegClk);
			_delay_ms(1);
			LedPort &= (~(1 << ShRegClk));
			_delay_ms(1);
			red = red << 1;
		}
		
		for (uint8_t i = 0; i < 8; i++) {
			if (green & 0b10000000) {
				// output high
				LedPort |= 1 << LedData;
			} else {
				//output low
				LedPort &= (~(1 << LedData));
			}
			
			// toggle the clock
			LedPort |= (1 << ShRegClk);
			_delay_ms(1);
			LedPort &= (~(1 << ShRegClk));
			_delay_ms(1);
			green = green << 1;
		}
		
		// latch the shift register
		LedPort |= (1 << Latch);
		_delay_ms(1);
		LedPort &= (~(1 << Latch));
		_delay_ms(1);
		
		ColPort = ColPort >> 1;
		_delay_ms(100);
		
		if (ColPort == 0) ColPort = 0b10000000;
	}
	
}