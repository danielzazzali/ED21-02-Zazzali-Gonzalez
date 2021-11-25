#ifndef FACEDETECTOR_HEADER
#define FACEDETECTOR_HEADER

#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class FaceDetector {

public:

    explicit FaceDetector();

    vector<Rect> detectFaceRectangles(const Mat& frame);

private:

    CascadeClassifier face_cascade;

    const int imageWidth;

    const int imageHeight;

    const double scaleFactor;

    const int minNeighbors;

};

#endif


