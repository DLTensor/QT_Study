#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerID = this->startTimer(1000); // 毫秒为单位，每隔1000ms(1s)触发一次
    timerID_2 = this->startTimer(100);

    connect(ui->pushButton, &QPushButton::released,
            [=]()
    {
        qDebug() << "233";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    qDebug() << (char)ev->key();

    if(ev->key() == Qt::Key_Escape)
        exit(0);
}

void MainWindow::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == timerID)
    {
        static int sec = 0;
        ui->label->setText(QString("<center><h1>sec = %1</h1><center>")
                           .arg(++ sec));
    }
    else if(ev->timerId() == timerID_2)
    {
        static double sec_2 = 0.10;
        sec_2 += 0.10;
        ui->label_2->setText(QString("<center><h1>sec = %1</h1><center>")
                             .arg(sec_2));
    }
}

// 在窗口关闭的时候，必须使用 accept()和 ignore()函数
void MainWindow::closeEvent(QCloseEvent *ev)
{
    int ret = QMessageBox::question(this, "关闭窗口", "你确定要关闭窗口吗？");
    if(ret == QMessageBox::Yes)
        ev->accept();
    else
        ev->ignore();
}

bool MainWindow::event(QEvent *ev)
{
    if(ev->type() == QEvent::Timer)
    {
        QTimerEvent  *env = static_cast<QTimerEvent *>(ev);
        timerEvent(env);
        return true;    // 返回true，事件停止传播
    }
    else
        return QWidget::event(ev);  // 其余的继续传播
}

