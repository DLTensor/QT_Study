#include "smallwidget.h"
#include <QSpinBox> // 数字框
#include <QSlider>  // 滑条
#include <QHBoxLayout>  // 布局管理器

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spinbox = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);

    // 将控件添加至布局中
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(spinbox);
    layout->addWidget(slider);

    spinbox->setValue(50);
    spinbox->setMaximum(100);
    spinbox->setMinimum(1);
    slider->setMaximum(100);
    slider->setMinimum(1);
    slider->setValue(50);

    // static_cast <void (QSpinBox::*)(int)> 强制类型转换
    connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider, &QSlider::setValue);

    connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
}
