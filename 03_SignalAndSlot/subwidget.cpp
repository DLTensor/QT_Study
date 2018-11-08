#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    resize(QSize(800, 600));

    setWindowTitle("子窗口");
    button_change.setParent(this);
    button_change.setText("切换回主窗口");
    button_change.move(250, 100);

    connect(&button_change, &QPushButton::released, this, &SubWidget::sendSlot);
}

void SubWidget::sendSlot()
{
    emit changeSignal();
}
