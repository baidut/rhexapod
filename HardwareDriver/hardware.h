/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
@example 

** -------------------------------------------------------------------------- */

#ifndef _hardware_H_
#define _hardware_H_

#include "bluetooth.h"
#include "encoder.h"
#include "motor.h"
#include "switch.h"

#include "clock.h"
#include "dog.h"

void Hardware_Init();

/** -------------------------------------------------------------------------- *
@brief 检查电机是否转动正常，编码器是否读数正常，校准编码器读数
** -------------------------------------------------------------------------- */
void Hardware_Test();

#endif