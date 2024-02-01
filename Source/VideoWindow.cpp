#include "..\Header\VideoWindow.h"

VideoWindow::VideoWindow(QWidget * parent) :
	QGraphicsView(parent), scene(new QGraphicsScene(this))
{
	UpdatePictureUI();
}

void VideoWindow::UpdatePictureUI() {
	// Path to the video file
	std::string videoPath = "C:\\Users\\3DDL\\Desktop\\Qt_OpenCV\\1.mp4";

	// Create a VideoCapture object to read from the video file
	cv::VideoCapture videoCap(videoPath);

	// Check if the file can be opened
	if (!videoCap.isOpened()) {
		std::cerr << "Error: Could not open video file." << std::endl;
	}

	cv::Mat frame;

	// Read a new frame from the video
	bool isSuccess = videoCap.read(frame);

	// Check if the frame has been successfully read
	if (!isSuccess) {
		std::cerr << "Error: Could not read frame from video file." << std::endl;
	}

	image = MatToQImage(frame);

	scene->addPixmap(QPixmap::fromImage(image));
	this->setScene(scene);
	this->setFixedSize(421, 381);
	this->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

	/*// Create a window
	cv::namedWindow("Window", cv::WINDOW_NORMAL); // Create a window with the name "Window"

	// Show the image inside the created window
	cv::imshow("Window", frame); // Show the captured frame inside the created window

	// Wait for any keystroke in the window
	cv::waitKey(0); // Wait for any keystroke in the window*/
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
	if (event->button() == Qt::LeftButton) {
		startPanning(event->pos());
	}
	QGraphicsView::mousePressEvent(event);
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
