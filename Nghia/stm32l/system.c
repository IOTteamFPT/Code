/**
 ******************************************************************************
 * @Author: ThanNT
 * @Date:   05/09/2016
 ******************************************************************************
**/
#include <stdint.h>
#include <stdbool.h>

#include "sys_cfg.h"
#include "system.h"
#include "stm32l.h"

#include "system_stm32l1xx.h"
#include "stm32l1xx.h"
#include "stm32l1xx_conf.h"
#include "core_cm3.h"

#include "../../sys/sys_dbg.h"
#include "../../sys/sys_ctrl.h"
#include "../../sys/sys_irq.h"

#include "../../ak/ak.h"
#include "../../ak/message.h"
#include "../../ak/timer.h"

#include "../../app/app.h"

/*****************************************************************************/
/* linker variable                                                           */
/*****************************************************************************/
extern uint32_t _ldata;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _bss;
extern uint32_t _ebss;
extern uint32_t _estack;

extern void (*__preinit_array_start[])();
extern void (*__preinit_array_end[])();
extern void (*__init_array_start[])();
extern void (*__init_array_end[])();
extern void _init();

/*****************************************************************************/
/* static function prototype                                                 */
/*****************************************************************************/
/*****************************/
/* system interrupt function */
/*****************************/
void default_handler();
void reset_handler();

/*****************************/
/* user interrupt function   */
/*****************************/
void exti_line1_irq();
void exti_line15_irq();
void timer6_irq();
void timer4_irq();
void timer7_irq();

/* cortex-M processor fault exceptions */
void nmi_handler()          __attribute__ ((weak));
void hard_fault_handler()   __attribute__ ((weak));
void mem_manage_handler()   __attribute__ ((weak));
void bus_fault_handler()    __attribute__ ((weak));
void usage_fault_handler()  __attribute__ ((weak));

/* cortex-M processor non-fault exceptions */
void svc_handler()          __attribute__ ((weak, alias("default_handler")));
void dg_monitor_handler()   __attribute__ ((weak, alias("default_handler")));
void pendsv_handler()       __attribute__ ((weak, alias("default_handler")));
void systick_handler();

/* external interrupts */
static void shell_handler();

/*****************************************************************************/
/* system variable                                                           */
/*****************************************************************************/
system_info_t system_info;

/*****************************************************************************/
/* interrupt vector table                                                    */
/*****************************************************************************/
__attribute__((section(".isr_vector")))
void (* const isr_vector[])() = {
		((void (*)())(uint32_t)&_estack),		//	The initial stack pointer
		reset_handler,							//	The reset handler
		nmi_handler,							//	The NMI handler
		hard_fault_handler,						//	The hard fault handler
		mem_manage_handler,						//	The MPU fault handler
		bus_fault_handler,						//	The bus fault handler
		usage_fault_handler,					//	The usage fault handler
		0,										//	Reserved
		0,										//	Reserved
		0,										//	Reserved
		0,										//	Reserved
		svc_handler,							//	SVCall handler
		dg_monitor_handler,						//	Debug monitor handler
		0,										//	Reserved
		pendsv_handler,							//	The PendSV handler
		systick_handler,						//	The SysTick handler

		//External Interrupts
		default_handler,						//	Window Watchdog
		default_handler,						//	PVD through EXTI Line detect
		default_handler,						//	Tamper and Time Stamp
		default_handler,						//	RTC Wakeup
		default_handler,						//	FLASH
		default_handler,						//	RCC
		default_handler,						//	EXTI Line 0
		exti_line1_irq,							//	EXTI Line 1
		default_handler,						//	EXTI Line 2
		default_handler,						//	EXTI Line 3
		default_handler,						//	EXTI Line 4
		default_handler,						//	DMA1 Channel 1
		default_handler,						//	DMA1 Channel 2
		default_handler,						//	DMA1 Channel 3
		default_handler,						//	DMA1 Channel 4
		default_handler,						//	DMA1 Channel 5
		default_handler,						//	DMA1 Channel 6
		default_handler,						//	DMA1 Channel 7
		default_handler,						//	ADC1
		default_handler,						//	USB High Priority
		default_handler,						//	USB Low  Priority
		default_handler,						//	DAC
		default_handler,						//	COMP through EXTI Line
		default_handler,						//	EXTI Line 9..5
		default_handler,						//	LCD
		default_handler,						//	TIM9
		default_handler,						//	TIM10
		default_handler,						//	TIM11
		default_handler,						//	TIM2
		default_handler,						//	TIM3
		timer4_irq,								//	TIM4
		default_handler,						//	I2C1 Event
		default_handler,						//	I2C1 Error
		default_handler,						//	I2C2 Event
		default_handler,						//	I2C2 Error
		default_handler,						//	SPI1
		default_handler,						//	SPI2
		shell_handler,							//	USART1
		default_handler,						//	USART2
		default_handler,						//	USART3
		exti_line15_irq,						//	EXTI Line 15..10
		default_handler,						//	RTC Alarm through EXTI Line
		default_handler,						//	USB FS Wakeup from suspend
		timer6_irq,								//	TIM6
		timer7_irq,								//	TIM7
		};

void __attribute__((naked))
sys_ctrl_delay(volatile uint32_t count)
{
	__asm("    subs    r0, #1\n"
	"    bne     sys_ctrl_delay\n"
	"    bx      lr");
}

static uint32_t millis_current  = 0;

uint32_t sys_ctrl_millis() {
	volatile uint32_t ret;
	ENTRY_CRITICAL();
	ret = millis_current;
	EXIT_CRITICAL();
	return ret;
}

void _init() {
	/* dummy */
}

/*****************************************************************************/
/* static function defination                                                */
/*****************************************************************************/
void default_handler() {
	FATAL("SY", 0xEE);
}

void reset_handler() {
	uint32_t *pSrc	= &_ldata;
	uint32_t *pDest	= &_data;
	volatile unsigned i, cnt;

	/* init system */
	SystemInit();

	/* copy init data from FLASH to SRAM */
	while(pDest < &_edata) {
		*pDest++ = *pSrc++;
	}

	/* zero bss */
	for (pDest = &_bss; pDest < &_ebss; pDest++) {
		*pDest = 0UL;
	}

	sys_cfg_clock();
	sys_cfg_tick();     /* system tick 1ms */
	sys_cfg_console();  /* system console */

	/* invoke all static constructors */
	cnt = __preinit_array_end - __preinit_array_start;
	for (i = 0; i < cnt; i++)
		__preinit_array_start[i]();

	_init();

	cnt = __init_array_end - __init_array_start;
	for (i = 0; i < cnt; i++)
		__init_array_start[i]();

	/* wait configuration stable */
	sys_ctrl_delay(100);  /* wait 300 cycles clock */

	/* update system information */
	sys_cfg_update_info();

	/* entry app function */
	main_app();
}

/***************************************/
/* cortex-M processor fault exceptions */
/***************************************/
void nmi_handler() {
	FATAL("SY", 0x01);
}

void hard_fault_handler() {
	FATAL("SY", 0x02);
}

void mem_manage_handler() {
	FATAL("SY", 0x03);
}

void bus_fault_handler() {
	FATAL("SY", 0x04);
}

void usage_fault_handler() {
	FATAL("SY", 0x05);
}

/*******************************************/
/* cortex-M processor non-fault exceptions */
/*******************************************/
void systick_handler() {
	static uint32_t div_counter = 0;

	/* increasing millis counter */
	millis_current++;

	if (div_counter == 10) {
		div_counter = 0;
	}

	switch(div_counter) {
	case 0:
		/* trigger heart beat of system */
		timer_tick(10);
		break;

	case 1:
		sys_irq_timer_10ms();
		break;

	default:
		break;
	}
	div_counter++;
}

/************************/
/* external interrupts  */
/************************/
void shell_handler() {
	if (USART_GetITStatus(USARTx, USART_IT_RXNE) == SET) {
		sys_irq_shell();
	}
}

void exti_line1_irq() {
	if (EXTI_GetITStatus(EXTI_Line1) != RESET) {
		EXTI_ClearITPendingBit(EXTI_Line1);
		sys_irq_nrf24l01();
	}
}

void exti_line15_irq() {
	if (EXTI_GetITStatus(EXTI_Line15) != RESET) {
		EXTI_ClearITPendingBit(EXTI_Line15);
		sys_irq_ir_io_rev();
	}
}

void timer6_irq() {
	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
		sys_irq_timer_50us();
	}
}

void timer7_irq() {
	if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
		sys_ctrl_soft_watchdog_increase_counter();
	}
}

void timer4_irq() {
	if (TIM_GetITStatus(TIM4, TIM_IT_CC4) != RESET) {
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC4);
		sys_irq_timer_hs1101();
	}
}
