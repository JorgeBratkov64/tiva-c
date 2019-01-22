#include "adc.h"
#include "stdint.h"
#include "adc_Cfg.h"



ADC_Module_t ADC_Module_0 = {
	/*******************************************/
	/* Bit fields in the ADC_O_ACTSS register. */
	ADC_ACTSS_ASEN3 + ADC_ACTSS_ASEN2 + ADC_ACTSS_ASEN1 + ADC_ACTSS_ASEN0
	,
	/*******************************************/
	/* Bit fields in the ADC_O_IM register. */
	ADC_IM_DCONSS3 + ADC_IM_DCONSS2 + ADC_IM_DCONSS1 +ADC_IM_DCONSS0 + ADC_IM_MASK3 + ADC_IM_MASK2 + ADC_IM_MASK1 + ADC_IM_MASK0
	,
	/*******************************************/
	/* Bit fields in the ADC_O_EMUX register. */
	/* Sample Sequencer 3 */ 
	ADC_EMUX_EM3_M + ADC_EMUX_EM3_PROCESSOR + ADC_EMUX_EM3_COMP0 + ADC_EMUX_EM3_COMP1 + ADC_EMUX_EM3_EXTERNAL +
	ADC_EMUX_EM3_TIMER + ADC_EMUX_EM3_PWM0 + ADC_EMUX_EM3_PWM1 + ADC_EMUX_EM3_PWM2 + ADC_EMUX_EM3_PWM3 + ADC_EMUX_EM3_ALWAYS + 
	
	/* Sample Sequencer 2 */
	ADC_EMUX_EM2_M + ADC_EMUX_EM2_PROCESSOR + ADC_EMUX_EM2_COMP0 + ADC_EMUX_EM2_COMP1 + ADC_EMUX_EM2_EXTERNAL +
	ADC_EMUX_EM2_TIMER + ADC_EMUX_EM2_PWM0 + ADC_EMUX_EM2_PWM1 + ADC_EMUX_EM2_PWM2 + ADC_EMUX_EM2_PWM3 + ADC_EMUX_EM2_ALWAYS + 
	
	/* Sample Sequencer 1 */
	ADC_EMUX_EM1_M + ADC_EMUX_EM1_PROCESSOR + ADC_EMUX_EM1_COMP0 + ADC_EMUX_EM1_COMP1 + ADC_EMUX_EM1_EXTERNAL +
	ADC_EMUX_EM1_TIMER + ADC_EMUX_EM1_PWM0 + ADC_EMUX_EM1_PWM1 + ADC_EMUX_EM1_PWM2 + ADC_EMUX_EM1_PWM3 + ADC_EMUX_EM1_ALWAYS + 
	
	/* Sample Sequencer 0 */
	ADC_EMUX_EM0_M + ADC_EMUX_EM0_PROCESSOR + ADC_EMUX_EM0_COMP0 + ADC_EMUX_EM0_COMP1 + ADC_EMUX_EM0_EXTERNAL +
	ADC_EMUX_EM0_TIMER + ADC_EMUX_EM0_PWM0 + ADC_EMUX_EM0_PWM1 + ADC_EMUX_EM0_PWM2 + ADC_EMUX_EM0_PWM3 + ADC_EMUX_EM0_ALWAYS
	, 
	/*******************************************/
	/* Bit fields in the ADC_O_TSSEL register. */
	/* Sample Sequencer 3 */ 
	ADC_TSSEL_PS3_M + ADC_TSSEL_PS3_0 + ADC_TSSEL_PS3_1 +
	
	/* Sample Sequencer 2 */ 
	ADC_TSSEL_PS2_M + ADC_TSSEL_PS2_0 + ADC_TSSEL_PS2_1 +
	
	/* Sample Sequencer 1 */ 
	ADC_TSSEL_PS1_M + ADC_TSSEL_PS1_0 + ADC_TSSEL_PS1_1 +
	
	/* Sample Sequencer 0 */ 
	ADC_TSSEL_PS0_M + ADC_TSSEL_PS0_0 + ADC_TSSEL_PS0_1
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSPRI register. */
	ADC_SSPRI_SS3_M + ADC_SSPRI_SS2_M + ADC_SSPRI_SS1_M + ADC_SSPRI_SS3_M
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SPC register. */
	/* ADC_SPC_PHASE_M	*/
	ADC_SPC_PHASE_0
	/* ADC_SPC_PHASE_22_5	*/
	/* ADC_SPC_PHASE_45		*/
	/* ADC_SPC_PHASE_67_5	*/
	/* ADC_SPC_PHASE_90		*/
	/* ADC_SPC_PHASE_112_5	*/
	/* ADC_SPC_PHASE_135	*/
	/* ADC_SPC_PHASE_157_5	*/
	/* ADC_SPC_PHASE_180	*/
	/* ADC_SPC_PHASE_202_5	*/
	/* ADC_SPC_PHASE_225	*/
	/* ADC_SPC_PHASE_247_5	*/
	/* ADC_SPC_PHASE_270	*/
	/* ADC_SPC_PHASE_292_5	*/
	/* ADC_SPC_PHASE_315	*/
	/* ADC_SPC_PHASE_337_5	*/
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_PSSI register. */
	ADC_PSSI_GSYNC + ADC_PSSI_SYNCWAIT + ADC_PSSI_SS3 + ADC_PSSI_SS2 + ADC_PSSI_SS1 + ADC_PSSI_SS0
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SAC register. */
	/* ADC_SAC_AVG_M + */
	ADC_SAC_AVG_OFF 
	/* ADC_SAC_AVG_2X */
	/* ADC_SAC_AVG_4X */
	/* ADC_SAC_AVG_8X */
	/* ADC_SAC_AVG_16X */
	/* ADC_SAC_AVG_32X */
	/* ADC_SAC_AVG_64X */
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_CTL register. */
	/* ADC_CTL_DITHER */
	/* ADC_CTL_VREF_M */
	ADC_CTL_VREF_INTERNAL
	,
	
	/********************************************************************************************/
	/*						SAMPLE SEQUENCER 0 CONFIGURATION									*/	
	/********************************************************************************************/
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSMUX0 register. */
	/* Modify the values of ADC_SSMUX0_MUXx_M to match the corresponding analog channel AINx */
	(ADC_SSMUX0_MUX7_M << ADC_SSMUX0_MUX7_S) + 
	(ADC_SSMUX0_MUX6_M << ADC_SSMUX0_MUX6_S) + 
	(ADC_SSMUX0_MUX5_M << ADC_SSMUX0_MUX5_S) + 
	(ADC_SSMUX0_MUX4_M << ADC_SSMUX0_MUX4_S) + 
	(ADC_SSMUX0_MUX3_M << ADC_SSMUX0_MUX3_S) + 
	(ADC_SSMUX0_MUX2_M << ADC_SSMUX0_MUX2_S) + 
	(ADC_SSMUX0_MUX1_M << ADC_SSMUX0_MUX1_S) + 
	(ADC_SSMUX0_MUX0_M << ADC_SSMUX0_MUX0_S)
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSCTL0 register. */
	/* 8th Sample Configuration */
	ADC_SSCTL0_TS7 + ADC_SSCTL0_IE7 + ADC_SSCTL0_END7 + ADC_SSCTL0_D7 +
	
	/* 7th Sample Configuration */
	ADC_SSCTL0_TS6 + ADC_SSCTL0_IE6 + ADC_SSCTL0_END6 + ADC_SSCTL0_D6 +
	
	/* 6th Sample Configuration */
	ADC_SSCTL0_TS5 + ADC_SSCTL0_IE5 + ADC_SSCTL0_END5 + ADC_SSCTL0_D5 +
	
	/* 5th Sample Configuration */
	ADC_SSCTL0_TS4 + ADC_SSCTL0_IE4 + ADC_SSCTL0_END4 + ADC_SSCTL0_D4 +
	
	/* 4th Sample Configuration */
	ADC_SSCTL0_TS3 + ADC_SSCTL0_IE3 + ADC_SSCTL0_END3 + ADC_SSCTL0_D3 +
	
	/* 3rd Sample Configuration */
	ADC_SSCTL0_TS2 + ADC_SSCTL0_IE2 + ADC_SSCTL0_END5 + ADC_SSCTL0_D2 +
	
	/* 2nd Sample Configuration */
	ADC_SSCTL0_TS1 + ADC_SSCTL0_IE1 + ADC_SSCTL0_END1 + ADC_SSCTL0_D1 +
	
	/* 1st Sample Configuration */
	ADC_SSCTL0_TS0 + ADC_SSCTL0_IE0 + ADC_SSCTL0_END0 + ADC_SSCTL0_D0 
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSOP0 register. */
	ADC_SSOP0_NULL
	/* ADC_SSOP0_S7DCOP +	*/
	/* ADC_SSOP0_S6DCOP +	*/
	/* ADC_SSOP0_S5DCOP + 	*/
	/* ADC_SSOP0_S4DCOP +	*/	
	/* ADC_SSOP0_S3DCOP +	*/
	/* ADC_SSOP0_S2DCOP +	*/
	/* ADC_SSOP0_S1DCOP + 	*/
	/* ADC_SSOP0_S0DCOP		*/
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSDC0 register. */
	ADC_SSDC0_NULL_M
	/* (ADC_SSDC0_S7DCSEL_M <<  ADC_SSDC0_S7DCSEL_S) +	*/
	/* (ADC_SSDC0_S6DCSEL_M <<  ADC_SSDC0_S6DCSEL_S) +	*/
	/* (ADC_SSDC0_S5DCSEL_M <<  ADC_SSDC0_S5DCSEL_S) +	*/
	/* (ADC_SSDC0_S4DCSEL_M <<  ADC_SSDC0_S4DCSEL_S) +	*/
	/* (ADC_SSDC0_S3DCSEL_M <<  ADC_SSDC0_S3DCSEL_S) +	*/	
	/* (ADC_SSDC0_S2DCSEL_M <<  ADC_SSDC0_S2DCSEL_S) +	*/
	/* (ADC_SSDC0_S1DCSEL_M <<  ADC_SSDC0_S1DCSEL_S) +	*/
	/* (ADC_SSDC0_S0DCSEL_M <<  ADC_SSDC0_S0DCSEL_S)	*/
	,
	
	/********************************************************************************************/
	/*						SAMPLE SEQUENCER 1 CONFIGURATION									*/	
	/********************************************************************************************/
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSMUX1 register. */
	/* Modify the values of ADC_SSMUX1_MUXx_M to match the corresponding analog channel AINx */
	(ADC_SSMUX1_MUX3_M << ADC_SSMUX1_MUX3_S) + 
	(ADC_SSMUX1_MUX2_M << ADC_SSMUX1_MUX2_S) + 
	(ADC_SSMUX1_MUX1_M << ADC_SSMUX1_MUX1_S) + 
	(ADC_SSMUX1_MUX0_M << ADC_SSMUX1_MUX0_S)
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSCTL1 register. */
	/* 4th Sample Configuration */
	ADC_SSCTL1_TS3 + ADC_SSCTL1_IE3 + ADC_SSCTL1_END3 + ADC_SSCTL1_D3 +
	
	/* 3rd Sample Configuration */
	ADC_SSCTL1_TS2 + ADC_SSCTL1_IE2 + ADC_SSCTL1_END2 + ADC_SSCTL1_D2 +
	
	/* 2nd Sample Configuration */
	ADC_SSCTL1_TS1 + ADC_SSCTL1_IE1 + ADC_SSCTL1_END1 + ADC_SSCTL1_D1 +
	
	/* 1st Sample Configuration */
	ADC_SSCTL1_TS0 + ADC_SSCTL1_IE0 + ADC_SSCTL1_END0 + ADC_SSCTL1_D0 
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSOP1 register. */
	ADC_SSOP1_NULL
	/* ADC_SSOP1_S3DCOP +	*/
	/* ADC_SSOP1_S2DCOP +	*/
	/* ADC_SSOP1_S1DCOP + 	*/
	/* ADC_SSOP1_S0DCOP		*/
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSDC1 register. */
	ADC_SSDC1_NULL_M
	/* (ADC_SSDC1_S3DCSEL_M <<  ADC_SSDC1_S3DCSEL_S) +	*/	
	/* (ADC_SSDC1_S2DCSEL_M <<  ADC_SSDC1_S2DCSEL_S) +	*/
	/* (ADC_SSDC1_S1DCSEL_M <<  ADC_SSDC1_S1DCSEL_S) +	*/
	/* (ADC_SSDC1_S0DCSEL_M <<  ADC_SSDC1_S0DCSEL_S)	*/
	,
	
	/********************************************************************************************/
	/*						SAMPLE SEQUENCER 2 CONFIGURATION									*/	
	/********************************************************************************************/
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSMUX2 register. */
	/* Modify the values of ADC_SSMUX2_MUXx_M to match the corresponding analog channel AINx */
	(ADC_SSMUX2_MUX3_M << ADC_SSMUX2_MUX3_S) + 
	(ADC_SSMUX2_MUX2_M << ADC_SSMUX2_MUX2_S) + 
	(ADC_SSMUX2_MUX1_M << ADC_SSMUX2_MUX1_S) + 
	(ADC_SSMUX2_MUX0_M << ADC_SSMUX2_MUX0_S)
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSCTL2 register. */
	/* 4th Sample Configuration */
	ADC_SSCTL2_TS3 + ADC_SSCTL2_IE3 + ADC_SSCTL2_END3 + ADC_SSCTL2_D3 +
	
	/* 3rd Sample Configuration */
	ADC_SSCTL2_TS2 + ADC_SSCTL2_IE2 + ADC_SSCTL2_END2 + ADC_SSCTL2_D2 +
	
	/* 2nd Sample Configuration */
	ADC_SSCTL2_TS1 + ADC_SSCTL2_IE1 + ADC_SSCTL2_END1 + ADC_SSCTL2_D1 +
	
	/* 1st Sample Configuration */
	ADC_SSCTL2_TS0 + ADC_SSCTL2_IE0 + ADC_SSCTL2_END0 + ADC_SSCTL2_D0 
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSOP2 register. */
	ADC_SSOP2_NULL
	/* ADC_SSOP2_S3DCOP +	*/
	/* ADC_SSOP2_S2DCOP +	*/
	/* ADC_SSOP2_S1DCOP + 	*/
	/* ADC_SSOP2_S0DCOP		*/
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSDC2 register. */
	ADC_SSDC2_NULL_M
	/* (ADC_SSDC2_S3DCSEL_M <<  ADC_SSDC2_S3DCSEL_S) +	*/	
	/* (ADC_SSDC2_S2DCSEL_M <<  ADC_SSDC2_S2DCSEL_S) +	*/
	/* (ADC_SSDC2_S1DCSEL_M <<  ADC_SSDC2_S1DCSEL_S) +	*/
	/* (ADC_SSDC2_S0DCSEL_M <<  ADC_SSDC2_S0DCSEL_S)	*/
	,
	
	/********************************************************************************************/
	/*						SAMPLE SEQUENCER 3 CONFIGURATION									*/	
	/********************************************************************************************/
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSMUX3 register. */
	/* Modify the values of ADC_SSMUX3_MUXx_M to match the corresponding analog channel AINx */
	(ADC_SSMUX3_MUX0_M << ADC_SSMUX3_MUX0_S)
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSCTL3 register. */
	/* 1st Sample Configuration */
	ADC_SSCTL3_TS0 + ADC_SSCTL3_IE0 + ADC_SSCTL3_END0 + ADC_SSCTL3_D0 
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSOP3 register. */
	ADC_SSOP3_NULL
	/* ADC_SSOP3_S0DCOP		*/
	,
	
	/*******************************************/
	/* Bit fields in the ADC_O_SSDC3 register. */
	ADC_SSDC3_NULL_M
	/* (ADC_SSDC3_S0DCSEL_M <<  ADC_SSDC3_S0DCSEL_S)	*/
	
};
