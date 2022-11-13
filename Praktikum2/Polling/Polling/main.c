/*
 * Polling.c
 *
 * Created: 11/10/2022 3:21:13 PM
 * Author : User
 */

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

volatile int on = PINB1;
volatile int off = PINB0;
volatile int blink = 0;

void setupPort(){
	DDRD=0x00;					//PORTD als input PD2 zu SW1 und PD3 zu SW2
	PORTD=0xff;
	
	DDRB=0xff;					//PORTB als output PB0 zu D0 unf PB1 zu D9
	PORTB=0x00;
}
int main(void)
{
	setupPort();
	
	
    while (1) 
    {
		if( !( PIND & (1<<PIND2) ) ){			//SW0 gedrückt 
			if(on==PINB0){
				blink^=(1<<0);
			}else{
				PINB= (1<<PINB0);
			}
			on = PINB0;
			off = PINB1;
			
		}
		
		if( !( PIND & (1<<PIND3) ) ){			//SW1 gedrückt 
			if(on==PINB1){
				blink^=(1<<0);
			}else{
				PINB= (1<<PINB1);
			}
			on = PINB1;
			off = PINB0;
		}
		
		
		if(blink==1){
			PORTB &= ~(1 << off);			//LED ausschalten 
			PORTB ^=(1<<on);				//LED blinkt
			
		}else{
			PORTB &= ~(1 << off);			//LED ausschalten 
			PORTB = (1<<on);				//LED einschalten
		}
		_delay_ms(200);
    }
}
