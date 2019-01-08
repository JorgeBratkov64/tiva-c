#include "TM4C123.h"                    // Device header
#include "led.h"

#define PORTF (1U << 5)
#define RED_LED	(2U << 0)
#define BLUE_LED	(1U << 2)	
#define GREEN_LED	(1U << 3)

// void delay(void);

void delay(){
	volatile unsigned int i;
	for(i=0; i< 1000000; i++);
}

void LED_Init( void ){
	volatile unsigned long delay = 0;
	SYSCTL -> RCGC2 |= PORTF; 
	delay = SYSCTL -> RCGC2;
	GPIOF -> DIR |= RED_LED | BLUE_LED | GREEN_LED;
	GPIOF -> AFSEL |= 0;
	GPIOF -> DEN |= RED_LED | BLUE_LED | GREEN_LED;	
}

void RED_toggle(void){
	GPIOF -> DATA |= RED_LED;					/* RED LED*/
	delay();
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}

void BLUE_toggle(void){
	GPIOF -> DATA |= BLUE_LED;					/* BLUE_LED */
	delay();
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}

void GREEN_toggle(void){
	GPIOF -> DATA |= GREEN_LED;					/* GREEN_LED */
	delay();	
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}
	
void MAGENTA_toggle(void){
	GPIOF -> DATA |= RED_LED | BLUE_LED;		/* MAGENTA */
	delay();
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}

void YELLOW_toggle(void){
	GPIOF -> DATA |= GREEN_LED | RED_LED;		/* YELLOW */
	delay();
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}

void CIAN_toggle(void){
	GPIOF -> DATA |= GREEN_LED | BLUE_LED;		/* CIAN */
	delay();
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}

void WHITE_toggle(void){
	GPIOF -> DATA |= RED_LED | GREEN_LED | BLUE_LED;		/* WHITE */
	delay();
	GPIOF -> DATA &= 0;							/* OFF */
	delay();
}
