#include <stdint.h>
#include "semaforo.h"
																											// Bit masking
#define OUTPUT  (*((volatile uint32_t *)0x400240FC))	// PE0-PE5 as outputs 
#define SENSOR  (*((volatile uint32_t *)0x4000700C)) 	// PD0,PD1 as inputs
	
#define GoNorth 0
#define WaitNorth 1
#define GoEast 2
#define WaitEast 3

void PLL_Init(void);
void SysTick_Wait(unsigned long delay);
void Port_Init(void);

struct state {
	unsigned long out;
	unsigned long wait;
	unsigned char next[4];
};
typedef const struct state SType;

SType FSM[4] = {
	/*
	Output Wait Next States
	*/
	{0x0C, 30, {GoNorth, WaitNorth, GoNorth, WaitNorth}},         
	{0x14, 10, {GoEast, GoEast, GoEast, GoEast}},
	{0x21, 30, {GoEast, GoEast, WaitEast, WaitEast}},
	{0x22, 10, {GoNorth, GoNorth, GoNorth, GoNorth,}}	
};



int main(void){
	unsigned long input;
	unsigned long cState;
	PLL_Init();
	Port_Init();
	cState = GoNorth;
	
	unsigned int toogle = 0xABCD;
	unsigned long mango = 0xFDEC1994;
	
	toogle ^= 0x0000;
	mango &= 0x00000000;	
	
	while(1){
		OUTPUT = FSM[cState].out;
		SysTick_Wait(FSM[cState].wait);
		input = SENSOR;
		cState = FSM[cState].next[input];
	}
	return 0;
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

void Port_Init(){
	unsigned long delay;
	SYSCTL_RCGC2_R |= 0x18;						// Enable clock for ports E and F
	delay = SYSCTL_RCGC2_R;
	
	GPIO_PORTE_LOCK_R = 0x4C4F434B;	// Unlock write the port
	GPIO_PORTE_CR_R |= 0x3F;					// Enable the write to corresponding pins
	GPIO_PORTE_DIR_R |= 0x3F;					// Configure pins as outputs
	GPIO_PORTE_AFSEL_R &= 0x00; 			// Disable alternae function
	GPIO_PORTE_PCTL_R &= 0x00;				// Clear PCMx pins
	GPIO_PORTE_DEN_R |= 0x3F;					// Enable digital function 	
	
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= 0x03;
	GPIO_PORTD_PUR_R |= 0x03;
	GPIO_PORTD_DIR_R |= 0xFC;
	GPIO_PORTD_AFSEL_R &= 0x00;
	GPIO_PORTD_DEN_R |= 0x03; 
	
}
