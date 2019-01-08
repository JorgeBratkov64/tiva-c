#include "led.h"
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX

void threadMAGENTA(void const *argument){
	while(1){
		RED_toggle();
	}
}

void threadCIAN(void const *argument){
	while(1){
		BLUE_toggle();
	}
}

/* Type ID definitions for threads*/
osThreadId id_main, id_MAGENTA, id_CIAN;

/* Definitions for threads*/
/*  osThreadDef(threadName, threadPriority, threadInstanceNumber, defaultThreadStackSize);*/

osThreadDef(threadCIAN, osPriorityNormal, 1, 0);
osThreadDef(threadMAGENTA, osPriorityNormal, 1, 0);

int main(void){
	LED_Init();
	id_main = osThreadGetId();
	id_MAGENTA = osThreadCreate(osThread(threadMAGENTA), NULL);
	id_CIAN = osThreadCreate(osThread(threadCIAN), NULL);
	osThreadTerminate(id_main);
	while(1){};
}
