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
    

    /*
    cout << tan(20) << endl;
    cout << tan(20 * (3.14159265358979323846 / 180));

    Routing* enrutamiento = new Routing();
    Line* nuevo = new Line();
    nuevo->setXCoord(200);
    nuevo->setYCoord(100);
    nuevo->setLineEndXValue(300);
    nuevo->setLineEndYValue(200);
    vector<Element*> elements;
    elements.push_back(nuevo);
    enrutamiento->route(elements, 20, 340, 666, 780);

    */


   
   int frames = 20;
   int degrees = 20;

   AnimatorGenerator *animator = new AnimatorGenerator();
   Selection *selection = new Selection();
   Routing *routing = new Routing();
   Generation *generation = new Generation();

   selection->attach(animator);
   routing->attach(animator);
   generation->attach(animator);

   animator->setSelection(selection);
   animator->setGeneration(generation);
   animator->setRouting(routing);

    SVG svgDetails;
    svgDetails.setFrames(frames);
    svgDetails.setDegrees(degrees);

    xml_document<> document;

    file<> file("Images/passenger-1.svg");
    document.parse<0>(file.data());
    if(document.first_node()->first_attribute("height")){
        svgDetails.setHeight(atof(document.first_node()->first_attribute("height")->value()));
    }
    if(document.first_node()->first_attribute("width")){
        svgDetails.setHeight(atof(document.first_node()->first_attribute("width")->value()));
    }
    svgDetails.setDoc(&document);
    
    vector<string> colors = {"#00E4FF", "#FF00B9", "#FFE800"};
    vector<vector<double>> positions = {{406, 270}, {500, 600}, {466, 3687}, {2295, 2676}};
    animator->start(document.first_node(), colors, positions, svgDetails);

    

    

    return 0;
}
