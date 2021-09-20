#include <opencv2\opencv.hpp>
#include <vector>

// Components used
using cv::VideoCapture;
using cv::Mat;
using cv::waitKey;
using cv::CascadeClassifier;
using cv::COLOR_BGR2GRAY;
using cv::Size;
using cv::Rect;
using cv::Scalar;
using cv::Point;
using std::vector;

int main() {
	
	// ---INITIALIZE COMPONENTS---

	// Scale for data processing
	double scale = 1.5;

	// Pre-trained machine learning model to detect faces
	CascadeClassifier faceCascade;
	faceCascade.load("C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");

	// Open the default camera
	VideoCapture cap(0);

	// Check if the camera was opened
	if (!cap.isOpened()) {
		return -1;
	}

	// ---PROCESS AND SHOW FRAMES---

	while (true) {

		// Matrix to store the frame of the camera
		Mat frame;
		// Wait for a new frame from camera and store it in 'frame'
		cap.read(frame);
		// Matrix to store the captured frame on gray-scale color
		Mat grayscale;

		// Convert the color of 'frame' to gray-scale and store it in 'grayscale'
		cvtColor(frame, grayscale, COLOR_BGR2GRAY);
		// Resize the image to make the process more efficient
		resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

		// Vector to store the area of the detected face
		vector<Rect> faces;

		// Detect and store the face in 'faces' as a list of rectangles
		faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(50, 50));

		// For every rectangle in tha face region
		for (Rect area : faces) {

			// Set the color to use (red)
			Scalar drawColor = Scalar(0, 0, 255);

			// Draws a rectangle around the area detected as a face
			rectangle(frame,
				Point(cvRound(area.x * scale), cvRound(area.y * scale)),
				Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)),
				drawColor, 2);

		}

		// Shows the frame in a windows
		imshow("Frame", frame);

		// Breaks the cycle if a key is pressed (exit)
		if (waitKey(30) >= 0) {
			break;
		}

	}

	return 0;

}