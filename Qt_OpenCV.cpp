#include "Qt_OpenCV.h"
#include <QtWidgets/QApplication>

Qt_OpenCV::Qt_OpenCV(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	VideoStarter();
	
}
void Qt_OpenCV::VideoStarter()
{
	QString path_1 = "C:\\Users\\3DDL\\Desktop\\Qt_OpenCV\\1.mp4";
	//QString path_2 = "C:\\Users\\3DDL\\Desktop\\Qt_OpenCV\\2.mp4";

	videoWindow = new VideoWindow(path_1, ui.graphicsView);
	//videoWindow_2 = new VideoWindow(path_2, ui.graphicsView_2);

<<<<<<< HEAD
=======
	InitVideoWindows();
	
}

void Qt_OpenCV::InitVideoWindows() {
	QString path_1 = "C:\\Users\\3DDL\\Desktop\\Qt_OpenCV\\1.mp4";
	QString path_2 = "C:\\Users\\3DDL\\Desktop\\Qt_OpenCV\\2.mp4";

	videoWindow = new VideoWindow(path_1, ui.graphicsView);
	videoWindow2 = new VideoWindow(path_2, ui.graphicsView_2);
>>>>>>> feature/playableScene
}

Qt_OpenCV::~Qt_OpenCV()
{}


