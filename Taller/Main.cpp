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

using namespace std;
using namespace cv;

int main() {

    LinkedList* list = new LinkedList();
    BinaryTree* tree = new BinaryTree();

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

    //Mientras que el fotograma en el que se encuentra sea menor o igual al fotograma final, entonces que detecte caras
    while (cap.get(CAP_PROP_POS_FRAMES) <= finalFrames)
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
                
                if (list->isEmpty())
                {
                    Identity* id = new Identity(cf);
                    list->add(id);
                    tree->add(id->getidentifier());

                } else {

                    int exists = list->search(cf);

                    if (exists == -1) {

                        Identity* id = new Identity(cf);
                        list->add(id);
                        tree->add(id->getidentifier());

                    } else {
                        tree->add(exists);

                    }

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

    }
    //Vector que guardara los nodos del arbol binario
    vector<BinaryNode> arreglo;

    tree->print();
    std::cout << "La altura es: " << tree->height() << endl;

    int* max = tree->findMax();
    std::cout << "Id con mayor tiempo en pantalla:  ID = " << max[1] << " Frames = " << max[0] << "\n" << endl;

    tree->show(1,arreglo); //Se llena el vector con los nodos
    std::sort(arreglo.begin(), arreglo.end()); // se ordena de mayor a menor

    std::cout << "Las 5 caras que mas se repitieron son:" << endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "ID: " << arreglo[i].getIdentifier() << " Frames: " << arreglo[i].getFrames()<<" " << "Segundos: " << float (arreglo[i].getFrames() / cap.get(CAP_PROP_FPS)) << endl;
    }


    //Mostrar todas las caras unicas que se detectaron
    for (int i = 0; i < list->getSize(); i++)
    {
        Mat face = list->getX(i)->getImage();
        int ident = list->getX(i)->getidentifier();
        putText(face,to_string(ident), Point(20, 20), 1, 1.5, Scalar(0, 0, 0), 2, 8, false);
        imshow(to_string(ident), face);
        cv::waitKey(0);
    }

    destroyAllWindows();

    return 0;
}