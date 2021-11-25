#include "../include/FaceDetector.h"

using namespace std;
using namespace cv;

FaceDetector::FaceDetector() : scaleFactor(1.05), minNeighbors(1), imageWidth(60), imageHeight(60) {
    face_cascade.load("classifiers/haarcascade_frontalface_alt.xml");
}

vector<Rect> FaceDetector::detectFaceRectangles(const Mat& frame) {

    vector<Rect> faces;
    Mat imageGray;

    // Detecto las caras (Se debe pasar la imagen a escala de grises
    cvtColor(frame, imageGray, COLOR_BGR2GRAY);

    // Aumento el constraste de una imagen
    equalizeHist(imageGray, imageGray);

    face_cascade.detectMultiScale(imageGray,
                                   faces,
                                   scaleFactor,
                                   minNeighbors,
                                   0 | CASCADE_SCALE_IMAGE,
                                   Size(imageWidth, imageHeight));


    return faces;
}