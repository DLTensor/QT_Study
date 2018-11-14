#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPen>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pixmap(400, 300); // 创建绘图设备 400*300
    QImage image(400, 300, QImage::Format_ARGB32);  // 创建QImage绘图设备，背景是透明
    QPicture picture;   // picture是一个二进制文件
    pixmap.fill(QColor(255, 0, 255)); // 填充颜色
    QPainter p(&pixmap), p2(&image), p3(&picture);
    p.drawLine(200, 150, 200, 250);
    p2.drawLine(200, 100, 200, 250);
    p3.drawLine(200, 150, 200, 250);

    for(int i = 0; i <= 50; i ++)
        image.setPixel(QPoint(i, i), qRgb(60, 120, 255)); // QImage可以对图片进行操作

    // 保存图片
    pixmap.save("../14_QtPixmap/pixmap.png");
    image.save("../14_QtPixmap/image.png");
    picture.save("../14_QtPixmap/picture.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
#if 0
    QPicture pic;
    pic.load("../14_QtPixmap/picture.png");

    QPainter p(this);
    p.drawPicture(0, 0, pic);
#endif
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("../14_QtPixmap/pixmap.png");

    QImage tempImage = pixmap.toImage();
    p.drawImage(0, 0, tempImage);
}
