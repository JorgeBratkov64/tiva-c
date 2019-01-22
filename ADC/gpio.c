/*

TM4C123G gpio.c

MIT License

Copyright (c) 2019 JorgeBratkov64

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

#include "stdint.h"
#include "TM4C123.h"                    // Device header
#include "gpio.h"

void gpioInit(GPIO_Port_t *GPIO_Port, GPIO_PORTn_t GPIO_PORTn){
	switch(GPIO_PORTn){
		case PORT_A:			/* GPIO Port A	*/
			GPIOA -> DIR = GPIO_Port -> gpioDirReg;
			GPIOA -> IS = GPIO_Port -> gpioIntSenseReg;
			GPIOA -> IBE = GPIO_Port -> gpioIntBothEdgeReg;
			GPIOA -> IEV = GPIO_Port -> gpioInteEvntReg;
			GPIOA -> IM = GPIO_Port -> gpioIntMaskReg;
			GPIOA -> AFSEL = GPIO_Port -> gpioAltenateFuncReg;
			GPIOA -> DR2R = GPIO_Port -> gpio2maDriverReg;
			GPIOA -> DR4R = GPIO_Port -> gpio4maDriverReg;
			GPIOA -> DR8R = GPIO_Port -> gpio8maDriverReg;
			GPIOA -> ODR = GPIO_Port -> gpioOpenDrainReg;
			GPIOA -> PUR = GPIO_Port -> gpioPullUpReg;
			GPIOA -> PDR = GPIO_Port -> gpioPullDownReg;
			GPIOA -> SLR = GPIO_Port -> gpioSlewRate;
			GPIOA -> DEN = GPIO_Port -> gpioDigitalEnableReg;
			GPIOA -> LOCK = GPIO_Port -> gpioLockReg;
			GPIOA -> AMSEL = GPIO_Port -> gpioAnalogModeReg;
			GPIOA -> PCTL = GPIO_Port ->  gpioPortCtrlReg;
			GPIOA -> ADCCTL = GPIO_Port -> gpioADCCtrlReg;
			GPIOA -> DMACTL = GPIO_Port -> gpioDMACtrlReg;
		break;
		case PORT_B:			/* GPIO Port B	*/
			GPIOB -> DIR = GPIO_Port -> gpioDirReg;
			GPIOB -> IS = GPIO_Port -> gpioIntSenseReg;
			GPIOB -> IBE = GPIO_Port -> gpioIntBothEdgeReg;
			GPIOB -> IEV = GPIO_Port -> gpioInteEvntReg;
			GPIOB -> IM = GPIO_Port -> gpioIntMaskReg;
			GPIOB -> AFSEL = GPIO_Port -> gpioAltenateFuncReg;
			GPIOB -> DR2R = GPIO_Port -> gpio2maDriverReg;
			GPIOB -> DR4R = GPIO_Port -> gpio4maDriverReg;
			GPIOB -> DR8R = GPIO_Port -> gpio8maDriverReg;
			GPIOB -> ODR = GPIO_Port -> gpioOpenDrainReg;
			GPIOB -> PUR = GPIO_Port -> gpioPullUpReg;
			GPIOB -> PDR = GPIO_Port -> gpioPullDownReg;
			GPIOB -> SLR = GPIO_Port -> gpioSlewRate;
			GPIOB -> DEN = GPIO_Port -> gpioDigitalEnableReg;
			GPIOB -> LOCK = GPIO_Port -> gpioLockReg;
			GPIOB -> AMSEL = GPIO_Port -> gpioAnalogModeReg;
			GPIOB -> PCTL = GPIO_Port ->  gpioPortCtrlReg;
			GPIOB -> ADCCTL = GPIO_Port -> gpioADCCtrlReg;
			GPIOB -> DMACTL = GPIO_Port -> gpioDMACtrlReg;
		break;
		case PORT_C:			/* GPIO Port C	*/
			GPIOC -> DIR = GPIO_Port -> gpioDirReg;
			GPIOC -> IS = GPIO_Port -> gpioIntSenseReg;
			GPIOC -> IBE = GPIO_Port -> gpioIntBothEdgeReg;
			GPIOC -> IEV = GPIO_Port -> gpioInteEvntReg;
			GPIOC -> IM = GPIO_Port -> gpioIntMaskReg;
			GPIOC -> AFSEL = GPIO_Port -> gpioAltenateFuncReg;
			GPIOC -> DR2R = GPIO_Port -> gpio2maDriverReg;
			GPIOC -> DR4R = GPIO_Port -> gpio4maDriverReg;
			GPIOC -> DR8R = GPIO_Port -> gpio8maDriverReg;
			GPIOC -> ODR = GPIO_Port -> gpioOpenDrainReg;
			GPIOC -> PUR = GPIO_Port -> gpioPullUpReg;
			GPIOC -> PDR = GPIO_Port -> gpioPullDownReg;
			GPIOC -> SLR = GPIO_Port -> gpioSlewRate;
			GPIOC -> DEN = GPIO_Port -> gpioDigitalEnableReg;
			GPIOC -> LOCK = GPIO_Port -> gpioLockReg;
			GPIOC -> AMSEL = GPIO_Port -> gpioAnalogModeReg;
			GPIOC -> PCTL = GPIO_Port ->  gpioPortCtrlReg;
			GPIOC -> ADCCTL = GPIO_Port -> gpioADCCtrlReg;
			GPIOC -> DMACTL = GPIO_Port -> gpioDMACtrlReg;
		break;
		case PORT_D:			/* GPIO Port D	*/
			GPIOD -> DIR = GPIO_Port -> gpioDirReg;
			GPIOD -> IS = GPIO_Port -> gpioIntSenseReg;
			GPIOD -> IBE = GPIO_Port -> gpioIntBothEdgeReg;
			GPIOD -> IEV = GPIO_Port -> gpioInteEvntReg;
			GPIOD -> IM = GPIO_Port -> gpioIntMaskReg;
			GPIOD -> AFSEL = GPIO_Port -> gpioAltenateFuncReg;
			GPIOD -> DR2R = GPIO_Port -> gpio2maDriverReg;
			GPIOD -> DR4R = GPIO_Port -> gpio4maDriverReg;
			GPIOD -> DR8R = GPIO_Port -> gpio8maDriverReg;
			GPIOD -> ODR = GPIO_Port -> gpioOpenDrainReg;
			GPIOD -> PUR = GPIO_Port -> gpioPullUpReg;
			GPIOD -> PDR = GPIO_Port -> gpioPullDownReg;
			GPIOD -> SLR = GPIO_Port -> gpioSlewRate;
			GPIOD -> DEN = GPIO_Port -> gpioDigitalEnableReg;
			GPIOD -> LOCK = GPIO_Port -> gpioLockReg;
			GPIOD -> AMSEL = GPIO_Port -> gpioAnalogModeReg;
			GPIOD -> PCTL = GPIO_Port ->  gpioPortCtrlReg;
			GPIOD -> ADCCTL = GPIO_Port -> gpioADCCtrlReg;
			GPIOD -> DMACTL = GPIO_Port -> gpioDMACtrlReg;
		break;
		case PORT_E:			/* GPIO Port E	*/
			GPIOE -> DIR = GPIO_Port -> gpioDirReg;
			GPIOE -> IS = GPIO_Port -> gpioIntSenseReg;
			GPIOE -> IBE = GPIO_Port -> gpioIntBothEdgeReg;
			GPIOE -> IEV = GPIO_Port -> gpioInteEvntReg;
			GPIOE -> IM = GPIO_Port -> gpioIntMaskReg;
			GPIOE -> AFSEL = GPIO_Port -> gpioAltenateFuncReg;
			GPIOE -> DR2R = GPIO_Port -> gpio2maDriverReg;
			GPIOE -> DR4R = GPIO_Port -> gpio4maDriverReg;
			GPIOE -> DR8R = GPIO_Port -> gpio8maDriverReg;
			GPIOE -> ODR = GPIO_Port -> gpioOpenDrainReg;
			GPIOE -> PUR = GPIO_Port -> gpioPullUpReg;
			GPIOE -> PDR = GPIO_Port -> gpioPullDownReg;
			GPIOE -> SLR = GPIO_Port -> gpioSlewRate;
			GPIOE -> DEN = GPIO_Port -> gpioDigitalEnableReg;
			GPIOE -> LOCK = GPIO_Port -> gpioLockReg;
			GPIOE -> AMSEL = GPIO_Port -> gpioAnalogModeReg;
			GPIOE -> PCTL = GPIO_Port ->  gpioPortCtrlReg;
			GPIOE -> ADCCTL = GPIO_Port -> gpioADCCtrlReg;
			GPIOE -> DMACTL = GPIO_Port -> gpioDMACtrlReg;
		break;
		case PORT_F:			/* GPIO Port F	*/
			GPIOF -> DIR = GPIO_Port -> gpioDirReg;
			GPIOF -> IS = GPIO_Port -> gpioIntSenseReg;
			GPIOF -> IBE = GPIO_Port -> gpioIntBothEdgeReg;
			GPIOF -> IEV = GPIO_Port -> gpioInteEvntReg;
			GPIOF -> IM = GPIO_Port -> gpioIntMaskReg;
			GPIOF -> AFSEL = GPIO_Port -> gpioAltenateFuncReg;
			GPIOF -> DR2R = GPIO_Port -> gpio2maDriverReg;
			GPIOF -> DR4R = GPIO_Port -> gpio4maDriverReg;
			GPIOF -> DR8R = GPIO_Port -> gpio8maDriverReg;
			GPIOF -> ODR = GPIO_Port -> gpioOpenDrainReg;
			GPIOF -> PUR = GPIO_Port -> gpioPullUpReg;
			GPIOF -> PDR = GPIO_Port -> gpioPullDownReg;
			GPIOF -> SLR = GPIO_Port -> gpioSlewRate;
			GPIOF -> DEN = GPIO_Port -> gpioDigitalEnableReg;
			GPIOF -> LOCK = GPIO_Port -> gpioLockReg;
			GPIOF -> AMSEL = GPIO_Port -> gpioAnalogModeReg;
			GPIOF -> PCTL = GPIO_Port ->  gpioPortCtrlReg;
			GPIOF -> ADCCTL = GPIO_Port -> gpioADCCtrlReg;
			GPIOF -> DMACTL = GPIO_Port -> gpioDMACtrlReg;
		break;
		default:
		break;		
	}
}

