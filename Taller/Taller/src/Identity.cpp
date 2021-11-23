#include <opencv2/opencv.hpp>
#include "include/Identity.h"

using cv::Mat;

Identity::Identity() {

	this->identifier = 0;
	this->image = NULL;

}

Identity::Identity(Mat image) {

	
	this->image = image;

}

Identity::~Identity() {

}

Mat Identity::getImage() {

	return image;

}

int Identity::getidentifier() {

	return identifier;

}

void Identity::setImage(Mat image) {

	this->image = image;

}

void Identity::setidentifier(int identifier) {

	this->identifier = identifier;

}