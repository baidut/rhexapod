/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
2014-5-28 22:34:15 Fixed errors.
2014-6-2 19:04:04 
接口访问放到头文件中，为了提升效率，但又宏替换的风险和暴露变量的风险
改为内联函数
发布，编写文档，不允许再进行修改
** ---------------------------------------------------------------------------*/

#include "encoder.h"
#include "rhexio.h"
#include "mcu.h"

/* -------------------------------------------------------------------------- */
typedef struct {
	const IO CLK;
	const IO DO;
        
	const IO CS;
	const IO INDEX;
	const IO GET_DIR;
} AS5040;

/* -------------------------------------------------------------------------- */

#define _AS_Struct(NAME) \
{NAME##_CLK,NAME##_DO,NAME##_CS,NAME##_INDEX,NAME##_GET_DIR}

AS5040 AS[LEN]={
  _AS_Struct(AS1),
  _AS_Struct(AS2),
  _AS_Struct(AS3),
  _AS_Struct(AS4),
  _AS_Struct(AS5),
  _AS_Struct(AS6)
};

#define AS_INDEX_EXTI_CFG		rising_down
#define AS_GET_DIR_EXTI_CFG		either_down

void ENC_Init(u8 index) {
AS5040* as = AS + index;
    
    _GPO_Init(as->CS,0);//EN
    _GPO_Init(as->CLK,0);
    _GPO_Init(as->DO,0);

    _GPIO_Clr(as->CS);

    _EXTI_Init(as->INDEX  , AS_INDEX_EXTI_CFG);
    _EXTI_Init(as->GET_DIR, AS_GET_DIR_EXTI_CFG);
}
/* -------------------------------------------------------------------------- */

u8 dir[6];
u8 cnt[6];
u8 pos[6];

/* -------------------------------------------------------------------------- */

#define _DEF_AS_123_GET_DIR_IRQHandler(n) \
void AS##n##_GET_DIR_IRQHandler(){        \
  dir[n-1]=!_GPIO_Get(AS##n##_GET_DIR);     \
}  
#define _DEF_AS_456_GET_DIR_IRQHandler(n) \
void AS##n##_GET_DIR_IRQHandler(){        \
  dir[n-1]=_GPIO_Get(AS##n##_GET_DIR);      \
}
_DEF_AS_123_GET_DIR_IRQHandler(1)
_DEF_AS_123_GET_DIR_IRQHandler(2)
_DEF_AS_123_GET_DIR_IRQHandler(3)
_DEF_AS_456_GET_DIR_IRQHandler(4)
_DEF_AS_456_GET_DIR_IRQHandler(5)
_DEF_AS_456_GET_DIR_IRQHandler(6)

/* -------------------------------------------------------------------------- */

u8 MOTOR_REDUCTION_RATIO = 56;//30;可能不是56还需要修改，所以改为可修改的
// 修改了测量位置， 原来是if(!dir[n-1])
#define _DEF_ASn_INDEX_IRQHandler(n)            \
void AS##n##_INDEX_IRQHandler(){                \
    if(dir[n-1]){ 								\
    cnt[n-1]++; pos[n-1]++;                     \
    if(pos[n-1]==MOTOR_REDUCTION_RATIO){        \
		pos[n-1]=0;}                            \
    }                                           \
  else{ cnt[n-1]--;                             \
    if(pos[n-1])pos[n-1]--;                     \
    else{pos[n-1]=MOTOR_REDUCTION_RATIO-1;}     \
  }                                             \
}
_DEF_ASn_INDEX_IRQHandler(1)
_DEF_ASn_INDEX_IRQHandler(2)
_DEF_ASn_INDEX_IRQHandler(3)
_DEF_ASn_INDEX_IRQHandler(4)
_DEF_ASn_INDEX_IRQHandler(5)
_DEF_ASn_INDEX_IRQHandler(6)


/* -------------------------------------------------------------------------- */
// 访问数据接口

pos_t   ENC_GetPosition(u8 index){
  ASSERT(index<6);
  return pos[index];
}

void    ENC_SetPosition(u8 index,pos_t p){
  ASSERT(index<6);
  pos[index] = p;
}

void    ENC_SetMotorReductionRatio(u8 val) {
  MOTOR_REDUCTION_RATIO = val;
}

#include "bluetooth.h"
void    ENC_SendData(){
  BHT_Printf("%c,%d,%d,%d,%d,%d,%d,%c",ACK_DATA_ENC_POS,pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],'#');
}

