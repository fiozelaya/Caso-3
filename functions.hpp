#ifndef __FUNCTIONS_HEADER__
#define __FUNCTIONS_HEADER__

#include <sstream>
#include "main.hpp"
#include "svgPaths.hpp"
#include <iostream>
#include <string>

vector<vector<double>> getPoints(string points){
    vector<vector<double>> vectorPoints;
    vector<double> xyPoints;
    while(!points.empty()){
        xyPoints.push_back(stoi(points.substr(0, points.find(" "))));
        points.erase(0,points.find(" ")+1);
        if(points.find(",")!= string::npos){
            xyPoints.push_back(stoi(points.substr(0, points.find(","))));
            points.erase(0,points.find(",")+2);
        }
        else{
            xyPoints.push_back(stoi(points.substr(0, points.length())));
            points.erase(0,points.length());
        }
        vectorPoints.push_back(xyPoints);
        xyPoints.clear();
    }
    return vectorPoints;
}


void matchPosition(xml_node<>* pNode, vector<string>pColors, vector<vector<double>>pPositions,string matchColor){
    //cout<<pNode->name()<<"\n";
    vector<Element*> selectedElements;

    if(string(pNode->name())=="circle"){
        Circle* newCircle=new Circle(atof(pNode->first_attribute("cx")->value()),atof(pNode->first_attribute("cy")->value()),
                                     atof(pNode->first_attribute("r")->value()),matchColor);

        for(int position=0;position<pPositions.size();position++){
            if(newCircle->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                selectedElements.push_back(newCircle);
            }
        }
    }

    else if(string(pNode->name())=="rect"){
        Rectangle* newRectangle=new Rectangle(atof(pNode->first_attribute("width")->value()),atof(pNode->first_attribute("x")->value()),
                                     atof(pNode->first_attribute("y")->value()),matchColor,atof(pNode->first_attribute("height")->value()));
        for(int position=0;position<pPositions.size();position++){
            if(newRectangle->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                selectedElements.push_back(newRectangle);
            }
        }
    }
    else if(string(pNode->name())=="ellipse"){
        Ellipse* newEllipse=new Ellipse(atof(pNode->first_attribute("rx")->value()),atof(pNode->first_attribute("ry")->value()),
                                     atof(pNode->first_attribute("cx")->value()),atof(pNode->first_attribute("cy")->value()),matchColor);
        for(int position=0;position<pPositions.size();position++){
            if(newEllipse->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                selectedElements.push_back(newEllipse);
            }
        }
    }

    else if(string(pNode->name())=="polyline"){
        vector<vector<double>> points=getPoints(pNode->first_attribute("points")->value());

       /* if(string(pNode->name())=="polyline"){
            Polyline* newPolyline=new Polyline(points);
        }
        else{
            Polygon* newPolygon=new Polygon(points);
        }*/
        Polyline* newPolyline=new Polyline(points);
        for(int position=0;position<pPositions.size();position++){
            if(newPolyline->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                selectedElements.push_back(newPolyline);
            }
        }

    }

    else if(string(pNode->name())=="polygon"){
        vector<vector<double>> points=getPoints(pNode->first_attribute("points")->value());
        Polygon* newPolygon=new Polygon(points);
        for(int position=0;position<pPositions.size();position++){
            if(newPolygon->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                selectedElements.push_back(newPolygon);
            }
        }
    }

    else if(string(pNode->name())=="line"){
       /* Line* newLine=new Line(atof(pNode->first_attribute("y1")->value()),atof(pNode->first_attribute("x1")->value()),
                                     atof(pNode->first_attribute("x2")->value()),atof(pNode->first_attribute("y2")->value()),matchColor);*/
    }
    else if(string(pNode->name())=="path"){
        Path* newPath=new Path();

        //cout << "\tAtributo: " << attrib->name() << endl;
        //cout << "\t-Valor: " << attrib->value() << endl;
    }


    /*for (xml_attribute<>* attrib = pNode->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
        if(string(pNode->name())=="path"){
            /*Circle* newCircle=new Circle(atof(pDocument->first_node()->first_attribute("x")->value()),
                                         atof(pDocument->first_node()->first_attribute("y")->value()),
                                         atof(pDocument->first_node()->first_attribute("r")->value()));*/
          /*  cout << "\tAtributo: " << attrib->name() << endl;
            cout << "\t-Valor: " << attrib->value() << endl;
        }

    }*/

}

void seleccion(xml_node<>* node, vector<string> pColors, vector<vector<double>>pPositions){
    for (node = node->first_node(); node != NULL; node = node->next_sibling()){
    if (node->type() == node_element){

        for(int position=0;position<pColors.size();position++){
            if(node->first_attribute("fill")){
                //cout<<node->first_attribute("fill")->value()<<"\n";
                if(pColors[position]==node->first_attribute("fill")->value()){
                    cout<<"MATCHED COLOR: "<<node->first_attribute("fill")->value()<<endl;
                    matchPosition(node,pColors,pPositions,pColors[position]);
                }
            }
            if(node->first_attribute("stroke")){
                if(pColors[position]==node->first_attribute("stroke")->value()){
                    cout<<"MATCHED COLOR";
                }
            }
        }
        /*if(node->first_attribute("fill")){
            cout<<node->first_attribute("fill")->value()<<"\n";
        }
        /*else{
            cout<<"no esta\n";
        }
        if(node->first_attribute("stroke")){
            cout<<node->first_attribute("stroke")->value()<<"\n";
        }
        else{
            cout<<"no esta\n";
        }*/

        //cout << "Etiqueta: " << node->name() << endl;

       /* for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
            cout << "\tAtributo: " << attrib->name() << endl;
            cout << "\t-Valor: " << attrib->value() << endl;
        }*/

        seleccion(node,pColors,pPositions);
    }
  }
}


void readFile(SVG& svg,file<> file,xml_document<>* myDocument){
    //istringstream archivo(fileName);
    //file<> file(archivo);
    //file<> file("Images/girl-1.svg");
    //xml_document<> myDocument;
    //myDocument.parse<0>(file.data());
    extractXMLData(myDocument);


}

void saveFile(string fileName, xml_document<>* myDoc){
    ofstream copyFile(fileName); //Nuevo archivo
    stringstream stringStream;
    stringStream << *myDoc->first_node(); //Pasa el nodo ra�z a ss
    string stringXML = stringStream.str(); //ss.toString
    copyFile << stringXML;
    copyFile.close(); //Escribe y cierra
}

void prueba(){
    cout<<"Hola";
}

#endif
