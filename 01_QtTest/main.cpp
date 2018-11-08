#include "mywidget.h"

// QApplication应用程序类
// 头文件以Q为开头，前两个字母大写，没有.h
#include <QApplication>

int main(int argc, char *argv[])
{
    // 有且只有一个应用程序类的对象
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    a.exec();

    return 0;
    // 等价于：
    // a.exec();    等待接收消息
    // return 0;    退出程序
}
