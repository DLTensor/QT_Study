#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>


class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *ev);  // 鼠标按下
    void mouseMoveEvent(QMouseEvent *ev);   // 鼠标拖动
    void mouseReleaseEvent(QMouseEvent *ev);    // 鼠标松开
    QString text;

signals:

public slots:
};

#endif // MYLABEL_H
