#include "../include/ImageCoding.h"
#include <sstream>
#include <vector>
#include <string>

using namespace std;

ImageCoding::ImageCoding() {

}

vector<Mat> ImageCoding::codeGray(vector<Rect> detections, bool equalize, Size size) {

    Mat cropColor;
    Mat imageGray;
    Mat resizedDown;

    vector<Mat> cropFaces;

    for (const auto& det : detections) {

        // Recorto la imagen detectada
        cropColor = frame(det);

        //Usamos solo imágenes en grises
        cvtColor(cropColor, imageGray, COLOR_BGR2GRAY);

        // Si se desea ecualizar la imagen (aumentar contraste)
        if (equalize) {
            equalizeHist(imageGray, imageGray);
        }

        equalizeHist(imageGray, imageGray);
        // Reescalamos

        resize(imageGray, resizedDown, size, INTER_LINEAR);

        cropFaces.push_back(resizedDown.clone());
    }

    return cropFaces;
}

void ImageCoding::setImage(Mat frame) {
    this->frame = frame;
}

