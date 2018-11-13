#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    resize(640, 360);

    QPainter p;
    p.begin(this);  // 制定当前窗口为绘图设备
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/images/image/background.jpg"));
    p.end();
}
