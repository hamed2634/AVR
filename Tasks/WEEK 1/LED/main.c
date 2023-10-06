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
	//pin 4 out
	setBit(DDRA,4);
	setBit(PORTA,4);
	while(1){
		_delay_ms(500);
	}
	return 0;
}
