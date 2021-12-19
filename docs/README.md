
# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Diego González Moreno
* Daniel Zazzali Peñaloza

## Resumen 

> Creación de sistema de vigilancia mediante OpenCV y C++.

## 1. Introducción

A dia de hoy es necesario para cualquier espacio de acceso publico contar con sistemas de seguridad para detectar anomalias y poseer evidencia en caso de que se produzca un problema, por lo tanto, en este proyecto se hará uso de las herramientas OpenCV, C++ y Visual Studio para desarrollar un software capaz de identificar los rostros que aparecen en la pantalla de vigilancia, además de desplegar informacion relevante para los usuarios del sistema.

### 1.1 Descripción del problema

Llevar un registro de las identidades que la camara es capaz de detectar en un determinado intervalo de tiempo.

### 1.2 Objetivos 

**Objetivo General**

Desarrollar un sistema de software capaz de reconocer, identificar y registrar las identidades detectadas en el video en un determinado tiempo.

**Objetivos específicos**

1. Reconocer todos los rostros detectados en la pantalla.
2. Identificar cada rostro indivualmente.
3. Contabilizar la cantidad de tiempo que cada rostro está en pantalla.
4. Desplegar los 5 rostros que mas tiempo estuvieron en pantalla.
5. Establecer la secuencia de video a analizar.
6. Contabilizar la cantidad de veces que cada rostro está en pantalla.
7. Desplegar las identidades detectadas en cada sesión.
8. Almacenar el video de la sesión con los rostros detectados.
9. Desplegar los intervalos de tiempo que aparece cada rostro en pantalla.

### 1.3 Solución propuesta

![diagrama](https://user-images.githubusercontent.com/90357250/136678660-8e52372a-a9ad-475e-8b9d-479b1e01adfa.png)

## 2. Materiales y métodos

Se utilizó la libreria OpenCV, la IDE Visual Studio 2019 y programación orientada a objetos en C++ para desarrollar el software.

### 2.2 Diseño 

Clases:
* Nodo (Lista Enlazada)
* LinkedList
* ImageCoding
* Identity
* FaceDetector
* BinaryNode
* BinaryTree

![Diagrama de clase](https://user-images.githubusercontent.com/90357250/138576534-cc880c47-fe1e-45ff-9545-adaa2f853933.jpg)

### 2.3 Implementación

* Para detectar los rostros en pantalla se utilizó el modelo haarcascade:

```c++
FaceDetector::FaceDetector() : scaleFactor_(1.2), minNeighbors_(4), imageWidth_(50), imageHeight_(50) {
    face_cascade.load("classifiers/haarcascade_frontalface_alt.xml");
}

std::vector<cv::Rect> FaceDetector::detectFaceRectangles(const cv::Mat& frame) {

    std::vector<cv::Rect> faces;
    Mat imageGray;

    // Detecto las caras (Se debe pasar la imagen a escala de grises
    cvtColor(frame, imageGray, COLOR_BGR2GRAY);
    // Aumento el constraste de una imagen
    equalizeHist(imageGray, imageGray);
    face_cascade.detectMultiScale(imageGray,
        faces,
        scaleFactor_,
        minNeighbors_,
        0 | CASCADE_SCALE_IMAGE,
        Size(imageWidth_, imageHeight_));

    return faces;
}

```

* Para almacenar las identidades se utilizó una lista enlazada:
```c++
bool LinkedList::add(Identity* identity) {

	Nodo* node = new Nodo(identity);

	if (size == 0) {

		first = node;
		first->setPrevious(nullptr);
		first->setNext(nullptr);
		int random;
		//se genera un numero random hasta que se encuentre uno que no exista
		do {
			random = 1 + rand() % (11 - 1);
		} while (checkrep(random, num));
		num[size] = random;

		size++;
		node->getData()->setidentifier(random);
		return true;
	}
	else {

		Nodo* p = first;

		while (p->getNext() != nullptr) {

			p = p->getNext();

		}
		 
		node->setPrevious(p);
		p->setNext(node);
		node->setNext(nullptr);
		int random;
		//se genera un numero random hasta que se encuentre uno que no exista
		do {
			random = 1 + rand() % (11 - 1);
		} while (checkrep(random, num));
		num[size] = random;

		size++;
		node->getData()->setidentifier(random);
		return true;

	}

	return false;

}

```

* Para actualizar actualizar las identidades en el arbol binario de busqueda se implementó el siguiente metodo:

```c++
void BinaryTree::Add(BinaryNode* parent, BinaryNode* newNode) {
	if (parent->getIdentifier() == newNode->getIdentifier()) {
		parent->addOneFrame();
		delete newNode;
	}

	else if (newNode->getIdentifier() < parent->getIdentifier()) {

		if (parent->getLLink() == nullptr) {

			parent->setLLink(newNode);

		} else {

			Add(parent->getLLink(), newNode);

		}

	} else if (newNode->getIdentifier() > parent->getIdentifier()) {

		if (parent->getRLink() == nullptr) {

			parent->setRLink(newNode);

		} else {

			Add(parent->getRLink(), newNode);

		}

	}

}
```

## 3. Resultados obtenidos
* Explicación de la estructura usada.
[![Alt text](https://img.youtube.com/vi/bcd-GEL9gnU/0.jpg)](https://www.youtube.com/watch?v=bcd-GEL9gnU)

* Se logró detectar los rostros que aparecen en pantalla señalados con un rectangulo de color rojo, almacenarlos y desplegarlos.

https://user-images.githubusercontent.com/90357250/144731696-a4634a05-ce09-4a01-8916-7343f13a9fe0.mp4


* Se logró contabilizar y desplegar las 5 identidades que pasan mas tiempo en camara.

![informacion de rostros](https://user-images.githubusercontent.com/90357250/146661365-c78807ec-9161-4d5f-a11f-1a0599dba0ff.PNG)


# Anexos

## Anexo A: Instalación y configuración librerías OpenCV

1. Bekios, J., Taller-01: Instalación de las librerías de OpenCV para Visual Studio en C++. https://www.youtube.com/watch?v=Hu7ArOaFm2g
