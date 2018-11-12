/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mybutton.h>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    MyLabel *label;
    MyLabel *label_2;
    MyButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 351);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new MyLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        label_2 = new MyLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 0, 127);\n"
"background-color: rgb(255, 255, 127);"));

        verticalLayout->addWidget(label_2);

        pushButton = new MyButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "MyButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
