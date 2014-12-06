/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------

** -------------------------------------------------------------------------- */

#ifndef _motor_H_
#define _motor_H_

#include "sys.h"

enum{
    MOTOR_DIR_NORMAL=0,
    MOTOR_DIR_REVERSE=1//!MOTOR_DIR_NORMAL
};

#define RATIO_FULL          1000
#define MOTOR_FREQ          1000
#define MOTOR_RATIO_MAX     1000// 300//爆时为300 800 //120 //

void MOTOR_Init(u8 index);
void MOTOR_SetForce(u8 index,s16 force);// 【-1000~+1000】
s16 MOTOR_GetForce(u8 index);

void MOTOR_SetMaxForce(s16 force);// 【-1000~+1000】
void    MOTOR_SendData();

#endif
