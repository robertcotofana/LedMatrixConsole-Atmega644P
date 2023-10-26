#include <avr/io.h>
#include <util/delay.h>

#define LedPort 		PORTD
#define LedDDR  		DDRD

//#define ColPort 		PORTA
//#define ColDDR  		DDRA

#define LedData 		PD2
#define ShRegClk 		PD5
#define ShRegClear 		PD6 // keep HIGH
#define Latch 			PD4
#define EN 				PD3 // keep LOW

//#define Bz 				PD7

//#define BtnPort			PORTC
//#define BtnDDR			DDRC

//#define UpBtn			PC2
//#define LeftBtn			PC3
//#define RightBtn		PC4
//#define DownBtn			PC5
//#define OkBtn			PC6
//#define EscBtn			PC7

void main() {
	//init ports
	
	//BtnDDR = 0b00000011;
	
	//ColDDR = 0b11111111;
	//ColPort = 0b00000000;
	
	LedDDR = (1 << LedData)|(1 << ShRegClk)|(1 << ShRegClear)|(1 << Latch)|(1 << EN);
	
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
	

	//setPixel(1,1,7,7);
	
	
	while(1) {
		
		uint8_t red = 0b00000001;
		uint8_t green = 0b01110111;
		uint8_t blue = 0b01110111;
		
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
		
		for (uint8_t i = 0; i < 8; i++) {
			if (blue & 0b10000000) {
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
			blue = blue << 1;
		}
		
		// latch the shift register
		LedPort |= (1 << Latch);
		_delay_ms(10);
		LedPort &= (~(1 << Latch));
		_delay_ms(10);
		
		//ColPort = ColPort >> 1;
		//_delay_ms(100);
		
		//if (ColPort == 0) ColPort = 0b10000000;
	}
	
}

/*
void setPixel(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2) {
	// take row and col values and turn on the led
	
	uint16_t rowData = 0; 
	rowData = (1 << row1)|(1 << row2);
	
	for (uint16_t i = 0; i < 16; i++) {
		if (i & rowData) {
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
		
		rowData = rowData << 1;
	}
	
	// latch the shift register
	LedPort |= (1 << Latch);
	_delay_ms(1);
	LedPort &= (~(1 << Latch));
	_delay_ms(1);
	
	ColPort = (1 << col1);
	ColPort |= (1 << col2);
	
	
}
*/