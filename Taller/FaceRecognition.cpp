#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "Identity.h"
#include "LinkedList.h"

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
using std::cout;
using std::endl;
using std::stringstream;
using cv::imwrite;
using std::to_string;
using cv::putText;

int main() {


	// ---INITIALIZE COMPONENTS---
	vector<Mat> images(7);
	vector<string> labels(7);
	string filename;
	string name;
	string filenumber;

	LinkedList* list = new LinkedList();

	// Scale for data processing
	double scale = 1.5;

	// Pre-trained machine learning model to detect faces
	CascadeClassifier faceCascade;
	faceCascade.load("C:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml");

	// Open the image

	vector<string> paths(7);
	paths[0] = "Resources/personas1.jpg";
	paths[1] = "Resources/personas2.jpg";
	paths[2] = "Resources/personas3.jpg";
	paths[3] = "Resources/personas4.jpg";
	paths[4] = "Resources/personas5.jpg";
	paths[5] = "Resources/personas6.jpg";
	paths[6] = "Resources/personas7.jpg";

	// ---PROCESS AND SHOW FRAMES---

	for (int i = 0; i < paths.size(); i++) {

		// Matrix to store the image
		Mat frame = imread(paths[i]);

		// Matrix to store the image on gray-scale color
		Mat grayscale;

		//Matrix to store the face cropped
		Mat croppedFace;

		// Convert the color of 'frame' to gray-scale and store it in 'grayscale'
		cvtColor(frame, grayscale, COLOR_BGR2GRAY);
		// Resize the image to make the process more efficient
		resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

		// Vector to store the area of the detected face
		vector<Rect> faces;

		// Detect and store the face in 'faces' as a list of rectangles
		faceCascade.detectMultiScale(grayscale, faces, 1.02, 3);

		for (int r = 0; r < faces.size(); r++) {

			int x = faces[r].x * scale;
			int y = faces[r].y * scale;
			int w = faces[r].width * scale;
			int h = faces[r].height * scale;

			croppedFace = frame(Rect(x, y, w, h));

			images[r] = croppedFace;

			filenumber = to_string(r);
			labels[r] = filenumber;

			stringstream ssfn;
			filename = "Resources\\Faces\\";
			ssfn << filename.c_str() << name << filenumber << ".jpg";
			filename = ssfn.str();
			imwrite(filename, croppedFace);

		}

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

		//Mat face = list->getX(i)->getImage();
		//string label = list->getX(i)->getLabel();

		//imshow("Face", images[i]);


		// Shows the frame in a windows
		imshow("Frame", frame);
		waitKey(1);


	}

	for (int i = 0; i < images.size(); i++) {

		Identity* id = new Identity(images[i], labels[i]);

		list->add(id);

		Mat face = list->getX(i)->getImage();
		string label = list->getX(i)->getLabel();

		putText(face, label, Point(20,20), 1, 1.5, Scalar(0,0,0), 2, 8, false);

		imshow(label, face);
		waitKey(1000);
	}

	return 0;

}