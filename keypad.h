#ifndef KEYPAD_H_
#define KEYPAD_H_

//Macros for configuration
#define INPUT_PORT_DIRECTION	DDRC
#define INPUR_PORT				PORTC
#define INPUT_PIN				PINC
#define OUTPUT_PORT_DIRECTION	DDRB
#define OUTPUT_PORT				PORTB


char keypad_scan();

#endif