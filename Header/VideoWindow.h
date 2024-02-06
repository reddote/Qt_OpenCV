#pragma once
#include <QWidget>
#include <opencv.hpp>
#include <QApplication>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QPointF>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


class VideoWindow : public QGraphicsView
{
	Q_OBJECT

public:
	VideoWindow(QString path, QWidget *parent = nullptr);
	~VideoWindow();

	QImage image;

protected:
	void wheelEvent(QWheelEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;

private:
	QTimer *timer;
	cv::VideoCapture *videoCap;
	QGraphicsScene *scene;
	QGraphicsPixmapItem *item;
	QString pathVideo;

	bool _dragging;
	QPointF _lastDragPoint;
	QPoint _lastPanPoint;
	void startPanning(const QPoint &pos);
	void doPanning(const QPoint &pos);
	void stopPanning();

	void ThreadStarter();


	QImage MatToQImage(const cv::Mat& mat);

signals:
	void workFinished();

public slots:
	void UpdatePictureUI();


};
