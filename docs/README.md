
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

![Diagrama de clase](https://user-images.githubusercontent.com/90357250/138576534-cc880c47-fe1e-45ff-9545-adaa2f853933.jpg)


