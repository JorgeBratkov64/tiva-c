/*

TM4C123G gpio.h

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

#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include "TM4C123.h"                    // Device header


typedef struct GPIO_Port{
	uint32_t gpioDirReg;
	uint32_t gpioIntSenseReg;
	uint32_t gpioIntBothEdgeReg;
	uint32_t gpioInteEvntReg;
	uint32_t gpioIntMaskReg;
	uint32_t gpioAltenateFuncReg;
	uint32_t gpio2maDriverReg;
	uint32_t gpio4maDriverReg;
	uint32_t gpio8maDriverReg;
	uint32_t gpioOpenDrainReg;
	uint32_t gpioPullUpReg;
	uint32_t gpioPullDownReg;
	uint32_t gpioSlewRate;
	uint32_t gpioDigitalEnableReg;
	uint32_t gpioLockReg;
	uint32_t gpioAnalogModeReg;
	uint32_t gpioPortCtrlReg;
	uint32_t gpioADCCtrlReg;
	uint32_t gpioDMACtrlReg;	
} GPIO_Port_t;

typedef enum{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
} GPIO_PORTn_t;

void gpioInit(GPIO_Port_t *GPIO_Port, GPIO_PORTn_t);

#endif
