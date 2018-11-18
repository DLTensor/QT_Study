#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QVariantList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    // 添加QMYSQL数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 连接数据库
    db.setHostName("127.0.0.1");    // 设置数据库服务器为本地主机
    db.setUserName("root"); // 设置数据库用户名
    db.setPassword("baibubaibu888I");
    db.setDatabaseName("shop");
    if(!db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return ;
    }

    QSqlQuery query;
    // query.exec("insert into good(id, name) values(20180001, '芒果干')");

    // 批量插入
    // 预处理语句
    // ?相当于占位符
    query.prepare("insert into good(id, name) values(?, ?)");
    // 设置内容list
    // 给字段绑定相应的值 按顺序绑定
    QVariantList idList,  nameList;
    idList << "20180002" << "20180003" << "20180004";
    nameList << "草莓干" << "黄桃干" << "菠萝干";
    query.addBindValue(idList);
    query.addBindValue(nameList);
    // 执行预处理命令
}

Widget::~Widget()
{
    delete ui;
}
