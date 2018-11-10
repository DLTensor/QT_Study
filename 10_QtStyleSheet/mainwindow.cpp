#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("QLabel{"
                             "color: rgb(0, 255, 255);"
                             "background-color: rgb(0,0,255)"
                             "}");
    ui->pushButton->setStyleSheet("QPushButton{"
                                    "background-color: rgb(0, 0, 0);"
                                    "color: rgb(255, 255, 255);"
                                    "border-radius: 10px;"
                                    "border: 2px groove gray;"
                                    "border-style: outset;}"

                                  "QPushButton:hover{"
                                    "background-color: rgb(255, 255, 255);"
                                    "color: rgb(0,0,0);}"

                                  "QPushButton:pressed{"
                                    "background-color:rgb(0, 255, 255);"
                                    "border-style:inset;"
                                  "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
