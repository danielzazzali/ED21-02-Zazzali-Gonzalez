#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "../include/LinkedList.h"
#include "../include/FaceDetector.h"
#include "../include/ImageCoding.h"
#include "BinaryTree.cpp"

// Components used
using cv::Mat;
using cv::waitKey;
using cv::Size;
using cv::Rect;
using cv::Scalar;
using cv::Point;
using cv::imread;
using cv::imshow;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {


	// ---INITIALIZE COMPONENTS---
	vector<Mat> images(7);

	LinkedList* list = new LinkedList();

	Identity* id = new Identity();

	NodeBinaryTree* node = new NodeBinaryTree(id);



	FaceDetector fdetector;

	ImageCoding icoding;

	// paths to the images
	vector<string> paths(6);
	paths[0] = "Resources/personas1.jpg";
	paths[1] = "Resources/personas2.jpg";
	paths[2] = "Resources/personas3.jpg";
	paths[3] = "Resources/personas4.jpg";
	paths[4] = "Resources/personas5.jpg";
	paths[5] = "Resources/personas6.jpg";

	// ---PROCESS AND SHOW FRAMES---

	string label = "cara";

	for (int i = 0; i < paths.size(); i++) {

		Mat image = imread(paths[i]);

		vector<Rect> facesMarkers = fdetector.detectFaceRectangles(image);
		
		Scalar color(0, 0, 255);

		Mat cropColor;
		Mat imageGray;
		Mat resizedDown;

		icoding.setImage(image);

		vector<Mat> faceCodingGray = icoding.codeGray(facesMarkers, true, Size(60, 60));
		
		for (const Rect faceMark : facesMarkers) {
			rectangle(image, faceMark, color, 2);
		}

		imshow("Frame", image);
		waitKey(1);
		

		label = "cara";

	}

	destroyAllWindows();

	return 0;

}