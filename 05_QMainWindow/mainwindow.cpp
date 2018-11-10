#include "mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenuBar> // 菜单栏
#include <QMenu>    // 菜单
#include <QToolBar> // 工具栏
#include <QPushButton>
#include <QStatusBar>   // 状态栏
#include <QLabel>   // 标签框
#include <QTextEdit>    // 文本编辑框
#include <QDockWidget>  // 浮动窗口

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);

    // 菜单栏
    QMenuBar *mBar = menuBar();
    // 添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    // 添加菜单项，添加动作
    QAction *pNewFile = pFile->addAction("新建");
    QAction *pOpenFile = pFile->addAction("打开");
    QAction *pSaveFile = pFile->addAction("保存");
    pFile->addSeparator();
    QAction *pClose = pFile->addAction("关闭");
    connect(pNewFile, &QAction::triggered,
            [=]()   mutable
    {
        qDebug() << "新建";
    });

    // 工具栏 菜单项的快捷方式
    QToolBar *toolBar = addToolBar("toolBar");
    //工具栏添加快捷键
    toolBar->addAction(pNewFile);
    QPushButton *b = new QPushButton(this);
    b->setText("^w^");
    toolBar->addWidget(b);
    connect(b, &QPushButton::released,
            [=]()   mutable
    {
        b->setText("T^T");
    });

    // 状态栏
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);
    sBar->addWidget(new QLabel("addWidget从左往右添加", this));
    sBar->addPermanentWidget(new QLabel("addPermanentWidget从右往左添加", this));

    // 核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    // 给浮动窗口添加控件
    QTextEdit *dock_text = new QTextEdit(this);
    dock->setWidget(dock_text);

}

MainWindow::~MainWindow()
{

}
