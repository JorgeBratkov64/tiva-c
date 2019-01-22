/*

TM4C123G adc12.h

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

#ifndef __ADC12_H
#define __ADC12_H

#include "stdint.h"

#define SSCTLn_ENDn	(1 << 1)

typedef enum{
	ENABLE_ADC_MODULE0 = 1,
	ENABLE_ADC_MODULE1,
	ENABLE_ADC_BOTH,
} ADC_Enable_Clock_t;

typedef enum{
	DISABLE_ADC_MODULE0 = 2,
	DISABLE_ADC_MODULE1 = 1,
	DISABLE_ADC_BOTH = 0 
} ADC_Disable_Clock_t;

typedef enum{
	ADC_PORT_CHANNELS_DISABLE = 0,
	ADC_PORTB_CHANNELS = 1,
	ADC_PORTD_CHANNELS = 4,
	ADC_PORTE_CHANNELS = 8
} ADC_Port_Clock_t;
	
typedef enum{
	ADC_SSPRIO_0 = 0,
	ADC_SSPRIO_1,
	ADC_SSPRIO_2,
	ADC_SSPRIO_3	
} ADC_SSPRIO_t;

typedef enum{
	ADC_SS0 = 0,
	ADC_SS1,
	ADC_SS2,
	ADC_SS3	
} ADC_SSn_t;

typedef enum{
	ADC_MOD0 = 0,
	ADC_MOD1
} ADC_MODn_t;

typedef enum{
	TRIG_SSn = 0, 					/* SSn bit in the ADCPSSI register.	*/
	TRIG_ANALOG_COMPARATOR0,		/* Analog Comparator Control 0 (ACCTL0) register	*/
	TRIG_ANALOG_COMPARATOR1,		/* Analog Comparator Control 1 (ACCTL1) register	*/
	TRIG_GPIO = 4,
	TRIG_TIMMER,
	TRIG_PWMGEN0,					/* PWM generator 0	*/
	TRIG_PWMGEN1,					/* PWM generator 1	*/
	TRIG_PWMGEN2,					/* PWM generator 2	*/
	TRIG_PWMGEN3,					/* PWM generator 3	*/
	CONTINOUS_SAMPLE = 15			/* Always (continuously sample)	*/ 	
} ADC_TRIGGER_EVENT_t;

typedef enum {
	GEN_PWM0 = 0,
	GEN_PWM1
} PWMn_MOD_t;

typedef enum {
	GEN0 = 0,
	GEN1,
	GEN2,
	GEN3
} GENn_PWM_t;

typedef enum {
	SSMUX_AIN0 = 0,
	SSMUX_AIN1,
	SSMUX_AIN2,
	SSMUX_AIN3,
	SSMUX_AIN4,
	SSMUX_AIN5,
	SSMUX_AIN6,
	SSMUX_AIN7,
	SSMUX_AIN8,
	SSMUX_AIN9,
	SSMUX_AIN10,
	SSMUX_AIN11	
} SSMUX_AINn_t;

typedef enum {
	SSMUX0 = 0,
	SSMUX1,
	SSMUX2,
	SSMUX3,
	SSMUX4,
	SSMUX5,
	SSMUX6,
	SSMUX7
} SSMUXn_t;

typedef enum{
	SSCTRL0_1STSAMPLE = 0,
	SSCTRL0_2NDSAMPLE,
	SSCTRL0_3RDSAMPLE,
	SSCTRL0_4THSAMPLE,
	SSCTRL0_5THSAMPLE,
	SSCTRL0_6THSAMPLE,
	SSCTRL0_7THSAMPLE,
	SSCTRL0_8THSAMPLE
} SSCTRL0_t;

typedef enum{
	SSCTRLn_1STSAMPLE = 0,
	SSCTRLn_2NDSAMPLE,
	SSCTRLn_3RDSAMPLE,
	SSCTRLn_4THSAMPLE,
} SSCTRLn_t;

typedef enum{
	SSCTRL3_1STSAMPLE = 0,
} SSCTRL3_t;

typedef enum{
	Dn = 1,			/* Sample Differential Input Select */ 
	ENDn = 2,		/* End of Sequence */
	IEn = 4,		/* The raw interrupt signal (INR0 bit) is asserted at the end of this sample's conversion */
	TSn = 8			/* The temperature sensor is read */
} SSCTRLF_t;


void ADC12_Enable_Clock_Source(ADC_Enable_Clock_t);
void ADC12_Disable_Clock_Source(ADC_Disable_Clock_t);
void ADC12_Set_Sequencer_Priority(ADC_MODn_t, ADC_SSn_t, ADC_SSPRIO_t);
void ADC12_Set_Trigger_Event(ADC_MODn_t, ADC_SSn_t , ADC_TRIGGER_EVENT_t);
void ADC12_PWM_Trigger_Source_Sel(ADC_MODn_t, GENn_PWM_t, PWMn_MOD_t);
void ADC12_SS_Input_Multiplexer_Sel(ADC_MODn_t ADC_MODn,ADC_SSn_t ADC_SSn, SSMUXn_t SSMUXn, SSMUX_AINn_t SSMUX_AINn);
void ADC12_Set_Sample_Ctrl0(ADC_MODn_t , SSCTRL0_t , SSCTRLF_t );
void ADC12_Set_Sample_Ctrl1(ADC_MODn_t , SSCTRLn_t , SSCTRLF_t );
void ADC12_Set_Sample_Ctrl2(ADC_MODn_t , SSCTRLn_t , SSCTRLF_t );
void ADC12_Set_Sample_Ctrl3(ADC_MODn_t , SSCTRLF_t );
void ADC12_Set_End_SS_Ctrl0(ADC_MODn_t , SSCTRL0_t );
void ADC12_Set_End_SS_Ctrl1(ADC_MODn_t , SSCTRLn_t );
void ADC12_Set_End_SS_Ctrl2(ADC_MODn_t , SSCTRLn_t );
void ADC12_Interrupt_Mask(ADC_MODn_t );


#endif