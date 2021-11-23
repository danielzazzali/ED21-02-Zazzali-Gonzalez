#ifndef Identity_HEADER
#define Identity_HEADER
#include <opencv2/opencv.hpp>

using cv::Mat;

class Identity {

private:

	Mat image;
	int identifier;

public:

	Identity();

	Identity(Mat image);

	~Identity();

	Mat getImage();

	int getidentifier();

	void setImage(Mat image);

	void setidentifier(int identifier);

};

#endif
