/** -------------------------------------------------------------------------- *\
 * @brief 	野火库中断处理接口
 * @note 	DO NOT MODIFY THIS FILE!!! 
 * @author 	Zhenqiang Ying(yingzhenqiang@gmail.com)  
 * @link	https://github.com/baidut/rhexapod
\** -------------------------------------------------------------------------- */

#ifndef __isr_H__
#define __isr_H__

#include "events.h"

/* UART --------------------------------------------------------------------- */

//#ifdef UART2_IRQHandler
#undef  VECTOR_065                        
#define VECTOR_065    UART2_IRQHandler
extern void UART2_IRQHandler(); 
//#endif

/* EXTI --------------------------------------------------------------------- */

#undef VECTOR_103
#define VECTOR_103 PORTA_IRQHandler 
extern void PORTA_IRQHandler(); 

#undef VECTOR_104
#define VECTOR_104 PORTB_IRQHandler 
extern void PORTB_IRQHandler(); 

#undef VECTOR_105
#define VECTOR_105 PORTC_IRQHandler 
extern void PORTC_IRQHandler(); 

#undef VECTOR_106
#define VECTOR_106 PORTD_IRQHandler 
extern void PORTD_IRQHandler(); 

#undef VECTOR_107
#define VECTOR_107 PORTE_IRQHandler 
extern void PORTE_IRQHandler(); 

/* PIT  --------------------------------------------------------------------- */

#undef VECTOR_084
#define VECTOR_084 PIT0_IRQHandler 
extern void PIT0_IRQHandler();

#undef VECTOR_085
#define VECTOR_085 PIT1_IRQHandler 
extern void PIT1_IRQHandler(); 

#undef VECTOR_086
#define VECTOR_086 PIT2_IRQHandler 
extern void PIT2_IRQHandler(); 

#undef VECTOR_087
#define VECTOR_087 PIT3_IRQHandler 
extern void PIT3_IRQHandler(); 

/* -------------------------------------------------------------------------- */
#endif  