#include <opencv2/opencv.hpp>
#include "include/Identity.h"

using cv::Mat;

Identity::Identity() {

	this->identifier = 0;
	this->image = NULL;
	this->frames = 0;

}

Identity::Identity(Mat image) {

	this->image = image;
	this->frames = 1;

}

Identity::~Identity() {

}

Mat Identity::getImage() {

	return image;

}

int Identity::getIdentifier() {

	return identifier;

}

int Identity::getFrames()
{
	return frames;
}

void Identity::setImage(Mat image) {

	this->image = image;

}

void Identity::setIdentifier(int identifier) {

	this->identifier = identifier;

}

void Identity::setFrames(int frames) {

	this->frames = frames;

}

void Identity::addFrame() {

	this->frames++;

}
