/*

TM4C123G adc12.c

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
#include "definitions.h"


uint16_t ADC_Write_AIn_On_MUXn(SSMUXn_t SSMUXn, SSMUX_AINn_t SSMUX_AINn);

/* 
*	ADC12_Init()
*
*/

void ADC12_Init(ADC_Init_t *ADC_Init ){
	SYSCTL -> RCGCADC |= ADC_Init -> ADC_Enable_Clock;
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

///* 
//*	ADC12_Denit()
//*
//*/
//void ADC12_Deinit(ADC_Deinit_t *ADC_Deinit ){
//	SYSCTL -> RCGCADC &= ADC_Deinit -> ADC_Module;
//	SYSCTL -> RCGCGPIO &= ADC_Deinit -> ADC_Ports;	
//	GPIOB -> AFSEL &= ADC_Deinit -> ADC_AFSEL_PORTB;
//	GPIOD -> AFSEL &= ADC_Deinit -> ADC_AFSEL_PORTD;
//	GPIOE -> AFSEL &= ADC_Deinit -> ADC_AFSEL_PORTE;
//	GPIOB -> DEN &= ADC_Deinit -> ADC_CLEAR_DEN_PORTB;
//	GPIOD -> DEN &= ADC_Deinit -> ADC_CLEAR_DEN_PORTD;
//	GPIOE -> DEN &= ADC_Deinit -> ADC_CLEAR_DEN_PORTE;
//	GPIOB -> AMSEL &= ADC_Deinit ->ADC_AMSEL_PORTB;
//	GPIOD -> AMSEL &= ADC_Deinit ->ADC_AMSEL_PORTD;
//	GPIOE -> AMSEL &= ADC_Deinit ->ADC_AMSEL_PORTE;
//}

/* 
*	ADC12_EnableClockSource(ADC_Enable_Clock_t)
*	Gates clock to ADC module
*/

void ADC12_Enable_Clock_Source(ADC_Enable_Clock_t ADC_Enable_Clock){
	SYSCTL -> RCGCADC |= ADC_Enable_Clock;	
}

/* 
*	ADC12_DisableClockSource(ADC_Disable_Clock_t)
*   Disables the ADC clock
*/
void ADC12_Disable_Clock_Source(ADC_Disable_Clock_t ADC_Disable_Clock){
	SYSCTL -> RCGCADC &= ADC_Disable_Clock;	
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
				ADC0 -> SSPRI |= ADC_SSPRIO;
			break;
			case ADC_SS1:
				ADC0 -> SSPRI |= (ADC_SSPRIO << FOUR);
			break;
			case ADC_SS3:
				ADC0 -> SSPRI |= (ADC_SSPRIO << EIGTH);
			break;
			default:
				ADC0 -> SSPRI |= (ADC_SSPRIO << TWELVE);
			break;
		}
	}
	else{
		switch(ADC_SSn){
			case ADC_SS0:
				ADC1 -> SSPRI |= ADC_SSPRIO;
			break;
			case ADC_SS1:
				ADC1 -> SSPRI |= (ADC_SSPRIO << FOUR);
			break;
			case ADC_SS3:
				ADC1 -> SSPRI |= (ADC_SSPRIO << EIGTH);
			break;
			default:
				ADC1 -> SSPRI |= (ADC_SSPRIO << TWELVE);
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
				ADC0 ->ACTSS &= ~(ONE << ZERO);
			break;
			case ADC_SS1:	/* Sample Sequencer 1	*/
				ADC0 ->ACTSS &= ~(ONE << ONE);
			break;
			case ADC_SS2:	/* Sample Sequencer 2	*/
				ADC0 ->ACTSS &= ~(ONE << TWO);
			break;
			default:		/* Sample Sequencer 3	*/
				ADC0 ->ACTSS &= ~(ONE << THREE);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(ADC_SSn){
			case ADC_SS0:	/* Sample Sequencer 0	*/
				ADC1 ->ACTSS &= ~(ONE << ZERO);
			break;
			case ADC_SS1:	/* Sample Sequencer 1	*/
				ADC1 ->ACTSS &= ~(ONE << ONE);
			break;
			case ADC_SS2:	/* Sample Sequencer 2	*/
				ADC1 ->ACTSS &= ~(ONE << TWO);
			break;
			default:		/* Sample Sequencer 3	*/
				ADC1 ->ACTSS &= ~(ONE << THREE);
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
			ADC0 -> EMUX |= (ADC_TRIGER_EVENT << ZERO);
		break;
		case 1:		/* Sample Sequencer 1	*/
			ADC0 -> EMUX |= (ADC_TRIGER_EVENT << FOUR);
		break;
		case 2:		/* Sample Sequencer 2	*/
			ADC0 -> EMUX |= (ADC_TRIGER_EVENT << EIGTH);
		break;
		default:	/* Sample Sequencer 3	*/
			ADC0 -> EMUX |= (ADC_TRIGER_EVENT << TWELVE);
		break;
		}
	}
	else{
		switch(ADC_SSn){	/* ADC Module 1 */
		case 0:		/* Sample Sequencer 0	*/
			ADC1 -> EMUX |= (ADC_TRIGER_EVENT << ZERO);
		break;
		case 1:		/* Sample Sequencer 1	*/
			ADC1 -> EMUX |= (ADC_TRIGER_EVENT << FOUR);
		break;
		case 2:		/* Sample Sequencer 2	*/
			ADC1 -> EMUX |= (ADC_TRIGER_EVENT << EIGTH);
		break;
		default:	/* Sample Sequencer 3	*/
			ADC1 -> EMUX |= (ADC_TRIGER_EVENT << TWELVE);
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
				ADC0 -> TSSEL |= (PWMn_MOD << FOUR);	/* Generator 0 PWM Module Trigger Select	*/	
			break;
			case 1:
				ADC0 -> TSSEL |= (PWMn_MOD << TWELVE);	/* Generator 1 PWM Module Trigger Select	*/
			break;
			case 2:
				ADC0 -> TSSEL |= (PWMn_MOD << TWENTY);	/* Generator 2 PWM Module Trigger Select	*/
			break;
			default:
				ADC0 -> TSSEL |= (PWMn_MOD << TWENTYEIGTH);	/* Generator 3 PWM Module Trigger Select	*/
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(GENn_PWM){	
			case 0:
				ADC1 -> TSSEL |= (PWMn_MOD << FOUR);	/* Generator 0 PWM Module Trigger Select	*/	
			break;
			case 1:
				ADC1 -> TSSEL |= (PWMn_MOD << TWELVE);	/* Generator 1 PWM Module Trigger Select	*/	
			break;
			case 2:
				ADC1 -> TSSEL |= (PWMn_MOD << TWENTY);	/* Generator 2 PWM Module Trigger Select	*/	
			break;
			default:
				ADC1 -> TSSEL |= (PWMn_MOD << TWENTYEIGTH);	/* Generator 3 PWM Module Trigger Select	*/	
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
					ADC0 -> SSMUX0 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 1:		/* Select Sample Sequencer 1 */		
					ADC0 -> SSMUX1 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 2:		/* Select Sample Sequencer 2 */	
					ADC0 -> SSMUX2 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				default:	/* Select Sample Sequencer 3 */		
					ADC0 -> SSMUX3 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
			}
		}
	}
	else{					/* ADC Module 1 */
		if(0 == ADC_SSn){
			switch(SSMUXn){	
				case 0:		/* Select Sample Sequencer 0 */	
					ADC1 -> SSMUX0 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 1:		/* Select Sample Sequencer 1 */		
					ADC1 -> SSMUX1 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				case 2:		/* Select Sample Sequencer 2 */	
					ADC1 -> SSMUX2 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
				break;
				default:	/* Select Sample Sequencer 3 */		
					ADC1 -> SSMUX3 |= ADC_Write_AIn_On_MUXn(SSMUXn, SSMUX_AINn);		/* AIn Sample Input Select on MUXn*/	
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
			valueReturn = (SSMUX_AINn << ZERO);
		break;
		case 1:
			valueReturn = (SSMUX_AINn << FOUR);
		break;
		case 2:
			valueReturn = (SSMUX_AINn << EIGTH);
		break;
		case 3:
			valueReturn = (SSMUX_AINn << TWELVE);
		break;
		case 4:
			valueReturn = (SSMUX_AINn << SIXTEEN);
		break;
		case 5:
			valueReturn = (SSMUX_AINn << TWENTY);
		break;
		case 6:
			valueReturn = (SSMUX_AINn << TWENTYFOUR);
		break;
		default:
			valueReturn = (SSMUX_AINn << TWENTYEIGTH);
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
				ADC0 -> SSCTL0 |= (SSCTRL0F << ZERO);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << FOUR);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << EIGTH);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << TWELVE);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << SIXTEEN);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << TWENTY);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << TWENTYFOUR);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTRL0F << TWENTYEIGTH);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRL0){
			case SSCTRL0_1STSAMPLE:				/* SSCTRL0_1STSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << ZERO);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << FOUR);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << EIGTH);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << TWELVE);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << SIXTEEN);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << TWENTY);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << TWENTYFOUR);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTRL0F << TWENTYEIGTH);
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
				case SSCTRLn_1STSAMPLE:				/* SSCTRL1_1STSAMPLE */
					ADC0 -> SSCTL1 |= (SSCTRL0F << ZERO);
				break;
				case SSCTRLn_2NDSAMPLE:				/* SSCTRL1_2NDSAMPLE */
					ADC0 -> SSCTL1 |= (SSCTRL0F << FOUR);
				break;
				case SSCTRLn_3RDSAMPLE:				/* SSCTRL1_3RDSAMPLE */
					ADC0 -> SSCTL1 |= (SSCTRL0F << EIGTH);
				break;
				default:							/* SSCTRL1_4THSAMPLE */
					ADC0 -> SSCTL1 |= (SSCTRL0F << TWELVE);
				break;
			}
		}
		else{					/* ADC Module 1 */
			switch(SSCTRLn){
				case SSCTRLn_1STSAMPLE:				/* SSCTRL1_1STSAMPLE */
					ADC1 -> SSCTL1 |= (SSCTRL0F << ZERO);
				break;
				case SSCTRLn_2NDSAMPLE:				/* SSCTRL1_2NDSAMPLE */
					ADC1 -> SSCTL1 |= (SSCTRL0F << FOUR);
				break;
				case SSCTRLn_3RDSAMPLE:				/* SSCTRL1_3RDSAMPLE */
					ADC1 -> SSCTL1 |= (SSCTRL0F << EIGTH);
				break;
				default:							/* SSCTRL1_4THSAMPLE */
					ADC1 -> SSCTL1 |= (SSCTRL0F << TWELVE);
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
					ADC0 -> SSCTL2 |= (SSCTRLF << ZERO);			
				break;
				case SSCTRL0_2NDSAMPLE:				/* SSCTRL2_2NDSAMPLE */
					ADC0 -> SSCTL2 |= (SSCTRLF << FOUR);
				break;
				case SSCTRL0_3RDSAMPLE:				/* SSCTRL2_3RDSAMPLE */
					ADC0 -> SSCTL2 |= (SSCTRLF << EIGTH);
				break;
				default:							/* SSCTRL2_4THSAMPLE */
					ADC0 -> SSCTL2 |= (SSCTRLF << TWELVE);
				break;
			}
		}
		else{					/* ADC Module 1 */
			switch(SSCTRLn){
				case SSCTRL0_1STSAMPLE:				/* SSCTRL2_1STSAMPLE */
					ADC1 -> SSCTL2 |= (SSCTRLF << ZERO);
				break;
				case SSCTRL0_2NDSAMPLE:				/* SSCTRL2_2NDSAMPLE */
					ADC1 -> SSCTL2 |= (SSCTRLF << FOUR);
				break;
				case SSCTRL0_3RDSAMPLE:				/* SSCTRL2_3RDSAMPLE */
					ADC1 -> SSCTL2 |= (SSCTRLF << EIGTH);
				break;
				default:							/* SSCTRL2_4THSAMPLE */
					ADC1 -> SSCTL2 |= (SSCTRLF << TWELVE);
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
			ADC1 -> SSCTL3 |= ((SSCTRLF << ZERO) | SSCTLn_ENDn);		/* SSCTRL3_1STSAMPLE */
		}
		else{					/* ADC Module 1 */
			ADC1 -> SSCTL3 |= ((SSCTRLF << ZERO) | SSCTLn_ENDn);		/* SSCTRL3_1STSAMPLE */
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
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << ZERO);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << FOUR);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << EIGTH);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << TWELVE);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << SIXTEEN);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << TWENTY);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << TWENTYFOUR);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC0 -> SSCTL0 |= (SSCTLn_ENDn << TWENTYEIGTH);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRL0){
			case SSCTRL0_1STSAMPLE:				/* SSCTRL0_1STSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << ZERO);
			break;
			case SSCTRL0_2NDSAMPLE:				/* SSCTRL0_2NDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << FOUR);
			break;
			case SSCTRL0_3RDSAMPLE:				/* SSCTRL0_3RDSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << EIGTH);
			break;
			case SSCTRL0_4THSAMPLE:				/* SSCTRL0_4THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << TWELVE);
			break;
			case SSCTRL0_5THSAMPLE:				/* SSCTRL0_5THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << SIXTEEN);
			break;
			case SSCTRL0_6THSAMPLE:				/* SSCTRL0_6THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << TWENTY);
			break;
			case SSCTRL0_7THSAMPLE:				/* SSCTRL0_7THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << TWENTYFOUR);
			break;
			default:							/* SSCTRL0_8THSAMPLE */
				ADC1 -> SSCTL0 |= (SSCTLn_ENDn << TWENTYEIGTH);
			break;
		}
	}
}

/* 
*	ADC12_Set_End_SS_Ctrl1(ADC_MODn_t, SSCTRLn_t)
*   
*
*/

void ADC12_Set_End_SS_Ctrl1(ADC_MODn_t ADC_MODn, SSCTRLn_t SSCTRLn){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(SSCTRLn){
			case SSCTRLn_1STSAMPLE:				/* SSCTRL1_1STSAMPLE */
				ADC0 -> SSCTL1 |= (SSCTLn_ENDn << ZERO);
			break;
			case SSCTRLn_2NDSAMPLE:				/* SSCTRL1_2NDSAMPLE */
				ADC0 -> SSCTL1 |= (SSCTLn_ENDn << FOUR);
			break;
			case SSCTRLn_3RDSAMPLE:				/* SSCTRL1_3RDSAMPLE */
				ADC0 -> SSCTL1 |= (SSCTLn_ENDn << EIGTH);
			break;
			default:							/* SSCTRL1_4THSAMPLE */
				ADC0 -> SSCTL1 |= (SSCTLn_ENDn << TWELVE);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRLn){
			case SSCTRLn_1STSAMPLE:				/* SSCTRL1_1STSAMPLE */
				ADC1 -> SSCTL1 |= (SSCTLn_ENDn << ZERO);
			break;
			case SSCTRLn_2NDSAMPLE:				/* SSCTRL1_2NDSAMPLE */
				ADC1 -> SSCTL1 |= (SSCTLn_ENDn << FOUR);
			break;
			case SSCTRLn_3RDSAMPLE:				/* SSCTRL1_3RDSAMPLE */
				ADC1 -> SSCTL1 |= (SSCTLn_ENDn << EIGTH);
			break;
			default:							/* SSCTRL1_4THSAMPLE */
				ADC1 -> SSCTL1 |= (SSCTLn_ENDn << TWELVE);
			break;
		}
	}
}

void ADC12_Set_End_SS_Ctrl2(ADC_MODn_t ADC_MODn, SSCTRLn_t SSCTRLn){
	if(ADC_MOD0 == ADC_MODn){		/* ADC Module 0 */
		switch(SSCTRLn){
			case SSCTRLn_1STSAMPLE:				/* SSCTRL2_1STSAMPLE */
				ADC0 -> SSCTL2 |= (SSCTLn_ENDn << ZERO);
			break;
			case SSCTRLn_2NDSAMPLE:				/* SSCTRL2_2NDSAMPLE */
				ADC0 -> SSCTL2 |= (SSCTLn_ENDn << FOUR);
			break;
			case SSCTRLn_3RDSAMPLE:				/* SSCTRL2_3RDSAMPLE */
				ADC0 -> SSCTL2 |= (SSCTLn_ENDn << EIGTH);
			break;
			default:							/* SSCTRL2_4THSAMPLE */
				ADC0 -> SSCTL2 |= (SSCTLn_ENDn << TWELVE);
			break;
		}
	}
	else{					/* ADC Module 1 */
		switch(SSCTRLn){
			case SSCTRLn_1STSAMPLE:				/* SSCTRL2_1STSAMPLE */
				ADC1 -> SSCTL2 |= (SSCTLn_ENDn << ZERO);
			break;
			case SSCTRLn_2NDSAMPLE:				/* SSCTRL2_2NDSAMPLE */
				ADC1 -> SSCTL2 |= (SSCTLn_ENDn << FOUR);
			break;
			case SSCTRLn_3RDSAMPLE:				/* SSCTRL2_3RDSAMPLE */
				ADC1 -> SSCTL2 |= (SSCTLn_ENDn << EIGTH);
			break;
			default:							/* SSCTRL2_4THSAMPLE */
				ADC1 -> SSCTL2 |= (SSCTLn_ENDn << TWELVE);
			break;
		}
	}
}

/* 
*	ADC12_Interrupt_Mask(ADC_MODn_t)
*   
*
*/

void ADC12_Interrupt_Mask(ADC_MODn_t ADC_MODn ){
	
}

/* 
*	ADC12_Enable_SS_Logic(ADC_MODn_t, ADC_SSn_t)
*   
*
*/

void ADC12_Enable_SS_Logic(ADC_MODn_t ADC_MODn, ADC_SSn_t ADC_SSn){
	if (ADC_MOD0 == ADC_MODn){
		switch(ADC_SSn){
			case ADC_SS0:
				ADC0 -> ACTSS |= ONE << ZERO;
			break;
			case ADC_SS1:
				ADC0 -> ACTSS |= ONE << ONE;
			break;
			case ADC_SS2:
				ADC0 -> ACTSS |= ONE << TWO;
			break;
			default:
				ADC0 -> ACTSS |= ONE << THREE;
			break;			
		}
	}
	else{
		switch(ADC_SSn){
			case ADC_SS0:
				ADC1 -> ACTSS |= ONE << ZERO;
			break;
			case ADC_SS1:
				ADC1 -> ACTSS |= ONE << ZERO;
			break;
			case ADC_SS2:
				ADC1 -> ACTSS |= ONE << ZERO;
			break;
			default:
				ADC1 -> ACTSS |= ONE << ZERO;
			break;			
		}
	}
	
}

