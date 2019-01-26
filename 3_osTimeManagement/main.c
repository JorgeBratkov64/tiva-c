#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "leds.h"

void threadRed(void const *argument){
	while(1){
		RED_toggle();
		osDelay(1000);
	}
}

void threadBlue(void const *argument){
	while(1){
		BLUE_toggle();
		osDelay(1000);
	}
}

void threadGreen(void const *argument){
	while(1){
		GREEN_toggle();
		osDelay(1000);
	}
}



osThreadDef(threadRed, osPriorityNormal, 1, 0);
osThreadDef(threadBlue, osPriorityNormal, 1, 0);
osThreadDef(threadGreen, osPriorityNormal, 1, 0);
		

int main(void){
	LED_Init();
	osThreadCreate(osThread(threadRed),NULL);
	osThreadCreate(osThread(threadBlue),NULL);
	osThreadCreate(osThread(threadGreen),NULL);
	

	while(1){

	}
	
}
