/*

TM4C123G gpio.c

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

#include "gpio.h"
#include "TM4C123.h"  

/* 
*	GPIO_EnableClockSource()
*
*/

void GPIO_Enable_Clock_Source(GPIO_Enable_Port_t GPIO_Enable_Port){
	SYSCTL -> RCGCGPIO |=  GPIO_Enable_Port;	
}

/* 
*	GPIO_DisableClockSource()
*
*/

void GPIO_Disable_Clock_Source(GPIO_Disable_Port_t GPIO_Disable_Port){
	SYSCTL -> RCGCGPIO &= GPIO_Disable_Port;	
}

/* 
*	GPIO_Set_Alternate_Function(GPIO_PORTn_t, GPIO_PINn_t)
*
*/

void GPIO_Set_Alternate_Function(GPIO_PORTn_t GPIO_PORTn, GPIO_PINn_t GPIO_PINn){
	switch(GPIO_PORTn){			
		case PORTA:			/* GPIO PORTA */
			GPIOA -> AFSEL |= GPIO_PINn;		/* Alternate function on PAn*/
		break;
		case PORTB:			/* GPIO PORTB */
			GPIOB -> AFSEL |= GPIO_PINn;		/* Alternate function on PBn*/
		break;
		case PORTC:			/* GPIO PORTC */
			GPIOC -> AFSEL |= GPIO_PINn;		/* Alternate function on PCn*/
		break;
		case PORTD:			/* GPIO PORTD */
			GPIOD -> AFSEL |= GPIO_PINn;		/* Alternate function on PDn*/
		break;
		case PORTE:			/* GPIO PORTE */
			GPIOE -> AFSEL |= GPIO_PINn;		/* Alternate function on PEn*/
		break;
		default:			/* GPIO PORTF */
			GPIOF -> AFSEL |= GPIO_PINn;		/* Alternate function on PFn*/
		break;
	}
}

void Write_Alternate_Function(){
}

