/*

TM4C123G adc.h

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

#ifndef __ADC_H
#define __ADC_H

#include "stdint.h"
#include "TM4C123.h"                    // Device header

#define ADCMODULE0	0
#define ADCMODULE1	1

typedef struct ADC_Module{
	uint32_t adcActiveSampleSequencerReg;
	uint32_t adcInterruptMaskReg;
	uint32_t adcEventMultiplexerSelReg;
	uint32_t adcTriggerSourceSelReg;
	uint32_t adcSampleSequencerPrioReg;
	uint32_t adcSamplePhaseCtrlReg;
	uint32_t adcSampleSequenceInitReg;
	uint32_t adcSampleAveragingCtrlReg;
	uint32_t adcCtrlReg;
	uint32_t adcSequencerInputMuxSel0Reg;					/* Sample Sequencer 0 */
	uint32_t adcSampleSequenceCtrl0;	
	uint32_t adcSampleSequenceOperation0;
	uint32_t adcSampleSequence0DigitalComparatorSelReg;
	uint32_t adcSequencerInputMuxSel1Reg;					/* Sample Sequencer 1 */
	uint32_t adcSampleSequenceCtrl1;
	uint32_t adcSampleSequenceOperation1;
	uint32_t adcSampleSequence1DigitalComparatorSelReg;
	uint32_t adcSequencerInputMuxSel2Reg;					/* Sample Sequencer 2 */
	uint32_t adcSampleSequenceCtrl2;
	uint32_t adcSampleSequenceOperation2;
	uint32_t adcSampleSequence2DigitalComparatorSelReg;
	uint32_t adcSequencerInputMuxSel3Reg;					/* Sample Sequencer 3 */
	uint32_t adcSampleSequenceCtrl3;
	uint32_t adcSampleSequenceOperation3;
	uint32_t adcSampleSequence3DigitalComparatorSelReg;	
} ADC_Module_t;

typedef enum{
	ADC_MOD0 = 0,
	ADC_MOD1
} ADC_MODn_t;


void adcInit(ADC_Module_t *ADC_Module, ADC_MODn_t ADC_MODn);


#endif
