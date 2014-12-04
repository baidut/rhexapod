/** -------------------------------------------------------------------------- *\
 * @brief 	野火库中断处理接口实现
 * @note 	DO NOT MODIFY THIS FILE!!! 
 * @author 	Zhenqiang Ying(yingzhenqiang@gmail.com)  
 * @link	https://github.com/baidut/rhexapod
\** -------------------------------------------------------------------------- */

#include "isr.h"
#include "mcu.h"

/* =========================================================================== *\
 * PIT
\* =========================================================================== */

void 	PIT0_IRQHandler(){
#ifdef 	PIT0_OnInt 
		PIT0_OnInt();
#endif
	PIT_Flag_Clear(PIT0);
}
void 	PIT1_IRQHandler(){
#ifdef 	PIT1_OnInt 
		PIT1_OnInt();
#endif
	PIT_Flag_Clear(PIT1);
}
void 	PIT2_IRQHandler(){
#ifdef 	PIT2_OnInt 
		PIT2_OnInt();
#endif
	PIT_Flag_Clear(PIT2);
}
void 	PIT3_IRQHandler(){
#ifdef 	PIT3_OnInt 
		PIT3_OnInt();
#endif
	PIT_Flag_Clear(PIT3);
}

/* =========================================================================== *\
 * PORT EXTI
\* =========================================================================== */

void PORTA_IRQHandler(){
#ifdef							PTA0_IRQHandler
	if( PORTA_ISFR & (1     )) 	PTA0_IRQHandler();
#endif
#ifdef							PTA1_IRQHandler
	if( PORTA_ISFR & (1 <<1 )) 	PTA1_IRQHandler();
#endif
#ifdef	PTA2_IRQHandler
	if( PORTA_ISFR & (1 <<2 )) 	PTA2_IRQHandler();
#endif
#ifdef							PTA3_IRQHandler
	if( PORTA_ISFR & (1 <<3 )) 	PTA3_IRQHandler();
#endif
#ifdef							PTA4_IRQHandler
	if( PORTA_ISFR & (1 <<4 )) 	PTA4_IRQHandler();
#endif
#ifdef							PTA5_IRQHandler
	if( PORTA_ISFR & (1 <<5 )) 	PTA5_IRQHandler();
#endif
#ifdef							PTA6_IRQHandler
	if( PORTA_ISFR & (1 <<6 )) 	PTA6_IRQHandler();
#endif
#ifdef							PTA7_IRQHandler
	if( PORTA_ISFR & (1 <<7 )) 	PTA7_IRQHandler();
#endif
#ifdef							PTA8_IRQHandler
	if( PORTA_ISFR & (1 <<8 )) 	PTA8_IRQHandler();
#endif
#ifdef							PTA9_IRQHandler
	if( PORTA_ISFR & (1 <<9 )) 	PTA9_IRQHandler();
#endif
#ifdef							PTA10_IRQHandler
	if( PORTA_ISFR & (1 <<10)) 	PTA10_IRQHandler();
#endif
#ifdef							PTA11_IRQHandler
	if( PORTA_ISFR & (1 <<11)) 	PTA11_IRQHandler();
#endif
#ifdef							PTA12_IRQHandler
	if( PORTA_ISFR & (1 <<12)) 	PTA12_IRQHandler();
#endif
#ifdef							PTA13_IRQHandler
	if( PORTA_ISFR & (1 <<13)) 	PTA13_IRQHandler();
#endif
#ifdef							PTA14_IRQHandler
	if( PORTA_ISFR & (1 <<14)) 	PTA14_IRQHandler();
#endif
#ifdef							PTA15_IRQHandler
	if( PORTA_ISFR & (1 <<15)) 	PTA15_IRQHandler();
#endif
#ifdef							PTA16_IRQHandler
	if( PORTA_ISFR & (1 <<16)) 	PTA16_IRQHandler();
#endif
#ifdef							PTA17_IRQHandler
	if( PORTA_ISFR & (1 <<17)) 	PTA17_IRQHandler();
#endif
#ifdef							PTA18_IRQHandler
	if( PORTA_ISFR & (1 <<18)) 	PTA18_IRQHandler();
#endif
#ifdef							PTA19_IRQHandler
	if( PORTA_ISFR & (1 <<19)) 	PTA19_IRQHandler();
#endif
#ifdef							PTA20_IRQHandler
	if( PORTA_ISFR & (1 <<20)) 	PTA20_IRQHandler();
#endif
#ifdef							PTA21_IRQHandler
	if( PORTA_ISFR & (1 <<21)) 	PTA21_IRQHandler();
#endif
#ifdef							PTA22_IRQHandler
	if( PORTA_ISFR & (1 <<22)) 	PTA22_IRQHandler();
#endif
#ifdef							PTA23_IRQHandler
	if( PORTA_ISFR & (1 <<23)) 	PTA23_IRQHandler();
#endif
#ifdef							PTA24_IRQHandler
	if( PORTA_ISFR & (1 <<24)) 	PTA24_IRQHandler();
#endif
#ifdef							PTA25_IRQHandler
	if( PORTA_ISFR & (1 <<25)) 	PTA25_IRQHandler();
#endif
#ifdef							PTA26_IRQHandler
	if( PORTA_ISFR & (1 <<26)) 	PTA26_IRQHandler();
#endif
#ifdef							PTA27_IRQHandler
	if( PORTA_ISFR & (1 <<27)) 	PTA27_IRQHandler();
#endif
#ifdef							PTA28_IRQHandler
	if( PORTA_ISFR & (1 <<28)) 	PTA28_IRQHandler();
#endif
#ifdef							PTA29_IRQHandler
	if( PORTA_ISFR & (1 <<29)) 	PTA29_IRQHandler();
#endif
#ifdef							PTA30_IRQHandler
	if( PORTA_ISFR & (1 <<30)) 	PTA30_IRQHandler();
#endif
#ifdef							PTA31_IRQHandler
	if( PORTA_ISFR & (1 <<31)) 	PTA31_IRQHandler();
#endif

	 PORTA_ISFR  = ~0;
}
void PORTB_IRQHandler(){

#ifdef							PTB0_IRQHandler
	if( PORTB_ISFR & (1     )) 	PTB0_IRQHandler();
#endif
#ifdef							PTB1_IRQHandler
	if( PORTB_ISFR & (1 <<1 )) 	PTB1_IRQHandler();
#endif
#ifdef							PTB2_IRQHandler
	if( PORTB_ISFR & (1 <<2 )) 	PTB2_IRQHandler();
#endif
#ifdef							PTB3_IRQHandler
	if( PORTB_ISFR & (1 <<3 )) 	PTB3_IRQHandler();
#endif
#ifdef							PTB4_IRQHandler
	if( PORTB_ISFR & (1 <<4 )) 	PTB4_IRQHandler();
#endif
#ifdef							PTB5_IRQHandler
	if( PORTB_ISFR & (1 <<5 )) 	PTB5_IRQHandler();
#endif
#ifdef							PTB6_IRQHandler
	if( PORTB_ISFR & (1 <<6 )) 	PTB6_IRQHandler();
#endif
#ifdef							PTB7_IRQHandler
	if( PORTB_ISFR & (1 <<7 )) 	PTB7_IRQHandler();
#endif
#ifdef							PTB8_IRQHandler
	if( PORTB_ISFR & (1 <<8 )) 	PTB8_IRQHandler();
#endif
#ifdef							PTB9_IRQHandler
	if( PORTB_ISFR & (1 <<9 )) 	PTB9_IRQHandler();
#endif
#ifdef							PTB10_IRQHandler
	if( PORTB_ISFR & (1 <<10)) 	PTB10_IRQHandler();
#endif
#ifdef							PTB11_IRQHandler
	if( PORTB_ISFR & (1 <<11)) 	PTB11_IRQHandler();
#endif
#ifdef							PTB12_IRQHandler
	if( PORTB_ISFR & (1 <<12)) 	PTB12_IRQHandler();
#endif
#ifdef							PTB13_IRQHandler
	if( PORTB_ISFR & (1 <<13)) 	PTB13_IRQHandler();
#endif
#ifdef							PTB14_IRQHandler
	if( PORTB_ISFR & (1 <<14)) 	PTB14_IRQHandler();
#endif
#ifdef							PTB15_IRQHandler
	if( PORTB_ISFR & (1 <<15)) 	PTB15_IRQHandler();
#endif
#ifdef							PTB16_IRQHandler
	if( PORTB_ISFR & (1 <<16)) 	PTB16_IRQHandler();
#endif
#ifdef							PTB17_IRQHandler
	if( PORTB_ISFR & (1 <<17)) 	PTB17_IRQHandler();
#endif
#ifdef							PTB18_IRQHandler
	if( PORTB_ISFR & (1 <<18)) 	PTB18_IRQHandler();
#endif
#ifdef							PTB19_IRQHandler
	if( PORTB_ISFR & (1 <<19)) 	PTB19_IRQHandler();
#endif
#ifdef							PTB20_IRQHandler
	if( PORTB_ISFR & (1 <<20)) 	PTB20_IRQHandler();
#endif
#ifdef							PTB21_IRQHandler
	if( PORTB_ISFR & (1 <<21)) 	PTB21_IRQHandler();
#endif
#ifdef							PTB22_IRQHandler
	if( PORTB_ISFR & (1 <<22)) 	PTB22_IRQHandler();
#endif
#ifdef							PTB23_IRQHandler
	if( PORTB_ISFR & (1 <<23)) 	PTB23_IRQHandler();
#endif
#ifdef							PTB24_IRQHandler
	if( PORTB_ISFR & (1 <<24)) 	PTB24_IRQHandler();
#endif
#ifdef							PTB25_IRQHandler
	if( PORTB_ISFR & (1 <<25)) 	PTB25_IRQHandler();
#endif
#ifdef							PTB26_IRQHandler
	if( PORTB_ISFR & (1 <<26)) 	PTB26_IRQHandler();
#endif
#ifdef							PTB27_IRQHandler
	if( PORTB_ISFR & (1 <<27)) 	PTB27_IRQHandler();
#endif
#ifdef							PTB28_IRQHandler
	if( PORTB_ISFR & (1 <<28)) 	PTB28_IRQHandler();
#endif
#ifdef							PTB29_IRQHandler
	if( PORTB_ISFR & (1 <<29)) 	PTB29_IRQHandler();
#endif
#ifdef							PTB30_IRQHandler
	if( PORTB_ISFR & (1 <<30)) 	PTB30_IRQHandler();
#endif
#ifdef							PTB31_IRQHandler
	if( PORTB_ISFR & (1 <<31)) 	PTB31_IRQHandler();
#endif

	 PORTB_ISFR  = ~0;
}
void PORTC_IRQHandler(){

#ifdef							PTC0_IRQHandler
	if( PORTC_ISFR & (1     )) 	PTC0_IRQHandler();
#endif
#ifdef							PTC1_IRQHandler
	if( PORTC_ISFR & (1 <<1 )) 	PTC1_IRQHandler();
#endif
#ifdef	PTC2_IRQHandler
	if( PORTC_ISFR & (1 <<2 )) 	PTC2_IRQHandler();
#endif
#ifdef							PTC3_IRQHandler
	if( PORTC_ISFR & (1 <<3 )) 	PTC3_IRQHandler();
#endif
#ifdef							PTC4_IRQHandler
	if( PORTC_ISFR & (1 <<4 )) 	PTC4_IRQHandler();
#endif
#ifdef							PTC5_IRQHandler
	if( PORTC_ISFR & (1 <<5 )) 	PTC5_IRQHandler();
#endif
#ifdef							PTC6_IRQHandler
	if( PORTC_ISFR & (1 <<6 )) 	PTC6_IRQHandler();
#endif
#ifdef							PTC7_IRQHandler
	if( PORTC_ISFR & (1 <<7 )) 	PTC7_IRQHandler();
#endif
#ifdef							PTC8_IRQHandler
	if( PORTC_ISFR & (1 <<8 )) 	PTC8_IRQHandler();
#endif
#ifdef							PTC9_IRQHandler
	if( PORTC_ISFR & (1 <<9 )) 	PTC9_IRQHandler();
#endif
#ifdef							PTC10_IRQHandler
	if( PORTC_ISFR & (1 <<10)) 	PTC10_IRQHandler();
#endif
#ifdef							PTC11_IRQHandler
	if( PORTC_ISFR & (1 <<11)) 	PTC11_IRQHandler();
#endif
#ifdef							PTC12_IRQHandler
	if( PORTC_ISFR & (1 <<12)) 	PTC12_IRQHandler();
#endif
#ifdef							PTC13_IRQHandler
	if( PORTC_ISFR & (1 <<13)) 	PTC13_IRQHandler();
#endif
#ifdef							PTC14_IRQHandler
	if( PORTC_ISFR & (1 <<14)) 	PTC14_IRQHandler();
#endif
#ifdef							PTC15_IRQHandler
	if( PORTC_ISFR & (1 <<15)) 	PTC15_IRQHandler();
#endif
#ifdef							PTC16_IRQHandler
	if( PORTC_ISFR & (1 <<16)) 	PTC16_IRQHandler();
#endif
#ifdef							PTC17_IRQHandler
	if( PORTC_ISFR & (1 <<17)) 	PTC17_IRQHandler();
#endif
#ifdef							PTC18_IRQHandler
	if( PORTC_ISFR & (1 <<18)) 	PTC18_IRQHandler();
#endif
#ifdef							PTC19_IRQHandler
	if( PORTC_ISFR & (1 <<19)) 	PTC19_IRQHandler();
#endif
#ifdef							PTC20_IRQHandler
	if( PORTC_ISFR & (1 <<20)) 	PTC20_IRQHandler();
#endif
#ifdef							PTC21_IRQHandler
	if( PORTC_ISFR & (1 <<21)) 	PTC21_IRQHandler();
#endif
#ifdef							PTC22_IRQHandler
	if( PORTC_ISFR & (1 <<22)) 	PTC22_IRQHandler();
#endif
#ifdef							PTC23_IRQHandler
	if( PORTC_ISFR & (1 <<23)) 	PTC23_IRQHandler();
#endif
#ifdef							PTC24_IRQHandler
	if( PORTC_ISFR & (1 <<24)) 	PTC24_IRQHandler();
#endif
#ifdef							PTC25_IRQHandler
	if( PORTC_ISFR & (1 <<25)) 	PTC25_IRQHandler();
#endif
#ifdef							PTC26_IRQHandler
	if( PORTC_ISFR & (1 <<26)) 	PTC26_IRQHandler();
#endif
#ifdef							PTC27_IRQHandler
	if( PORTC_ISFR & (1 <<27)) 	PTC27_IRQHandler();
#endif
#ifdef							PTC28_IRQHandler
	if( PORTC_ISFR & (1 <<28)) 	PTC28_IRQHandler();
#endif
#ifdef							PTC29_IRQHandler
	if( PORTC_ISFR & (1 <<29)) 	PTC29_IRQHandler();
#endif
#ifdef							PTC30_IRQHandler
	if( PORTC_ISFR & (1 <<30)) 	PTC30_IRQHandler();
#endif
#ifdef							PTC31_IRQHandler
	if( PORTC_ISFR & (1 <<31)) 	PTC31_IRQHandler();
#endif

	 PORTC_ISFR  = ~0;
}
void PORTD_IRQHandler(){

#ifdef							PTD0_IRQHandler
	if( PORTD_ISFR & (1     )) 	PTD0_IRQHandler();
#endif
#ifdef							PTD1_IRQHandler
	if( PORTD_ISFR & (1 <<1 )) 	PTD1_IRQHandler();
#endif
#ifdef	PTD2_IRQHandler
	if( PORTD_ISFR & (1 <<2 )) 	PTD2_IRQHandler();
#endif
#ifdef							PTD3_IRQHandler
	if( PORTD_ISFR & (1 <<3 )) 	PTD3_IRQHandler();
#endif
#ifdef							PTD4_IRQHandler
	if( PORTD_ISFR & (1 <<4 )) 	PTD4_IRQHandler();
#endif
#ifdef							PTD5_IRQHandler
	if( PORTD_ISFR & (1 <<5 )) 	PTD5_IRQHandler();
#endif
#ifdef							PTD6_IRQHandler
	if( PORTD_ISFR & (1 <<6 )) 	PTD6_IRQHandler();
#endif
#ifdef							PTD7_IRQHandler
	if( PORTD_ISFR & (1 <<7 )) 	PTD7_IRQHandler();
#endif
#ifdef							PTD8_IRQHandler
	if( PORTD_ISFR & (1 <<8 )) 	PTD8_IRQHandler();
#endif
#ifdef							PTD9_IRQHandler
	if( PORTD_ISFR & (1 <<9 )) 	PTD9_IRQHandler();
#endif
#ifdef							PTD10_IRQHandler
	if( PORTD_ISFR & (1 <<10)) 	PTD10_IRQHandler();
#endif
#ifdef							PTD11_IRQHandler
	if( PORTD_ISFR & (1 <<11)) 	PTD11_IRQHandler();
#endif
#ifdef							PTD12_IRQHandler
	if( PORTD_ISFR & (1 <<12)) 	PTD12_IRQHandler();
#endif
#ifdef							PTD13_IRQHandler
	if( PORTD_ISFR & (1 <<13)) 	PTD13_IRQHandler();
#endif
#ifdef							PTD14_IRQHandler
	if( PORTD_ISFR & (1 <<14)) 	PTD14_IRQHandler();
#endif
#ifdef							PTD15_IRQHandler
	if( PORTD_ISFR & (1 <<15)) 	PTD15_IRQHandler();
#endif
#ifdef							PTD16_IRQHandler
	if( PORTD_ISFR & (1 <<16)) 	PTD16_IRQHandler();
#endif
#ifdef							PTD17_IRQHandler
	if( PORTD_ISFR & (1 <<17)) 	PTD17_IRQHandler();
#endif
#ifdef							PTD18_IRQHandler
	if( PORTD_ISFR & (1 <<18)) 	PTD18_IRQHandler();
#endif
#ifdef							PTD19_IRQHandler
	if( PORTD_ISFR & (1 <<19)) 	PTD19_IRQHandler();
#endif
#ifdef							PTD20_IRQHandler
	if( PORTD_ISFR & (1 <<20)) 	PTD20_IRQHandler();
#endif
#ifdef							PTD21_IRQHandler
	if( PORTD_ISFR & (1 <<21)) 	PTD21_IRQHandler();
#endif
#ifdef							PTD22_IRQHandler
	if( PORTD_ISFR & (1 <<22)) 	PTD22_IRQHandler();
#endif
#ifdef							PTD23_IRQHandler
	if( PORTD_ISFR & (1 <<23)) 	PTD23_IRQHandler();
#endif
#ifdef							PTD24_IRQHandler
	if( PORTD_ISFR & (1 <<24)) 	PTD24_IRQHandler();
#endif
#ifdef							PTD25_IRQHandler
	if( PORTD_ISFR & (1 <<25)) 	PTD25_IRQHandler();
#endif
#ifdef							PTD26_IRQHandler
	if( PORTD_ISFR & (1 <<26)) 	PTD26_IRQHandler();
#endif
#ifdef							PTD27_IRQHandler
	if( PORTD_ISFR & (1 <<27)) 	PTD27_IRQHandler();
#endif
#ifdef							PTD28_IRQHandler
	if( PORTD_ISFR & (1 <<28)) 	PTD28_IRQHandler();
#endif
#ifdef							PTD29_IRQHandler
	if( PORTD_ISFR & (1 <<29)) 	PTD29_IRQHandler();
#endif
#ifdef							PTD30_IRQHandler
	if( PORTD_ISFR & (1 <<30)) 	PTD30_IRQHandler();
#endif
#ifdef							PTD31_IRQHandler
	if( PORTD_ISFR & (1 <<31)) 	PTD31_IRQHandler();
#endif

	 PORTD_ISFR  = ~0;
}
void PORTE_IRQHandler(){

#ifdef							PTE0_IRQHandler
	if( PORTE_ISFR & (1     )) 	PTE0_IRQHandler();
#endif
#ifdef							PTE1_IRQHandler
	if( PORTE_ISFR & (1 <<1 )) 	PTE1_IRQHandler();
#endif
#ifdef	PTE2_IRQHandler
	if( PORTE_ISFR & (1 <<2 )) 	PTE2_IRQHandler();
#endif
#ifdef							PTE3_IRQHandler
	if( PORTE_ISFR & (1 <<3 )) 	PTE3_IRQHandler();
#endif
#ifdef							PTE4_IRQHandler
	if( PORTE_ISFR & (1 <<4 )) 	PTE4_IRQHandler();
#endif
#ifdef							PTE5_IRQHandler
	if( PORTE_ISFR & (1 <<5 )) 	PTE5_IRQHandler();
#endif
#ifdef							PTE6_IRQHandler
	if( PORTE_ISFR & (1 <<6 )) 	PTE6_IRQHandler();
#endif
#ifdef							PTE7_IRQHandler
	if( PORTE_ISFR & (1 <<7 )) 	PTE7_IRQHandler();
#endif
#ifdef							PTE8_IRQHandler
	if( PORTE_ISFR & (1 <<8 )) 	PTE8_IRQHandler();
#endif
#ifdef							PTE9_IRQHandler
	if( PORTE_ISFR & (1 <<9 )) 	PTE9_IRQHandler();
#endif
#ifdef							PTE10_IRQHandler
	if( PORTE_ISFR & (1 <<10)) 	PTE10_IRQHandler();
#endif
#ifdef							PTE11_IRQHandler
	if( PORTE_ISFR & (1 <<11)) 	PTE11_IRQHandler();
#endif
#ifdef							PTE12_IRQHandler
	if( PORTE_ISFR & (1 <<12)) 	PTE12_IRQHandler();
#endif
#ifdef							PTE13_IRQHandler
	if( PORTE_ISFR & (1 <<13)) 	PTE13_IRQHandler();
#endif
#ifdef							PTE14_IRQHandler
	if( PORTE_ISFR & (1 <<14)) 	PTE14_IRQHandler();
#endif
#ifdef							PTE15_IRQHandler
	if( PORTE_ISFR & (1 <<15)) 	PTE15_IRQHandler();
#endif
#ifdef							PTE16_IRQHandler
	if( PORTE_ISFR & (1 <<16)) 	PTE16_IRQHandler();
#endif
#ifdef							PTE17_IRQHandler
	if( PORTE_ISFR & (1 <<17)) 	PTE17_IRQHandler();
#endif
#ifdef							PTE18_IRQHandler
	if( PORTE_ISFR & (1 <<18)) 	PTE18_IRQHandler();
#endif
#ifdef							PTE19_IRQHandler
	if( PORTE_ISFR & (1 <<19)) 	PTE19_IRQHandler();
#endif
#ifdef							PTE20_IRQHandler
	if( PORTE_ISFR & (1 <<20)) 	PTE20_IRQHandler();
#endif
#ifdef							PTE21_IRQHandler
	if( PORTE_ISFR & (1 <<21)) 	PTE21_IRQHandler();
#endif
#ifdef							PTE22_IRQHandler
	if( PORTE_ISFR & (1 <<22)) 	PTE22_IRQHandler();
#endif
#ifdef							PTE23_IRQHandler
	if( PORTE_ISFR & (1 <<23)) 	PTE23_IRQHandler();
#endif
#ifdef							PTE24_IRQHandler
	if( PORTE_ISFR & (1 <<24)) 	PTE24_IRQHandler();
#endif
#ifdef							PTE25_IRQHandler
	if( PORTE_ISFR & (1 <<25)) 	PTE25_IRQHandler();
#endif
#ifdef							PTE26_IRQHandler
	if( PORTE_ISFR & (1 <<26)) 	PTE26_IRQHandler();
#endif
#ifdef							PTE27_IRQHandler
	if( PORTE_ISFR & (1 <<27)) 	PTE27_IRQHandler();
#endif
#ifdef							PTE28_IRQHandler
	if( PORTE_ISFR & (1 <<28)) 	PTE28_IRQHandler();
#endif
#ifdef							PTE29_IRQHandler
	if( PORTE_ISFR & (1 <<29)) 	PTE29_IRQHandler();
#endif
#ifdef							PTE30_IRQHandler
	if( PORTE_ISFR & (1 <<30)) 	PTE30_IRQHandler();
#endif
#ifdef							PTE31_IRQHandler
	if( PORTE_ISFR & (1 <<31)) 	PTE31_IRQHandler();
#endif

	 PORTE_ISFR  = ~0;
}