/** -------------------------------------------------------------------------- *\
 * @brief 	提供使用野火库的接口，如需要一直其他库，完成对应的接口匹配即可。
 * @note 	DO NOT MODIFY THIS FILE!!! 
 * @author 	Zhenqiang Ying(yingzhenqiang@gmail.com)  
 * @link	https://github.com/baidut/rhexapod
\** -------------------------------------------------------------------------- */

#ifndef _mcu_H_
#define _mcu_H_

#include "util.h"
#include "common.h"

// 在common中包含了FIRE_MK60_conf.h中包含printf的重定向
// #define FIRE_PORT           UART3
// #define FIRE_BAUD           115200

#define IO            	            PTxn// PTXn_e 


#define MCU_Reset()                 (SCB_AIRCR = SCB_AIRCR_VECTKEY(0x5FA)|SCB_AIRCR_SYSRESETREQ_MASK)
#define MCU_DisInt()                DisableInterrupts
#define MCU_EnInt()                 EnableInterrupts

/* DELAY -------------------------------------------------------------------- */

#include "lptmr.h"

#define _DELAY_US(t)                delayms( (1000*t) )//dwt_delay_ms( t) //


/* GPIO --------------------------------------------------------------------- */

#include  "gpio.h"

#define PTX(PTxn)                   (PORTx)((PTxn)>>5)
#define PTn(PTxn)                   ((PTxn)&0x1f)
#define PORTX_BASE(PTxn)            PORTX[PTX(PTxn)]       //PORT模块的地址

#define _GPO_Init(ptxn,val)	        gpio_init(PTX(ptxn),PTn(ptxn),GPO,val)
#define _GPI_Init(ptxn)		        gpio_init(PTX(ptxn),PTn(ptxn),GPI,LOW)

#define _GPIO_Get(ptxn)		        gpio_get(PTX(ptxn),PTn(ptxn))
#define _GPIO_Set(ptxn)			    gpio_set(PTX(ptxn),PTn(ptxn),1)
#define _GPIO_Clr(ptxn)				gpio_set(PTX(ptxn),PTn(ptxn),0)
#define _GPIO_Put(ptxn,val)			gpio_set(PTX(ptxn),PTn(ptxn),val)
#define _GPIO_Turn(ptxn)		    gpio_turn(PTX(ptxn),PTn(ptxn))

/* PWM ---------------------------------------------------------------------- */

#include "FTM.h"

typedef struct {
	FTMn	ftm;
	CHn		ch;
} PWM;

/*
        --FTM0--  --FTM1--  --FTM2--
CH0       PTC1      PTA8      PTA10
CH1       PTC2      PTA9      PTA11
CH2       PTC3       \         \
CH3       PTC4       \         \
CH4       PTD4       \         \
CH5       PTD5       \         \
CH6       PTD6       \         \
CH7       PTD7       \         \
*/

#define PTC1_PWM					{FTM0,CH0}//{0,0}
#define PTC2_PWM					{FTM0,CH1}//{0,1}
#define PTC3_PWM					{FTM0,CH2}//{0,2}
#define PTC4_PWM					{FTM0,CH3}//{0,3}
#define PTD4_PWM					{FTM0,CH4}//{0,4}
#define PTD5_PWM					{FTM0,CH5}//{0,5}
#define PTD6_PWM					{FTM0,CH6}//{0,6}
#define PTD7_PWM					{FTM0,CH7}//{0,7}

#define PTA8_PWM					{FTM1,CH0}//{1,0}
#define PTA9_PWM					{FTM1,CH1}//{1,1}

#define PTA10_PWM					{FTM2,CH0}//{2,0}
#define PTA11_PWM					{FTM2,CH1}//{2,1}

#define _CONCAT(x,y)                x##y
#define _IO_TO_PWM(io)              _CONCAT(io,_PWM)

#define _PWM_Init(me, freq, ouput)	FTM_PWM_init( (me).ftm, (me).ch, freq, ouput)   // 0-200 20% void FTM_PWM_init(FTMn_e, FTM_CHn_e, uint32 freq, uint32 duty); 
#define	_PWM_SetDuty(me, duty)		FTM_PWM_Duty( (me).ftm, (me).ch, duty)          // void FTM_PWM_Duty(FTMn_e ftmn, FTM_CHn_e ch, uint32 duty)

/* EXTI --------------------------------------------------------------------- */

#include "exti.h"

#define _EXTI_Init(ptxn,cfg)		exti_init(PTX(ptxn),PTn(ptxn),cfg);         //  exti_init(PORTB, 1, rising_down);


/* PIT  --------------------------------------------------------------------- */

#include "pit.h"

#define _TIMER_EnIrq(pitn)			enable_irq (pitn+68)                        //这里PIT0是枚举0 68是PIT0对应的irq号码 由于PIT0的irq+n即对应PITn的irq号，所以这么写
#define _TIMER_DisIrq(pitn)			disable_irq (pitn+68)
#define _TIMER_Init(pitn,period)	pit_init_ms(pitn,period)
#define _TIMER_SetPeriod(pitn,p)    _TIMER_Init(pitn,period)

/* UART --------------------------------------------------------------------- */

#include  "uart.h" 

#define _UART_EnIrq(uart)           uart_irq_EN(uart)
#define _UART_DisIrq(uart)          uart_irq_DIS(uart)

#define _UART_Init(uart,baud)		uart_init(uart,baud)

#define _UART_SendChar(uart,ch)     uart_putchar (uart,ch)
#define _UART_SendStr(uart,s)       uart_sendStr (uart,s)

#define _UART_Query(uart)           uart_query(uart)
#define _UART_RecvChar(uart)        uart_getchar(uart)
#define _UART_TryRecv(uart,ch)      uart_pendchar(uart,ch)

#endif
