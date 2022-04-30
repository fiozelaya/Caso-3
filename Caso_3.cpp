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
//#include "svgPaths.hpp"
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
    
    /*
    Animator()

    Seleccion()
    Enrutamiento()
    Generacion()

    Seleccion.attach(observer)
    Enrutamiento.attach(observer)
    Generacion.attach(observer)

    llamar a seleccion

    */
    

    cout << tan(20) << endl;
    cout << tan(20 * (3.14159265358979323846 / 180));

    Routing* enrutamiento = new Routing();
    Line* nuevo = new Line();
    nuevo->setXCoord(200);
    nuevo->setYCoord(100);
    nuevo->setLineEndXValue(300);
    nuevo->setLineEndYValue(200);
    vector<Element> elements;
    elements.push_back(*nuevo);
    enrutamiento->route(elements, 20, 340, 666, 780);

    

    return 0;
}
