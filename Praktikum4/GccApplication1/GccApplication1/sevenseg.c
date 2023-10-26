/*
 * sevenseg.c
 *
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel-Nr : 3503937
 */ 
#include "sevenseg.h"

/*
  gfe dcba
0:100 0000 = 64
1:111 1001 = 121
2:010 0100 = 36
3:011 0000 = 48
4:001 1001 = 25
5:001 0010 = 18
6:000 0010 = 2
7:111 1000 = 120
8:000 0000 = 0
9:001 0000 = 16
*/
int convert[10] ={ 64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

void out(int count){
	PORTD = convert[count];							//take number from the "count" position in convert
	_delay_ms(10);									//delay 50 times, and there are 2 sevseg, with minimum 50 times of repetition for each.
													//1s = 1000 ms/(50*2) = 10ms
	PORTB ^=(1<<PINB0);								//switching between left and right seveseg
}