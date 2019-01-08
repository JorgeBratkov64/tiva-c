#include "TM4C123.h"                    // Device header
#include "led.h"

#define PORTF (1U << 5)
#define RED_LED	(2U << 0)
#define BLUE_LED	(1U << 2)	
#define GREEN_LED	(1U << 3)

static void delay(unsigned int);

static void delay(unsigned int delay){
	volatile unsigned int i;
	for(i=0; i< delay; i++);
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
	delay(1000000);
	GPIOF -> DATA &= 0;							/* OFF */
	delay(500000);
}

void BLUE_toggle(void){
	GPIOF -> DATA |= BLUE_LED;					/* BLUE_LED */
	delay(10000000);
	GPIOF -> DATA &= 0;							/* OFF */
	delay(500000);
}

void GREEN_toggle(void){
	GPIOF -> DATA |= GREEN_LED;					/* GREEN_LED */
	delay(1000000);	
	GPIOF -> DATA &= 0;							/* OFF */
	delay(500000);
}
	
void MAGENTA_toggle(void){
	GPIOF -> DATA |= RED_LED | BLUE_LED;		/* MAGENTA */
	delay(1000000);
	GPIOF -> DATA &= 0;							/* OFF */
	delay(500000);
}

void YELLOW_toggle(void){
	GPIOF -> DATA |= GREEN_LED | RED_LED;		/* YELLOW */
	delay(1000000);
	GPIOF -> DATA &= 0;							/* OFF */
	delay(1000000);
}

void CIAN_toggle(void){
	GPIOF -> DATA |= GREEN_LED | BLUE_LED;		/* CIAN */
	delay(1000000);
	GPIOF -> DATA &= 0;							/* OFF */
	delay(500000);
}

void WHITE_toggle(void){
	GPIOF -> DATA |= RED_LED | GREEN_LED | BLUE_LED;		/* WHITE */
	delay(1000000);
	GPIOF -> DATA &= 0;							/* OFF */
	delay(500000);
}
