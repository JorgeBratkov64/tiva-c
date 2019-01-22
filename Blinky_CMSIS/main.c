#include "led.h"

int main(void){

	LED_Init();

	while(1){
		RED_toggle();
		BLUE_toggle();
		MAGENTA_toggle();
		GREEN_toggle();
		YELLOW_toggle();
		CIAN_toggle();
		WHITE_toggle();
	}
}


