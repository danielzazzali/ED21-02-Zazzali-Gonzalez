#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

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

    while (true)
    {
        Mat image;
        cap.read(image);

        if (image.empty())
        {
            break;
        }

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
        waitKey(1);
    }
    //Vector que guardara los nodos del arbol binario
    vector<BinaryNode> arreglo;

    tree->print();
    cout << "La altura es: " << tree->height() << endl;

    int* max = tree->findMax();
    cout << "Id con mayor tiempo en pantalla:  ID = " << max[1] << " Frames = " << max[0] << "\n" << endl;

    tree->show(1,arreglo); //Se llena el vector con los nodos
    sort(arreglo.begin(), arreglo.end()); // se ordena de mayor a menor

    cout << "Las 5 caras que mas se repitieron son:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "ID: " << arreglo[i].getIdentifier() << " Frames: " << arreglo[i].getFrames()<<" " << "Segundos: " << float (arreglo[i].getFrames() / 10.) << endl;
    }


    //Mostrar todas las caras unicas que se detectaron
    for (int i = 0; i < list->getSize(); i++)
    {
        Mat face = list->getX(i)->getImage();
        int ident = list->getX(i)->getidentifier();
        putText(face,to_string(ident), Point(20, 20), 1, 1.5, Scalar(0, 0, 0), 2, 8, false);
        imshow(to_string(ident), face);
        waitKey(0);
    }

    destroyAllWindows();

    return 0;
}