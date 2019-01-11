
#ifndef __ADC12_H
#define __ADC12_H

#include "stdint.h"

/* AFSEL BITS FOR PORT B*/
#define ADC_AFSEL_AIN10	(1 << 4) 	/* AIN10 -> PB4 */
#define ADC_AFSEL_AIN11	(1 << 5) 	/* AIN11 -> PB5 */

/* AFSEL BITS FOR PORT D*/
#define ADC_AFSEL_AIN7	(1 << 0)	/* AIN7 -> PD0 */
#define ADC_AFSEL_AIN6	(1 << 1)	/* AIN6 -> PD1 */
#define ADC_AFSEL_AIN5	(1 << 2)	/* AIN5 -> PD2 */
#define ADC_AFSEL_AIN4	(1 << 3)	/* AIN4 -> PD3 */

/* AFSEL BITS FOR PORT E*/
#define ADC_AFSEL_AIN3	(1 << 0)	/* AIN3 -> PE0 */
#define ADC_AFSEL_AIN2	(1 << 1)	/* AIN2 -> PE1 */
#define ADC_AFSEL_AIN1	(1 << 2)	/* AIN1 -> PE2 */
#define ADC_AFSEL_AIN0	(1 << 3)	/* AIN0 -> PE3 */
#define ADC_AFSEL_AIN9	(1 << 4)	/* AIN9 -> PE4 */
#define ADC_AFSEL_AIN8	(1 << 5)	/* AIN8 -> PE5 */


typedef uint8_t ADC_AFSEL_PORTB;
typedef uint8_t ADC_AFSEL_PORTD;
typedef uint8_t ADC_AFSEL_PORTE;

/* CLEAR DEN BITS FOR PORT B*/
#define ADC_CLEAR_DEN_AIN10	~(1 << 4) 	/* AIN10 -> PB4 */
#define ADC_CLEAR_DEN_AIN11	~(1 << 5) 	/* AIN11 -> PB5 */

/* CLEAR DEN BITS FOR PORT D*/
#define ADC_CLEAR_DEN_AIN7	~(1 << 0)	/* AIN7 -> PD0 */
#define ADC_CLEAR_DEN_AIN6	~(1 << 1)	/* AIN6 -> PD1 */
#define ADC_CLEAR_DEN_AIN5	~(1 << 2)	/* AIN5 -> PD2 */
#define ADC_CLEAR_DEN_AIN4	~(1 << 3)	/* AIN4 -> PD3 */

/* CLEAR DEN BITS FOR PORT E*/
#define ADC_CLEAR_DEN_AIN3	~(1 << 0)	/* AIN3 -> PE0 */
#define ADC_CLEAR_DEN_AIN2	~(1 << 1)	/* AIN2 -> PE1 */
#define ADC_CLEAR_DEN_AIN1	~(1 << 2)	/* AIN1 -> PE2 */
#define ADC_CLEAR_DEN_AIN0	~(1 << 3)	/* AIN0 -> PE3 */
#define ADC_CLEAR_DEN_AIN9	~(1 << 4)	/* AIN9 -> PE4 */
#define ADC_CLEAR_DEN_AIN8	~(1 << 5)	/* AIN8 -> PE5 */

typedef uint8_t ADC_CLEAR_DEN__PORTB;
typedef uint8_t ADC_CLEAR_DEN__PORTD;
typedef uint8_t ADC_CLEAR_DEN__PORTE;

typedef uint8_t ADC_AMSEL__PORTB;
typedef uint8_t ADC_AMSEL__PORTD;
typedef uint8_t ADC_AMSEL__PORTE;




typedef enum{
	ENABLE_ADC_MODULE0 = 1,
	ENABLE_ADC_MODULE1,
	ENABLE_ADC_BOTH 
} ADC_Enable_t;

typedef enum{
	DISABLE_ADC_MODULE0 = 1,
	DISABLE_ADC_MODULE1,
	DISABLE_ADC_BOTH 
} ADC_Disable_t;

typedef enum{
	ADC_PORTB_CHANNELS = 1,
	ADC_PORTD_CHANNELS = 4,
	ADC_PORTE_CHANNELS = 8
} ADC_Port_Clock_t;
	
typedef struct ADC_Init_t{
	ADC_Enable_t ADC_Module;				/* Enable ADC clock*/ 
	ADC_Port_Clock_t ADC_Ports;				/* Enable the clock to appropiate GPIO modules */
	
}ADC_Init_t;


void ADC12_Enable(ADC_Enable_t);
void ADC12_Disable(ADC_Disable_t);

#endif
