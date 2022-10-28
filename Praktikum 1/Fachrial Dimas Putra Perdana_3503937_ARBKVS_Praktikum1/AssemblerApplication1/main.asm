;
; AssemblerApplication1.asm
;
; Created: 10/12/2022 8:38:58 PM
; Author : User
;

.org 0x000		; Reset Vector
	rjmp start
	

start:
    ; Stack Pointer initialisieren
	ldi r16, LOW( RAMEND )
	out SPL, r16
	ldi r16, HIGH( RAMEND )
	out SPH, r16
	
	;PORTD als Output
	ldi r16,0b11111111
	out DDRD, r16
	;PORTB 0 und 1 als Output
	ldi r17,0b00000011
	out DDRB, r17

main:
	ldi r16,0b00000001				;r16 laden in 0. bit
	out PORTD, r16					;in PORTD schreiben
	rcall delay						;delay

loop1:								;1. Schleife for PORTD 1 bis 7
	lsl r16							;link shit (mal 2) damin das 1 in r16 nach link verschoben
	out PORTD, r16					;in PORTD schreiben
	rcall delay						;delay
	ldi r21, 0b10000000				;r21 als Hilfe schreiben als letzte Position in PORTD damit kein 2 Licht eingeschaltet oder 1 Licht 2 mal eingeschaltet
	cp r21,r16						;r21 und r16 vergleichen
	breq next						;wenn r21 und r16 gleich geh nach "next"
	brcc loop1						;zum loop1 zurückspringen, wenn Carry-Flag nicht gesetzt
							
next:								
	ldi r16,0b00000000				;0 in r16 laden
	ldi r17,0b00000001				;1 in r17 laden
	out PORTD, r16					;r16 in PORTD schreiben, damit alle Licht von PORTD ausgeschaltet
	out PORTB, r17					;r17 in PORTB schreiben, erste Licht von PORTB einschalten
	rcall delay
	lsl r17							;bit von r17 nach link schieben(mal 2)
	out PORTB, r17					;in PORTB schreiben
	rcall delay

	lsr r17							;bit von r17 zurück nach rechts schieben
	out PORTB, r17					;in PORTB schreiben
	rcall delay
	dec r17							;r17 -1 damit r17 ist 0
	ldi r16,0b10000000				;r16 laden (letzte Bit)
	out PORTB, r17					;r17 in PORTB schreiben
	out PORTD, r16					;r17 in PORTD schreiben
	rcall delay

loop2:								;loop von PORTD6 bis 1
	lsr r16							; r16 nach rechts scheieben
	out PORTD, r16					;in PORTD schreiben
	rcall delay
	ldi r21, 0b00000010				;r21 wieder als Hifle, jetzt 2 setzen
	cp r21,r16						;r16 und r21 vergleichen
	brne loop2						;wenn r16 und r21 nicht gleich zum "loop2" zurückspringen
	rjmp main						; zum main zurückspringen
									;wenn bis 1, die 1. Licht wird 2 mal eingeschaltet
									;wenn bis 0, es gibt ein Moment, wenn alle licht ausgeschaltet werden

delay:
	ldi  r18, 17
    ldi  r19, 60
    ldi  r20, 204
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
	ret






