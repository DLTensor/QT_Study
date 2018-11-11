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
    QString text;
    if(ev->button() == Qt::RightButton || ev->button() == Qt::MidButton)
        text = "<center><h1>Please Use LeftButton</h1></center>";
    else
    {
        int x = ev->x(), y = ev->y();
        /* Qt中的sprinf:
         * QString str = QString("abc %1 =w= %2").arg(123).arg("mike")
         * str = "abc 123 =w= mike"
         */
        text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>").arg(x).arg(y);
    }
    setText(text);
}

// 鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
}

// 鼠标松开
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

}
