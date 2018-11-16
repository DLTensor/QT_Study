#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 连接数据库
}

Widget::~Widget()
{
    delete ui;
}
