#ifndef IMAGE_CODING_HEADER
#define IMAGE_CODING_HEADER

#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

class ImageCoding {

public:

    explicit ImageCoding();

    vector<Mat> codeGray(vector<Rect> detections, bool equalize, Size size);

    void setImage(Mat frame);

private:

    Mat frame;

};

#endif

