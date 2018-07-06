/****************************************************************************************/
/*  MIT License                                                                         */
/*                                                                                      */
/*  Copyright (c) 2018 JorgeBratkov64                                                   */
/*                                                                                      */
/*  Permission is hereby granted, free of charge, to any person obtaining a copy        */
/*  of this software and associated documentation files (the "Software"), to deal       */
/*  in the Software without restriction, including without limitation the rights        */
/*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell           */
/*  copies of the Software, and to permit persons to whom the Software is               */
/*  furnished to do so, subject to the following conditions:                            */
/*                                                                                      */
/*  The above copyright notice and this permission notice shall be included in all      */
/*  copies or substantial portions of the Software.                                     */
/*                                                                                      */
/*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR          */
/*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,            */
/*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE         */
/*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER              */
/*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,       */
/*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE       */
/*  SOFTWARE.                                                                           */
/*                                                                                      */
/****************************************************************************************/


/****************************************************************************************/
/*  Includes                                                                            */
/****************************************************************************************/

#include "tm4c123gh6pm.h"

/****************************************************************************************/
/*  Internal defines                                                                    */
/****************************************************************************************/



/****************************************************************************************/
/*  Internal types definition                                                           */
/****************************************************************************************/



/****************************************************************************************/
/*  External types definition                                                           */
/****************************************************************************************/



/****************************************************************************************/
/*  Internal variables definition/declaration                                           */
/****************************************************************************************/



/****************************************************************************************/
/*  Internal routines declaration                                                       */
/****************************************************************************************/

void setGpioDir(unsigned int dir); 
void setGpioAltF(unsigned int altf); 

/****************************************************************************************/
/*  External routines definition                                                        */
/****************************************************************************************/




/********************************************************************************************************/
/*  name:   PortA_Init                                                                                  */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void PortA_Init(void){
	volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;       // Activate clock for Port A
    delay = SYSCTL_RCGC2_R;                     // allow time for clock to start
	GPIO_PORTA_DIR_R |= 0x000000FF;		        // Enable all pins as outputs
	GPIO_PORTA_AFSEL_R &= 0x00;			        // No Alternate Fucntion Available
	GPIO_PORTA_DEN_R |= 0x0E;			        // 
}

/********************************************************************************************************/
/*  name:   PortB_Init                                                                                  */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void PortB_Init(void){
	volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;       // Activate clock for Port B
    delay = SYSCTL_RCGC2_R;                     // allow time for clock to start
	GPIO_PORTB_DIR_R |= 0x000000FF;		        // Enable all pins as outputs
	GPIO_PORTB_AFSEL_R &= 0x00;			        // No Alternate Fucntion Available
	GPIO_PORTB_DEN_R |= 0x0E;			        // 
}

/********************************************************************************************************/
/*  name:   PortC_Init                                                                                  */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void PortC_Init(void){
	volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOC;       // Activate clock for Port C
    delay = SYSCTL_RCGC2_R;                     // allow time for clock to start
	GPIO_PORTC_DIR_R |= 0x000000FF;             // Enable all pins as outputs
	GPIO_PORTC_AFSEL_R &= 0x00;			        // No Alternate Fucntion Available
	GPIO_PORTC_DEN_R |= 0x0E;			        // 
}

/********************************************************************************************************/
/*  name:   PortD_Init                                                                                  */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void PortD_Init(void){
	volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD;       // Activate clock for Port D
    delay = SYSCTL_RCGC2_R;                     // allow time for clock to start
	GPIO_PORTD_DIR_R |= 0x000000FF;		        // Enable all pins as outputs
	GPIO_PORTD_AFSEL_R &= 0x00;			        // No Alternate Fucntion Available
	GPIO_PORTD_DEN_R |= 0x0E;			        // 
}

/********************************************************************************************************/
/*  name:   PortE_Init                                                                                  */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void PortE_Init(void){
	volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;       // Activate clock for Port E
    delay = SYSCTL_RCGC2_R;                     // allow time for clock to start
	GPIO_PORTE_DIR_R |= 0x000000FF;		        // Enable all pins as outputs
	GPIO_PORTE_AFSEL_R &= 0x00;			        // No Alternate Fucntion Available
	GPIO_PORTE_DEN_R |= 0x0E;			        // 
}

/********************************************************************************************************/
/*  name:   PortF_Init                                                                                  */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void PortF_Init(void){
	volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF        // Activate clock for Port F
    delay = SYSCTL_RCGC2_R;                     // allow time for clock to start
	GPIO_PORTF_DIR_R |= 0x000000FF;		        // Enable all pins as outputs
	GPIO_PORTF_AFSEL_R &= 0x00;			        // No Alternate Fucntion Available
	GPIO_PORTF_DEN_R |= 0x0E;			        // 
}

/********************************************************************************************************/
/*  name:   setGpioDir                                                                                  */
/*                                                                                                      */
/**  @brief  set input/output port direction                                                            */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void setGpioDir(unsigned int dir){

}

/********************************************************************************************************/
/*  name:   setGpioAltF                                                                                 */
/*                                                                                                      */
/**  @brief  set alternate function for specifici port                                                                                          */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void setGpioAltF(unsigned int altf){

}
