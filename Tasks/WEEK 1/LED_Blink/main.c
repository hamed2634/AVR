//snake effect
//Author : Hamed


#include <util/delay.h>
typedef unsigned char u8;

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x3B)

#define setBit(x,n) (x |= (1 << n))
#define clrBit(x,n) (x &= ~(1 << n))
#define getBit(x,n) ((x >> n) & 1)


int main(void)
{
	//Setup PinMode A0 As output
	setBit(DDRA,0);

	//Super Loop
	while(1){
		//Write High on A0 PIN
		setBit(PORTA,0);

		//delay
		_delay_ms(300);

		//Write Low on A0 PIN
		clrBit(PORTA,0);

		//delay
		_delay_ms(300);
	}

	return 0;
}
