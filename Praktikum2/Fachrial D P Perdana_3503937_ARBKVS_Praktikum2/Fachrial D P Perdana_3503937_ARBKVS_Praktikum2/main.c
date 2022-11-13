/*
 * Fachrial D P Perdana_3503937_ARBKVS_Praktikum2.c
 *
 * Created: 10/28/2022 11:47:01 AM
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel-Nr : 3503937
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int on = 0;													
volatile int blink = 0;

void setUp(){	
	DDRB = 0xff;														//Data register B als Output (hier werden B0 und B1 verwendet)
	PORTB =0x00;														//PORTB 0 setzen
	
	DDRD = 0x00;														//Data Register B als input (D2 und D3 verwendet)
	PORTD = (1<<PIND2)|(1<<PIND3);										//Bit für die beide Switchs setzen
	cli();																//Interrupt-Flag löschen und Interupt sperren
	EIMSK = (1<<INT0) | (1<<INT1);										//Enable-External-Interrupt von	INT1 und INT0 (PIND2 und PIND3)		
	EICRA = (1<<ISC11) | (1<<ISC01);									//Falling-Edge von INT0 und INT1 bilden Interrupt-Request
	sei();																//Enable global Interrupt
}

ISR(INT0_vect){															//Interrupt Service Routine, wenn PIND2 gedrückt wird
	if(PORTB0==on){														//PORTB 0 = LED D0
		blink^=(1<<0);													//blinker ein/ausschalten			
	}else{																//wenn nicht an ist	
		PORTB=(1<<PORTB0);												//LED D0 einschalten
	}
	on = PORTB0;														// on-Status zu LED D0 umsetzen
}

ISR(INT1_vect){															//Interrupt Service Routine, wenn PIND3 gedrückt wird
	if(PORTB1==on){														//PORTB 1 = LED D9
		blink^=(1<<0);													//blinker ein/ausschalten
	}else{																//wenn nicht an ist
		PORTB=(1<<PORTB1);												//LED D9 einschalten
	}
	on = PORTB1;														// on-Status zu LED D9 umsetzen
}

int main(void)
{
    setUp();
    while (1)
    {
		if(blink==1) {
			PORTB ^=(1<<on);
		}else{
			PORTB = (1<<on);
		}
		_delay_ms(200);
    }
}