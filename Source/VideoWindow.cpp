#include "..\Header\VideoWindow.h"
#include <QThread>

VideoWindow::VideoWindow(QString path, QWidget * parent) :
	QGraphicsView(parent), scene(new QGraphicsScene(this))
{
	pathVideo = path;
	ThreadStarter();
}

void VideoWindow::ThreadStarter() {
	QThread* thread = new QThread();

	this->moveToThread(thread);

	connect(thread, &QThread::started, this, &VideoWindow::UpdatePictureUI);
	connect(this, &VideoWindow::workFinished, thread, &QThread::quit);
	
	thread->start();

}

void VideoWindow::UpdatePictureUI() {

	// Path to the video file
	//std::string videoPath = "C:\\Users\\3DDL\\Desktop\\Qt_OpenCV\\1.mp4";
	std::string path = pathVideo.toStdString();
	// Create a VideoCapture object to read from the video file
	cv::VideoCapture videoCap(path);

	// Check if the file can be opened
	if (!videoCap.isOpened()) {
		std::cerr << "Error: Could not open video file." << std::endl;
	}

	cv::Mat frame;

	// Read a new frame from the video
	while (videoCap.read(frame)) {
		image = MatToQImage(frame);

		scene->clear();
		scene->addPixmap(QPixmap::fromImage(image));
		this->setScene(scene);
		this->setFixedSize(421, 381);
		this->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

		// Artificial delay to simulate processing time and control the frame rate
		cv::waitKey(1);
	}

	emit workFinished();
}

QImage VideoWindow::MatToQImage(const cv::Mat& mat) {
	switch (mat.type()) {
	case CV_8UC4: {
		QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image;
	}
	case CV_8UC3: {
		QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	case CV_8UC1: {
		QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
		return image;
	}
	default:
		qWarning("Unsupported Mat format in MatToQImage");
		return QImage();
	}
}

//Mouse Controller Start
void VideoWindow::wheelEvent(QWheelEvent *event) {
	// Zoom Factor
	double scaleFactor = 1.15;
	if (event->angleDelta().y() > 0) {
		// Zoom in
		scale(scaleFactor, scaleFactor);
	}
	else {
		// Zooming out
		scale(1.0 / scaleFactor, 1.0 / scaleFactor);
	}
}

void VideoWindow::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		startPanning(event->pos());
	}else if(event->button() == Qt::LeftButton) {
		QPointF scenePos = mapToScene(event->pos());

		// Create a pen with desired color (blue) and increased width for boldness
		QPen pen(Qt::blue);
		pen.setWidth(5); // Increase the width of the pen to make the ellipse bolder

		QGraphicsEllipseItem* ellipse = scene->addEllipse(scenePos.x() - 10, scenePos.y() - 10, 20, 20, pen, QBrush(Qt::transparent));
		ellipse->setFlag(QGraphicsItem::ItemIsMovable);
	}

	QGraphicsView::mousePressEvent(event); // Call base class implementation
}

void VideoWindow::mouseMoveEvent(QMouseEvent *event) {
	if (_lastPanPoint != QPoint()) {
		doPanning(event->pos());
	}
	QGraphicsView::mouseMoveEvent(event);
}

void VideoWindow::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		stopPanning();
	}
	QGraphicsView::mouseReleaseEvent(event);
}

void VideoWindow::startPanning(const QPoint &pos) {
	_lastPanPoint = pos;
	setCursor(Qt::ClosedHandCursor);
}

void VideoWindow::doPanning(const QPoint &pos) {
	QPoint delta = pos - _lastPanPoint;
	_lastPanPoint = pos;
	horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
	verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
}

void VideoWindow::stopPanning() {
	_lastPanPoint = QPoint();
	setCursor(Qt::ArrowCursor);
}
//Mouse Controller End


VideoWindow::~VideoWindow()
{
}
