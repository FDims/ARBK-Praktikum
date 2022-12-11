/*
 * sevenseg.c
 *
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel-Nr : 3503937
 */ 
#include "sevenseg.h"

void out(int count, int convert[]){
	PORTD = convert[count];							//take number from the "count" position in convert
	_delay_ms(10);									//delay 50 times, and there are 2 sevseg, with minimum 50 times of repetition for each.
													//1s = 1000 ms/(50*2) = 10ms
	PORTB ^=(1<<PINB0);								//switching between left and right seveseg
}