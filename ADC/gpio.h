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


#define PORTA_ENABLE
#define PORTB_ENABLE
#define PORTC_ENABLE
#define PORTD_ENABLE
#define PORTE_ENABLE
#define PORTF_ENABLE

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC2 register.
//
//*****************************************************************************
#define SYSCTL_RCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_RCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_RCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_RCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_RCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // Port A Clock Gating Control


//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTn_DATA register.
//
//*****************************************************************************
#define GPIO_PORTA_DATA_M          0x000000FF  // GPIO Port A Data
#define GPIO_PORTB_DATA_M          0x000000FF  // GPIO Port B Data
#define GPIO_PORTC_DATA_M          0x000000FF  // GPIO Port C Data
#define GPIO_PORTD_DATA_M          0x000000FF  // GPIO Port D Data
#define GPIO_PORTE_DATA_M          0x000000FF  // GPIO Port E Data
#define GPIO_PORTF_DATA_M          0x000000FF  // GPIO Port F Data
#define GPIO_PORT_DATA_RST         0x00000000  // GPIO Port Data Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTn_DIR register.
//
//*****************************************************************************
#define GPIO_PORTA_DIR_M          0x000000FF  // GPIO Port A Direction
#define GPIO_PORTB_DIR_M          0x000000FF  // GPIO Port B Direction
#define GPIO_PORTC_DIR_M          0x000000FF  // GPIO Port C Direction
#define GPIO_PORTD_DIR_M          0x000000FF  // GPIO Port D Direction
#define GPIO_PORTE_DIR_M          0x000000FF  // GPIO Port E Direction
#define GPIO_PORTF_DIR_M          0x000000FF  // GPIO Port F Direction
#define GPIO_PORT_DIR_RST         0x00000000  // GPIO Port Direction Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_IS_R register.
//
//*****************************************************************************
#define GPIO_PORTA_IS_M          0x000000FF  // GPIO Port A Detect levels
#define GPIO_PORTB_IS_M          0x000000FF  // GPIO Port B Detect levels
#define GPIO_PORTC_IS_M          0x000000FF  // GPIO Port C Detect levels
#define GPIO_PORTD_IS_M          0x000000FF  // GPIO Port D Detect levels
#define GPIO_PORTE_IS_M          0x000000FF  // GPIO Port E Detect levels
#define GPIO_PORTF_IS_M          0x000000FF  // GPIO Port F Detect levels
#define GPIO_PORT_IS_RST		 0x00000000	 // GPIO Port Detect Edges

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_IBE_R register.
//
//*****************************************************************************
#define GPIO_PORTA_IBE_M          0x000000FF  // GPIO Port A Interrupt Both Edges
#define GPIO_PORTB_IBE_M          0x000000FF  // GPIO Port B Interrupt Both Edges
#define GPIO_PORTC_IBE_M          0x000000FF  // GPIO Port C Interrupt Both Edges
#define GPIO_PORTD_IBE_M          0x000000FF  // GPIO Port D Interrupt Both Edges
#define GPIO_PORTE_IBE_M          0x000000FF  // GPIO Port E Interrupt Both Edges
#define GPIO_PORTF_IBE_M          0x000000FF  // GPIO Port F Interrupt Both Edges
#define GPIO_PORT_IBE_RST         0x00000000  // GPIO Port Interrupt controleed by GPIOIEV

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_IEV_R register.
//
//*****************************************************************************
#define GPIO_PORTA_IEV_M          0x000000FF  // GPIO Port A Interrupt Event
#define GPIO_PORTB_IEV_M          0x000000FF  // GPIO Port B Interrupt Event
#define GPIO_PORTC_IEV_M          0x000000FF  // GPIO Port C Interrupt Event
#define GPIO_PORTD_IEV_M          0x000000FF  // GPIO Port D Interrupt Event
#define GPIO_PORTE_IEV_M          0x000000FF  // GPIO Port E Interrupt Event
#define GPIO_PORTF_IEV_M          0x000000FF  // GPIO Port F Interrupt Event
#define GPIO_PORT_IEV_RST        0x00000000  // GPIO Port Null Interrupt Event


//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_IM register.
//
//*****************************************************************************
#define GPIO_PORTA_IM_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_PORTB_IM_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_PORTC_IM_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_PORTD_IM_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_PORTE_IM_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_PORTF_IM_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_PORT_IM_RST         0x00000000  // GPIO Interrupt Mask Disable
#define GPIO_IM_GPIO_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_RIS register.
//
//*****************************************************************************
#define GPIO_RIS_GPIO_M         0x000000FF  // GPIO Interrupt Raw Status
#define GPIO_RIS_GPIO_RST       0x00000000  
#define GPIO_RIS_GPIO_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_MIS register.
//
//*****************************************************************************
#define GPIO_MIS_GPIO_M         0x000000FF  // GPIO Masked Interrupt Status
#define GPIO_MIS_GPIO_RST      0x00000000
#define GPIO_MIS_GPIO_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_ICR_R register.
//
//*****************************************************************************
#define GPIO_ICR_GPIO_M         0x000000FF  // GPIO Interrupt Clear
#define GPIO_ICR_GPIO_RST      0x00000000  
#define GPIO_ICR_GPIO_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_AFSEL_R register.
//
//*****************************************************************************
#define GPIO_PORTA_AFSEL_M          0x000000FF  // GPIO Alternate Funtion Enable
#define GPIO_PORTB_AFSEL_M          0x000000FF  // GPIO Alternate Funtion Enable
#define GPIO_PORTC_AFSEL_M          0x000000FF  // GPIO Alternate Funtion Enable
#define GPIO_PORTD_AFSEL_M          0x000000FF  // GPIO Alternate Funtion Enable
#define GPIO_PORTE_AFSEL_M          0x000000FF  // GPIO Alternate Funtion Enable
#define GPIO_PORTF_AFSEL_M          0x000000FF  // GPIO Alternate Funtion Enable
#define GPIO_PORT_AFSEL_RST         0x00000000  // GPIO Alternate Funtion Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_DR2R_R register.
//
//*****************************************************************************
 #define GPIO_PORTA_DR2R_M          0x00000000  // GPIO 2-ma Drive Select
 #define GPIO_PORTB_DR2R_M          0x00000000  // GPIO 2-ma Drive Select
 #define GPIO_PORTC_DR2R_M          0x00000000  // GPIO 2-ma Drive Select
 #define GPIO_PORTD_DR2R_M          0x00000000  // GPIO 2-ma Drive Select
 #define GPIO_PORTE_DR2R_M          0x00000000  // GPIO 2-ma Drive Select
 #define GPIO_PORTF_DR2R_M          0x00000000  // GPIO 2-ma Drive Select
 #define GPIO_PORT_DR2R_RST         0x000000FF  // GPIO 2-ma Drive Select Null
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_DR4R_R register.
//
//*****************************************************************************
 #define GPIO_PORTA_DR4R_M          0x000000FF  // GPIO 4-ma Drive Select
 #define GPIO_PORTB_DR4R_M          0x000000FF  // GPIO 4-ma Drive Select
 #define GPIO_PORTC_DR4R_M          0x000000FF  // GPIO 4-ma Drive Select
 #define GPIO_PORTD_DR4R_M          0x000000FF  // GPIO 4-ma Drive Select
 #define GPIO_PORTE_DR4R_M          0x000000FF  // GPIO 4-ma Drive Select
 #define GPIO_PORTF_DR4R_M          0x000000FF  // GPIO 4-ma Drive Select
 #define GPIO_PORT_DR4R_RST         0x00000000   // GPIO 4-ma Drive Select Null
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_DR8R_R register.
//
//*****************************************************************************
 #define GPIO_PORTA_DR8R_M          0x000000FF  // GPIO 8-ma Drive Select
 #define GPIO_PORTB_DR8R_M          0x000000FF  // GPIO 8-ma Drive Select
 #define GPIO_PORTC_DR8R_M          0x000000FF  // GPIO 8-ma Drive Select
 #define GPIO_PORTD_DR8R_M          0x000000FF  // GPIO 8-ma Drive Select
 #define GPIO_PORTE_DR8R_M          0x000000FF  // GPIO 8-ma Drive Select
 #define GPIO_PORTF_DR8R_M          0x000000FF  // GPIO 8-ma Drive Select
 #define GPIO_PORT_DR8R_RST         0x00000000  // GPIO 8-ma Drive Select Null
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORT_DR8R_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_ODR_R           0x000000FF  // GPIO Port A Open Drain Select
 #define GPIO_PORTB_ODR_R           0x000000FF  // GPIO Port B Open Drain Select
 #define GPIO_PORTC_ODR_R           0x000000FF  // GPIO Port C Open Drain Select
 #define GPIO_PORTD_ODR_R           0x000000FF  // GPIO Port D Open Drain Select
 #define GPIO_PORTE_ODR_R           0x000000FF  // GPIO Port E Open Drain Select
 #define GPIO_PORTF_ODR_R           0x000000FF  // GPIO Port F Open Drain Select
 #define GPIO_PORT_ODR_RST          0x00000000  // GPIO Port Open Drain Select Reset 

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_PUR_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_PUR_R           0x000000FF  // GPIO Port A Pull-Up Registor Select
 #define GPIO_PORTB_PUR_R           0x000000FF  // GPIO Port B Pull-Up Registor Select
 #define GPIO_PORTC_PUR_R           0x000000FF  // GPIO Port C Pull-Up Registor Select
 #define GPIO_PORTD_PUR_R           0x000000FF  // GPIO Port D Pull-Up Registor Select
 #define GPIO_PORTE_PUR_R           0x000000FF  // GPIO Port E Pull-Up Registor Select
 #define GPIO_PORTF_PUR_R           0x000000FF  // GPIO Port F Pull-Up Registor Select
 #define GPIO_PORT_PUR_RST          0x00000000  // GPIO Port Pull-Up Registor Reset
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_PUR_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_PDR_R           0x000000FF  // GPIO Port A Pull-Down Registor Select
 #define GPIO_PORTB_PDR_R           0x000000FF  // GPIO Port B Pull-Down Registor Select
 #define GPIO_PORTC_PDR_R           0x000000FF  // GPIO Port C Pull-Down Registor Select
 #define GPIO_PORTD_PDR_R           0x000000FF  // GPIO Port D Pull-Down Registor Select
 #define GPIO_PORTE_PDR_R           0x000000FF  // GPIO Port E Pull-Down Registor Select
 #define GPIO_PORTF_PDR_R           0x000000FF  // GPIO Port F Pull-Down Registor Select
 #define GPIO_PORT_PDR_RST          0x00000000  // GPIO Port Pull-Down Registor Reset 
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_SLR_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_SLR_R           0x000000FF  // GPIO Port A Slew-Rate Control Select
 #define GPIO_PORTB_SLR_R           0x000000FF  // GPIO Port B Slew-Rate Control Select
 #define GPIO_PORTC_SLR_R           0x000000FF  // GPIO Port C Slew-Rate Control Select
 #define GPIO_PORTD_SLR_R           0x000000FF  // GPIO Port D Slew-Rate Control Select
 #define GPIO_PORTE_SLR_R           0x000000FF  // GPIO Port E Slew-Rate Control Select
 #define GPIO_PORTF_SLR_R           0x000000FF  // GPIO Port F Slew-Rate Control Select
 #define GPIO_PORT_SLR_RST          0x00000000  // GPIO Port Slew-Rate Control Select Reset
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_DEN_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_DEN_R           0x000000FF  // GPIO Port A Digital Enable Select
 #define GPIO_PORTB_DEN_R           0x000000FF  // GPIO Port B Digital Enable Select
 #define GPIO_PORTC_DEN_R           0x000000FF  // GPIO Port C Digital Enable Select
 #define GPIO_PORTD_DEN_R           0x000000FF  // GPIO Port D Digital Enable Select
 #define GPIO_PORTE_DEN_R           0x000000FF  // GPIO Port E Digital Enable Select
 #define GPIO_PORTF_DEN_R           0x000000FF  // GPIO Port F Digital Enable Select
 #define GPIO_PORT_DEN_RST          0x000000FF  // GPIO Port Digital Enable Select Reset 

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_LOCK register.
//
//*****************************************************************************
#define GPIO_LOCK_M             0xFFFFFFFF  // GPIO Lock
#define GPIO_LOCK_UNLOCKED      0x00000000  // The GPIOCR register is unlocked
                                            // and may be modified
#define GPIO_LOCK_LOCKED        0x00000001  // The GPIOCR register is locked
                                            // and may not be modified
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_AMSEL_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_AMSEL_R         0x000000FF  // GPIO Port A Analog Mode Select
 #define GPIO_PORTB_AMSEL_R         0x000000FF  // GPIO Port B Analog Mode Select
 #define GPIO_PORTC_AMSEL_R         0x000000FF  // GPIO Port C Analog Mode Select
 #define GPIO_PORTD_AMSEL_R         0x000000FF  // GPIO Port D Analog Mode Select
 #define GPIO_PORTE_AMSEL_R         0x000000FF  // GPIO Port E Analog Mode Select
 #define GPIO_PORTF_AMSEL_R         0x000000FF  // GPIO Port F Analog Mode Select
 #define GPIO_PORT_AMSEL_RST        0x00000000  // GPIO Port Analog Mode Select Reset
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port A.
//
//*****************************************************************************
#define GPIO_PCTL_PA7_M         0xF0000000  // PA7 mask
#define GPIO_PCTL_PA7_I2C1SDA   0x30000000  // I2C1SDA on PA7
#define GPIO_PCTL_PA7_M1PWM3    0x50000000  // M1PWM3 on PA7
#define GPIO_PCTL_PA6_M         0x0F000000  // PA6 mask
#define GPIO_PCTL_PA6_I2C1SCL   0x03000000  // I2C1SCL on PA6
#define GPIO_PCTL_PA6_M1PWM2    0x05000000  // M1PWM2 on PA6
#define GPIO_PCTL_PA5_M         0x00F00000  // PA5 mask
#define GPIO_PCTL_PA5_SSI0TX    0x00200000  // SSI0TX on PA5
#define GPIO_PCTL_PA4_M         0x000F0000  // PA4 mask
#define GPIO_PCTL_PA4_SSI0RX    0x00020000  // SSI0RX on PA4
#define GPIO_PCTL_PA3_M         0x0000F000  // PA3 mask
#define GPIO_PCTL_PA3_SSI0FSS   0x00002000  // SSI0FSS on PA3
#define GPIO_PCTL_PA2_M         0x00000F00  // PA2 mask
#define GPIO_PCTL_PA2_SSI0CLK   0x00000200  // SSI0CLK on PA2
#define GPIO_PCTL_PA1_M         0x000000F0  // PA1 mask
#define GPIO_PCTL_PA1_U0TX      0x00000010  // U0TX on PA1
#define GPIO_PCTL_PA1_CAN1TX    0x00000080  // CAN1TX on PA1
#define GPIO_PCTL_PA0_M         0x0000000F  // PA0 mask
#define GPIO_PCTL_PA0_U0RX      0x00000001  // U0RX on PA0
#define GPIO_PCTL_PA0_CAN1RX    0x00000008  // CAN1RX on PA0
#define GPIO_PCTL_PORTA_RST     0x00000000  // Port A Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port B.
//
//*****************************************************************************
#define GPIO_PCTL_PB7_M         0xF0000000  // PB7 mask
#define GPIO_PCTL_PB7_SSI2TX    0x20000000  // SSI2TX on PB7
#define GPIO_PCTL_PB7_M0PWM1    0x40000000  // M0PWM1 on PB7
#define GPIO_PCTL_PB7_T0CCP1    0x70000000  // T0CCP1 on PB7
#define GPIO_PCTL_PB6_M         0x0F000000  // PB6 mask
#define GPIO_PCTL_PB6_SSI2RX    0x02000000  // SSI2RX on PB6
#define GPIO_PCTL_PB6_M0PWM0    0x04000000  // M0PWM0 on PB6
#define GPIO_PCTL_PB6_T0CCP0    0x07000000  // T0CCP0 on PB6
#define GPIO_PCTL_PB5_M         0x00F00000  // PB5 mask
#define GPIO_PCTL_PB5_SSI2FSS   0x00200000  // SSI2FSS on PB5
#define GPIO_PCTL_PB5_M0PWM3    0x00400000  // M0PWM3 on PB5
#define GPIO_PCTL_PB5_T1CCP1    0x00700000  // T1CCP1 on PB5
#define GPIO_PCTL_PB5_CAN0TX    0x00800000  // CAN0TX on PB5
#define GPIO_PCTL_PB4_M         0x000F0000  // PB4 mask
#define GPIO_PCTL_PB4_SSI2CLK   0x00020000  // SSI2CLK on PB4
#define GPIO_PCTL_PB4_M0PWM2    0x00040000  // M0PWM2 on PB4
#define GPIO_PCTL_PB4_T1CCP0    0x00070000  // T1CCP0 on PB4
#define GPIO_PCTL_PB4_CAN0RX    0x00080000  // CAN0RX on PB4
#define GPIO_PCTL_PB3_M         0x0000F000  // PB3 mask
#define GPIO_PCTL_PB3_I2C0SDA   0x00003000  // I2C0SDA on PB3
#define GPIO_PCTL_PB3_T3CCP1    0x00007000  // T3CCP1 on PB3
#define GPIO_PCTL_PB2_M         0x00000F00  // PB2 mask
#define GPIO_PCTL_PB2_I2C0SCL   0x00000300  // I2C0SCL on PB2
#define GPIO_PCTL_PB2_T3CCP0    0x00000700  // T3CCP0 on PB2
#define GPIO_PCTL_PB1_M         0x000000F0  // PB1 mask
#define GPIO_PCTL_PB1_USB0VBUS  0x00000000  // USB0VBUS on PB1
#define GPIO_PCTL_PB1_U1TX      0x00000010  // U1TX on PB1
#define GPIO_PCTL_PB1_T2CCP1    0x00000070  // T2CCP1 on PB1
#define GPIO_PCTL_PB0_M         0x0000000F  // PB0 mask
#define GPIO_PCTL_PB0_USB0ID    0x00000000  // USB0ID on PB0
#define GPIO_PCTL_PB0_U1RX      0x00000001  // U1RX on PB0
#define GPIO_PCTL_PB0_T2CCP0    0x00000007  // T2CCP0 on PB0
#define GPIO_PCTL_PORTB_RST     0x00000000  // Port B Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port C.
//
//*****************************************************************************
#define GPIO_PCTL_PC7_M         0xF0000000  // PC7 mask
#define GPIO_PCTL_PC7_U3TX      0x10000000  // U3TX on PC7
#define GPIO_PCTL_PC7_WT1CCP1   0x70000000  // WT1CCP1 on PC7
#define GPIO_PCTL_PC7_USB0PFLT  0x80000000  // USB0PFLT on PC7
#define GPIO_PCTL_PC6_M         0x0F000000  // PC6 mask
#define GPIO_PCTL_PC6_U3RX      0x01000000  // U3RX on PC6
#define GPIO_PCTL_PC6_PHB1      0x06000000  // PHB1 on PC6
#define GPIO_PCTL_PC6_WT1CCP0   0x07000000  // WT1CCP0 on PC6
#define GPIO_PCTL_PC6_USB0EPEN  0x08000000  // USB0EPEN on PC6
#define GPIO_PCTL_PC5_M         0x00F00000  // PC5 mask
#define GPIO_PCTL_PC5_U4TX      0x00100000  // U4TX on PC5
#define GPIO_PCTL_PC5_U1TX      0x00200000  // U1TX on PC5
#define GPIO_PCTL_PC5_M0PWM7    0x00400000  // M0PWM7 on PC5
#define GPIO_PCTL_PC5_PHA1      0x00600000  // PHA1 on PC5
#define GPIO_PCTL_PC5_WT0CCP1   0x00700000  // WT0CCP1 on PC5
#define GPIO_PCTL_PC5_U1CTS     0x00800000  // U1CTS on PC5
#define GPIO_PCTL_PC4_M         0x000F0000  // PC4 mask
#define GPIO_PCTL_PC4_U4RX      0x00010000  // U4RX on PC4
#define GPIO_PCTL_PC4_U1RX      0x00020000  // U1RX on PC4
#define GPIO_PCTL_PC4_M0PWM6    0x00040000  // M0PWM6 on PC4
#define GPIO_PCTL_PC4_IDX1      0x00060000  // IDX1 on PC4
#define GPIO_PCTL_PC4_WT0CCP0   0x00070000  // WT0CCP0 on PC4
#define GPIO_PCTL_PC4_U1RTS     0x00080000  // U1RTS on PC4
#define GPIO_PCTL_PC3_M         0x0000F000  // PC3 mask
#define GPIO_PCTL_PC3_TDO       0x00001000  // TDO on PC3
#define GPIO_PCTL_PC3_T5CCP1    0x00007000  // T5CCP1 on PC3
#define GPIO_PCTL_PC2_M         0x00000F00  // PC2 mask
#define GPIO_PCTL_PC2_TDI       0x00000100  // TDI on PC2
#define GPIO_PCTL_PC2_T5CCP0    0x00000700  // T5CCP0 on PC2
#define GPIO_PCTL_PC1_M         0x000000F0  // PC1 mask
#define GPIO_PCTL_PC1_TMS       0x00000010  // TMS on PC1
#define GPIO_PCTL_PC1_T4CCP1    0x00000070  // T4CCP1 on PC1
#define GPIO_PCTL_PC0_M         0x0000000F  // PC0 mask
#define GPIO_PCTL_PC0_TCK       0x00000001  // TCK on PC0
#define GPIO_PCTL_PC0_T4CCP0    0x00000007  // T4CCP0 on PC0
#define GPIO_PCTL_PORTC_RST     0x00000000  // Port C Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port D.
//
//*****************************************************************************
#define GPIO_PCTL_PD7_M         0xF0000000  // PD7 mask
#define GPIO_PCTL_PD7_U2TX      0x10000000  // U2TX on PD7
#define GPIO_PCTL_PD7_PHB0      0x60000000  // PHB0 on PD7
#define GPIO_PCTL_PD7_WT5CCP1   0x70000000  // WT5CCP1 on PD7
#define GPIO_PCTL_PD7_NMI       0x80000000  // NMI on PD7
#define GPIO_PCTL_PD6_M         0x0F000000  // PD6 mask
#define GPIO_PCTL_PD6_U2RX      0x01000000  // U2RX on PD6
#define GPIO_PCTL_PD6_M0FAULT0  0x04000000  // M0FAULT0 on PD6
#define GPIO_PCTL_PD6_PHA0      0x06000000  // PHA0 on PD6
#define GPIO_PCTL_PD6_WT5CCP0   0x07000000  // WT5CCP0 on PD6
#define GPIO_PCTL_PD5_M         0x00F00000  // PD5 mask
#define GPIO_PCTL_PD5_USB0DP    0x00000000  // USB0DP on PD5
#define GPIO_PCTL_PD5_U6TX      0x00100000  // U6TX on PD5
#define GPIO_PCTL_PD5_WT4CCP1   0x00700000  // WT4CCP1 on PD5
#define GPIO_PCTL_PD4_M         0x000F0000  // PD4 mask
#define GPIO_PCTL_PD4_USB0DM    0x00000000  // USB0DM on PD4
#define GPIO_PCTL_PD4_U6RX      0x00010000  // U6RX on PD4
#define GPIO_PCTL_PD4_WT4CCP0   0x00070000  // WT4CCP0 on PD4
#define GPIO_PCTL_PD3_M         0x0000F000  // PD3 mask
#define GPIO_PCTL_PD3_AIN4      0x00000000  // AIN4 on PD3
#define GPIO_PCTL_PD3_SSI3TX    0x00001000  // SSI3TX on PD3
#define GPIO_PCTL_PD3_SSI1TX    0x00002000  // SSI1TX on PD3
#define GPIO_PCTL_PD3_IDX0      0x00006000  // IDX0 on PD3
#define GPIO_PCTL_PD3_WT3CCP1   0x00007000  // WT3CCP1 on PD3
#define GPIO_PCTL_PD3_USB0PFLT  0x00008000  // USB0PFLT on PD3
#define GPIO_PCTL_PD2_M         0x00000F00  // PD2 mask
#define GPIO_PCTL_PD2_AIN5      0x00000000  // AIN5 on PD2
#define GPIO_PCTL_PD2_SSI3RX    0x00000100  // SSI3RX on PD2
#define GPIO_PCTL_PD2_SSI1RX    0x00000200  // SSI1RX on PD2
#define GPIO_PCTL_PD2_M0FAULT0  0x00000400  // M0FAULT0 on PD2
#define GPIO_PCTL_PD2_WT3CCP0   0x00000700  // WT3CCP0 on PD2
#define GPIO_PCTL_PD2_USB0EPEN  0x00000800  // USB0EPEN on PD2
#define GPIO_PCTL_PD1_M         0x000000F0  // PD1 mask
#define GPIO_PCTL_PD1_AIN6      0x00000000  // AIN6 on PD1
#define GPIO_PCTL_PD1_SSI3FSS   0x00000010  // SSI3FSS on PD1
#define GPIO_PCTL_PD1_SSI1FSS   0x00000020  // SSI1FSS on PD1
#define GPIO_PCTL_PD1_I2C3SDA   0x00000030  // I2C3SDA on PD1
#define GPIO_PCTL_PD1_M0PWM7    0x00000040  // M0PWM7 on PD1
#define GPIO_PCTL_PD1_M1PWM1    0x00000050  // M1PWM1 on PD1
#define GPIO_PCTL_PD1_WT2CCP1   0x00000070  // WT2CCP1 on PD1
#define GPIO_PCTL_PD0_M         0x0000000F  // PD0 mask
#define GPIO_PCTL_PD0_AIN7      0x00000000  // AIN7 on PD0
#define GPIO_PCTL_PD0_SSI3CLK   0x00000001  // SSI3CLK on PD0
#define GPIO_PCTL_PD0_SSI1CLK   0x00000002  // SSI1CLK on PD0
#define GPIO_PCTL_PD0_I2C3SCL   0x00000003  // I2C3SCL on PD0
#define GPIO_PCTL_PD0_M0PWM6    0x00000004  // M0PWM6 on PD0
#define GPIO_PCTL_PD0_M1PWM0    0x00000005  // M1PWM0 on PD0
#define GPIO_PCTL_PD0_WT2CCP0   0x00000007  // WT2CCP0 on PD0
#define GPIO_PCTL_PORTD_RST     0x00000000  // Port D Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port E.
//
//*****************************************************************************
#define GPIO_PCTL_PE5_M         0x00F00000  // PE5 mask
#define GPIO_PCTL_PE5_AIN8      0x00000000  // AIN8 on PE5
#define GPIO_PCTL_PE5_U5TX      0x00100000  // U5TX on PE5
#define GPIO_PCTL_PE5_I2C2SDA   0x00300000  // I2C2SDA on PE5
#define GPIO_PCTL_PE5_M0PWM5    0x00400000  // M0PWM5 on PE5
#define GPIO_PCTL_PE5_M1PWM3    0x00500000  // M1PWM3 on PE5
#define GPIO_PCTL_PE5_CAN0TX    0x00800000  // CAN0TX on PE5
#define GPIO_PCTL_PE4_M         0x000F0000  // PE4 mask
#define GPIO_PCTL_PE4_AIN9      0x00000000  // AIN9 on PE4
#define GPIO_PCTL_PE4_U5RX      0x00010000  // U5RX on PE4
#define GPIO_PCTL_PE4_I2C2SCL   0x00030000  // I2C2SCL on PE4
#define GPIO_PCTL_PE4_M0PWM4    0x00040000  // M0PWM4 on PE4
#define GPIO_PCTL_PE4_M1PWM2    0x00050000  // M1PWM2 on PE4
#define GPIO_PCTL_PE4_CAN0RX    0x00080000  // CAN0RX on PE4
#define GPIO_PCTL_PE3_M         0x0000F000  // PE3 mask
#define GPIO_PCTL_PE3_AIN0      0x00000000  // AIN0 on PE3
#define GPIO_PCTL_PE2_M         0x00000F00  // PE2 mask
#define GPIO_PCTL_PE2_AIN1      0x00000000  // AIN1 on PE2
#define GPIO_PCTL_PE1_M         0x000000F0  // PE1 mask
#define GPIO_PCTL_PE1_AIN2      0x00000000  // AIN2 on PE1
#define GPIO_PCTL_PE1_U7TX      0x00000010  // U7TX on PE1
#define GPIO_PCTL_PE0_M         0x0000000F  // PE0 mask
#define GPIO_PCTL_PE0_AIN3      0x00000000  // AIN3 on PE0
#define GPIO_PCTL_PE0_U7RX      0x00000001  // U7RX on PE0
#define GPIO_PCTL_PORTE_RST     0x00000000  // Port E Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port F.
//
//*****************************************************************************
#define GPIO_PCTL_PF4_M         0x000F0000  // PF4 mask
#define GPIO_PCTL_PF4_M1FAULT0  0x00050000  // M1FAULT0 on PF4
#define GPIO_PCTL_PF4_IDX0      0x00060000  // IDX0 on PF4
#define GPIO_PCTL_PF4_T2CCP0    0x00070000  // T2CCP0 on PF4
#define GPIO_PCTL_PF4_USB0EPEN  0x00080000  // USB0EPEN on PF4
#define GPIO_PCTL_PF3_M         0x0000F000  // PF3 mask
#define GPIO_PCTL_PF3_SSI1FSS   0x00002000  // SSI1FSS on PF3
#define GPIO_PCTL_PF3_CAN0TX    0x00003000  // CAN0TX on PF3
#define GPIO_PCTL_PF3_M1PWM7    0x00005000  // M1PWM7 on PF3
#define GPIO_PCTL_PF3_T1CCP1    0x00007000  // T1CCP1 on PF3
#define GPIO_PCTL_PF3_TRCLK     0x0000E000  // TRCLK on PF3
#define GPIO_PCTL_PF2_M         0x00000F00  // PF2 mask
#define GPIO_PCTL_PF2_SSI1CLK   0x00000200  // SSI1CLK on PF2
#define GPIO_PCTL_PF2_M0FAULT0  0x00000400  // M0FAULT0 on PF2
#define GPIO_PCTL_PF2_M1PWM6    0x00000500  // M1PWM6 on PF2
#define GPIO_PCTL_PF2_T1CCP0    0x00000700  // T1CCP0 on PF2
#define GPIO_PCTL_PF2_TRD0      0x00000E00  // TRD0 on PF2
#define GPIO_PCTL_PF1_M         0x000000F0  // PF1 mask
#define GPIO_PCTL_PF1_U1CTS     0x00000010  // U1CTS on PF1
#define GPIO_PCTL_PF1_SSI1TX    0x00000020  // SSI1TX on PF1
#define GPIO_PCTL_PF1_M1PWM5    0x00000050  // M1PWM5 on PF1
#define GPIO_PCTL_PF1_PHB0      0x00000060  // PHB0 on PF1
#define GPIO_PCTL_PF1_T0CCP1    0x00000070  // T0CCP1 on PF1
#define GPIO_PCTL_PF1_C1O       0x00000090  // C1O on PF1
#define GPIO_PCTL_PF1_TRD1      0x000000E0  // TRD1 on PF1
#define GPIO_PCTL_PF0_M         0x0000000F  // PF0 mask
#define GPIO_PCTL_PF0_U1RTS     0x00000001  // U1RTS on PF0
#define GPIO_PCTL_PF0_SSI1RX    0x00000002  // SSI1RX on PF0
#define GPIO_PCTL_PF0_CAN0RX    0x00000003  // CAN0RX on PF0
#define GPIO_PCTL_PF0_M1PWM4    0x00000005  // M1PWM4 on PF0
#define GPIO_PCTL_PF0_PHA0      0x00000006  // PHA0 on PF0
#define GPIO_PCTL_PF0_T0CCP0    0x00000007  // T0CCP0 on PF0
#define GPIO_PCTL_PF0_NMI       0x00000008  // NMI on PF0
#define GPIO_PCTL_PF0_C0O       0x00000009  // C0O on PF0
#define GPIO_PCTL_PORTF_RST     0x00000000  // Port F Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_ADCCTL_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_ADCCTL_R        0x000000FF  // GPIO Port A ADC Control Select
 #define GPIO_PORTB_ADCCTL_R        0x000000FF  // GPIO Port B ADC Control Select
 #define GPIO_PORTC_ADCCTL_R        0x000000FF  // GPIO Port C ADC Control Select
 #define GPIO_PORTD_ADCCTL_R        0x000000FF  // GPIO Port D ADC Control Select
 #define GPIO_PORTE_ADCCTL_R        0x000000FF  // GPIO Port E ADC Control Select
 #define GPIO_PORTF_ADCCTL_R        0x000000FF  // GPIO Port F ADC Control Select
 #define GPIO_PORT_ADCCTL_RST       0x00000000  // GPIO Port ADC Control Reset Select
 
//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PORTA_DMACTL_R register.
//
//*****************************************************************************

 #define GPIO_PORTA_DMACTL_R        0x000000FF  // GPIO Port A DMA Control Select
 #define GPIO_PORTB_DMACTL_R        0x000000FF  // GPIO Port B DMA Control Select
 #define GPIO_PORTC_DMACTL_R        0x000000FF  // GPIO Port C DMA Control Select
 #define GPIO_PORTD_DMACTL_R        0x000000FF  // GPIO Port D DMA Control Select
 #define GPIO_PORTE_DMACTL_R        0x000000FF  // GPIO Port E DMA Control Select
 #define GPIO_PORTF_DMACTL_R        0x000000FF  // GPIO Port F DMA Control Select
 #define GPIO_PORT_DMACTL_RST        0x00000000  // GPIO Port DMA Control Select Reset
 
typedef enum{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
} GPIO_PORTn_t;

void gpioInitPortA( void );
void gpioInitPortB( void );
void gpioInitPortC( void );
void gpioInitPortD( void );
void gpioInitPortE( void );
void gpioInitPortF( void );
	

#endif
