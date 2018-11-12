#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        // 接收事件
        qDebug() << "按下左键";
        ev->accept();
    }
    else
    {
        /* ignore() 不常用(一般没有传递给父组件的需求)
         * 忽略，事件传递给“父组件”(不是父类)
         * MyButton的父组件是MainWindow
         * 会执行MainWindow的mouseReleaseEvent函数
         */
        ev->ignore();
        /* QPushButton::mouseReleaseEvent(ev) 常用
         * 忽略，事件传递给“父组件”(不是父类)
         * QPushButton
         * 会执行QPushButton的mouseReleaseEvent函数
         * 不调用则父类的相应事件也不会调用，会导致潜在风险！
         */
        QPushButton::mouseReleaseEvent(ev);
    }
}
