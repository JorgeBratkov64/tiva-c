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
#include "SysCtl.h" 
#include <stdint.h>

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



/****************************************************************************************/
/*  External routines definition                                                        */
/****************************************************************************************/




/********************************************************************************************************/
/*  name: PLL_Init                                                                                      */
/*                                                                                                      */
/**  @brief Configure PLL system clock 80 MHz                                                           */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

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


/********************************************************************************************************/
/*  name: StsTick_Wait                                                                                  */
/*                                                                                                      */
/**  @briefs   Delay timer usins SysTick Timer                                                          */
/*                                                                                                      */
/**  @param[in] unsigned long delay                                                                     */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void SysTick_Wait(unsigned long delay){
	unsigned long i;
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x7A1200;  // 100 ms count
	NVIC_ST_CURRENT_R = 0x00;			// Clear current value
	NVIC_ST_CTRL_R |= 0x00000005; //Run On System Clock & Enable 
	for(i=delay-1; i>0; i--){
		while((NVIC_ST_CTRL_R & 0x00010000) == 0);
	}
}