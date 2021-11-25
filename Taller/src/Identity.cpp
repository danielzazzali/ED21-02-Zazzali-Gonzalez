#include <opencv2/opencv.hpp>
#include <string>
#include "../include/Identity.h"

using cv::Mat;
using std::string;

Identity::Identity() {

	this->label = "";
	this->image = NULL;
	
}

Identity::Identity(Mat image, string label) {

	this->label = label;
	this->image = image;

}

Identity::~Identity() {

}

Mat Identity::getImage() {

	return image;

}

string Identity::getLabel() {

	return label;

}

void Identity::setImage(Mat image) {

	this->image = image;

}

void Identity::setLabel(string label) {

	this->label = label;

}