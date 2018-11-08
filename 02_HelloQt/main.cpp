#include <QApplication>
#include <QWidget>  //窗口控件基类
#include <QPushButton>  //按钮类

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    // 设置标题
    w.setWindowTitle("Hello Qt!");

    QPushButton button(&w);

    // 给按钮设置内容
    button.setText("OK");

    /*
     *  按钮显示 必须指定父对象
     *  指定父对象的方式：
     *      1. setParent
     *      2. 通过构造函数传参
     *  只需要父对象显示，子对象就会自动显示
    */
    button.move(400, 300);

    w.show();
    app.exec();
    return 0;
}
