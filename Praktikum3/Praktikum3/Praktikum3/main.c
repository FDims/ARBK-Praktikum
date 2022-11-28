/*
 * Praktikum3.c
 *
 * Created: 11/26/2022 10:01:58 PM
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel- Nr : 3503937
 */ 

#include <avr/io.h>

#define F_CPU 16000000
#include <avr/interrupt.h>

#define LED PIND0

volatile uint32_t systemClock = 0;

void TC0_setUp() {							//Timer 0 verwenden
	TCCR0A = (1 << WGM01);					// enable CTC mode of Timer/Counter 0 Control Register A
	TCCR0B |= (1 << CS01) | (1 << CS00);	// set Prescaler 64
											// Prescaler = (16000000Hz . 0,001s)/2^8 = 62,5
											//closest factor = 64
											
	OCR0A = 249;							// set up Output Comparison Register A for Timer0 to generate an interrupt when timer counter and OCR0A are equals
											// OCR = F_clk / (F_TimerInterrupt x prescaler) - 1 = ( 16MHz/(1000Hz x 64) ) - 1 = 249
	TIMSK0 = (1 << OCIE0A);					// enable interrupt
}
void dir_setUp(){
	DDRD = 0xff;							// Data direction register D (D0) as output
	PORTD = 0x00;
	sei();									// set global interrupt enable
}

ISR(TIMER0_COMPA_vect) {
	systemClock++;
}

void waitFor(uint32_t ms) {
	uint32_t currentTime = systemClock + ms;
	while (systemClock < currentTime) {}
}

void waitUntil(uint32_t ms) {
	while (systemClock <= ms) {}
}

int main(void)
{
	/* Replace with your application code */
	
	dir_setUp();
	TC0_setUp();

	
	waitUntil(3000);						// wait until 3s from the beginning then turn on LED
	PORTD = 1;								// setting bit for LED
	while (1)
	{
		waitFor(1000);						// wait for 1s then toggle LED on/off
		PORTD += 1;							// LED will count will increase
	}
}

