/*
 * File:         hexapod.c
 * Date:         September 22th, 2005
 * Description:  Alternate tripod gait using linear servos
 * Author:       Yvan Bourquin
 * Modifications:Simon Blanchoud - September 12th, 2006
 *               Indentation of the code so that it follows the Webots Coding
 *               Standards
 *
 * Copyright (c) 2006 Cyberbotics - www.cyberbotics.com
 */

#include <webots/robot.h>
#include <webots/servo.h>
#include <stdio.h>

//The time step used by controller "simpleRhex" is not a multiple of WorldInfo.basicTimeStep!
#define TIME_STEP 860//160// 太短开不出来。。。。来不及调整
#define NUM_SERVOS 6
#define NUM_STATES 4

// 初始位置不准造成不稳定，放慢了可以看出来 不是一前一后

// 注意规定初始位置

//#define M_PI   3.14

int main() {
  const char *SERVO_NAMES[NUM_SERVOS] = {
        "servo_r0",
        "servo_r1",
        "servo_r2",
        "servo_l0",
        "servo_l1",
        "servo_l2"};
  WbDeviceTag servos[NUM_SERVOS];
  int elapsed = 0;
  int state, i;
  long double pos = 0,lastPos = 0; // int 害死了  0-6.28
  int flag = 0;
  const int dir[] = {1,1,1,1,1,1};//{1,1,1,-1,-1,-1}
  // 增加在地面上的时间，就会更加稳定
  const double rate = 1.0/6;// 1/4
  
  wb_robot_init();

  for (i = 0; i < NUM_SERVOS; i++) {
    servos[i] = wb_robot_get_device(SERVO_NAMES[i]);
    if (!servos[i]) {
      printf("could not find servo: %s\n",SERVO_NAMES[i]);
    }
  }
  
  pos = M_PI * rate ;
  flag = 0;

  while(wb_robot_step(TIME_STEP)!=-1) {
    elapsed++;
    state = (elapsed / 25 + 1) % NUM_STATES;
	
    lastPos = pos;
    
    
    
    
    if(flag) pos += 2*M_PI * rate;
    else pos += 2*M_PI * (1-rate);
    flag = !flag;
	
    for (i = 0; i < 6; i+=2 ){
      wb_servo_set_position(servos[i], dir[i]*pos);
    }
    for (i = 1; i < 6; i+=2 ) {
      wb_servo_set_position(servos[i], dir[i]*lastPos); 
    }
  }
  
  wb_robot_cleanup();

  return 0;
}