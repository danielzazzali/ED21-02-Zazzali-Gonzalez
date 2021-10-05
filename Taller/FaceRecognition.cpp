#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

// Components used
using cv::Mat;
using cv::waitKey;
using cv::CascadeClassifier;
using cv::COLOR_BGR2GRAY;
using cv::Size;
using cv::Rect;
using cv::Scalar;
using cv::Point;
using cv::imread;
using std::vector;
using std::string;

int main() {
	
	// ---INITIALIZE COMPONENTS---

	// Scale for data processing
	double scale = 1.5;

	// Pre-trained machine learning model to detect faces
	CascadeClassifier faceCascade;
	faceCascade.load("C:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml");

	// Open the image
	string path = "Resources/personas.jpg";
	

	// ---PROCESS AND SHOW FRAMES---



	// Matrix to store the image
	Mat frame = imread(path);
	
	// Matrix to store the image on gray-scale color
	Mat grayscale;

	// Convert the color of 'frame' to gray-scale and store it in 'grayscale'
	cvtColor(frame, grayscale, COLOR_BGR2GRAY);
	// Resize the image to make the process more efficient
	resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

	// Vector to store the area of the detected face
	vector<Rect> faces;

	// Detect and store the face in 'faces' as a list of rectangles
	faceCascade.detectMultiScale(grayscale, faces, 1.02, 3);

	// For every rectangle in the face region
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
	waitKey(0);

	return 0;

}