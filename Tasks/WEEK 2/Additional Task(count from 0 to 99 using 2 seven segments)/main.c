
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


u8 commonCathode[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

int main(){
	//Set PORTA, PORTB As Output
	DDRA = 0xFF;
	DDRB = 0xFF;

	//Set All Pins To Low
	PORTA = 0;
	PORTB = 0;

	u8 Counter = 0;
	while(1){
		Counter %= 100;
		PORTB = commonCathode[Counter % 10];
		if(Counter / 10) PORTA = commonCathode[Counter / 10];
		else PORTA = 0;
		_delay_ms(100);
		Counter++;
	}

}
