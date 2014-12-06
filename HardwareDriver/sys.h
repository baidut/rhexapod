
/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
--------------------------------------------------------------------------------

** -------------------------------------------------------------------------- */

#ifndef _sys_H_
#define _sys_H_

#include "mcu.h"
#include "util.h"
#include "types.h"
#include <stdio.h>

#define TEST

#define MIN(x,y)    ((x)<(y)?(x):(y))
#define MAX(x,y)    ((x)>(y)?(x):(y))

typedef enum{
	LEG_NONE,
	LeftFore,
	LeftMid,
	LeftHind,
	RightFore,
	RightMid,
	RightHind,
	LEN
}Leg_e;
#define LEG_NUM	RightHind


#define ACK_END_MARK       	'#'

#define ACK_BEGIN(type)		_DEBUG_OUT("%c",ACK_##type)
#define ACK_END				_DEBUG_OUT("%c",ACK_END_MARK)

#define USE_RHEX_DEBUGGER
#define DEBUG_WATCH
#define DEBUG_CHECKPOINT 
#define USE_DEBUG
#include "debug.h"

//u8 Tripod1[]={LeftFore,RightMid,LeftHind};
//u8 Tripod2[]={RightFore,LeftMid,RightHind};

#endif