/*

TM4C123G gpio.h

MIT License

Copyright (c) 2018 JorgeBratkov64

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef __GPIO_H
#define __GPIO_H

#include "definitions.h"

typedef enum{
	GPIO_ENABLE_PORTA = (ONE << ZERO),
	GPIO_ENABLE_PORTB = (ONE << ONE),
	GPIO_ENABLE_PORTC = (ONE << TWO),
	GPIO_ENABLE_PORTD = (ONE << THREE),
	GPIO_ENABLE_PORTE = (ONE << FOUR),
	GPIO_ENABLE_PORTF = (ONE << FIVE),
	GPIO_ENABLE_ALL = (SIXTYTHREE << ZERO)
} GPIO_Enable_Port_t;

typedef enum{
	GPIO_DISABLE_PORTA = ~(ONE << ZERO),
	GPIO_DISABLE_PORTB = ~(ONE << ONE),
	GPIO_DISABLE_PORTC = ~(ONE << TWO),
	GPIO_DISABLE_PORTD = ~(ONE << THREE),
	GPIO_DISABLE_PORTE = ~(ONE << FOUR),
	GPIO_DISABLE_PORTF = ~(ONE << FIVE),
	GPIO_DISABLE_ALL = ~(SIXTYTHREE << ZERO)
} GPIO_Disable_Port_t;

typedef enum{
	PORTA = ZERO,
	PORTB,
	PORTC, 
	PORTD, 
	PORTE, 
	PORTF 
} GPIO_PORTn_t;

typedef enum{
	GPIO_PIN0 = (ONE << ZERO),
	GPIO_PIN1 = (ONE << ONE),
	GPIO_PIN2 = (ONE << TWO),
	GPIO_PIN3 = (ONE << THREE),
	GPIO_PIN4 = (ONE << FOUR),
	GPIO_PIN5 = (ONE << FIVE),
	GPIO_PIN6 = (ONE << SIX),
	GPIO_PIN7 = (ONE << SEVEN)
} GPIO_PINn_t;

void GPIO_Enable_Clock_Source(GPIO_Enable_Port_t );
void GPIO_Disable_Clock_Source(GPIO_Disable_Port_t );
void GPIO_Set_Alternate_Function(GPIO_PORTn_t , GPIO_PINn_t );
void GPIO_Enable_Digital_Function(GPIO_PORTn_t, GPIO_PINn_t );
void GPIO_Disable_Digital_Function(GPIO_PORTn_t , GPIO_PINn_t );
void GPIO_Disable_Analog_Isolation(GPIO_PORTn_t , GPIO_PINn_t );

#endif
