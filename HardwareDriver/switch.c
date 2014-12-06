/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
@example 
继电器控制
  Switch_Init(MOTOR_POWER);
  Switch_On(LIGHT);
LED控制
  LED_On(P1); 或LED_On(1);

2014-6-10 18:37:40 添加checkpoint 模块使能失能初始化需要反馈信息
** -------------------------------------------------------------------------- */

#include "rhexio.h"
#include "mcu.h"
#include "switch.h"


#define MOTOR_POWER_LEVEL_EN	0
#define LIGHT_LEVEL_EN		    0

#define Switch_Init(name)      	_GPO_Init(name##_IO,!name##_LEVEL_EN)
#define Switch_On(name)      	_GPIO_Put(name##_IO,name##_LEVEL_EN)
#define Switch_Off(name)      	_GPIO_Put(name##_IO,!name##_LEVEL_EN) 	
#define Switch_Neg(name)      	_GPIO_Turn(name##_IO)


int isPowerOn(){
  return ( _GPIO_Get(MOTOR_POWER_IO)== MOTOR_POWER_LEVEL_EN ) ;
}

#define _DEF_SWITCH(name)   \
void name##_Init(){         \
  CHECKPOINT();             \
  Switch_Init(name);        \
}                           \
void name##_Dis(){          \
  CHECKPOINT();             \
  Switch_Off(name);         \
}                           \
void name##_En(){           \
  CHECKPOINT();             \
  Switch_On(name);          \
}
_DEF_SWITCH(MOTOR_POWER)
_DEF_SWITCH(LIGHT)

/* -------------------------------------------------------------------------- */

IO LEDs[]={
 P1_IO,
 P2_IO,
 P3_IO,
 P4_IO
};

#define LED_LEVEL_EN			0//1

void LED_Init(u8 index){  
  _GPO_Init(LEDs[index],!LED_LEVEL_EN);
}
void LEDs_Init(){
  CHECKPOINT();
  
  LED_Init(P1);
  LED_Init(P2);
  LED_Init(P3);
  LED_Init(P4);
}
void LED_On(u8 index){
  CHECKPOINT();
  
  _GPIO_Put(LEDs[index],LED_LEVEL_EN);
}
void LED_Off(u8 index){
  CHECKPOINT();
  
  _GPIO_Put(LEDs[index],!LED_LEVEL_EN);
}
