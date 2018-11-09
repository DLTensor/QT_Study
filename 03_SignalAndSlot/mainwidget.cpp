#include "mainwidget.h"
#include "QPushButton"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    /* resize(800, 600)
     * Lambda表达式，匿名函数对象
     * C++11的新特性，项目文件：CONFIG += C++11
     * Qt配合信号使用非常方便
     */

    QPushButton *Button_4 = new QPushButton(this);
    Button_4->setText("Lambda表达式");
    Button_4->move(550, 100);
    int a = 10, b = 100;
    connect(Button_4, &QPushButton::released,
            [=]() mutable
    /* [=]: 把外部变量所有变量、局部变量以值方式传入Lambda函数，加mutable可修改（最安全，最常用）
     * [this]: 把类中所有成员以值传递方式
     * [&]: 把外部所有变量以引用方式传入（可能会使用到无效内存出现Bug）
     */
    {
        Button_4->setText("Lambda");
        qDebug() << "Lambda表达式";
        qDebug() << a << " " << b;
    }
    );
    connect(Button_4, &QPushButton::clicked,
            [=](bool isCheck)   // 括号内是函数的参数，如果使用有参数的信号则需要修改
    {
        qDebug() << isCheck;
    }
    );

    resize(800, 600);

    //QPushButton button_1;写在此处成为局部变量，退出后析构，无法显示
    button_1.setParent(this);
    button_1.setText("关闭");
    button_1.move(100, 100);

    button_2 = new QPushButton(this);
    button_2->setText("按钮2");
    button_2->move(250, 100);

    connect(&button_1, &QPushButton::released, this, &MainWidget::close);
    /* connect函数：信号与槽函数的桥梁
     * QObject::connect(
     *  const QObject *sender,  信号发出者，指针
     *  const char *signal,     处理的信号，发送者的类名::信号名字
     *  const QObject *receiver,    信号接收者
     *  const char *method,     槽函数(信号处理函数)
     *  Qt::ConnectionType type = Qt::AutoConnection)
     */

    /* 自定义槽
     * Qt5支持的自定义槽函数：
     *      1.任意的成员函数
     *      2.普通的全局函数
     *      3.static静态函数
     * 槽函数需要和信号一致（参数相同，没有返回值）
     *
     */
    connect(button_2, &QPushButton::released, this, &MainWidget::mySlot);
    // connect(button_2, &QPushButton::released, button_2, &QPushButton::hide);

    setWindowTitle("主窗口");

    button_3.setParent(this);
    button_3.setText("切换到子窗口");
    button_3.move(400, 100);
    connect(&button_3, &QPushButton::released, this, &MainWidget::changeWindowToSub);

    // 处理子窗口信号
    void (SubWidget::*tmpSingnal_1)() = &SubWidget::changeSignal;
    connect(&sub_w, tmpSingnal_1, this, &MainWidget::changeWindowToMain);

    void (SubWidget::*tmpSingnal_2)(int, QString) = &SubWidget::changeSignal;
    connect(&sub_w, tmpSingnal_2, this, &MainWidget::dealSlot);

}

void MainWidget::mySlot()
{
    button_2->setText("按钮0");
}

void MainWidget::changeWindowToSub()
{
    // 子窗口显示，主窗口隐藏
    sub_w.show();
    hide();
}

void MainWidget::changeWindowToMain()
{
    // 主窗口显示，子窗口隐藏
    sub_w.hide();
    show();
}

void MainWidget::dealSlot(int x, QString s)
{
    // toUft8():     QString -> 字节数组(ByteArray)
    // data():       字节数组(ByteArray) -> char数组
    qDebug() << x << " " << s.toUtf8().data() << endl;
}

MainWidget::~MainWidget()
{

}
