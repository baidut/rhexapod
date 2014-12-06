/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1

--------------------------------------------------------------------------------

** -------------------------------------------------------------------------- */

#ifndef _bluetooth_H_
#define _bluetooth_H_

#include "sys.h"
#include "mcu.h"

#define DEBUG_UART              FIRE_PORT
#define DEBUG_BAUD              FIRE_BAUD

#define BHT_Init()              _UART_Init(DEBUG_UART,DEBUG_BAUD)

#define BHT_SendChar(ch)       	_UART_SendChar(DEBUG_UART,ch)
#define BHT_SendStr(s)         	_UART_SendStr(DEBUG_UART,s)

#define BHT_EnIrq()             _UART_EnIrq(DEBUG_UART)
#define BHT_DisIrq()            _UART_DisIrq(DEBUG_UART)

#define BHT_GetChar()           _UART_RecvChar(DEBUG_UART)
#define BHT_TryGetChar(ch)      _UART_TryRecv(DEBUG_UART,ch)
#define BHT_isReceived()        _UART_Query(DEBUG_UART)

#define BHT_Printf              printf // 比较费时
#define BHT_Msg(FORMAT,...)     printf("M" FORMAT,##__VA_ARGS__)
#define BHT_Alert(FORMAT,...)   printf("A" FORMAT,##__VA_ARGS__)

void BHT_SetIrqHandler(void (*f)());
void BHT_Test();

#endif
