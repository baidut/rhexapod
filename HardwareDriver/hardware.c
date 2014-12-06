/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
@example 

** -------------------------------------------------------------------------- */

#include "hardware.h"

#include "events.h"

void Hardware_Init(){
int i;
  MOTOR_POWER_Init();
  LIGHT_Init();
  LEDs_Init();
  //Clock_Init();
  BHT_Init();

  for(i=0;i<6;i++){
    ENC_Init(i);
    MOTOR_Init(i);
  }
  
  // DOG_Init();
  
  Events_Init();
}

#include "remoteControl.h"


void Hardware_Test() {
cmd_e cmd;
int index;
s32 value;

Hardware_Init();
RemoteCtrl_Init();// 初始化要配对。配对应当只进行一次。

// 需要确保位置更新模块时关闭的，所以需要
// PosCtrl_Dis(); 为了防止 系统开始只进行远程控制模块的初始化，其他初始化由各个部分完成。

    for(;;){ 
    
    cmd=RemoteCtrl_GetCommand();

    if(cmd==CMD_NONE)continue;
    commonCmdProcess(cmd);

    switch(cmd ){
     // COMMON_CASES 
    case CMD_SET_MOTOR_FORCE:
      RemoteCtrl_Scanf("%d,%d",&index,&value);
      //index = index-'0';
     // force[index] = value;
      MOTOR_SetForce(index,value);
      // 摆动 8-18
      break;
    case CMD_SET_ENC_POS:
      RemoteCtrl_Scanf("%d,%d",&index,&value);
      //index = index-'0';
      ENC_SetPosition(index,value); // 校准匹配转盘。
      break; 
    case CMD_RETURN:
      return;// return 之前关闭电机。 /**/
    default :break;
    }
  }
}