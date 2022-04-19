#ifndef __ROUTE_FUNCTIONS_HEADER__
#define __ROUTE_FUNCTIONS_HEADER__

#include <iostream>
#include "svgPaths.hpp"
#include <vector>

using namespace std;

void firstQuadrant(Element &element, int lastX, int lastY, int width, int degrees, bool rect){ 
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;
    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }
    if (rect){ //si es en linea recta
        while (auxDisplacement < 10){
            cout << "desplazamiento insignificativo" << endl;
            auxDisplacement += displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX + auxDisplacement) /*- element.getXCoord()*/;
        newY = element.getYCoord() - ((newX - element.getXCoord()) * (tan(degrees * (3.14159265358979323846/180))));
        cout << newX << " " << newY << endl;

        if (newX > width || newY < 0){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            cout << "se pasa del limite" << endl;
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
        }
    }
    else{

    }

    //lamada recursiva
    firstQuadrant(element, newX, newY, width, degrees, rect);
}

void secondQuadrant(Element &element, int lastX, int lastY, int degrees, bool rect){
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;

    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }

    if (rect){
        while (auxDisplacement < 10){
            cout << "desplazamiento insignificativo" << endl;
            auxDisplacement -= displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX - auxDisplacement) /*- element.getXCoord()*/;
        newY = element.getYCoord() - ((element.getXCoord() - newX) * (tan(degrees * (3.14159265358979323846/180))));
        cout << newX << " " << newY << endl;

        if (newX < 0 || newY < 0){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            cout << "se pasa del limite" << endl;
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
            cout << "se agrego" << endl;
        }
    }
    else{
        
    }

    //llamada recursiva
    secondQuadrant(element, newX, newY, degrees, rect);
}

void thirdQuadrant(Element &element, int lastX, int lastY, int height, int degrees, bool rect){
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;

    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }

    if (rect){
        while (auxDisplacement < 10){
            cout << "desplazamiento insignificativo" << endl;
            auxDisplacement -= displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX - auxDisplacement) /*- element.getXCoord()*/;
        newY = element.getYCoord() + ((element.getXCoord() - newX) * (tan(degrees * (3.14159265358979323846/180))));
        cout << newX << " " << newY << endl;

        if (newX < 0 || newY > height){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            cout << "se pasa del limite" << endl;
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
            cout << "se agrego" << endl;
        }
    }
    else{
        
    }

    //llamada recursiva
    thirdQuadrant(element, newX, newY, height, degrees, rect);
}

void fourthQuadrant(Element &element, int lastX, int lastY, int height, int width, int degrees, bool rect){
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;

    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }

    if (rect){
        while (auxDisplacement < 10){
            cout << "desplazamiento insignificativo" << endl;
            auxDisplacement += displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX + auxDisplacement) /*- element.getXCoord()*/;
        newY = element.getYCoord() + ((newX - element.getXCoord()) * (tan(degrees * (3.14159265358979323846/180))));
        cout << newX << " " << newY << endl;

        if (newX > width || newY > height){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            cout << "se pasa del limite" << endl;
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
            cout << "se agrego" << endl;
        }
    }
    else{
        
    }

    //llamada recursiva
    fourthQuadrant(element, newX, newY, height, width, degrees, rect);
}

void determinePoints90(Element &element, int width, int degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = width - x, finalY, hypotenuse, displacement;
    if ((y - ((tan(degrees * (3.14159265358979323846/180))) * finalX) < 0)){ //si el límite de la hipotenusa está en el extremo de arriba
        finalY = 0;
        finalX = x + (y / (tan(degrees * (3.14159265358979323846/180))));
        hypotenuse = y / (sin(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la derecha
        finalY = (y - ((tan(degrees * (3.14159265358979323846/180))) * finalX));
        finalX = width;
        hypotenuse = finalX / (cos(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    firstQuadrant(element, x, y, width, degrees, true); //lamada a la funcion para enrutar el elemento
}

void determinePoints180(Element &element, int degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = 0, finalY, hypotenuse, displacement;
    degrees = 180 - degrees;

    if ((y - ((tan(degrees * (3.14159265358979323846/180))) * x) < 0)){ //si el límite de la hipotenusa está en el extremo de arriba
        finalY = 0;
        finalX = x - (y / (tan(degrees * (3.14159265358979323846/180))));
        hypotenuse = y / (sin(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la izquierda
        finalY = (y - ((tan(degrees * (3.14159265358979323846/180))) * x));
        finalX = 0;
        hypotenuse = x / (cos(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    secondQuadrant(element, x, y, degrees, true); //lamada a la funcion para enrutar el elemento
}

void determinePoints270(Element &element, int height, int degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = 0, finalY = height - y, hypotenuse, displacement;
    degrees = degrees - 180;

    if ((y + ((tan(degrees * (3.14159265358979323846/180))) * x) > height)){ //si el límite de la hipotenusa está en el extremo de abajo
        finalY = height;
        finalX = x - (finalY / (tan(degrees * (3.14159265358979323846/180))));
        hypotenuse = finalY / (sin(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la izquierda
        finalY = (y + ((tan(degrees * (3.14159265358979323846/180))) * x));
        finalX = 0;
        hypotenuse = x / (cos(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    thirdQuadrant(element, x, y, height, degrees, true); //lamada a la funcion para enrutar el elemento

}

void determinePoints360(Element &element, int width, int height, int degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = width, finalY = height, hypotenuse, displacement;
    degrees = 360 - degrees;

    if ((y + ((tan(degrees * (3.14159265358979323846/180))) * (finalX - x)) > height)){ //si el límite de la hipotenusa está en el extremo de abajo
        finalY = height;
        finalX = x + ((finalY - y) / (tan(degrees * (3.14159265358979323846/180))));
        hypotenuse = (finalY - y) / (sin(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la derecha
        finalY = (y + ((tan(degrees * (3.14159265358979323846/180))) * (finalX - x)));
        finalX = width;
        hypotenuse = (finalX - x) / (cos(degrees * (3.14159265358979323846/180)));
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    fourthQuadrant(element, x, y, height, width, degrees, true); //lamada a la funcion para enrutar el elemento

}

#endif