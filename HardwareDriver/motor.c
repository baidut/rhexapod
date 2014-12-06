/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
2014-9-5 08:43:55 添加MOTOR_Freeze() // 采用比例调节，不会有副作用直接调用即可。
缺陷需要定时调用，只调用一次没有效果。
模块化编程，系统每次调用一次。
** ---------------------------------------------------------------------------*/

#include "motor.h"
#include "rhexio.h"
#include "mcu.h"

typedef struct {
    const IO    SET_DIR;
    const PWM   SET_PWM;
} BTS7971;

#define _BTS_Struct(NAME)       {NAME##_DIR,_IO_TO_PWM(NAME##_PWM)}
BTS7971 BTS[LEN]={
  _BTS_Struct(BTS1),
  _BTS_Struct(BTS2),
  _BTS_Struct(BTS3),
  _BTS_Struct(BTS4),
  _BTS_Struct(BTS5),
  _BTS_Struct(BTS6)
};

void MOTOR_Init(u8 index){
BTS7971* me = BTS + index;
    
    _GPO_Init(me->SET_DIR,MOTOR_DIR_NORMAL);
    _PWM_Init(me->SET_PWM,MOTOR_FREQ,0/*80*/);
}

volatile  s16 motorForce[6];

s16 motorMaxForce = MOTOR_RATIO_MAX;


#define Motor_SetDir(me,dir)    	_GPIO_Put(me->SET_DIR,dir) // 加一层
#define Motor_SetRatio(me,ratio)   	_PWM_SetDuty(me->SET_PWM,ratio)

void MOTOR_SetForce(u8 index,s16 f){
u8 dir;
u16 ratio; // u16 设置成有符号的？
BTS7971* me;

me = BTS + index;

ASSERT(index<6);
//ASSERT( f>=-RATIO_FULL || f<=RATIO_FULL );

  motorForce[index]=f; //记录数据

  //限幅 这里没有限幅，pid输出限幅
  if(f>motorMaxForce)   f=motorMaxForce;
  if(f<-motorMaxForce)  f=-motorMaxForce;
/**/
    if(f>=0) {
        dir=MOTOR_DIR_NORMAL;
        ratio=f;
    }
    else{
        dir=MOTOR_DIR_REVERSE;
        ratio=RATIO_FULL+f; // force -200   ratio 800  // -900 100 
    }
    Motor_SetDir(me,dir);//_GPIO_Put(me->SET_DIR,dir); 
   /* switch(index){
    case 0: FTM_PWM_Duty(FTM2, CH1, ratio); break;
    case 1: FTM_PWM_Duty(FTM1, CH0,ratio); break;
    case 2: FTM_PWM_Duty(FTM2, CH0,ratio); break;
    case 3:FTM_PWM_Duty(FTM1, CH1,ratio); break;
    case 4:FTM_PWM_Duty(FTM0, CH3,ratio); break;
    case 5:FTM_PWM_Duty(FTM0, CH5,ratio); break;
    default: break;
    }*/
    Motor_SetRatio(me,ratio);//_PWM_SetDuty(me->SET_PWM,ratio);
}
s16 MOTOR_GetForce(u8 index){
  return motorForce[index];
}

void MOTOR_SetMaxForce(s16 force){
  motorMaxForce = force;
}


#include "bluetooth.h"
void    MOTOR_SendData(){
int i=0;
BHT_SendChar(ACK_DATA_MOTOR_FORCE);
BHT_SendChar(',');
for(i=0;i<6;i++){
  BHT_Printf("%d,",motorForce[i]);
}
BHT_SendChar('#');
}

/** -------------------------------------------------------------------------- *
// 改名 为了和前进后退区分 正转normal ，反转reverse
enum{
    MOTOR_FORWARD=0,
    MOTOR_BACK=!MOTOR_FORWARD
};
一处bug
//ratio = MIN(ratio,motorMaxForce);
// ratio = MAX(ratio,RATIO_FULL- motorMinForce);
        if(ratio>motorMaxForce) ratio=motorMaxForce;
        if(ratio<RATIO_FULL-motorMaxForce) ratio=motorMaxForce;
if(f>=0) {
        dir=MOTOR_FORWARD;
        ratio=f;
        Limiter(ratio,MOTOR_RATIO_MIN,MOTOR_RATIO_MAX);
        me->force=ratio;
    }
    else{
        dir=MOTOR_BACK;
        ratio=1000+f; // force -200   ratio 800
        Limiter(ratio,1000-MOTOR_RATIO_MAX,1000-MOTOR_RATIO_MIN);
        me->force=ratio-1000; // 1000-ratio;
    }

// 先换向，再变力量，可以抵消一定前进的速度。
** ---------------------------------------------------------------------------*/
