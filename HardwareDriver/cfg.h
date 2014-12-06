
/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
--------------------------------------------------------------------------------
本文件是工程配置文件， 包含在common.h文件的最后
common.h是野火的通用配置头文件，所有的文件都包含这个头
所以这个文件可以对野火的工程进行配置。
同时，这里还存放我们的硬件配置信息
除此文件外的其他文件中不得包含与我们具体硬件配置相关的信息，
以实现对硬件配置修改的灵活性。
** -------------------------------------------------------------------------- */

#ifndef _cfg_H_
#define _cfg_H_

// 配置宏 以CFG开头，是对工程的配置=============================================

// #define CFG_DEBUG
// 如果定义了这个宏，就可以使用DEBUG设备，同时，程序中有输出错误信息。

// 对野火库的配置文件的更改=====================================================
// 设置串口调试对应的端口


#include "rhexio.h"//注意


#define debug // 显示断言发生的中断号

// 单片机资源分配===============================================================

// TIM-TIMER
#define	TIM_ACTION_UPDATE	PIT0 //TIM_MEASURE_SPEED
#define	TIM_DOG         	PIT1
#define TIM_SYS_CLOCK 	    PIT2
#define TIM_PID             PIT3

#define PIT0_OnInt          TIM_ACTION_UPDATE_OnInt
#define PIT1_OnInt          TIM_DOG_OnInt

#define PIT2_OnInt          SYS_CLOCK_OnInt
#define PIT3_OnInt          PID_OnInt
// 中断函数 OnInt 是简化了PE中的OnInterrupt命名风格
// 注意与IRQHandler区别 后者是处理，需要进行清中断处理，而前者自动处理了这个工作
// 可以看到PE的处理并没有通过宏来提高速度，建议少用宏牺牲速度而保证安全可靠性

//#define JLINK_DEBUG //模拟测试，调整周期一秒则
#ifdef JLINK_DEBUG
#define PERIOD_PID              1000//测试逻辑时改成1秒更新一次，用手模拟20
//30 1s测量一次，一秒不会超过半圈 15之内
#else
#define PERIOD_PID              20
#endif

#define PERIOD_ACTION_UPDATE    1000//200//PERIOD_MEASURE_SPEED	100
#define PERIOD_DOG	            1000//每秒喂狗一次、
#define PERIOD_SYS_CLOCK	    2

#define  LED_CHECK_CONNECT      P1
#define  LED_UART               P2
#define  LED_MEASURE_SPEED      P3


extern void Safe_ShutDown();


#endif