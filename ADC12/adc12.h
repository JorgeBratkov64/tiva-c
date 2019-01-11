#ifndef __ADC12_H
#define __ADC12_H

typedef char ADC_Channel;

typedef enum{
	ENABLE_ADC_MODULE0 = 1,
	ENABLE_ADC_MODULE1,
	ENABLE_ADC_BOTH 
} ADC_Enable_t;

typedef enum{
	DISABLE_ADC_MODULE0 = 1,
	DISABLE_ADC_MODULE1,
	DISABLE_ADC_BOTH 
} ADC_Disable_t;

typedef enum{
	ADC_PORTB_CHANNELS = 1,
	ADC_PORTD_CHANNELS = 4,
	ADC_PORTE_CHANNELS = 8
} ADC_Port_Clock_t;
	
typedef struct ADC_Init_t{
	ADC_Enable_t ADC_Module;
	ADC_Port_Clock_t ADC_Ports;
	
}ADC_Init_t;


void ADC12_Enable(ADC_Enable_t);
void ADC12_Disable(ADC_Disable_t);

#endif
