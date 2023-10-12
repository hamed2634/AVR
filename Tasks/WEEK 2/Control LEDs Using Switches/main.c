
#include <util/delay.h>
typedef unsigned char u8;

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB *((volatile u8*)0x36)

#define DDRC *((u8*)0x34)
#define PORTC *((u8*)0x35)
#define PINC *((volatile u8*)0x33)

#define setBit(x,n) (x |= (1 << n))
#define clrBit(x,n) (x &= ~(1 << n))
#define getBit(x,n) ((x >> n) & 1)

int main(){

	//Set B0, B1, B2 Pins As Input
	DDRB = 0;
	//Pull B0, B1, B2 Up
	PORTB = 0x07;

	//Set A0, A1 Pins As Output
	DDRA = 0x03;
	//Initial A0, A1 Pins To Low
	PORTA = 0;

	//Super Loop
	while(1){

		if(!getBit(PINB,2) || (!getBit(PINB,0) && !getBit(PINB,1))){
			PORTA = 0x03;
		}
		else if(!getBit(PINB,0)){
			setBit(PORTA,0);
			clrBit(PORTA,1);
		}
		else if(!getBit(PINB,1)){
			setBit(PORTA,1);
			clrBit(PORTA,0);
		}
		else PORTA = 0;
	}

}
