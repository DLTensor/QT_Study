#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "QPushButton"
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
private:
    QPushButton     button_1;
    QPushButton*    button_2;
    QPushButton     button_3;

    SubWidget sub_w;
    void mySlot();
    void changeWindowToSub();
    void changeWindowToMain();
    void dealSlot(int, QString);
};

#endif // MAINWIDGET_H
