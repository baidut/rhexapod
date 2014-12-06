/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
特别注意：电量低时测速无法进行测速。
inline不能被外部

添加ENC_SendData提供上位机访问数据接口
** -------------------------------------------------------------------------- */

#ifndef _encoder_H_
#define _encoder_H_

#include "sys.h" 

void    ENC_Init(u8 index);
pos_t   ENC_GetPosition(u8 index);
void    ENC_SetPosition(u8 index,pos_t p);
void    ENC_SetMotorReductionRatio(u8 val);

void    ENC_SendData();
#endif