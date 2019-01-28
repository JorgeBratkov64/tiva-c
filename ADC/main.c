#include "adc.h"
#include "gpio.h"

extern ADC_Module_t ADC_Module_0;

int main(void){

	
	adcInit(&ADC_Module_0, ADC_MOD0);
}

