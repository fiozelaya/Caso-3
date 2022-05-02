#ifndef __ROUTE_FUNCTIONS_HEADER__
#define __ROUTE_FUNCTIONS_HEADER__
# define M_PI 3.14159265358979323846

#include <iostream>
//#include "svgPaths.hpp"
#include <vector>

using namespace std;

void generatePointsDegrees90(Element* &pElement, int pX, int pY){
    int displacement = pElement->getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (pElement->getMovements().size() < pElement->getHypotenuse() / displacement){ //generar puntos
        pY -= auxDisplacement;
        if (pY < pElement->getFinalYCoord()){ //si se pasa del limite, se mantiene el punto anterior
            pY += auxDisplacement;
            pElement->addMovement(pX, pY);
            continue;
        }
        pElement->addMovement(pX, pY);
    }
}

void generatePointsDegrees180(Element* &pElement, int pX, int pY){
    int displacement = pElement->getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (pElement->getMovements().size() < pElement->getHypotenuse() / displacement){ //generar puntos
        pX -= auxDisplacement;
        if (pX < pElement->getFinalXCoord()){ //si se pasa del limite, se mantiene el punto anterior
            pX += auxDisplacement;
            pElement->addMovement(pX, pY);
            continue;
        }
        pElement->addMovement(pX, pY);
    }
    return;
}

void generatePointsDegrees270(Element* &pElement, int pX, int pY){
    int displacement = pElement->getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (pElement->getMovements().size() < pElement->getHypotenuse() / displacement){ //generar puntos
        pY += auxDisplacement;
        if (pY > pElement->getFinalYCoord()){ //si se pasa del limite, se mantiene el punto anterior
            pY -= auxDisplacement;
            pElement->addMovement(pX, pY);
            continue;
        }
        pElement->addMovement(pX, pY);
    }
    return;
}

void generatePointsDegrees360(Element* &pElement, int pX, int pY){
    int displacement = pElement->getDisplacement(), auxDisplacement = displacement;
    while (auxDisplacement < 10){ //ajustar el desplazamiento para que sea significativo
        auxDisplacement += displacement;
    }
    while (pElement->getMovements().size() < pElement->getHypotenuse() / displacement){ //generar puntos
        pX += auxDisplacement;
        if (pX > pElement->getFinalXCoord()){ //si se pasa del limite, se mantiene el punto anterior
            pX -= auxDisplacement;
            pElement->addMovement(pX, pY);
            continue;
        }
        pElement->addMovement(pX, pY);
    }
    return;
}

void firstQuadrant(Element* &pElement, int pLastX, int pLastY, int pWidth, double pDegrees, double lastDegrees){ 
    int newX, newY, displacement = pElement->getDisplacement(), auxDisplacement = displacement, frames = pElement->getHypotenuse() / displacement;
    int actualDegrees = pDegrees;

    if (pElement->getMovements().size() >= frames && pElement->getAttribute() != "line"){ //si ya el vector está lleno retorna
        return;
    }
    if(pElement->getMovements2().size() >= frames){
        return;
    }

    if (!pElement->isRect()){ //si es linea curva, se modifica el angulo que debe ser usado
        int finalDegrees = pDegrees + (frames / 4); //grados en los que tiene que empezar a "devolverse" para construir la curva
        lastDegrees++;
        actualDegrees = lastDegrees;
        if (lastDegrees > finalDegrees){ //si ya tiene que comenzar a devolverse le va restando 1 al finalDegrees en cada iteración recursiva
            actualDegrees = (finalDegrees + 1 - (lastDegrees - finalDegrees));
        }
    }

    while (auxDisplacement < 10){ //se modifica el desplazamiento para que sea significativo
        auxDisplacement += displacement;
        pElement->addMovement(pLastX, pLastY);
    }

    newX = (pLastX + auxDisplacement); //nueva X
    if (pElement->getAttribute() == "line"){newY = pElement->getLineEndYValue() - ((newX - pElement->getLineEndXValue()) * (tan(actualDegrees * (M_PI/180))));} // nueva Y = coord pY actual - (coord X en una grafica * tan(angulo))
    else{newY = pElement->getYCoord() - ((newX - pElement->getXCoord()) * (tan(actualDegrees * (M_PI/180))));}

    if (newX > pWidth || newY < 0){ //si el siguiente punto queda afuera del SVG se descarta pY se mantiene el viejo punto
        newX = pLastX; newY = pLastY;
        // (pElement->getAttribute() == "line") ? pElement->addMovement(newX, newY) : pElement->addMovement2(newX, newY);
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }
    else{ //si no, se agrega el nuevo punto
        // (pElement->getAttribute() == "line") ? pElement->addMovement(newX, newY) : pElement->addMovement2(newX, newY);
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }

    //lamada recursiva
    firstQuadrant(pElement, newX, newY, pWidth, pDegrees, lastDegrees);
}

void secondQuadrant(Element* &pElement, int pLastX, int pLastY, double pDegrees, double lastDegrees){
    int newX, newY, displacement = pElement->getDisplacement(), auxDisplacement = displacement, frames = pElement->getHypotenuse() / displacement;
    int actualDegrees = pDegrees;

    if (pElement->getMovements().size() >= frames && pElement->getAttribute() != "line"){ //si ya el vector está lleno retorna
        return;
    }
    if(pElement->getMovements2().size() >= frames){
        return;
    }

    if (!pElement->isRect()){
        int finalDegrees = pDegrees + (frames / 4); //grados en los que tiene que empezar a "devolverse" para construir la curva
        lastDegrees++;
        actualDegrees = lastDegrees;
        if (lastDegrees > finalDegrees){ //si ya tiene que comenzar a devolverse le va restando 1 al finalDegrees en cada iteración recursiva
            actualDegrees = (finalDegrees + 1 - (lastDegrees - finalDegrees));
        }
    }

    while (auxDisplacement < 10){
        auxDisplacement -= displacement;
        pElement->addMovement(pLastX, pLastY);
    }
    
    //nuevas coordenadas pX pY pY
    newX = (pLastX - auxDisplacement); //nueva X
    //newY = pElement->getYCoord() - ((pElement->getXCoord() - newX) * (tan(actualDegrees * (M_PI/180)))); // nueva Y = coord pY actual - (coord X en una grafica * tan(angulo))
    if (pElement->getAttribute() == "line"){newY =pElement->getLineEndYValue() - ((pElement->getLineEndXValue() - newX) * (tan(actualDegrees * (M_PI/180))));} // nueva Y = coord pY actual - (coord X en una grafica * tan(angulo))
    else{newY = pElement->getYCoord() - ((pElement->getXCoord() - newX) * (tan(actualDegrees * (M_PI/180))));}

    if (newX < 0 || newY < 0){ //si el siguiente punto queda afuera del SVG se descarta pY se mantiene el viejo punto
        newX = pLastX; newY = pLastY;
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }
    else{ //si no, se agrega el nuevo punto
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }

    //llamada recursiva
    secondQuadrant(pElement, newX, newY, pDegrees, lastDegrees);
}

void thirdQuadrant(Element* &pElement, int pLastX, int pLastY, int pHeight, double pDegrees, double lastDegrees){
    int newX, newY, displacement = pElement->getDisplacement(), auxDisplacement = displacement, frames = pElement->getHypotenuse() / displacement;
    int actualDegrees = pDegrees;

    if (pElement->getMovements().size() >= frames && pElement->getAttribute() != "line"){ //si ya el vector está lleno retorna
        return;
    }
    if(pElement->getMovements2().size() >= frames){
        return;
    }

    if (!pElement->isRect()){
        int finalDegrees = pDegrees + (frames / 4); //grados en los que tiene que empezar a "devolverse" para construir la curva
        lastDegrees++;
        actualDegrees = lastDegrees;
        if (lastDegrees > finalDegrees){ //si ya tiene que comenzar a devolverse le va restando 1 al finalDegrees en cada iteración recursiva
            actualDegrees = (finalDegrees + 1 - (lastDegrees - finalDegrees));
        }
    }

    while (auxDisplacement < 10){
        auxDisplacement -= displacement;
        pElement->addMovement(pLastX, pLastY);
    }
    //nuevas coordenadas pX pY pY
    newX = (pLastX - auxDisplacement); //nueva X
    //newY = pElement->getYCoord() + ((pElement->getXCoord() - newX) * (tan(actualDegrees * (M_PI/180)))); // nueva Y = coord pY actual + (coord X en una grafica * tan(angulo))
    if (pElement->getAttribute() == "line"){newY = pElement->getLineEndYValue() + ((pElement->getLineEndXValue() - newX) * (tan(actualDegrees * (M_PI/180))));} // nueva Y = coord pY actual - (coord X en una grafica * tan(angulo))
    else{newY = pElement->getYCoord() + ((pElement->getXCoord() - newX) * (tan(actualDegrees * (M_PI/180))));}

    if (newX < 0 || newY > pHeight){ //si el siguiente punto queda afuera del SVG se descarta pY se mantiene el viejo punto
        newX = pLastX; newY = pLastY;
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }
    else{ //si no, se agrega el nuevo punto
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }

    //llamada recursiva
    thirdQuadrant(pElement, newX, newY, pHeight, pDegrees, lastDegrees);
}

void fourthQuadrant(Element* &pElement, int pLastX, int pLastY, int pHeight, int pWidth, double pDegrees, double lastDegrees){
    int newX, newY, displacement = pElement->getDisplacement(), auxDisplacement = displacement, frames = pElement->getHypotenuse() / displacement;
    int actualDegrees = pDegrees;

    if (pElement->getMovements().size() >= frames && pElement->getAttribute() != "line"){ //si ya el vector está lleno retorna
        return;
    }
    if(pElement->getMovements2().size() >= frames){
        return;
    }

    if (!pElement->isRect()){
        int finalDegrees = pDegrees + (frames / 4); //grados en los que tiene que empezar a "devolverse" para construir la curva
        lastDegrees++;
        actualDegrees = lastDegrees;
        if (lastDegrees > finalDegrees){ //si ya tiene que comenzar a devolverse le va restando 1 al finalDegrees en cada iteración recursiva
            actualDegrees = (finalDegrees + 1 - (lastDegrees - finalDegrees));
        }
    }

    while (auxDisplacement < 10){
        auxDisplacement += displacement;
        pElement->addMovement(pLastX, pLastY);
    }
    //nuevas coordenadas pX pY pY
    newX = (pLastX + auxDisplacement); //nueva X
    // newY = pElement->getYCoord() + ((newX - pElement->getXCoord()) * (tan(actualDegrees * (M_PI/180)))); // nueva Y = coord pY actual + (coord X en una grafica * tan(angulo))
    if (pElement->getAttribute() == "line"){newY = pElement->getLineEndYValue() + ((newX - pElement->getLineEndXValue()) * (tan(actualDegrees * (M_PI/180))));} // nueva Y = coord pY actual - (coord X en una grafica * tan(angulo))
    else{newY = pElement->getYCoord() + ((newX - pElement->getXCoord()) * (tan(actualDegrees * (M_PI/180))));}

    if (newX > pWidth || newY > pHeight){ //si el siguiente punto queda afuera del SVG se descarta pY se mantiene el viejo punto
        newX = pLastX; newY = pLastY;
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }
    else{ //si no, se agrega el nuevo punto
        if (pElement->getAttribute() == "line" && pElement->getMovements().size() >= frames){
            pElement->addMovement2(newX, newY);
        }
        else{
            pElement->addMovement(newX, newY);
        }
    }

    //llamada recursiva
    fourthQuadrant(pElement, newX, newY, pHeight, pWidth, pDegrees, lastDegrees);
}

void determinePoints90(Element* &pElement, int pWidth, double pDegrees, int pFrames){
    double pX = pElement->getXCoord(), pY = pElement->getYCoord();
    double finalX = pWidth - pX, finalY, hypotenuse, displacement;
    double tangentOfAngle = tan(pDegrees * (M_PI/180));

    if (pDegrees == 90){ //si el angulo es de 90
        pElement->setFinalXCoord(pX);
        pElement->setFinalYCoord(0);
        pElement->setHypotenuse(pY);
        pElement->setDisplacement(pY / pFrames);
        generatePointsDegrees90(pElement, pX, pY);
        return;
    }

    // -----------------------------------------------POR EL MOMENTO, EL PUNTO FINAL ES ASÍ PARA LINEA CURVA Y RECTA ------------------------------------------
    //Calculo del punto (x,y) final del elemento 
    if ((pY - ((tangentOfAngle) * finalX) <= 0)){ //si el límite de la hipotenusa está en el extremo de arriba
            finalY = 0; //punto final de Y
            finalX = pX + (pY / (tangentOfAngle)); //punto final de X (X actual + (pY actual / tan(angulo)))
            hypotenuse = pY / (sin(pDegrees * (M_PI/180))); //hipotenusa = pY actual / sen(angulo)
            pElement->setHypotenuse(hypotenuse);
        } 
        else{ //si el limite esta en el extremo de la derecha
            finalY = (pY - ((tangentOfAngle) * finalX)); //punto final en Y (pY actual - (pX final en la imagen * tan(angulo)))
            finalX = pWidth;
            hypotenuse = finalX / (cos(pDegrees * (M_PI/180))); //hipotenusa = pX final en la imagen / cos(angulo)
            pElement->setHypotenuse(hypotenuse);
        }
    pElement->setFinalXCoord(finalX);
    pElement->setFinalYCoord(finalY);
    displacement = hypotenuse / pFrames;
    pElement->setDisplacement(displacement);

    if (pElement->getAttribute() == "line"){
        pElement->setAttribute("none");
        firstQuadrant(pElement, pX, pY, pWidth, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
        pElement->setAttribute("line");
        firstQuadrant(pElement, pElement->getLineEndXValue(), pElement->getLineEndYValue(), pWidth, pDegrees, pDegrees);
    }
    else{
        firstQuadrant(pElement, pX, pY, pWidth, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
    }
    
}

void determinePoints180(Element* &pElement, double pDegrees, int pFrames){
    double pX = pElement->getXCoord(), pY = pElement->getYCoord();
    double finalX = 0, finalY, hypotenuse, displacement;
    pDegrees = 180 - pDegrees;
    double tangentOfAngle = tan(pDegrees * (M_PI/180));

    if (pDegrees == 0){ //Si el angulo es de 180
        pElement->setFinalXCoord(0);
        pElement->setFinalYCoord(pY);
        pElement->setHypotenuse(pX);
        pElement->setDisplacement(pX / pFrames);
        generatePointsDegrees180(pElement, pX, pY);
        return;
    }
    
    if ((pY - ((tangentOfAngle) * pX) <= 0)){ //si el límite de la hipotenusa está en el extremo de arriba
        finalY = 0;
        finalX = pX - (pY / (tangentOfAngle)); //punto final de X = pX actual - (pY actual / tan(angulo))
        hypotenuse = pY / (sin(pDegrees * (M_PI/180))); // hipotenusa = pY actual / sen(angulo)
        pElement->setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la izquierda
        finalY = (pY - ((tangentOfAngle) * pX)); //punto final de Y = pY actual - (pX actual * tan(angulo))
        finalX = 0;
        hypotenuse = pX / (cos(pDegrees * (M_PI/180))); // hipotenusa = pX actual / cos(angulo)
        pElement->setHypotenuse(hypotenuse);
    }
    pElement->setFinalXCoord(finalX);
    pElement->setFinalYCoord(finalY);
    displacement = hypotenuse / pFrames;
    pElement->setDisplacement(displacement);

    if (pElement->getAttribute() == "line"){
        pElement->setAttribute("none");
        secondQuadrant(pElement, pX, pY, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
        pElement->setAttribute("line");
        secondQuadrant(pElement, pElement->getLineEndXValue(), pElement->getLineEndYValue(), pDegrees, pDegrees);
    }
    else{
        secondQuadrant(pElement, pX, pY, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
    }
}

void determinePoints270(Element* &pElement, int pHeight, double pDegrees, int pFrames){
    double pX = pElement->getXCoord(), pY = pElement->getYCoord();
    double finalX = 0, finalY = pHeight - pY, hypotenuse, displacement;
    pDegrees = pDegrees - 180;
    double tangentOfAngle = tan(pDegrees * (M_PI/180));

    if (pDegrees == 90){
        hypotenuse = finalY;
        pElement->setFinalXCoord(pX);
        pElement->setFinalYCoord(pHeight);
        pElement->setHypotenuse(hypotenuse);
        pElement->setDisplacement(hypotenuse / pFrames);
        generatePointsDegrees270(pElement, pX, pY);
        return;
    }
    
    if ((pY + ((tangentOfAngle) * pX) >= pHeight)){ //si el límite de la hipotenusa está en el extremo de abajo
        finalY = pHeight;
        finalX = pX - (finalY / (tangentOfAngle)); //punto final de X = pX actual - (pY final en la imagen / tan(angulo))
        hypotenuse = finalY / (sin(pDegrees * (M_PI/180))); //hipotenusa = pY final en la imagen / sen(angulo)
        pElement->setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la izquierda
        finalY = (pY + ((tangentOfAngle) * pX)); //punto final de pY = pY actual + (pX actual * tan(angulo))
        finalX = 0;
        hypotenuse = pX / (cos(pDegrees * (M_PI/180))); //hipotenusa = pX actual / cos(angulo)
        pElement->setHypotenuse(hypotenuse);
    }
    pElement->setFinalXCoord(finalX);
    pElement->setFinalYCoord(finalY);
    displacement = hypotenuse / pFrames;
    pElement->setDisplacement(displacement);

    if (pElement->getAttribute() == "line"){
        pElement->setAttribute("none");
        thirdQuadrant(pElement, pX, pY, pHeight, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
        pElement->setAttribute("line");
        thirdQuadrant(pElement, pElement->getLineEndXValue(), pElement->getLineEndYValue(),pHeight, pDegrees, pDegrees);
    }
    else{
        thirdQuadrant(pElement, pX, pY, pHeight, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
    }

}

void determinePoints360(Element* &pElement, int pWidth, int pHeight, double pDegrees, int pFrames){
    double pX = pElement->getXCoord(), pY = pElement->getYCoord();
    double finalX = pWidth, finalY = pHeight, hypotenuse, displacement;
    pDegrees = 360 - pDegrees;
    double tangentOfAngle = tan(pDegrees * (M_PI/180));

    if (pDegrees == 0){
        hypotenuse = finalX - pX;
        pElement->setFinalXCoord(finalX);
        pElement->setFinalYCoord(pY);
        pElement->setHypotenuse(finalX - pX);
        pElement->setDisplacement(hypotenuse / pFrames);
        generatePointsDegrees360(pElement, pX, pY);
        return;
    }

    if ((pY + ((tangentOfAngle) * (finalX - pX)) >= pHeight) || pDegrees == 0){ //si el límite de la hipotenusa está en el extremo de abajo
        finalY = pHeight;
        finalX = pX + ((finalY - pY) / (tangentOfAngle)); //punto final de X = pX actual + (pY en una grafica / tan(angulo))
        hypotenuse = (finalY - pY) / (sin(pDegrees * (M_PI/180))); // hipotenusa = pY en una grafica - sen(angulo)
        pElement->setHypotenuse(hypotenuse);
    } 
    else{ //si el limite esta en el extremo de la derecha
        finalY = (pY + ((tangentOfAngle) * (finalX - pX))); //punto final de pY = pY actual + (pX en una grafica * tan(angulo))
        finalX = pWidth;
        hypotenuse = (finalX - pX) / (cos(pDegrees * (M_PI/180))); //hipotenusa = pX en una grafica / cos(angulo)
        pElement->setHypotenuse(hypotenuse);
        }
    pElement->setFinalXCoord(finalX);
    pElement->setFinalYCoord(finalY);
    displacement = hypotenuse / pFrames;
    pElement->setDisplacement(displacement);

    if (pElement->getAttribute() == "line"){
        pElement->setAttribute("none");
        fourthQuadrant(pElement, pX, pY, pHeight, pWidth, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
        pElement->setAttribute("line");
        fourthQuadrant(pElement, pElement->getLineEndXValue(), pElement->getLineEndYValue(),pHeight, pWidth, pDegrees, pDegrees);
    }
    else{
        fourthQuadrant(pElement, pX, pY, pHeight, pWidth, pDegrees, pDegrees); //lamada a la funcion para enrutar el elemento
    }
}




#endif