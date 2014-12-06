/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
2014-6-6 14:57:32 模块测试完毕
可用 高优化没问题


配置蓝牙中断，把接收到的先存储到buff中，每次从buf里读出
保持remoteCtrl接口不变化
因为远程控制可采用多种方案，如果蓝牙距离受限的话就需要改变方案。
暂时不影响就不管了
注意不能和remoteCtrl统一，前面方案变化是第一个原因，而且这里涉及底层，中断
、mcu的访问，应当向上层屏蔽这些

根据ACK响应类型调整

9600的波特率的信道，理论上每秒可以传输9600/8个英文字母的数据量，也就是1200个字节，大约1.2KB。
每ms传输1.2个字节，发送间隔为0.83ms，也就是要求单片机在这个间隔下取走上一个数
这样就不会覆盖，
野火默认频率为200M 见MCG模块
在 200M主频下，就是 1.25*200 DMIPS ……每秒 1.25*200 * 1000 000 条整形运行指令
即250 * 1000/ms

采用中断方式能确保命令不丢失。


调试：
硬件检查，
蓝牙模块问题 中间位置
电脑发送时电脑端和rhex端都是蓝灯亮，
rhex发送时都是黄灯亮
注意要直接给蓝牙5v供电，否则不会配对。

前端-是否切换到蓝牙发送指令？

进入中断
中断取一个字符，发送一串时中断有丢失现象，如果中断先做一些事情，比如printf
然后再取字符，可能后面的字符已经被覆盖了
** ---------------------------------------------------------------------------*/

#include "bluetooth.h"

void (*func)();

void BHT_IRQHandler(){
#ifdef TEST
  //BHT_Printf("Enter BHT_IRQHandler\n");
#endif
  ASSERT(func!=NULL);
  
  (*func)();
}
void BHT_SetIrqHandler( void (*f)() ){
  //BHT_EnIrq();
  func = f;
}



bool isBhtTestDone = false;
int recvNum= 0;
void sayHello(){
  //BHT_Printf("Hello!\n");
char ch=BHT_GetChar();//BHT_Clear();
   /* BHT_SendStr("Catch a char:");
    BHT_SendChar(ch);
    BHT_SendChar('\n');*/
    if(ch=='#')isBhtTestDone = true;
    
    // 回传速度比较慢，会影响接收，接收会被覆盖，而且最后一个接收的不会被检测到
    // 存入数组而不发送回来，放置一个变量测试，每收到一个加1
    // 采用中断方式，没有问题。发送100个未出现丢失问题
    recvNum ++;
}

void BHT_Test(){
char ch;
  BHT_Init();
  BHT_DisIrq();
  CHECKPOINT();
  BHT_Printf("Receive this message indicates the send module is ok.\n");
  BHT_Printf("Please send a string end of # to test the receive module.\n"); 
  do{
      ch=BHT_GetChar();
      BHT_Printf("%c",ch);
  }while('#'!=ch);
  BHT_Printf("\nThe above print what you send if the receive module is ok.\n");
  /*BHT_Printf("Test uart irq  \n");
  BHT_SetIrqHandler(sayHello);
  BHT_EnIrq();
  while(!isBhtTestDone);*/
}

