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

// void extractXMLData(xml_node<>* node){

//     if (node->next_sibling() == NULL){
//         if (node->first_node()->name() == (string)"path"){
//             cout << "fin" << endl;
//             return;
//         }
//         else{
//             cout << "next child" << endl;
//             extractXMLData(node->first_node());
//         }
//     }
//     else{
//         cout << "next sibling" << endl;
//         extractXMLData(node->next_sibling());
//     }
// }

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
   int degrees = 230;
   double height;
   double width;

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

    //  extractXMLData(document.first_node());
    //  return 0;

    if(document.first_node()->first_attribute("height")){
        height = stod(document.first_node()->first_attribute("height")->value());
        svgDetails.setHeight(height);
    }
    if(document.first_node()->first_attribute("width")){
        width = stod(document.first_node()->first_attribute("width")->value());
        svgDetails.setWidth(width);
    }

    if((int)svgDetails.getHeight() == 0 || (int)svgDetails.getWidth() == 0 || document.first_node()->first_attribute("viewBox")->value() != ""){
        string viewBox = document.first_node()->first_attribute("viewBox")->value();
        string viewBoxParameter[4];
        int i = 0;
        stringstream ssin(viewBox);
        while (ssin.good() && i < 4){
            ssin >> viewBoxParameter[i];
            ++i;
        }
        for(i = 0; i < 4; i++){
            cout << viewBoxParameter[i] << endl;
        }
        height = stod(viewBoxParameter[2]);
        width = stod(viewBoxParameter[3]);
        svgDetails.setHeight(height);
        svgDetails.setWidth(width);

    }

    cout << height << " /// " << width << endl;
    cout << (int)svgDetails.getHeight() << " /// " << (int)svgDetails.getWidth() << endl;
    svgDetails.setDoc(&document);

    vector<string> colors = {"#00E4FF", "#FF00B9", "#FFE800", "#F7FF00", "#00FF1A", "#FF0101" , "#FF8101"};
    vector<vector<double>> positions = {{406, 270}, {500, 600}, {466, 3687}, {2295, 2676}, {1000, 1800}, {2645, 1820}, {160, 464}, {200, 500}, {400, 200}, {264.013,440}, {500,500}};
    animator->start(document.first_node(), colors, positions, svgDetails);

    delete(animator);
    delete(selection);
    delete(routing);
    delete(generation);

    /*
   string attributeD = "m 459.976, 646.99 c 7.263,0 13.189,5.924 13.189,13.19 0,7.266 -5.926,13.192 -13.189,13.192 -7.269,0 -13.195,-5.926 -13.195,-13.192 0,-7.266 5.926,-13.19 13.195,-13.19";

    Path *newPath = new Path();
    newPath->setAttributeD(attributeD);
    newPath->setXCoord(200.23);
    newPath->setYCoord(100.567);

    newPath->createSVGAttribute(nullptr);

    */


    return 0;
}
