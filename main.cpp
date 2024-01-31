#include "Qt_OpenCV.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_OpenCV w;
    w.show();
    return a.exec();
}
