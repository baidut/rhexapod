#ifndef RHEX_H
#define RHEX_H

#include <QMainWindow>

#include <QtCore>//QTimer

#include <QMessageBox> // 消息框
#include <qstring.h> // 字符串
#include <QtCore>

//#include <QFile>
//#include <QInputDialog>
//#include <QFileDialog>
//#include <QTextStream>

#include "../../debugger.h" // 自定义的命令枚举
#include "qextserial/qextserialport.h"


#define DFLT_TIME_OUT        10
#define PASSWORD            "hellorhex"

#define FEED_DOG_INTERVAL       200
#define READ_DATA_INTERVAL      500


//#define ABS(x)  ((x>0)?(x):(-x))
inline int ABS(int x){
    return ((x>0)?(x):(-x));
}

//延时，TIME_OUT是串口读写的延时
#define TIME_OUT 10


// -----------------------------------------------------------------------------
#define _SEND_CMD(cmd,FORMAT,...)                                                \
do{                                                                             \
    char cmdParams[PARAMS_MAX_LEN];                                             \
    sprintf(cmdParams,FORMAT,##__VA_ARGS__);                                    \
    sendCmd(cmd,cmdParams);                                                     \
}while(0)
// -----------------------------------------------------------------------------
#define _DEF_on_checkBox_switch_clicked(uiName,cmd)                             \
void  on_checkBox_##uiName##_clicked(bool checked)                              \
{                                                                               \
    if(checked){                                                                \
        sendCmd(cmd,"e");                                                       \
    }                                                                           \
    else{                                                                       \
        sendCmd(cmd,"d");                                                       \
    }                                                                           \
}
// -----------------------------------------------------------------------------
#define _DEF_on_checkBox_LED_clicked(x)                                         \
void on_checkBox_P##x##_clicked(bool checked)                                   \
{                                                                               \
    if(checked){                                                                \
        _SEND_CMD(CMD_SWITCH_LED,"%c%c", x+'0'-1,'e');                          \
    }                                                                           \
    else{                                                                       \
        _SEND_CMD(CMD_SWITCH_LED,"%c%c", x+'0'-1,'d');                          \
    }                                                                           \
}


#define sendCmdStr(cmd,format,...)  \
do{                                                                             \
    char cmdParams[PARAMS_MAX_LEN];                                             \
    sprintf(cmdParams,format,##__VA_ARGS__);                                    \
    sendCmd(cmd,cmdParams);                                                     \
}while(0)


namespace Ui {
class rhex;
}

class rhex : public QMainWindow
{
    Q_OBJECT

public:
    explicit rhex(QWidget *parent = 0);
    ~rhex();

    void    init();
    ack_e   getAck();
    QString getMsg();
    ack_e   waitAck();

    void sendStr(char* str);
    QextSerialPort *com;

private:
    Ui::rhex *ui;

    class test_action *w_testAction;
    class test_pid *w_testPid;
    QTimer* timer_readData;

    bool isSending;

    QString msgBuffer;
    struct{
        ack_e type;
        QString content;
    }ackString;

    inline void ui_showStatus(QString str);
    inline void ui_alert(QString str);
    inline void ui_showMsg(QString str);

    void ui_showMotorData(QVector<int> data);
    void ui_showEncoderData(QVector<int> data);
public slots:
    void sendCmd(cmd_e cmd,const char* msgStr="0");// public

private slots:
    void readData();
    void readCom();


    _DEF_on_checkBox_switch_clicked(light,CMD_SWITCH_LIGHT)
    _DEF_on_checkBox_switch_clicked(power,CMD_SWITCH_MOTOR_POWER)
    //_DEF_on_checkBox_switch_clicked(dog,CMD_SWITCH_DOG)
    _DEF_on_checkBox_LED_clicked(1)
    _DEF_on_checkBox_LED_clicked(2)
    _DEF_on_checkBox_LED_clicked(3)
    _DEF_on_checkBox_LED_clicked(4)
    void on_pushButton_reconnect_clicked();
    void on_checkBox_stopReadData_clicked(bool checked){
        checked?timer_readData->start(READ_DATA_INTERVAL)
               :timer_readData->stop();
    }
    void on_pushButton_resetSys_clicked(){sendCmd(CMD_RESET_SYS);}
    //void on_pushButton_powerOff_clicked(){sendCmd(CMD_SWITCH_MOTOR_POWER,"d");}
    void on_spinBox_reductionRatio_valueChanged(int arg1){sendCmdStr(CMD_SET_REDUCTION_RATIO,"%d",arg1);}
    void on_pushButton_safeShutDown_clicked(){sendCmd(CMD_SAFE_SHUTDOWN);}

    void on_pushButton_clearBrowser_clicked();
    void on_lineEdit_setPosAll_returnPressed();
    void on_spinBox_OL_SetSmallForce_valueChanged(int arg1){
        sendCmdStr(CMD_OL_CFG,"%d,%d,%d,%d",arg1,0,0,0);}
    void on_spinBox_OL_setBigForce_valueChanged(int arg1){
        sendCmdStr(CMD_OL_CFG,"%d,%d,%d,%d",0,arg1,0,0);}
    void on_spinBox_OL_setSmallTarget_valueChanged(int arg1){
        sendCmdStr(CMD_OL_CFG,"%d,%d,%d,%d",0,0,arg1,0);}
    void on_spinBox_OL_setBigTarget_valueChanged(int arg1){
        sendCmdStr(CMD_OL_CFG,"%d,%d,%d,%d",0,0,0,arg1);}
    void on_pushButton_OL_step_clicked(){sendCmd(CMD_OL_STEP);}
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButton_switchPort_clicked(bool checked);
//假设下位机接收正常，下位机反馈收到的字符，测试下位机发送是否正常
    void on_pushButton_testCom_clicked(){sendCmd(CMD_TEST_COM);}
    void on_pushButton_forward_clicked(){sendCmd(CMD_FORWARD);}
    void on_pushButton_backward_clicked(){sendCmd(CMD_BACKWARD);}
    void on_pushButton_left_clicked(){sendCmd(CMD_LEFT);}
    void on_pushButton_right_clicked(){sendCmd(CMD_RIGHT);}
    void on_pushButton_walk_clicked(){sendCmd(CMD_WALK);}
    void on_pushButton_stand_clicked(){sendCmd(CMD_STAND);}
    void on_checkBox_switchPid_clicked(bool checked);
};
#endif // RHEX_H
