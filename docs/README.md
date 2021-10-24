
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

Se utilizará la libreria OpenCV, la IDE Visual Studio 2019 y programación orientada a objetos en C++ para desarrollar el software.

### 2.2 Diseño 

Clases:
* Identidad
* Aparicion
* Usuario
* Administrador
* Guardia

![Diagrama de clase](https://user-images.githubusercontent.com/90357250/138576534-cc880c47-fe1e-45ff-9545-adaa2f853933.jpg)

### 2.3 Implementación

Para detectar los rostros en pantalla se utilizó el modelo haarcascade.

```c++
 1. CascadeClassifier faceCascade;
 2. faceCascade.load("C:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml");

 3. faceCascade.detectMultiScale(grayscale, faces, 1.02, 3);

 4. for (int r = 0; r < faces.size(); r++) {

	5. int x = faces[r].x * scale;
	6. int y = faces[r].y * scale;
	7. int w = faces[r].width * scale;
	8. int h = faces[r].height * scale;

	9. croppedFace = frame(Rect(x, y, w, h));

	10. images[r] = croppedFace;

	11. filenumber = to_string(r);
	12. labels[r] = filenumber;

	13. stringstream ssfn;
	14. filename = "Resources\\Faces\\";
	15. ssfn << filename.c_str() << name << filenumber << ".jpg";
	16. filename = ssfn.str();
	17. imwrite(filename, croppedFace);

}
```
## 3. Resultados obtenidos

Se logro detectar los rostros que aparecen en pantalla señalados con un rectangulo de color rojo, almacenarlos y desplegarlos.

https://user-images.githubusercontent.com/90357250/138578225-5df71a15-27a3-41c4-bac4-645b2aefc688.mp4


# Anexos

## Anexo A: Instalación y configuración librerías OpenCV

1. Bekios, J., Taller-01: Instalación de las librerías de OpenCV para Visual Studio en C++. https://www.youtube.com/watch?v=Hu7ArOaFm2g
  

