#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

signals:
    /*
     * 信号必须由signals关键字声明
     * 信号没有返回值，但可以有参数
     * 信号就是函数的声明，只需声明，无需定义
     * 使用：emit mySignal();
     */
    void changeSignal();

public slots:

private:
    QPushButton     button_change;
    void sendSlot();
};

#endif // SUBWIDGET_H
