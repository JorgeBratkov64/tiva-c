/*
* TM4C123G ADC12 Driver
* Functions implemented in this file are taken as example from the article from below
* http://ww1.microchip.com/downloads/en/AppNotes/Atmel-42451-SAM-Analog-to-Digital-Converter-ADC-Driver_ApplicationNote_AT11380.pdf
* 
//MIT License

//Copyright (c) 2018 JorgeBratkov64

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

*/

#include "adc12.h"
#include <stdint.h>
#include "TM4C123.h"                    // Device header

/* 
*	ADC12_Init()
*
*/

void ADC12_Init(ADC_Init_t *ADC_Init ){
	SYSCTL -> RCGCADC = ADC_Init -> ADC_Module;
	SYSCTL -> RCGCGPIO = ADC_Init -> ADC_Ports;	
	GPIOB -> AFSEL = ADC_Init -> ADC_AFSEL_PORTB;
	GPIOD -> AFSEL = ADC_Init -> ADC_AFSEL_PORTD;
	GPIOE -> AFSEL = ADC_Init -> ADC_AFSEL_PORTE;
	GPIOB -> DEN = ADC_Init -> ADC_CLEAR_DEN_PORTB;
	GPIOD -> DEN = ADC_Init -> ADC_CLEAR_DEN_PORTD;
	GPIOE -> DEN = ADC_Init -> ADC_CLEAR_DEN_PORTE;
	GPIOB -> AMSEL = ADC_Init ->ADC_AMSEL_PORTB;
	GPIOD -> AMSEL = ADC_Init ->ADC_AMSEL_PORTD;
	GPIOE -> AMSEL = ADC_Init ->ADC_AMSEL_PORTE;
}

//typedef struct ADC_Init_t{
//	ADC_Enable_t ADC_Module;
//	ADC_Port_Clock_t ADC_Ports;
//	ADC_PORTB_AFSEL_t ADC_Channel_B;
//	ADC_PORTD_AFSEL_t ADC_Channel_D;
//	ADC_PORTE_AFSEL_t ADC_Channel_C;
//	ADC_PORTB_DEN_t ADC_DEN_B;
//	ADC_PORTD_DEN_t ADC_DEN_D;
//	ADC_PORTE_DEN_t ADC_DEN_E;
//}ADC_Init_t;

/* 
*	ADC12_Denit()
*
*/
void ADC12_Deinit(void ){
	
}

/* 
*	ADC12_Enable()
*	Enables the ADC clock		
*/

void ADC12_Enable(ADC_Enable_t ADCModule){
	SYSCTL -> RCGCADC = ADCModule;	
}

/* 
*	ADC12_Disable()
*   Disables the ADC clock
*/
void ADC12_Disable(ADC_Disable_t ADCModule){
	SYSCTL -> RCGCADC = ADCModule;	
}

/* 
*	ADC12_Reset()
*   Resets an ADC module, clearing all module state, and registers to their default values.
*
*/
void ADC12_Reset(){
}

/* 
*	ADC12_Start_Convertion()
*   Starts a new ADC conversion.
*
*/

void ADC12_Start_Convertion(void){
}

/* 
*	ADC12_Read()
*   Reads the result from an ADC conversion that was previously started.
*
*/
 uint16_t ADC12_Read(void){
	 return 0;
}

/* 
*	ADC12_Set_Differential_Input()
*   
*
*/
void ADC12_Set_Differential_Input(void){
}

