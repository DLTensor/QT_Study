#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    point_x = point_y = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter p;
    p.begin(this);  // 制定当前窗口为绘图设备
    // 绘制背景图
    // p.drawPixmap(rect(), QPixmap(":/images/image/background.jpg"));

    QPen pen;   // 定义画笔
    pen.setWidth(5);    // 设置画笔粗细
    p.drawEllipse(point_x, point_y, 80, 80);

    pen.setColor(QColor(255, 120, 15));  // 设置画笔颜色
    pen.setStyle(Qt::DotLine);  // 设置风格
    QBrush brush;   // 定义画刷(填充色)
    brush.setColor(QColor(200, 0, 200));    // 定义画刷颜色
    brush.setStyle(Qt::Dense3Pattern);  // 定义填色样式
    p.setBrush(brush);  // 把画刷交给画家
    p.setPen(pen);  // 把画笔交给画家



    // 绘制直线 矩形 圆形
    // p.drawLine(50, 50, 600, 50);
    // p.drawRect(100, 100, 100, 50);
    // p.drawEllipse(300, 300, 100, 200);

    p.end();
}

void Widget::on_pushButton_released()
{
    if(point_x > width() || point_y > height())
        point_x = point_y = 0;
    point_x += 20;
    point_y += 20;
    update();
}
