
#ifndef _events_H_
#define _events_H_

#include "common.h"

extern void AS1_INDEX_IRQHandler();
extern void AS2_INDEX_IRQHandler();
extern void AS3_INDEX_IRQHandler();
extern void AS4_INDEX_IRQHandler();
extern void AS5_INDEX_IRQHandler();
extern void AS6_INDEX_IRQHandler();

extern void AS1_GET_DIR_IRQHandler();
extern void AS2_GET_DIR_IRQHandler();
extern void AS3_GET_DIR_IRQHandler();
extern void AS4_GET_DIR_IRQHandler();
extern void AS5_GET_DIR_IRQHandler();
extern void AS6_GET_DIR_IRQHandler();

// extern void UART2_IRQHandler(); 
// void BHT_IRQHandler();

void SYS_CLOCK_OnInt();
void PID_OnInt();

void TIM_DOG_OnInt();
void TIM_ACTION_UPDATE_OnInt();

void Events_Init();

#endif