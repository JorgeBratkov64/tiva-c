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
	SYSCTL -> RCGCADC |= ADC_Init -> ADC_Module;
	SYSCTL -> RCGCGPIO |= ADC_Init -> ADC_Ports;	
	GPIOB -> AFSEL |= ADC_Init -> ADC_AFSEL_PORTB;
	GPIOD -> AFSEL |= ADC_Init -> ADC_AFSEL_PORTD;
	GPIOE -> AFSEL |= ADC_Init -> ADC_AFSEL_PORTE;
	GPIOB -> DEN |= ADC_Init -> ADC_CLEAR_DEN_PORTB;
	GPIOD -> DEN |= ADC_Init -> ADC_CLEAR_DEN_PORTD;
	GPIOE -> DEN |= ADC_Init -> ADC_CLEAR_DEN_PORTE;
	GPIOB -> AMSEL |= ADC_Init ->ADC_AMSEL_PORTB;
	GPIOD -> AMSEL |= ADC_Init ->ADC_AMSEL_PORTD;
	GPIOE -> AMSEL |= ADC_Init ->ADC_AMSEL_PORTE;
}

/* 
*	ADC12_Denit()
*
*/
void ADC12_Deinit(ADC_Deinit_t *ADC_Deinit ){
	SYSCTL -> RCGCADC &= ADC_Deinit -> ADC_Module;
	SYSCTL -> RCGCGPIO &= ADC_Deinit -> ADC_Ports;	
	GPIOB -> AFSEL &= ADC_Deinit -> ADC_AFSEL_PORTB;
	GPIOD -> AFSEL &= ADC_Deinit -> ADC_AFSEL_PORTD;
	GPIOE -> AFSEL &= ADC_Deinit -> ADC_AFSEL_PORTE;
	GPIOB -> DEN &= ADC_Deinit -> ADC_CLEAR_DEN_PORTB;
	GPIOD -> DEN &= ADC_Deinit -> ADC_CLEAR_DEN_PORTD;
	GPIOE -> DEN &= ADC_Deinit -> ADC_CLEAR_DEN_PORTE;
	GPIOB -> AMSEL &= ADC_Deinit ->ADC_AMSEL_PORTB;
	GPIOD -> AMSEL &= ADC_Deinit ->ADC_AMSEL_PORTD;
	GPIOE -> AMSEL &= ADC_Deinit ->ADC_AMSEL_PORTE;
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
*	ADC12_ADC12_setSequencerPriority(ADC_SSn_t, ADC_SSPRIO_t)
*   Sets the priority ADC_SSPRIO_t for the ADC sequencer ADC_SSn_t for the ADC module ADC_MODn_t
*
*/
void ADC12_setSequencerPriority(ADC_MODn_t ADC_MODn, ADC_SSn_t ADC_SSn, ADC_SSPRIO_t ADC_SSPRIO){
	if(ADC_MODn < 1){
		switch(ADC_SSn){
			case ADC_SS0:
				ADC0 -> SSPRI = ADC_SSPRIO;
			break;
			case ADC_SS1:
				ADC0 -> SSPRI = (ADC_SSPRIO << 4);
			break;
			case ADC_SS3:
				ADC0 -> SSPRI = (ADC_SSPRIO << 8);
			break;
			default:
				ADC0 -> SSPRI = (ADC_SSPRIO << 12);
			break;
		}
	}
	else{
		switch(ADC_SSn){
			case ADC_SS0:
				ADC1 -> SSPRI = ADC_SSPRIO;
			break;
			case ADC_SS1:
				ADC1 -> SSPRI = (ADC_SSPRIO << 4);
			break;
			case ADC_SS3:
				ADC1 -> SSPRI = (ADC_SSPRIO << 8);
			break;
			default:
				ADC1 -> SSPRI = (ADC_SSPRIO << 12);
			break;
		}
	}
}

/* 
*	ADC12_SampleSequencer_Config()
*   
*
*/
void ADC12_SampleSequencer_Config(ADC_MODn_t ADC_MODn, ADC_SSn_t ADC_SSn){
	if(ADC_MODn == 0){		/* ADC Module 0 */
		switch(ADC_SSn){
			case ADC_SS0:	/* Sample Sequencer 0	*/
			break;
			case ADC_SS1:	/* Sample Sequencer 1	*/
			break;
			case ADC_SS2:	/* Sample Sequencer 2	*/
			break;
			default:		/* Sample Sequencer 3	*/
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(ADC_SSn){
			case ADC_SS0:	/* Sample Sequencer 0	*/
			break;
			case ADC_SS1:	/* Sample Sequencer 1	*/
			break;
			case ADC_SS2:	/* Sample Sequencer 2	*/
			break;
			default:		/* Sample Sequencer 3	*/
			break;			
		}
	}
}

/* 
*	ADC12_Set_Differential_Input()
*   
*
*/

void ADC12_Set_Differential_Input(void){
}

