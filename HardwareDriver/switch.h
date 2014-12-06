/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
@brief 控制开关
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
命名说明：
En是模块使能，On是打开
电机电源模块使能是通过打开控制电机的继电器开关
LED模块是直接打开和关闭的，而不是通过开关继电器间接使能的（LIGHT）
不建议为了调用效率而用类函数宏定义实现，如果一定要效率的话就用内联函数实现
** -------------------------------------------------------------------------- */

#ifndef _switch_H_
#define _switch_H_

#include "sys.h"

enum{
  P1,
  P2,
  P3,
  P4
};

extern IO LEDs[];

void MOTOR_POWER_Init();
void MOTOR_POWER_En();
void MOTOR_POWER_Dis();


int isPowerOn();

void LIGHT_Init();
void LIGHT_En();
void LIGHT_Dis();

void LEDs_Init();
void LED_Init(u8 index);
void LED_On(u8 index);
void LED_Off(u8 index);



#include "LED.H"

#define LED_WaterLamp()             water_lights()


#endif

/** -------------------------------------------------------------------------- *
#define Switch_Init(name)      	_GPO_Init(name##_IO,!name##_LEVEL_EN)
#define Switch_On(name)      	_GPIO_Put(name##_IO,name##_LEVEL_EN)
#define Switch_Off(name)      	_GPIO_Put(name##_IO,!name##_LEVEL_EN) 	
#define Switch_Neg(name)      	_GPIO_Turn(name##_IO)

#define LED_LEVEL_OFF			1
#define LED_Init(x)				_GPO_Init(LEDs[x],!LED_LEVEL_EN)
#define LED_On(x)				_GPIO_Put(LEDs[x],LED_LEVEL_EN)
#define LED_Off(x)				_GPIO_Put(LEDs[x],!LED_LEVEL_EN)
#define LEDs_Init()             LED_Init(P1);LED_Init(P2);LED_Init(P3);LED_Init(P4)
** -------------------------------------------------------------------------- */

