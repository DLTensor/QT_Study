#include "mylabel.h"
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    text = QString("<center><h1>Please Press Mouse</h1></center>");
    this -> setText(text);
}

// 鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    /* Qt中的sprinf:
     * QString str = QString("abc %1 =w= %2").arg(123).arg("mike")
     * str = "abc 123 =w= mike"
     */
    QString text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    setText(text);
}

// 鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    setText(text);
}

// 鼠标松开
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    setText(text);
}

// 进入窗口区域
void MyLabel::enterEvent(QEvent*)
{
    QString text = QString("<center><h1>Mouse Enter</h1></center>");
    setText(text);
}

void MyLabel::leaveEvent(QEvent*)
{
    QString text = QString("<center><h1>Mouse Leave</h1></center>");
    setText(text);
}
