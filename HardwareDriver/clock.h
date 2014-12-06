/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
--------------------------------------------------------------------------------
@example  
  mark = Clock_GetTime(); // mark current time
  while( Clock_GetTimeElapsed(mark) < waitTime ); // wait for a while

不提供具体时间
  但是可以为任务建立一个周期为系统周期的n倍的计时器。可以了解计时器时间到的信息
** -------------------------------------------------------------------------- */

#ifndef _clock_H_
#define _clock_H_

#include "sys.h"

void Clock_Init();
tim_t Clock_GetTime();// 锯齿波 获取当前时间标记
tim_t Clock_GetTimeElapsed(tim_t fromWhen);
tim_t Clock_GetTimDiff(tim_t timeStart,tim_t timeEnd);

#ifdef TEST
void Clock_Test(); 
#endif

#endif