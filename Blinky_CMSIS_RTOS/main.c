#include "led.h"
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX

void threadRED(void const *argument){
	while(1){
		RED_toggle();
	}
}

void threadBLUE(void const *argument){
	while(1){
		MAGENTA_toggle();
	}
}

/* Type ID definitions for threads*/
osThreadId id_main, id_RED, id_BLUE;

/* Definitions for threads*/
/*  osThreadDef(threadName, threadPriority, threadInstanceNumber, defaultThreadStackSize);*/

osThreadDef(threadBLUE, osPriorityNormal, 1, 0);
osThreadDef(threadRED, osPriorityNormal, 1, 0);

int main(void){
	LED_Init();
	id_main = osThreadGetId();
	id_RED = osThreadCreate(osThread(threadRED), NULL);
	id_BLUE = osThreadCreate(osThread(threadBLUE), NULL);
	osThreadTerminate(id_main);
	while(1){};
}
