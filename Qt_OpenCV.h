#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_OpenCV.h"
#include "Header/VideoWindow.h"
#include <qgraphicsview.h>

class Qt_OpenCV : public QMainWindow
{
    Q_OBJECT

public:
    Qt_OpenCV(QWidget *parent = nullptr);
	void InitVideoWindows();
	~Qt_OpenCV();

private:
	VideoWindow *videoWindow;
<<<<<<< HEAD
	VideoWindow *videoWindow_2;
=======
	VideoWindow *videoWindow2;
>>>>>>> feature/playableScene
	QGraphicsView *graphicsView;
	void VideoStarter();

    Ui::Qt_OpenCVClass ui;
};
