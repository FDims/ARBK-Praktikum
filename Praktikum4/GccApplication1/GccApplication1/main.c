/*
 * GccApplication1.c
 *
 * Created: 12/11/2022 10:02:33 PM
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel-Nr : 3503937
 */ 

#include "keys.h"
#include "sevenseg.h"


volatile uint32_t count = 0;

ISR(PCINT0_vect){														//Interrupt Routine
	if(!(PINB & (1<<PINB1))){											//if SW1 pressed
		if(count == 0){
			count =99;
			}else{
			count--;
		}
	}
	if(!(PINB & (1<<PINB2))){											//if SW2 pressed
		if(count == 99){
			count =0;
			}else{
			count++;
		}
	}
}

void setup(){
	DDRD=0xff;															//PORTD as output
	PORTD=1<<PIND6;														//starting from 0 in sevseg.
	
	DDRB = 0x01;														//PINB 0 as input and the rest are output
	PORTB = (1<<PINB1)|(1<<PINB2);										//set bit for both inputs
}
int main(void)
{
    setup();
	init();
    while (1) 
    {
		int ones = count%10;										//for the right sevseg
		int tens = count/10;									//for the left sevseg
		
		out(ones);											//output display
		out(tens);											//output display
    }
}

