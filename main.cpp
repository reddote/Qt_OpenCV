#include "Qt_OpenCV.h"
#include <opencv.hpp>
#include <core/mat.hpp>
#include <opencv_modules.hpp>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_OpenCV w;
    w.show();

	// Path to the image file
	std::string imagePath = "C:\\Users\\3DDL\\Desktop\\QT_Test\\Reseources\\custom.png"; // Replace with the path to your image file

	// Read the image file
	cv::Mat image = cv::imread(imagePath);

	// Check for failure
	if (image.empty()) {
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get(); // Wait for any key press
		return -1;
	}

	// Create a window
	cv::namedWindow("Window", cv::WINDOW_NORMAL); // Create a window with the name "Window"

	// Show the image inside the created window
	cv::imshow("Window", image); // Show our image inside the created window

	// Wait for any keystroke in the window
	cv::waitKey(0); // Wait for any keystroke in the window

    return a.exec();
	
}
