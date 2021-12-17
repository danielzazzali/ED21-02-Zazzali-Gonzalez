#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include <opencv.hpp>

#include "src/include/FaceDetector.h"
#include "src/include/ImageCoding.h"
#include "src/include/LinkedList.h"
#include "src/include/Identity.h"
#include "src/include/BinaryTree.h"
#include "AVLTree.h"

using namespace std;
using namespace cv;

int main() {

    AVLTree* tree = new AVLTree();

    string path = "resources/Personas.mp4";
    VideoCapture cap(path);

    int segundos = cap.get(CAP_PROP_FRAME_COUNT)/ cap.get(CAP_PROP_FPS); //Calculo la cantidad de segundos del video
    double comienzo,final; 

    std::cout << "El video dura " << segundos << " segundos" << std::endl;

    //Inicio del video
    std::cout << "¿Desde que segundo quiere comenzar?" << std::endl;
    std::cin >> comienzo;
    while (comienzo < 0 || comienzo > segundos)
    {
        std::cout << "Segundos fuera de rango, intente de nuevo" << std::endl;
        std::cin >> comienzo;
    }

    int comienzoMilisegundos = comienzo * 1000; //Paso segundos a milisegundos para setearlos en el video
    cap.set(CAP_PROP_POS_MSEC, comienzoMilisegundos);

    //Final del video
    std::cout << "¿Hasta que segundo?" << std::endl;
    std::cin >> final;
    while (final < comienzo || final > segundos)
    {
        std::cout << "Segundos fuera de rango, intente de nuevo" << std::endl;
        std::cin >> final;
    }
    int finalFrames = final * cap.get(CAP_PROP_FPS); //Paso los segundos a fotogramas
    
    //Instancio video en donde estará el video cortado
    string output_path = "resources/Cut"+to_string(int(comienzo))+"-"+to_string(int(final))+".mp4";
    int fourcc = VideoWriter::fourcc('0', '0', '0', 'C');
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    VideoWriter output_cap(output_path, fourcc,cap.get(CAP_PROP_FPS),Size(width,height),true);

    //Mientras que el fotograma en el que se encuentra sea menor o igual al fotograma final, entonces que detecte caras
    while (cap.get(CAP_PROP_POS_FRAMES) < finalFrames)
    {
        Mat image;
        cap.read(image);
 
        FaceDetector fdetector;
        ImageCoding icoding;

        auto facesMarkers = fdetector.detectFaceRectangles(image);
        
        Scalar color(0, 0, 255);

        // Codifico las caras detectadas
        icoding.setImage(image);
        auto faceCodingGray = icoding.codeGray(facesMarkers, true, Size(60, 60));

        // Por cada cara detectada busca si se ha detectado anteriormente
        if (faceCodingGray.size() != 0) {

            for (const auto& cf : faceCodingGray) {

                int exist = tree->search(cf);

                cout << exist << endl; // AAAAAAAAAAAAAAAAAQUIIIIIIIIIIIIIIIIIIIIIIII

                if (exist == -1) {

                    tree->insert(cf);

                }
                else {

                    tree->addFrame(exist);

                }
            }  
        }
        
        //Muestro las caras encontradas en la imagen original
        for (const auto& fm : facesMarkers) {
            rectangle(image, fm, color, 4);
        }

        // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
        imshow("Detected Face", image);
        cv::waitKey(1);
        //agrego el frame al video
        output_cap.write(image);

    }

    tree->print();

    destroyAllWindows();

    return 0;
}