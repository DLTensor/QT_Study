#include "coordinatewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoordinateWidget w;
    w.show();

    return a.exec();
}
