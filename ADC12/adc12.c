/*

TM4C123G ADC12 Driver

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

#include "adc12.h"
#include <stdint.h>
#include "TM4C123.h"                    // Device header


uint16_t ADC_Write_AIn_On_MUXn(SSMUXn_t SSMUXn, SSMUX_AINn_t SSMUX_AINn);

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
	if(ADC_MOD0 == ADC_MODn){
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
*	SS_Disable(ADC_MODn_t, ADC_SSn_t)
*   
*
*/
void SS_Disable(ADC_MODn_t ADC_MODn, ADC_SSn_t ADC_SSn){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(ADC_SSn){
			case ADC_SS0:	/* Sample Sequencer 0	*/
				ADC0 ->ACTSS = ~(1 << 0);
			break;
			case ADC_SS1:	/* Sample Sequencer 1	*/
				ADC0 ->ACTSS = ~(1 << 1);
			break;
			case ADC_SS2:	/* Sample Sequencer 2	*/
				ADC0 ->ACTSS = ~(1 << 2);
			break;
			default:		/* Sample Sequencer 3	*/
				ADC0 ->ACTSS = ~(1 << 3);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(ADC_SSn){
			case ADC_SS0:	/* Sample Sequencer 0	*/
				ADC1 ->ACTSS = ~(1 << 0);
			break;
			case ADC_SS1:	/* Sample Sequencer 1	*/
				ADC1 ->ACTSS = ~(1 << 1);
			break;
			case ADC_SS2:	/* Sample Sequencer 2	*/
				ADC1 ->ACTSS = ~(1 << 2);
			break;
			default:		/* Sample Sequencer 3	*/
				ADC1 ->ACTSS = ~(1 << 3);
			break;			
		}
	}
}

/* 
*	ADC12_Set_Trigger_Event(ADC_MODn_t, ADC_SSn_t, ADC_TRIGGER_EVENT_t)
*   
*
*/
void ADC12_Set_Trigger_Event(ADC_MODn_t ADC_MODn, ADC_SSn_t ADC_SSn, ADC_TRIGGER_EVENT_t ADC_TRIGER_EVENT){
	
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(ADC_SSn){
		case 0:		/* Sample Sequencer 0	*/
			ADC0 -> EMUX = (ADC_TRIGER_EVENT << 0);
		break;
		case 1:		/* Sample Sequencer 1	*/
			ADC0 -> EMUX = (ADC_TRIGER_EVENT << 4);
		break;
		case 2:		/* Sample Sequencer 2	*/
			ADC0 -> EMUX = (ADC_TRIGER_EVENT << 8);
		break;
		default:	/* Sample Sequencer 3	*/
			ADC0 -> EMUX = (ADC_TRIGER_EVENT << 12);
		break;
		}
	}
	else{
		switch(ADC_SSn){	/* ADC Module 1 */
		case 0:		/* Sample Sequencer 0	*/
			ADC1 -> EMUX = (ADC_TRIGER_EVENT << 0);
		break;
		case 1:		/* Sample Sequencer 1	*/
			ADC1 -> EMUX = (ADC_TRIGER_EVENT << 4);
		break;
		case 2:		/* Sample Sequencer 2	*/
			ADC1 -> EMUX = (ADC_TRIGER_EVENT << 8);
		break;
		default:	/* Sample Sequencer 3	*/
			ADC1 -> EMUX = (ADC_TRIGER_EVENT << 12);
		break;
		}
	}

}

/* 
*	ADC12_PWM_Trigger_Source_Sel(ADC_MODn_t, GENn_PWM_t, PWMn_MOD_t)
*   
*
*/
void ADC12_PWM_Trigger_Source_Sel(ADC_MODn_t ADC_MODn, GENn_PWM_t GENn_PWM, PWMn_MOD_t PWMn_MOD){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(GENn_PWM){	
			case 0:
				ADC0 -> TSSEL = (PWMn_MOD << 4);	/* Generator 0 PWM Module Trigger Select	*/	
			break;
			case 1:
				ADC0 -> TSSEL = (PWMn_MOD << 12);	/* Generator 1 PWM Module Trigger Select	*/
			break;
			case 2:
				ADC0 -> TSSEL = (PWMn_MOD << 20);	/* Generator 2 PWM Module Trigger Select	*/
			break;
			default:
				ADC0 -> TSSEL = (PWMn_MOD << 28);	/* Generator 3 PWM Module Trigger Select	*/
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(GENn_PWM){	
			case 0:
				ADC1 -> TSSEL = (PWMn_MOD << 4);	/* Generator 0 PWM Module Trigger Select	*/	
			break;
			case 1:
				ADC1 -> TSSEL = (PWMn_MOD << 12);	/* Generator 1 PWM Module Trigger Select	*/	
			break;
			case 2:
				ADC1 -> TSSEL = (PWMn_MOD << 20);	/* Generator 2 PWM Module Trigger Select	*/	
			break;
			default:
				ADC1 -> TSSEL = (PWMn_MOD << 28);	/* Generator 3 PWM Module Trigger Select	*/	
			break;
		}
	}
}

/* 
*	ADC_SS_Input_Multiplexer_Sel(ADC_MODn_t, ADC_SSn_t, SSMUXn_t, SSMUX_AINn_t)
*   
*
*/

void ADC_SS_Input_Multiplexer_Sel(ADC_MODn_t ADC_MODn, ADC_SSn_t ADC_SSn, SSMUXn_t SSMUXn, SSMUX_AINn_t SSMUX_AINn){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		if(0 == ADC_SSn){
			switch(SSMUXn){	
				case 0:		/* Select Sample Sequencer 0 */	
					ADC0 -> SSMUX0 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 1:		/* Select Sample Sequencer 1 */		
					ADC0 -> SSMUX1 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 2:		/* Select Sample Sequencer 2 */	
					ADC0 -> SSMUX2 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				default:	/* Select Sample Sequencer 3 */		
					ADC0 -> SSMUX3 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
			}
		}
	}
	else{					/* ADC Module 1 */
		if(0 == ADC_SSn){
			switch(SSMUXn){	
				case 0:		/* Select Sample Sequencer 0 */	
					ADC1 -> SSMUX0 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 1:		/* Select Sample Sequencer 1 */		
					ADC1 -> SSMUX1 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 2:		/* Select Sample Sequencer 2 */	
					ADC1 -> SSMUX2 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				default:	/* Select Sample Sequencer 3 */		
					ADC1 -> SSMUX3 = ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
			}
		}
	}
}

/* 
*	ADC_Write_AIn_On_MUXn(SSMUXn_t SSMUXn,SSMUX_AINn_t SSMUX_AINn)
*   
*
*/

uint16_t ADC_Write_AIn_On_MUXn(SSMUXn_t SSMUXn, SSMUX_AINn_t SSMUX_AINn){
	uint16_t valueReturn = 0;
	switch(SSMUXn){
		case 0:
			valueReturn = (SSMUX_AINn << 0);
		break;
		case 1:
			valueReturn = (SSMUX_AINn << 4);
		break;
		case 2:
			valueReturn = (SSMUX_AINn << 8);
		break;
		case 3:
			valueReturn = (SSMUX_AINn << 12);
		break;
		case 4:
			valueReturn = (SSMUX_AINn << 16);
		break;
		case 5:
			valueReturn = (SSMUX_AINn << 20);
		break;
		case 6:
			valueReturn = (SSMUX_AINn << 24);
		break;
		default:
			valueReturn = (SSMUX_AINn << 28);
		break;
	}
	return valueReturn;
}

/* 
*	ADC12_Set_Sample_Ctrl0(ADC_MODn_t, SSCTRL0_t, SSCTRL0F_t)
*   
*
*/

void ADC12_Set_Sample_Ctrl0(ADC_MODn_t ADC_MODn, SSCTRL0_t SSCTRL0, SSCTRLF_t SSCTRL0F){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(SSCTRL0){
			case SSCTRL0_1STSAMPLE:				/* SSCTRL0_1STSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 0);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 4);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 8);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 12);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 16);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 20);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 24);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << 28);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRL0){
			case SSCTRL0_1STSAMPLE:				/* SSCTRL0_1STSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 0);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 4);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 8);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 12);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 16);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 20);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 24);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << 28);
			break;
		}
	}
}

/* 
*	ADC12_Set_Sample_Ctrl1(ADC_MODn_t, SSCTRL1_t, SSCTRL0F_t)
*   
*
*/

void ADC12_Set_Sample_Ctrl1(ADC_MODn_t ADC_MODn, SSCTRLn_t SSCTRLn, SSCTRLF_t SSCTRL0F){
		if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
			switch(SSCTRLn){
				case SSCTRL0_1STSAMPLE:				/* SSCTRL1_1STSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRL0F << 0);
				break;
				case SSCTRL0_2NDSAMPLE:				/* SSCTRL1_2NDSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRL0F << 4);
				break;
				case SSCTRL0_3RDSAMPLE:				/* SSCTRL1_3RDSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRL0F << 8);
				break;
				default:							/* SSCTRL1_4THSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRL0F << 12);
				break;
			}
		}
		else{					/* ADC Module 1 */
			switch(SSCTRLn){
				case SSCTRL0_1STSAMPLE:				/* SSCTRL1_1STSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRL0F << 0);
				break;
				case SSCTRL0_2NDSAMPLE:				/* SSCTRL1_2NDSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRL0F << 4);
				break;
				case SSCTRL0_3RDSAMPLE:				/* SSCTRL1_3RDSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRL0F << 8);
				break;
				default:							/* SSCTRL1_4THSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRL0F << 12);
				break;
			}
		}
}

/* 
*	ADC12_Set_Sample_Ctrl2(ADC_MODn_t, SSCTRL2_t, SSCTRL0F_t)
*   
*
*/

void ADC12_Set_Sample_Ctrl2(ADC_MODn_t ADC_MODn, SSCTRLn_t SSCTRLn, SSCTRLF_t SSCTRLF){
		if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
			switch(SSCTRLn){
				case SSCTRL0_1STSAMPLE:				/* SSCTRL2_1STSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRLF << 0);			
				break;
				case SSCTRL0_2NDSAMPLE:				/* SSCTRL2_2NDSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRLF << 4);
				break;
				case SSCTRL0_3RDSAMPLE:				/* SSCTRL2_3RDSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRLF << 8);
				break;
				default:							/* SSCTRL2_4THSAMPLE */
					ADC0 -> SSCTL0 |= (SSCTRLF << 12);
				break;
			}
		}
		else{					/* ADC Module 1 */
			switch(SSCTRLn){
				case SSCTRL0_1STSAMPLE:				/* SSCTRL2_1STSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRLF << 0);
				break;
				case SSCTRL0_2NDSAMPLE:				/* SSCTRL2_2NDSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRLF << 4);
				break;
				case SSCTRL0_3RDSAMPLE:				/* SSCTRL2_3RDSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRLF << 8);
				break;
				default:							/* SSCTRL2_4THSAMPLE */
					ADC1 -> SSCTL0 |= (SSCTRLF << 12);
				break;
			}
		}
}

/* 
*	ADC12_Set_Sample_Ctrl3(ADC_MODn_t, SSCTRLF_t)
*   
*
*/

void ADC12_Set_Sample_Ctrl3(ADC_MODn_t ADC_MODn, SSCTRLF_t SSCTRLF){
		if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
			ADC1 -> SSCTL0 |= ((SSCTRLF << 0) | SSCTLn_ENDn);		/* SSCTRL3_1STSAMPLE */
		}
		else{					/* ADC Module 1 */
			ADC1 -> SSCTL0 |= (SSCTRLF << 0 | SSCTLn_ENDn);		/* SSCTRL3_1STSAMPLE */
		}
}
 
/* 
*	ADC12_Set_End_SS_Ctrl0(ADC_MODn_t, SSCTRLF_t)
*   
*
*/

void ADC12_Set_End_SS_Ctrl0(ADC_MODn_t ADC_MODn, SSCTRL0_t SSCTRL0){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(SSCTRL0){
			case SSCTRL0_1STSAMPLE:				/* SSCTRL0_1STSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 0);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 4);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 8);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 12);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 16);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 20);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 24);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 28);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRL0){
			case SSCTRL0_1STSAMPLE:				/* SSCTRL0_1STSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 0);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 4);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 8);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 12);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 16);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 20);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 24);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 28);
			break;
		}
	}
}

/* 
*	ADC12_Set_End_SS_Ctrln(ADC_MODn_t, SSCTRLn_t)
*   
*
*/

void ADC12_Set_End_SS_Ctrln(ADC_MODn_t ADC_MODn, SSCTRLn_t SSCTRLn){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(SSCTRLn){
			case SSCTRLn_1STSAMPLE:				/* SSCTRLn_1STSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 0);
			break;
			case SSCTRLn_2NDSAMPLE:				/* SSCTRLn_2NDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 4);
			break;
			case SSCTRLn_3RDSAMPLE:				/* SSCTRLn_3RDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 8);
			break;
			default:							/* SSCTRLn_4THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << 12);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRLn){
			case SSCTRLn_1STSAMPLE:				/* SSCTRLn_1STSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 0);
			break;
			case SSCTRLn_2NDSAMPLE:				/* SSCTRLn_2NDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 4);
			break;
			case SSCTRLn_3RDSAMPLE:				/* SSCTRLn_3RDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 8);
			break;
			default:							/* SSCTRLn_4THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << 12);
			break;
		}
	}
}