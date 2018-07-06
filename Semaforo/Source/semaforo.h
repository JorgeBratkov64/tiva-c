//*****************************************************************************
//
// System Control registers (SYSCTL)
//
//*****************************************************************************
#define SYSCTL_RIS_R            (*((volatile uint32_t *)0x400FE050))
#define SYSCTL_RCC_R            (*((volatile uint32_t *)0x400FE060))
#define SYSCTL_RCC2_R           (*((volatile uint32_t *)0x400FE070))	
#define SYSCTL_RCGC2_R          (*((volatile uint32_t *)0x400FE108))
	
//*****************************************************************************
//
// NVIC registers (NVIC)
//
//*****************************************************************************
#define NVIC_ST_CTRL_R          (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))
	
//*****************************************************************************
//
// GPIO registers (PORTE)
//
//*****************************************************************************

#define GPIO_PORTE_DATA_R       (*((volatile uint32_t *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile uint32_t *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile uint32_t *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile uint32_t *)0x40024510))
#define GPIO_PORTE_PDR_R        (*((volatile uint32_t *)0x40024514))
#define GPIO_PORTE_DEN_R        (*((volatile uint32_t *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile uint32_t *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile uint32_t *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile uint32_t *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile uint32_t *)0x4002452C))


//*****************************************************************************
//
// GPIO registers (PORTD)
//
//*****************************************************************************

#define GPIO_PORTD_DATA_R       (*((volatile uint32_t *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile uint32_t *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile uint32_t *)0x40007420))
#define GPIO_PORTD_PUR_R        (*((volatile uint32_t *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile uint32_t *)0x40007514))
#define GPIO_PORTD_DEN_R        (*((volatile uint32_t *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile uint32_t *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile uint32_t *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile uint32_t *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile uint32_t *)0x4000752C))


	

	
