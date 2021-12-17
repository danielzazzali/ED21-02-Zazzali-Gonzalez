#ifndef Identity_HEADER
#define Identity_HEADER
#include <opencv2/opencv.hpp>

using cv::Mat;

class Identity {

private:

	Mat image;
	int identifier;
	int frames;

public:

	Identity();

	Identity(Mat image);

	~Identity();

	Mat getImage();

	int getIdentifier();

	int getFrames();

	void setImage(Mat image);

	void setIdentifier(int identifier);

	void setFrames(int frames);

	void addFrame();

};

#endif
