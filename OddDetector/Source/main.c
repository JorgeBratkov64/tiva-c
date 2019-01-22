#include <stdint.h>
#include "odddetector.h"

#define Even 0							// Shortcuts to refer to the various
#define Odd 1								// states in the FSM machine

void PLL_Init(void);
void PortF_Init(void);
void SysTick_Wait(unsigned long delay);



struct state{
	unsigned char out;				// Output for the state
	unsigned short wait;			// Time to wait when in the present state
	unsigned char next[2]; 		// Next state array
};
typedef const struct state Stype;

unsigned char cState;				// Current state is Even/Odd

Stype FSM[2]={							// The data structure that captures the FSM state transition graph
	
	{0, 4, {Even, Odd}}, 
	{1, 4, {Odd, Even}}
};


int main(void){
	unsigned char input;
	PLL_Init();
	PortF_Init();
	cState = Even;
	while(1){																					//output based on current state
     GPIO_PORTF_DATA_R = FSM[cState].out<<3; 				//Output to PF2
		 SysTick_Wait(FSM[cState].wait);  							// wait for time relevant to state get input   
     input = (~GPIO_PORTF_DATA_R & 0x10)>>4;				// Input 0/1: Sw1 NotPressed/Pressed		
     cState = FSM[cState].next[input]; 							// change state based on input and current state
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
  delay = SYSCTL_RCGC2_R;           // Allow time for clock to start
	GPIO_PORTF_DIR_R |= 0xEF;
	GPIO_PORTF_AFSEL_R &= 0x00;
	GPIO_PORTF_PUR_R |= 0x10;
	GPIO_PORTF_DEN_R |= 0X18;
}

void SysTick_Wait(unsigned long delay){
	unsigned long i;
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x7A1200;  		// 100 ms count
	NVIC_ST_CURRENT_R = 0x00;					// Clear current value
	NVIC_ST_CTRL_R |= 0x00000005; 		//Run On System Clock & Enable 
	for(i=delay-1; i>0; i--){
		while((NVIC_ST_CTRL_R & 0x00010000) == 0);
	}
}


