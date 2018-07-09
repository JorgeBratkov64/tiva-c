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



/****************************************************************************************/
/*  External routines definition                                                        */
/****************************************************************************************/




/********************************************************************************************************/
/*  name:                                                                                               */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void I2C0_Init(){
    SYSCTL_RCGC1_R |= SYSCTL_RCGC1_I2C0;                            /* Select Run Mode Gating Control */
    SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_0;                           /* Select I2C Run Mode Clock Gating Control */
    SYSCTL_RCGC1_R |= SYSCTL_RCGC2_GPIOB;                           /* Enable Run Mode Port B Gating Control */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;                        /*  GPIO Port B Run Mode Clock Gating Control*/
    while((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R1)!= 1);                /*  GPIO Port B Peripheral Ready    */
    GPIO_PORTB_AFSEL_R |= I2C0_AF_SDA + I2C0_AF_SDA                 /*  PB.2 and PB.3 set to alternate function */
    
}

/********************************************************************************************************/
/*  name:                                                                                               */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void I2C1_Init(){
    SYSCTL_RCGC1_R |= SYSCTL_RCGC1_I2C0 + SYSCTL_RCGC1_I2C1;        /* Select Run Mode Gating Control */
    SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_R3;                          /* Select I2C Run Mode Clock Gating Control */
    
    
}

/********************************************************************************************************/
/*  name:                                                                                               */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void I2C2_Init(){
    SYSCTL_RCGC1_R |= SYSCTL_RCGC1_I2C0 + SYSCTL_RCGC1_I2C1;        /* Select Run Mode Gating Control */
    SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_R3;                          /* Select I2C Run Mode Clock Gating Control */
    
    
}

/********************************************************************************************************/
/*  name:                                                                                               */
/*                                                                                                      */
/**  @brief                                                                                             */
/*                                                                                                      */
/**  @param[in] none                                                                                    */
/**  @return none                                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

void I2C3_Init(){
    SYSCTL_RCGC1_R |= SYSCTL_RCGC1_I2C0 + SYSCTL_RCGC1_I2C1;        /* Select Run Mode Gating Control */
    SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_R3;                          /* Select I2C Run Mode Clock Gating Control */
    
    
}

