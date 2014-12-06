/** -------------------------------------------------------------------------- *
@author YingZhenqiang yingzhenqiang@163.com
--------------------------------------------------------------------------------
2014-9-10
+ serial settings
2014-9-10 Ying Zhenqiang  <yingzhenqiang@163.com>
    - 检查连接定时器
    - 上位机添加检查数据是否匹配，读取数据功能
** -------------------------------------------------------------------------- */

#include "rhex.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    rhex w;
    w.show();

    return a.exec();
}
