#ifndef Identity_HEADER
#define Identity_HEADER
#include <opencv2/opencv.hpp>
#include <string>

using cv::Mat;
using std::string;

class Identity {

private:

	Mat image;
	string label;

public:

	Identity();

	Identity(Mat image, string label);

	~Identity();

	Mat getImage();

	string getLabel();

	void setImage(Mat image);

	void setLabel(string label);

};

#endif