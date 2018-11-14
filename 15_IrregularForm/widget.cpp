#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1024, 768);

    // 去除窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    // 窗口背景设置为透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("../15_IrregularForm/ball1.png"));
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        move(ev->globalPos() - p);
    }
}

void Widget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::RightButton)
        close();
    else if(ev->buttons() == Qt::LeftButton)
    {
        p = ev->globalPos() - this->frameGeometry().topLeft();
    }
}
