#ifndef __ROUTE_FUNCTIONS_HEADER__
#define __ROUTE_FUNCTIONS_HEADER__

#include <iostream>
#include "svgPaths.hpp"
#include <vector>

using namespace std;

void degrees90(Element &element, int x, int y){
    int displacement = element.getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (element.getMovements().size() < element.getHypotenuse() / displacement){ //generar puntos
        y -= auxDisplacement;
        if (y < element.getFinalYCoord()){ //si se pasa del limite, se mantiene el punto anterior
            y += auxDisplacement;
            element.addMovement(x, y);
            continue;
        }
        element.addMovement(x, y);
    }
}

void degrees180(Element &element, int x, int y){
    int displacement = element.getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (element.getMovements().size() < element.getHypotenuse() / displacement){ //generar puntos
        x -= auxDisplacement;
        if (x < element.getFinalXCoord()){ //si se pasa del limite, se mantiene el punto anterior
            x += auxDisplacement;
            element.addMovement(x, y);
            continue;
        }
        element.addMovement(x, y);
    }
    return;
}

void degrees270(Element &element, int x, int y){
    int displacement = element.getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (element.getMovements().size() < element.getHypotenuse() / displacement){ //generar puntos
        y += auxDisplacement;
        if (y > element.getFinalYCoord()){ //si se pasa del limite, se mantiene el punto anterior
            y -= auxDisplacement;
            element.addMovement(x, y);
            continue;
        }
        element.addMovement(x, y);
    }
    return;
}

void degrees360(Element &element, int x, int y){
    int displacement = element.getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (element.getMovements().size() < element.getHypotenuse() / displacement){ //generar puntos
        x += auxDisplacement;
        if (x > element.getFinalXCoord()){ //si se pasa del limite, se mantiene el punto anterior
            x -= auxDisplacement;
            element.addMovement(x, y);
            continue;
        }
        element.addMovement(x, y);
    }
    return;
}

void firstQuadrant(Element &element, int lastX, int lastY, int width, double degrees, bool rect){ 
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;
    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }
    if (rect){ //si es en linea recta
        while (auxDisplacement < 10){ 
            auxDisplacement += displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX + auxDisplacement); //nueva X
        newY = element.getYCoord() - ((newX - element.getXCoord()) * (tan(degrees * (3.14159265358979323846/180)))); // nueva Y = coord y actual - (coord X en una grafica * tan(angulo))

        if (newX > width || newY < 0){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
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

void secondQuadrant(Element &element, int lastX, int lastY, double degrees, bool rect){
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;

    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }
    if (rect){
        while (auxDisplacement < 10){
            auxDisplacement -= displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX - auxDisplacement); //nueva X
        newY = element.getYCoord() - ((element.getXCoord() - newX) * (tan(degrees * (3.14159265358979323846/180)))); // nueva Y = coord y actual - (coord X en una grafica * tan(angulo))

        if (newX < 0 || newY < 0){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
        }
    }
    else{
        
    }

    //llamada recursiva
    secondQuadrant(element, newX, newY, degrees, rect);
}

void thirdQuadrant(Element &element, int lastX, int lastY, int height, double degrees, bool rect){
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;

    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }
    if (rect){
        while (auxDisplacement < 10){
            auxDisplacement -= displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX - auxDisplacement); //nueva X
        newY = element.getYCoord() + ((element.getXCoord() - newX) * (tan(degrees * (3.14159265358979323846/180)))); // nueva Y = coord y actual + (coord X en una grafica * tan(angulo))

        if (newX < 0 || newY > height){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
        }
    }
    else{
        
    }

    //llamada recursiva
    thirdQuadrant(element, newX, newY, height, degrees, rect);
}

void fourthQuadrant(Element &element, int lastX, int lastY, int height, int width, double degrees, bool rect){
    int newX, newY, displacement = element.getDisplacement(), auxDisplacement = displacement;

    if (element.getMovements().size() >= element.getHypotenuse() / displacement){ //si ya el vector está lleno
        return;
    }
    if (rect){
        while (auxDisplacement < 10){
            auxDisplacement += displacement;
            element.addMovement(lastX, lastY);
        }
        //nuevas coordenadas x y y
        newX = (lastX + auxDisplacement); //nueva X
        newY = element.getYCoord() + ((newX - element.getXCoord()) * (tan(degrees * (3.14159265358979323846/180)))); // nueva Y = coord y actual + (coord X en una grafica * tan(angulo))

        if (newX > width || newY > height){ //si el siguiente punto queda afuera del SVG se descarta y se mantiene el viejo punto
            newX = lastX; newY = lastY;
            element.addMovement(newX, newY);
        }
        else{ //si no, se agrega el nuevo punto
            element.addMovement(newX, newY);
        }
    }
    else{
        
    }

    //llamada recursiva
    fourthQuadrant(element, newX, newY, height, width, degrees, rect);
}

void determinePoints90(Element &element, int width, double degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = width - x, finalY, hypotenuse, displacement;
    if (degrees == 90){ //si el angulo es de 90
        element.setFinalXCoord(x);
        element.setFinalYCoord(0);
        element.setHypotenuse(y);
        element.setDisplacement(y / frames);
        degrees90(element, x, y);
        return;
    }
    if ((y - ((tan(degrees * (3.14159265358979323846/180))) * finalX) <= 0)){ //si el límite de la hipotenusa está en el extremo de arriba
        finalY = 0; //punto final de Y
        finalX = x + (y / (tan(degrees * (3.14159265358979323846/180)))); //punto final de X (X actual + (y actual / tan(angulo)))
        hypotenuse = y / (sin(degrees * (3.14159265358979323846/180))); //hipotenusa = y actual / sen(angulo)
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la derecha
        finalY = (y - ((tan(degrees * (3.14159265358979323846/180))) * finalX)); //punto final en Y (y actual - (x final en la imagen * tan(angulo)))
        finalX = width;
        hypotenuse = finalX / (cos(degrees * (3.14159265358979323846/180))); //hipotenusa = x final en la imagen / cos(angulo)
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);

    firstQuadrant(element, x, y, width, degrees, true); //lamada a la funcion para enrutar el elemento
}

void determinePoints180(Element &element, double degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = 0, finalY, hypotenuse, displacement;
    degrees = 180 - degrees;
    if (degrees == 0){ //Si el angulo es de 180
        element.setFinalXCoord(0);
        element.setFinalYCoord(y);
        element.setHypotenuse(x);
        element.setDisplacement(x / frames);
        degrees180(element, x, y);
        return;
    }
    if ((y - ((tan(degrees * (3.14159265358979323846/180))) * x) <= 0)){ //si el límite de la hipotenusa está en el extremo de arriba
        finalY = 0;
        finalX = x - (y / (tan(degrees * (3.14159265358979323846/180)))); //punto final de X = x actual - (y actual / tan(angulo))
        hypotenuse = y / (sin(degrees * (3.14159265358979323846/180))); // hipotenusa = y actual / sen(angulo)
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la izquierda
        finalY = (y - ((tan(degrees * (3.14159265358979323846/180))) * x)); //punto final de Y = y actual - (x actual * tan(angulo))
        finalX = 0;
        hypotenuse = x / (cos(degrees * (3.14159265358979323846/180))); // hipotenusa = x actual / cos(angulo)
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    
    secondQuadrant(element, x, y, degrees, true); //lamada a la funcion para enrutar el elemento
}

void determinePoints270(Element &element, int height, double degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = 0, finalY = height - y, hypotenuse, displacement;
    degrees = degrees - 180;
    if (degrees == 90){
        hypotenuse = finalY;
        element.setFinalXCoord(x);
        element.setFinalYCoord(height);
        element.setHypotenuse(hypotenuse);
        element.setDisplacement(hypotenuse / frames);
        degrees270(element, x, y);
        return;
    }
    if ((y + ((tan(degrees * (3.14159265358979323846/180))) * x) >= height)){ //si el límite de la hipotenusa está en el extremo de abajo
        finalY = height;
        finalX = x - (finalY / (tan(degrees * (3.14159265358979323846/180)))); //punto final de X = x actual - (y final en la imagen / tan(angulo))
        hypotenuse = finalY / (sin(degrees * (3.14159265358979323846/180))); //hipotenusa = y final en la imagen / sen(angulo)
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la izquierda
        finalY = (y + ((tan(degrees * (3.14159265358979323846/180))) * x)); //punto final de y = y actual + (x actual * tan(angulo))
        finalX = 0;
        hypotenuse = x / (cos(degrees * (3.14159265358979323846/180))); //hipotenusa = x actual / cos(angulo)
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    thirdQuadrant(element, x, y, height, degrees, true); //lamada a la funcion para enrutar el elemento

}

void determinePoints360(Element &element, int width, int height, double degrees, int frames){
    double x = element.getXCoord(), y = element.getYCoord();
    double finalX = width, finalY = height, hypotenuse, displacement;
    degrees = 360 - degrees;
    if (degrees == 0){
        hypotenuse = finalX - x;
        element.setFinalXCoord(finalX);
        element.setFinalYCoord(y);
        element.setHypotenuse(finalX - x);
        element.setDisplacement(hypotenuse / frames);
        degrees360(element, x, y);
        return;
    }
    if ((y + ((tan(degrees * (3.14159265358979323846/180))) * (finalX - x)) >= height) || degrees == 0){ //si el límite de la hipotenusa está en el extremo de abajo
        finalY = height;
        finalX = x + ((finalY - y) / (tan(degrees * (3.14159265358979323846/180)))); //punto final de X = x actual + (y en una grafica / tan(angulo))
        hypotenuse = (finalY - y) / (sin(degrees * (3.14159265358979323846/180))); // hipotenusa = y en una grafica - sen(angulo)
        element.setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la derecha
        finalY = (y + ((tan(degrees * (3.14159265358979323846/180))) * (finalX - x))); //punto final de y = y actual + (x en una grafica * tan(angulo))
        finalX = width;
        hypotenuse = (finalX - x) / (cos(degrees * (3.14159265358979323846/180))); //hipotenusa = x en una grafica / cos(angulo)
        element.setHypotenuse(hypotenuse);
    }
    element.setFinalXCoord(finalX);
    element.setFinalYCoord(finalY);

    displacement = hypotenuse / frames;
    element.setDisplacement(displacement);
    fourthQuadrant(element, x, y, height, width, degrees, true); //lamada a la funcion para enrutar el elemento

}




#endif