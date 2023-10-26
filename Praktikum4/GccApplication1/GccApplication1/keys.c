/*
 * keys.c
 *
 * Author : Fachrial Dimas Putra Perdana
 * Matrikel-Nr : 3503937
 */ 

#include "keys.h"



void init(){
	cli();
	PCICR = (1<<PCIE0);
	PCMSK0=(1<<PINB1)|(1<<PINB2);
	sei();
}

