/*
 * GccApplication1.c
 *
 * Created: 12/11/2022 10:02:33 PM
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel-Nr : 3503937
 */ 

#include "keys.h"
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

volatile uint32_t count = 0;
int convert[10] ={ 64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

ISR(PCINT0_vect){
	if(!(PINB & (1<<PINB1))){
		if(count == 99){
			count =0;
		}else{
			count++;
		}
	}
	if(!(PINB & (1<<PINB2))){
		if(count == 0){
			count =99;
		}else{
			count--;
		}
	}
}
void setup(){
	DDRD=0xff;
	PORTD=1<<PIND6;
	
	DDRB = 0x01;
	PORTB = (1<<PINB1)|(1<<PINB2);
}
int main(void)
{
    setup();
	init();
    while (1) 
    {
		int ones = count%10;
		int tens = (count-ones)/10;
		
		out(ones,convert);
		out(tens,convert);
    }
}

