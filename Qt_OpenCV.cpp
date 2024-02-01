#include "Qt_OpenCV.h"
#include <QtWidgets/QApplication>

Qt_OpenCV::Qt_OpenCV(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	videoWindow = new VideoWindow(ui.graphicsView);
}

Qt_OpenCV::~Qt_OpenCV()
{}
