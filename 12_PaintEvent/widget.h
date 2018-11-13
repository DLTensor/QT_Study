#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    /* 绘图事件是虚函数
     * 如果在窗口内绘图，必须在绘图事件中实现
     * 绘图事件会在内部自动调用（窗口状态改变时会再调用）
     */
    void paintEvent(QPaintEvent *);
};

#endif // WIDGET_H
