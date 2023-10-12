
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

#define DDRD *((u8*)0x31)
#define PORTD *((u8*)0x32)
#define PIND *((volatile u8*)0x30)

#define setBit(x,n) (x |= (1 << n))
#define clrBit(x,n) (x &= ~(1 << n))
#define getBit(x,n) ((x >> n) & 1)

u8 commonCathode[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Write(u8 value){
	//Write on The 7 Segment
	PORTD = commonCathode[value % 10];
	if(value / 10) PORTC = commonCathode[value / 10];
	else PORTC = 0;
}

int main(){
	u8 Counter = 0;

	//Set PORTC, PORTD As Output
	DDRC = 0xFF;
	DDRD = 0xFF;

	//Set All Pins To Low
	PORTC = 0;
	PORTD = 0;

	//Set A0, A1 Pins As Input
	DDRA = 0;

	//Pull A0, A1 Pins Up
	PORTA = 0x03;

	while(1){

		//Update Counter
		if(!getBit(PINA,0) && Counter < 99) {
			Counter++;

			//Write on The 7 Segment
			Write(Counter);

			//Wait Until Button Is Not Pushed
			while(!getBit(PINA,0));
		}
		else if(!getBit(PINA,1) && Counter > 0) {
			Counter--;

			//Write on The 7 Segment
			Write(Counter);

			//Wait Until Button Is Not Pushed
			while(!getBit(PINA,1));
		}
	}
}
