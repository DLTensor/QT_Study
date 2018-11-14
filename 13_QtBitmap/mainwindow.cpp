#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBitmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap(":/images/images/QQ图片20160726185338 - 副本.jpg"));
    p.drawPixmap(900, 0, QBitmap(":/images/images/QQ图片20160726185338 - 副本.jpg"));
}
