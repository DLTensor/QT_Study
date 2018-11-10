#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QDialog>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("弹出...");
    QAction *p1 = menu->addAction("模态对话框");
    QAction *p2 = menu->addAction("非模态对话框");
    QAction *p3 = menu->addAction("问题对话框");
    QAction *p4 = menu->addAction("文件对话框");
    QAction *p5 = menu->addAction("关于对话框");

    connect(p1, &QAction::triggered,
            [=]() mutable
    {
        QDialog dlg_exec;
        dlg_exec.resize(300, 200);
        dlg_exec.exec();
    });

    connect(p2, &QAction::triggered,
            [=]() mutable
    {
        dlg_show.resize(300, 200);
        dlg_show.show();
        dlg_show.exec();
    });

    connect(p3, &QAction::triggered,
            [=]() mutable
    {
        int ret = QMessageBox::question(this, "保存文件", "你确定要保存文件吗？");
        if (ret == QMessageBox::Yes)
        {
            QMessageBox::information(this, "保存文件", "保存成功！");
        }
        else
            QMessageBox::warning(this, "保存文件", "未能保存文件！");
    });

    connect(p4, &QAction::triggered,
            [=]() mutable
    {
        QString path = QFileDialog::getOpenFileName(this, "打开", "../",
                                                    "JPEG图像(*.jpg *.jpeg);;PNG图像(*.png);;位图(*.bmp);;所有(*.*)");
        QMessageBox::information(this, "路径", path);
    });

    connect(p5, &QAction::triggered,
            [=]() mutable
    {
        QMessageBox::about(this, "关于", "仅供学习使用");
    });
}

MainWindow::~MainWindow()
{

}
