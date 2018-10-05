#include <avr/io.h>
#include <util/delay.h>
#include <tot/all.h>

int main(void) {
	DDRB   = 0xFF;
	
	while (1) {
		PORTB = ~PORTB;
		_delay_ms(500);
	}
}
