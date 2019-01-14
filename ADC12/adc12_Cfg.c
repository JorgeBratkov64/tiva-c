/*

TM4C123G adc12_Cfg.c

MIT License

Copyright (c) 2018 JorgeBratkov64

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "adc12.h"

//ADC_Init_t ADC_Init = {
//	ENABLE_ADC_MODULE0, 		/* ADC_Module  	ENABLE_ADC_MODULE0, ENABLE_ADC_MODULE1, ENABLE_ADC_BOTH*/
//	ADC_PORTB_CHANNELS,	/* ADC_Ports  	ADC_PORT_CHANNELS_DISABLE = 0, ADC_PORTB_CHANNELS, ADC_PORTD_CHANNELS, ADC_PORTE_CHANNELS*/
//	ADC_AFSEL_DISABLE,		/* ADC_PORTB  ADC_AFSEL_AIN10, ADC_AFSEL_AIN11*/
//	ADC_AFSEL_DISABLE,		/* ADC_PORTD ADC_AFSEL_AIN7, ADC_AFSEL_AIN6, ADC_AFSEL_AIN5, ADC_AFSEL_AIN4 */
//	ADC_AFSEL_DISABLE,		/* ADC_PORTE ADC_AFSEL_AIN3, ADC_AFSEL_AIN2, ADC_AFSEL_AIN1, ADC_AFSEL_AIN0, ADC_AFSEL_AIN9, ADC_AFSEL_AIN8 */
//	ADC_SET_DEN_PORTB,		/* ADC_CLEAR_DEN_PORTB  ADC_CLEAR_DEN_AIN10, ADC_CLEAR_DEN_AIN11 */
//	ADC_SET_DEN_PORTD,		/* ADC_CLEAR_DEN_PORTD ADC_CLEAR_DEN_AIN7, ADC_CLEAR_DEN_AIN6, ADC_CLEAR_DEN_AIN5, ADC_CLEAR_DEN_AIN4*/
//	ADC_SET_DEN_PORTE,		/* ADC_CLEAR_DEN_PORTE ADC_CLEAR_DEN_AIN3, ADC_CLEAR_DEN_AIN2, ADC_CLEAR_DEN_AIN1, ADC_CLEAR_DEN_AIN0, ADC_CLEAR_DEN_AIN9, ADC_CLEAR_DEN_AIN8*/
//	ADC_AMSEL_ENABLE_PORTB,		/* ADC_AMSEL_PROTB ADC_AMSEL_AIN10, ADC_AMSEL_AIN11*/
//	ADC_AMSEL_ENABLE_PORTD,		/* ADC_AMSEL_PROTD ADC_AMSEL_AIN7, ADC_AMSEL_AIN6, ADC_AMSEL_AIN5, ADC_AMSEL_AIN4*/
//	ADC_AMSEL_ENABLE_PORTE		/* ADC_AMSEL_PROTE ADC_AMSEL_AIN3, ADC_AMSEL_AIN2, ADC_AMSEL_AIN1, ADC_AMSEL_AIN0, ADC_AMSEL_AIN9, ADC_AMSEL_AIN8*/
//};


/* Declaration of Deinit structure for ADC. Uncomment if use */

//ADC_Deinit_t ADC_Deinit = {
//	DISABLE_ADC, 		/* ADC_Module */
//	ADC_PORT_CHANNELS_DISABLE,	 /* ADC_Ports */
//	ADC_AFSEL_DISABLE,		/* ADC_PORTB */
//	ADC_AFSEL_DISABLE,		/* ADC_PORTD */
//	ADC_AFSEL_DISABLE,		/* ADC_PORTE */
//	ADC_SET_DEN_PORTB,		/* ADC_CLEAR_DEN_PORTB */
//	ADC_SET_DEN_PORTD,		/* ADC_CLEAR_DEN_PORTD */
//	ADC_SET_DEN_PORTE,		/* ADC_CLEAR_DEN_PORTE */
//	ADC_AMSEL_ENABLE_PORTB,		/* ADC_AMSEL_PROTB */
//	ADC_AMSEL_ENABLE_PORTD,		/* ADC_AMSEL_PROTD */
//	ADC_AMSEL_ENABLE_PORTE		/* ADC_AMSEL_PROTE */
//};
