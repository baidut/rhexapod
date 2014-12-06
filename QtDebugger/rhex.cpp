/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@gmail.com
@version v3.1
>> DONT MODIFY IT <<
--------------------------------------------------------------------------------
@brief
** -------------------------------------------------------------------------- */

#include "rhex.h"
#include "ui_rhex.h"

#include <QProgressDialog>
#include <QProgressBar>



#define DFLT_PORT_NAME       "COM5"
#define DFLT_BAUD_RATE       "9600"
#define DFLT_PARITY_TYPE     "无"
#define DFLT_DATA_BITS_TYPE  "8"

#define blockForSeconds(x)  do{\
                              QElapsedTimer t;\
                              t.start();\
                              while(t.elapsed()<x)\
                                QCoreApplication::processEvents();\
                            }while(0)

rhex::rhex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rhex)
{
    ui->setupUi(this);
// 串口设置 ----------------------------------------------------------
    QStringList PORT_NAME_LIST;
    #ifdef Q_OS_LINUX
       PORT_NAME_LIST << "ttyUSB0" << "ttyUSB1" << "ttyUSB2" << "ttyUSB3"
                      << "ttyS0" << "ttyS1" << "ttyS2" << "ttyS3" << "ttyS4" << "ttyS5" << "ttyS6";
    #elif defined (Q_OS_WIN)
       for(int i=0; i<16;i++){
            PORT_NAME_LIST << "COM"+QString::number(i);
       }
    #endif
       ui->comboBox_portName->addItems(PORT_NAME_LIST);
       // 默认设置
       ui->comboBox_portName->setCurrentText(DFLT_PORT_NAME);
       ui->comboBox_baudRate->setCurrentText(DFLT_BAUD_RATE);
       ui->comboBox_dataBits->setCurrentText(DFLT_DATA_BITS_TYPE);
       ui->comboBox_parity->setCurrentText(DFLT_PARITY_TYPE);

  //this->move(0,80);
  init();
}

void rhex::on_pushButton_switchPort_clicked(bool checked) {
    if(checked){
      Q_ASSERT (com!=NULL);
      com->close();
      delete com;
      ui->pushButton_switchPort->setText("打开串口");
    }
    else {
      QString portName = ui->comboBox_portName->currentText();
#ifdef Q_OS_LINUX
      com = new QextSerialPort("/dev/" + portName);
#elif defined (Q_OS_WIN)
      com = new QextSerialPort(portName);
#endif
      com->setBaudRate((BaudRateType)ui->comboBox_baudRate->currentText().toInt());
      com->setDataBits((DataBitsType)ui->comboBox_dataBits->currentText().toInt());
      ParityType parCfgList[] = {PAR_NONE,PAR_ODD,PAR_EVEN};
      com->setParity(parCfgList[ui->comboBox_parity->currentIndex()]);
      StopBitsType stopBitCfgList[] = {STOP_1,STOP_1_5,STOP_2};
      com->setStopBits(stopBitCfgList[ui->comboBox_stopBits->currentIndex()]);
      com->setFlowControl(FLOW_OFF);
      com->setTimeout(TIME_OUT);
      connect(com, SIGNAL(readyRead()), this, SLOT(readCom()));

      if(com->open(QIODevice::ReadWrite)){
        ui->pushButton_switchPort->setText("关闭串口");
      }else{
        QMessageBox::critical(this, tr("打开失败"), tr("未能打开串口") +portName+ tr("\n该串口设备不存在或已被占用"), QMessageBox::Ok);
        ui->pushButton_switchPort->setChecked(true);
      }
    }
}

rhex::~rhex()
{
    delete ui;
}
void rhex::on_tabWidget_tabBarClicked(int index){
    if(index == 3){

    }
}
void rhex::ui_showStatus(QString str){
    ui->statusBar->showMessage(str);
}
void rhex::ui_alert(QString str){
    QMessageBox::information(this, "warning", str, QMessageBox::Ok);
}
void rhex::ui_showMsg(QString str){
    ui->textBrowser->insertPlainText(str);//ui->textBrowser->append(str);//
    ui->textBrowser->moveCursor(QTextCursor::End);
}
void rhex::init(){ 


  /*
   * 根据接收到的信号进行status进度更新，安装槽即可。
  ui_showStatus("Link to rhex...");
  if(waitAck()!=ACK_LOST){
    ui_alert("Acknowledgment match failed.");
    return;
  }
  sendCmd(CMD_SYS_START,PASSWORD);
  switch(waitAck()){
    case ACK_MATCHED:break;
    case ACK_WRONG_PSW:ui_alert("Password match failed.");return;
    case ACK_WRONG_CMD:ui_alert("Command match failed.");return;
    default :break;
  }*/

  ui_showStatus("init successed.");

  timer_readData = new QTimer(this);
  connect(timer_readData, SIGNAL(timeout()), this, SLOT(readData()));
  // 初始化不允许使能模块timer_readData->start(READ_DATA_INTERVAL);

  ui_showStatus("timer .");
}

void rhex::readData(){
    if(!isSending)sendCmd(CMD_READ_DATA);
}
/*void rhex::disconnect(){
  com->close();
  com = NULL;
}*/
/*
void rhex::feedDog(){
  SEND_CMD(CMD_VOID);
}
void rhex::on_checkBox_switchDog_clicked(bool checked)
{
    if(checked){
        SEND_CMD_STR(CMD_SWITCH_DOG,"%c",'e');// 注意发送str 与scanf不同
    }
    else{
        SEND_CMD_STR(CMD_SWITCH_DOG,"%c",'d');
    }
}
void rhex::on_pushButton_switchFeed_clicked(bool checked)
{
    if(checked)
        timer_feedDog->start(FEED_DOG_INTERVAL);
    else
        timer_feedDog->stop();
}*/
void rhex::readCom(){
  QStringList list;
  QVector<int> data;
  msgBuffer += com->readAll();
  // 取开始符号和结束符号之间的存入数组中，如果一次没有接收完毕，则继续接收。先查找结束符
  // 采用弱连接，如果没有及时处理信息就会被后面的信息覆盖
  if(-1!=msgBuffer.indexOf("#")){
    char data_id=msgBuffer.at(0).toLatin1();
    switch(data_id) {
    // 读取到的位置信息
      case ACK_DATA_ENC_POS:
        list = msgBuffer.split(",");
        list.pop_front();
        foreach(QString str,list)data<<str.toInt();
        ui_showEncoderData(data);
         break;
      case ACK_DATA_MOTOR_FORCE:
        list = msgBuffer.split(",");
        list.pop_front();
        foreach(QString str,list)data<<str.toInt();
        ui_showMotorData(data);
         break;
      case ACK_MSG:
        msgBuffer=msgBuffer.remove('#');
        ui_showMsg(msgBuffer.toUtf8());
        break;
      default:
        ui_showMsg(msgBuffer.toUtf8());
        break;
    }
    //ui_showMsg(msgBuffer);
    msgBuffer = "";
  }
}

void rhex::ui_showEncoderData(QVector<int> data){
QList<QLCDNumber*> list;
list.append( ui->lcdNumber_pos_1 );
list.append( ui->lcdNumber_pos_2 );
list.append( ui->lcdNumber_pos_3 );
list.append( ui->lcdNumber_pos_4 );
list.append( ui->lcdNumber_pos_5 );
list.append( ui->lcdNumber_pos_6 );
int i = 0;
foreach(QLCDNumber* l,list)
    l->display(data[i++]);
}
void rhex::ui_showMotorData(QVector<int> data){
QList<QProgressBar*> list;
    list << ui->progressBar_force_1
         << ui->progressBar_force_2
         << ui->progressBar_force_3
         << ui->progressBar_force_4
         << ui->progressBar_force_5
         << ui->progressBar_force_6;
    int i = 0;
    foreach(QProgressBar* p,list){
        p -> setValue(ABS(data[i])/10);
        p ->setInvertedAppearance((bool)(data[i]<0));
        i++;
    }
}
void rhex::on_pushButton_clearBrowser_clicked(){
   ui->textBrowser->clear();
}
ack_e rhex::getAck(){
  // if(empty)
    return ACK_NONE;
  // else return ackString.type;
}
QString rhex::getMsg(){
  return ackString.content;
}
ack_e rhex::waitAck(){
ack_e ack;
  do{
    ack = getAck();
  }while(ack != ACK_NONE);
  return ack;
}
void rhex::sendStr(char* str){
  if(com!=NULL){ //ui->pushButton_portswitch->isChecked()
    com->write(str);
    blockForSeconds(10);
  }
  else{
    ui_showMsg(str);
  }
}
void rhex::sendCmd(cmd_e cmd,const char* msgStr){
  char s[60]="";// 小心溢出 定义最大长度 或采用QString 推荐后者

  isSending = true;//用户的命令不会出现冲突的情况，但是定时发送的命令需要避免冲突
  s[0]=CMD_BEGIN;
  s[1]=cmd;
  // s[2]='\0';
  strcat(s,msgStr);
  s[strlen(s)]=CMD_END;
  sendStr(s);//com->write(ch);
  isSending = false;
}
void rhex::on_pushButton_reconnect_clicked()
{
    sendCmd(CMD_RECONNECT);
}
void rhex::on_lineEdit_setPosAll_returnPressed(){
    int value = ui->lineEdit_setPosAll->text().toInt();
    int max = ui->spinBox_reductionRatio->text().toInt();
    if(value>=0&&value<=max)
        sendCmdStr(CMD_SET_POS_ALL,"%d",value);
}

void rhex::on_checkBox_switchPid_clicked(bool checked)
{
    if(checked){
        _SEND_CMD(CMD_SWITCH_PID,"%c",'e');
    }
    else{
        _SEND_CMD(CMD_SWITCH_PID,"%c",'d');
    }
}

