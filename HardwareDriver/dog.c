
/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
2014-6-6 16:57:06 调试通过，现象: 如果连续发送则不会叫，否则一旦停止发送则叫。每隔一秒喂狗一次。
原本的急停需要在串口中断中读取检测，现在只需要停止发送空命令就会在一秒内停止。虽然响应没有直接停止
快，但检查关闭命令比较麻烦。


使用硬件看门狗很方便，但软件看门狗也未尝不可。
软件看门狗可以让六足完成当前步态稳定下来后，等待连接。等待超时再坐下并自动关闭电机。
不至于直接复位。（直接复位会丢失修改的参数？参数记录可以让上位机完成）

看门狗是一种计数器。当计数的值溢出时会自动复位MCU。（需要在溢出前“喂狗”，避免复位）
看门狗机制可以避免程序跑死（跑死时自动复位）
复位后各个模块重新初始化，重置参数，电机关闭，之后如果编写了自动站立程序的话，就会站立，
等待连接密钥确定，等待超时后，就会坐下，关闭电机。
** -------------------------------------------------------------------------- */

#include "dog.h"
#include "rhexio.h"
#include "mcu.h"

volatile bool isOK;
void (*bark)();

// 默认的bark 不能死在里面，需要测试 如果没有喂狗，就一直叫
void DOG_Bark(){
   CHECKPOINT(); 
}

void DOG_Init(){
  CHECKPOINT();
  if(bark==NULL)bark = DOG_Bark;// 防止分支测试界面dog重新初始化为bark。。。
  _TIMER_Init(TIM_DOG,PERIOD_DOG);
  DOG_Dis();
}
void DOG_En(){
  CHECKPOINT();
  _TIMER_EnIrq(TIM_DOG);
}
void DOG_Dis(){
  CHECKPOINT();
  _TIMER_DisIrq(TIM_DOG);
}
  
void TIM_DOG_OnInt(){
  ASSERT(bark!=NULL);
  //CHECKPOINT();
  if(!isOK){
     (*bark) ();
  }
  isOK = false;
}

void DOG_Feed(){
  isOK = true;
}

void DOG_SetBark( void (*f)() ){
  CHECKPOINT();
  bark = f;
}


#ifdef TEST

#include "RemoteControl.h"

void DOG_Test(){
cmd_e cmd;
  RemoteCtrl_Init();
  DOG_Init();
  DOG_En();
  while(1){
    cmd=(cmd_e)RemoteCtrl_GetCommand();
    if(cmd==CMD_NONE)continue;
     switch(cmd ){
    case CMD_NEXT:
      return;
    case '1':
      DOG_Feed();
      break;
    case CMD_VOID:
      DOG_Feed();
      break;
     default: break;
   }
  }
}
#endif