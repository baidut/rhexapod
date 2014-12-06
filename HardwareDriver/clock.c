/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
--------------------------------------------------------------------------------
使用一路定时器作为控制节拍
2014-5-29 23:38:40 
文件丢失重写
timeElapsed = Clock_GetTimeElapsed(last,now)改为自动获取当前时间
而不是计算两个时间的差值
Clock_GetTimDiff(tim1,tim2)
系统时钟中断，系统更新的最小单位
进行各种工作。如果把测速放在中断中，固定时间间隔触发，即可直接获取速度值，
但影响模块化轮询的结构。
程序主循环内更新时钟模块，将当前时钟置为0，
并保证主循环小于CNT_MOD个时钟周期，允许超一次。将数据类型改变可以方便地扩展
为保证安全，设tim_t为u32型。
#define CNT_MOD 1<<(sizeof(tim_t)*8) 需要比long int还要大1
Clock_Reset()

timCnt cnt改名，全局变量重名问题

TODO
添加timer类，提供定时器功能。基于一路PIT实现多个定时。
** -------------------------------------------------------------------------- */

#include "clock.h"

#include "rhexio.h"

tim_t timCnt=0;
#define CNT_MOD 256


void Clock_Init(){
  _TIMER_Init(TIM_SYS_CLOCK,PERIOD_SYS_CLOCK);
}
// 在events.h中或cfg中声明void SYS_CLOCK_OnInt();
void SYS_CLOCK_OnInt(){
	timCnt++;
}
// 添加一个定时器中断
tim_t Clock_GetTime(){
	return timCnt;
}
tim_t Clock_GetTimeElapsed(tim_t mark){
	return (timCnt+CNT_MOD-mark)%CNT_MOD;
}
tim_t Clock_GetTimDiff(tim_t timeStart,tim_t timeEnd){
	return (timeEnd+CNT_MOD-timeStart)%CNT_MOD;
}

#ifdef TEST
void Clock_Test(){
tim_t t;
	t = Clock_GetTime();
	printf("%d ",t);
}
#endif

// 0,1,...,255(11111111),0(256%256),1,....