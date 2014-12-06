/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
--------------------------------------------------------------------------------
>> DONT MODIFY IT <<
** -------------------------------------------------------------------------- */

#ifndef _dog_H_
#define _dog_H_

#include "sys.h" 

void DOG_Init();// active the dog
void DOG_Feed();
void DOG_SetBark( void (*f)());
void DOG_En();
void DOG_Dis();

#ifdef TEST
void DOG_Test();
#endif

#endif