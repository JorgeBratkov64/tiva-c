/*

TM4C123G adc.c

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
#include "adc.h"

void adcInit(ADC_Module_t *ADC_Module, ADC_MODn_t ADC_MODn){
	if (ADCMODULE0 == ADC_MODn){	/* ADC Module 0 */
		ADC0 -> ACTSS |=  ADC_Module -> adcActiveSampleSequencerReg; 				/* ADC Active Sample Sequencer */
		ADC0 -> IM |=  ADC_Module -> adcInterruptMaskReg; 	 	 					/* ADC Interrupt Mask */
		ADC0 -> EMUX |=  ADC_Module -> adcEventMultiplexerSelReg; 	 				/* ADC Event Multiplexer Select */
		ADC0 -> TSSEL |=  ADC_Module -> adcTriggerSourceSelReg; 	  					/* ADC Trigger Source Select */
		ADC0 -> SSPRI |=  ADC_Module -> adcSampleSequencerPrioReg; 					/* ADC Sample Sequencer Priority */
		ADC0 -> SPC |=  ADC_Module -> adcSamplePhaseCtrlReg; 						/* ADC Sample Phase Control */
		ADC0 -> PSSI |=  ADC_Module -> adcSampleSequenceInitReg; 					/* ADC Processor Sample Sequence Initiate */
		ADC0 -> SAC |=  ADC_Module -> adcSampleAveragingCtrlReg; 					/* ADC Sample Averaging Control */
		ADC0 -> CTL |=  ADC_Module -> adcCtrlReg; 									/* ADC Control */
		ADC0 -> SSMUX0 |=  ADC_Module -> adcSequencerInputMuxSel0Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 0 */
		ADC0 -> SSCTL0 |=  ADC_Module -> adcSampleSequenceCtrl0; 					/* ADC Sample Sequence Control 0 */
		ADC0 -> SSOP0 |=  ADC_Module -> adcSampleSequenceOperation0; 				/* ADC Sample Sequence 0 Operation */
		ADC0 -> SSDC0 |=  ADC_Module -> adcSampleSequence0DigitalComparatorSelReg; 	/* ADC Sample Sequence 0 Digital Comparator Select*/
		ADC0 -> SSMUX1 |=  ADC_Module -> adcSequencerInputMuxSel1Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 1 */
		ADC0 -> SSCTL1 |=  ADC_Module -> adcSampleSequenceCtrl1; 					/* ADC Sample Sequence Control 1 */
		ADC0 -> SSOP1 |=  ADC_Module -> adcSampleSequenceOperation1; 				/* ADC Sample Sequence 1 Operation */
		ADC0 -> SSDC1 |=	 ADC_Module -> adcSampleSequence1DigitalComparatorSelReg; 	/* ADC Sample Sequence 1 Digital Comparator Select*/
		ADC0 -> SSMUX2 |=  ADC_Module -> adcSequencerInputMuxSel2Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 2 */
		ADC0 -> SSCTL2 |=  ADC_Module -> adcSampleSequenceCtrl2; 					/* ADC Sample Sequence Control 2 */
		ADC0 -> SSOP2 |=  ADC_Module -> adcSampleSequenceOperation2; 				/* ADC Sample Sequence 2 Operation */
		ADC0 -> SSDC2 |=  ADC_Module -> adcSampleSequence2DigitalComparatorSelReg; 	/* ADC Sample Sequence 2 Digital Comparator Select*/
		ADC0 -> SSMUX3 |=  ADC_Module -> adcSequencerInputMuxSel3Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 3 */
		ADC0 -> SSCTL3 |=  ADC_Module -> adcSampleSequenceCtrl3; 					/* ADC Sample Sequence Control 3 */
		ADC0 -> SSOP3 |=	ADC_Module -> adcSampleSequenceOperation3; 					/* ADC Sample Sequence 3 Operation */
		ADC0 -> SSDC3 |= ADC_Module -> adcSampleSequence3DigitalComparatorSelReg; 	/* ADC Sample Sequence 3 Digital Comparator Select*/		
	}
	else{							/* ADC Module 1 */
		ADC1 -> ACTSS |=  ADC_Module -> adcActiveSampleSequencerReg; 				/* ADC Active Sample Sequencer */
		ADC1 -> IM |=  ADC_Module -> adcInterruptMaskReg; 	 	 					/* ADC Interrupt Mask */
		ADC1 -> EMUX |=  ADC_Module -> adcEventMultiplexerSelReg; 	 				/* ADC Event Multiplexer Select */
		ADC1 -> TSSEL |=  ADC_Module -> adcTriggerSourceSelReg; 	  					/* ADC Trigger Source Select */
		ADC1 -> SSPRI |=  ADC_Module -> adcSampleSequencerPrioReg; 					/* ADC Sample Sequencer Priority */
		ADC1 -> SPC |=  ADC_Module -> adcSamplePhaseCtrlReg; 						/* ADC Sample Phase Control */
		ADC1 -> PSSI |=  ADC_Module -> adcSampleSequenceInitReg; 					/* ADC Processor Sample Sequence Initiate */
		ADC1 -> SAC |=  ADC_Module -> adcSampleAveragingCtrlReg; 					/* ADC Sample Averaging Control */
		ADC1 -> CTL |=  ADC_Module -> adcCtrlReg; 									/* ADC Control */
		ADC1 -> SSMUX0 |=  ADC_Module -> adcSequencerInputMuxSel0Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 0 */
		ADC1 -> SSCTL0 |=  ADC_Module -> adcSampleSequenceCtrl0; 					/* ADC Sample Sequence Control 0 */
		ADC1 -> SSOP0 |=  ADC_Module -> adcSampleSequenceOperation0; 				/* ADC Sample Sequence 0 Operation */
		ADC1 -> SSDC0 |=  ADC_Module -> adcSampleSequence0DigitalComparatorSelReg; 	/* ADC Sample Sequence 0 Digital Comparator Select*/
		ADC1 -> SSMUX1 |=  ADC_Module -> adcSequencerInputMuxSel1Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 1 */
		ADC1 -> SSCTL1 |=  ADC_Module -> adcSampleSequenceCtrl1; 					/* ADC Sample Sequence Control 1 */
		ADC1 -> SSOP1 |=  ADC_Module -> adcSampleSequenceOperation1; 				/* ADC Sample Sequence 1 Operation */
		ADC1 -> SSDC1 |=	 ADC_Module -> adcSampleSequence1DigitalComparatorSelReg; 	/* ADC Sample Sequence 1 Digital Comparator Select*/
		ADC1 -> SSMUX2 |=  ADC_Module -> adcSequencerInputMuxSel2Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 2 */
		ADC1 -> SSCTL2 |=  ADC_Module -> adcSampleSequenceCtrl2; 					/* ADC Sample Sequence Control 2 */
		ADC1 -> SSOP2 |=  ADC_Module -> adcSampleSequenceOperation2; 				/* ADC Sample Sequence 2 Operation */
		ADC1 -> SSDC2 |=  ADC_Module -> adcSampleSequence2DigitalComparatorSelReg; 	/* ADC Sample Sequence 2 Digital Comparator Select*/
		ADC1 -> SSMUX3 |=  ADC_Module -> adcSequencerInputMuxSel3Reg; 	 			/* ADC Sample Sequence Input Multiplexer Select 3 */
		ADC1 -> SSCTL3 |=  ADC_Module -> adcSampleSequenceCtrl3; 					/* ADC Sample Sequence Control 3 */
		ADC1 -> SSOP3 |=	ADC_Module -> adcSampleSequenceOperation3; 					/* ADC Sample Sequence 3 Operation */
		ADC1 -> SSDC3 |= ADC_Module -> adcSampleSequence3DigitalComparatorSelReg; 	/* ADC Sample Sequence 3 Digital Comparator Select*/	
	}
}

