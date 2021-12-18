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
#include "src/include/AVLTree.h"
#include "src/include/AVLNode.h"


using namespace std;
using namespace cv;


int main() {

    LinkedList* list = new LinkedList();
    AVLTree* AVLtree = new AVLTree();


    string path = "resources/Personas.mp4";
    VideoCapture cap(path);

    int segundos = cap.get(CAP_PROP_FRAME_COUNT) / cap.get(CAP_PROP_FPS); //Calculo la cantidad de segundos del video
    double comienzo, final;

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
    string output_path = "resources/Cut" + to_string(int(comienzo)) + "-" + to_string(int(final)) + ".mp4";
    int fourcc = VideoWriter::fourcc('0', '0', '0', 'C');
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    VideoWriter output_cap(output_path, fourcc, cap.get(CAP_PROP_FPS), Size(width, height), true);

    int frameCounter = 1;

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

                if (list->isEmpty())
                {
                    Identity* id = new Identity(cf);
                    list->add(id);

                    //Aqui se añade el id y el frame especifico en el que se detectó
                    AVLtree->insert(id->getIdentifier(), frameCounter);

                }
                else {

                    int exists = list->search(cf);

                    if (exists == -1) {

                        Identity* id = new Identity(cf);
                        list->add(id);

                        //Aqui se añade el id y el frame especifico en el que se detectó
                        AVLtree->insert(id->getIdentifier(), frameCounter);

                    }
                    else {
                        //Aqui se busca el id y se añade el frame especifico en el que se detectó
                        AVLtree->insert(exists, frameCounter);
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
        //agrego el frame al video
        output_cap.write(image);

        frameCounter++;

    }

    //Mostrar todas las caras unicas que se detectaron
    for (int i = 0; i < list->getSize(); i++)
    {
        Mat face = list->getX(i)->getImage();
        int ident = list->getX(i)->getIdentifier();
        putText(face,to_string(ident), Point(20, 20), 1, 1.5, Scalar(0, 0, 0), 2, 8, false);
        imshow(to_string(ident), face);
        cv::waitKey(0);
    }

    AVLtree->printTreeLevels();

    //Vector que guardara los nodos del arbol binario
    vector<AVLNode> arreglo;


    AVLtree->show(1, arreglo); //Se llena el vector con los nodos
    sort(arreglo.begin(), arreglo.end()); // se ordena de mayor a menor

    cout << "Las 5 caras que mas se repitieron son:" << endl;

    for (int i = 0; i < 5; i++) {

        cout << "ID: " << arreglo[i].getId() << " Frames: " << arreglo[i].getFrames() << " " << "Segundos: " << float(arreglo[i].getFrames() / cap.get(CAP_PROP_FPS)) << endl;

        // Problemas: Los vectores de frames estan en 0

        cout << "ID: " << arreglo[i].getId() << " size intervals: " << arreglo[i].getIntervals().size() << endl;

        //for (int x = 0; x < arreglo[i].getIntervals().size(); x++) {

        //    cout << arreglo[i].getIntervals()[x] << endl;

        //}

    }

    /*
    AVLtree->preorder();
    
    cout << endl;
    
    AVLtree->inorder();
    
    cout << endl;
    
    AVLtree->postorder();

    cout << endl;
    */

    destroyAllWindows();

    return 0;
}
