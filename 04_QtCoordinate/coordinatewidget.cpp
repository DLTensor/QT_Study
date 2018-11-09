#include "coordinatewidget.h"

CoordinateWidget::CoordinateWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 300);
    /* 主窗口的父窗口是屏幕
     * 原点为左上角
     * x向右递增 y向下递增
     */
    move(760, 390);
    QPushButton *button_1 = new QPushButton(this);
    button_1->resize(100, 30);
    button_1->move(150, 135);
    button_1->setText("Button_1");

    QPushButton *button_2 = new QPushButton(button_1);
    button_1->resize(100, 30);
    button_2->move(50, 15);
    button_2->setText("Button_2");
}

CoordinateWidget::~CoordinateWidget()
{

}
