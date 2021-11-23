#ifndef IMAGE_CODING_HPP
#define IMAGE_CODING_HPP

#include "opencv2/opencv.hpp"
using namespace cv;

class ImageCoding {
public:
    explicit ImageCoding();

    /**
     * Procesar imagen, convertirla en grises, es escalarla y ecualizarla (opcional)
     * @param frame (Mat) imagen fuente para detectar caras
     * @param detections (Vector<Rect>) Vector con los rectangulos de las detecciones
     * @param equalize (bool) True - ecualizo la imagen, en caso contrario no se ecualiza
     * @param size (Size) Tamaño de las imágenes finales. (Todas tendrán ese tamaño)
     * @return (vector) un listado de caras detectadas
     */
    std::vector<Mat> codeGray(std::vector<Rect> detections, bool equalize, Size size);

    /**
     * Carga la imagen a ser procesada
     * @param frame (Mat) Imagen original para ser procesada
     */
    void setImage(Mat frame);

private:
    /**
     * Imagen a ser procesada
     */
    Mat frame_;

};

#endif //IMAGE_CODING_HPP


