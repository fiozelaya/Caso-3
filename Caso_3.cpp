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

    /*
    
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
    enrutamiento->enrutar(elements, 20, 20, 666, 780);
    cout << "ok" << endl;


    */


    svgDetails mySvg;
    file<> theFile("Images/wifi-3.svg");
    xml_document<> myDoc;
    myDoc.parse<0>(theFile.data());
    
    readFile(mySvg, theFile, &myDoc);

    return 0;
}
