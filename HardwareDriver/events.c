/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
** -------------------------------------------------------------------------- */

#include "events.h"
#include "mcu.h"

/* =========================================================================== *\
@brief 设置中断优先级： 端口中断 > 定时中断 > 串口中断
由于是整体的配置，因此具体端口配置修改后无需修改这里
--------------------------------------------------------------------------------
K60设置优先级
没有设置优先级的中断默认是无抢占机制的，因此如果要设置优先级，就要对两个中断都做优先级配置。
默认优先级就是中断向量表里的顺序。通过调用Cortex-M4的内核函数set_irq_priority实现修改优先级
void set_irq_priority (int irq, int prio)源代码在arm_cm4.c里
参数1是irq号：irq号=中断号-16 前16个中断是系统的 不能用
参数2是优先级：正整数，数字越小，优先级越高

K60中断管理属于NVIC模块的内容（一个中断管理器）
通过enable_irq (int irq)打开对应的中断

资料 
官方手册NVIC部分
K60芯片NVIC模块中断相关寄存器配置以及应用举例 http://www.docin.com/p-675904085.html 
stm32f407之NVIC  http://blog.csdn.net/w471176877/article/details/7957174 
对应表见>Ch3.1-Chip Configuration(k60中文) http://wenku.baidu.com/link?url=u_WxxIq5SJgVH-KsAzD_PM-FzYGVUEBdrDIuVGlHs9CpOehm6x1dNP4TpvbSesVcIGwglqH97OVzxanNG1u8NZIqzeupOqBaAmViI2YdfAW
  或查看vector.h
--------------------------------------------------------------------------------
测试记录：让程序死在定时中断中，再动足触发IO中断 测试结果，没有跳出 
现象解释：两个都要设置优先级才可以

#define VECTOR_103      default_isr     // 0x0000_019C 103   87     Port control module Pin Detect (Port A)
#define VECTOR_104      default_isr     // 0x0000_01A0 104   88     Port control module Pin Detect (Port B)
#define VECTOR_105      default_isr     // 0x0000_01A4 105   89     Port control module Pin Detect (Port C)
#define VECTOR_106      default_isr     // 0x0000_01A8 106   90     Port control module Pin Detect (Port D)
#define VECTOR_107      default_isr     // 0x0000_01AC 107   91     Port control module Pin Detect (Port E)

#define VECTOR_084      default_isr     // 0x0000_0150 84   68     PIT Channel 0
#define VECTOR_085      default_isr     // 0x0000_0154 85    69     PIT Channel 1
#define VECTOR_086      default_isr     // 0x0000_0158 86    70     PIT Channel 2
#define VECTOR_087      default_isr     // 0x0000_015C 87    71     PIT Channel 3

#define VECTOR_061      default_isr     // 0x0000_00F4 61    45     UART0            Single interrupt vector for UART status sources
#define VECTOR_062      default_isr     // 0x0000_00F8 62    46     UART0            Single interrupt vector for UART error sources
#define VECTOR_063      default_isr     // 0x0000_00FC 63    47     UART1            Single interrupt vector for UART status sources
#define VECTOR_064      default_isr     // 0x0000_0100 64    48     UART1            Single interrupt vector for UART error sources
#define VECTOR_065      default_isr     // 0x0000_0104 65    49     UART2            Single interrupt vector for UART status sources
#define VECTOR_066      default_isr     // 0x0000_0108 66    50     UART2            Single interrupt vector for UART error sources
#define VECTOR_067      default_isr     // 0x0000_010C 67    51     UART3            Single interrupt vector for UART status sources
#define VECTOR_068      default_isr     // 0x0000_0110 68    52     UART3            Single interrupt vector for UART error sources
#define VECTOR_069      default_isr     // 0x0000_0114 69    53     UART4            Single interrupt vector for UART status sources
#define VECTOR_070      default_isr     // 0x0000_0118 70    54     UART4            Single interrupt vector for UART error sources
#define VECTOR_071      default_isr     // 0x0000_011C 71    55     UART5            Single interrupt vector for UART status sources
#define VECTOR_072      default_isr     // 0x0000_0120 72    56     UART5            Single interrupt vector for UART error sources

\* =========================================================================== */
void Events_Init(){

  set_irq_priority (87, 1);
  set_irq_priority (88, 1);
  set_irq_priority (89, 1);
  set_irq_priority (90, 1);
  set_irq_priority (91, 1);

  set_irq_priority (68, 2);
  set_irq_priority (69, 2);
  set_irq_priority (70, 2);
  set_irq_priority (71, 2);
  
  set_irq_priority (45, 3);
  set_irq_priority (47, 3);
  set_irq_priority (49, 3);
  set_irq_priority (51, 3);
  set_irq_priority (53, 3);
  set_irq_priority (55, 3);
  
  //TIM_MEASURE_SPEED_Init();
  //TIM_CHECK_CONNECT_Init();
  //TIM_SYS_UPDATE_Init();
}