/*

Caso 3
Fiorella Zelaya
Ericka Yu Min Guo Chen

*/

#include "rapidxml/rapidxml_ext.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include <iostream>
#include "functions.hpp"
#include "path.hpp"
#include <math.h>
#include <string>
#include <vector>
#include "IObserverPattern.hpp"
#include "AnimatorGenerator.hpp"
#include "Selection.hpp"
#include "Routing.hpp"
#include "Generation.hpp"
#include "svgPaths.hpp"
#include <queue>

using namespace std;

//variables globales
int frames;
int degrees;
int height;
int width;


void prueba2(queue<string> &cola){
    if(cola.empty()){
        cout<<"vacia";
    }
    else{cout<<"con algo";}
}

int main()
{
  //char nombre='Images/gato1.svg';
    // svgDetails mySvg;
    // readFile(mySvg);
    // cout<<mySvg.getHeight()<<"\n";
    // cout<<mySvg.getWidth();
    //AnimatorGenerator* animator=new AnimatorGenerator();
    //Subject* seleccion = new Selection();
    //int curso = 2;
    //int* cursoPointer = &curso;
    //animator->notify(cursoPointer);

/*
    Circle* circulo=new Circle();
    circulo->setXCoord(3);
    cout<<circulo->getXCoord();*/

    // AnimatorGenerator* animator = new AnimatorGenerator();

    // Selection* seleccion = new Selection();
    // seleccion->attach(animator);
    // seleccion->notify(cursoPointer);
    // curso=1;
    // seleccion->notify(cursoPointer);

    //queue<string> cola;
    //cola.push("h");
    //prueba2(cola);
    //cola.push("hola");
    //prueba2(cola);
    
    cout << tan(20) << endl;
    cout << tan(20 * (3.14159265358979323846 / 180));

    Enrutamiento* enrutamiento = new Enrutamiento();
    cout << "ok" << endl;
    Element* nuevo = new Element();
    cout << "ok" << endl;
    nuevo->setXCoord(406);
    nuevo->setYCoord(270);
    cout << "ok" << endl;
    vector<Element> elements;
    elements.push_back(*nuevo);
    cout << "ok" << endl;
    enrutamiento->enrutar(elements, 20, 360, 666, 780);
    cout << "ok" << endl;

    // seleccion->attach(animator);
    // enrutamiento->attach(animator);
    // generacion->attach(animator);

/*
    seleccion->notify();
    enrutamiento->notify();
    generacion->notify();
/*
    Circle circulo(55);
    circulo.setArea();
    cout<<circulo.getString();

    Rectangle rectangulo;
    rectangulo.setSide(5);
    rectangulo.setWidth(5);
    rectangulo.setArea();
    cout<<rectangulo.getString();*/
/*
    vector<vector<int>> vectorPrueba;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vectorPrueba.push_back(a);

    cout<<vectorPrueba.at(0)[1];*/
    //circulo->setSide(132);
    //cout<<circulo->getSide();



    return 0;
}
