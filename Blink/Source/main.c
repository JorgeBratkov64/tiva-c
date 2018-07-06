/*  This program blink the RGB LED of the TM4C123G LaunchPad Evaluation Board
*   which is connected to PF1, PF2,and PF3 the PLL is enable and runnig at 80 MHz
*   The SysTick Timer has a count for 100 ms and it's used by the funtion
*		SysTick_Wait() to execute 
*		
*/

#include <stdint.h>
#include "blink.h"

void PLL_Init(void);
void PortF_Init(void);
void SysTick_Wait();

int main(void){
	
	PLL_Init();
	PortF_Init();

	while(1){
		
		GPIO_PORTF_DATA_R |= 0x0E;
		SysTick_Wait(20);	
		GPIO_PORTF_DATA_R &= 0x00;
		SysTick_Wait(10);
	}
	return 0;
} 

void PLL_Init(void){
  SYSCTL_RCC2_R |=  0x80000000;  
  SYSCTL_RCC2_R |=  0x00000800;  
  SYSCTL_RCC_R = (SYSCTL_RCC_R &~0x000007C0) + 0x00000540;   
  SYSCTL_RCC2_R &= ~0x00000070;  
  SYSCTL_RCC2_R &= ~0x00002000;
  SYSCTL_RCC2_R |= 0x40000000;   
  SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~ 0x1FC00000) + (4<<22);      
  while((SYSCTL_RIS_R&0x00000040)==0){};  
  SYSCTL_RCC2_R &= ~0x00000800;
}

void PortF_Init(void){
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // Activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
	GPIO_PORTF_DIR_R |= 0x000000FF;		// Enable all pins as outputs
	GPIO_PORTF_AFSEL_R &= 0x00;				// No Alternate Fucntion Available
	GPIO_PORTF_DEN_R |= 0x0E;					// 
}

void SysTick_Wait(unsigned long delay){
	unsigned long i;
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x7A1200;  // 100 ms count
	NVIC_ST_CURRENT_R = 0x00;			// Clear current value
	NVIC_ST_CTRL_R |= 0x00000005; //Run On System Clock & Enable 
	for(i=delay-1; i>0; i--){
		while((NVIC_ST_CTRL_R & 0x00010000) == 0);
	}
}







