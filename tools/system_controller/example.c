/*
	Simple example of toggling pins on ATMega128

	Programmed by William Harrington
 */

/* this stuff needs to be here */
#include <avr/io.h>
#include <util/delay.h>

/* main function, bruh */
int main (void){

	/* set all pins of PORTF for output*/
	DDRF = 0xFF;

	/* in embedded, you never return son. */
	while (1) {
		/* set all pins of PORTF high */
		PORTF = 0xFF;

		/* delay so your puny human eyes can see it */
		_delay_ms(500);

		/* set all pins of PORTF low */
		PORTF = 0x00;

		/* delay so your puny human eyes can see it */
		_delay_ms(500);
	}

	/* this don't happen in your world but if it did we'd return 0 */
	return 0;
}
