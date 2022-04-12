#include <sstream>
#include "main.hpp"
#include "svgPaths.hpp"
#include <iostream>
#include <string>

void verifyParameters(double xValue, double yValue,xml_node<>* node ){
    string arrayPathCategories[]={"M","L","H","V","C","S","Q","T","A"};
    for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
        cout << "\tAtributo: " << attrib->name() << endl;
        cout << "\t-Valor: " << attrib->value() << endl;
        string value=attrib->value();
        /*if(value.substr(0,1)=="M"|| value.substr(0,1)=="m"){
           cout<<"\tValor: "<<value.substr(1,value.find(",")-1)<< endl;
        }*/
        /*if(value.find("M")==0&&xValue==stod(value.substr(value.find("M")+1,value.find(",")-1))&&
           yValue==stod(value.substr(value.find("M")+1+value.find(","),value.find(",")-1))){
            cout<<"AGREGADO: "<< endl;
            break;
        }

        else{
            cout<<"noo"<< endl;;
        }*/
        //for()
        //cout<<"\tValor: "<<value.substr(value.find("M")+1+value.find(","),value.find(",")-1)<< endl;


      }


}

void extractNodeData(xml_node<>* node){
  for (node = node->first_node(); node != NULL; node = node->next_sibling()){
    if (node->type() == node_element){
      cout << "Etiqueta: " << node->name() << endl;

      for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
        //cout << "\tAtributo: " << attrib->name() << endl;
        //cout << "\t-Valor: " << attrib->value() << endl;
        verifyParameters(331.91711,410.02944,node);
      }

      extractNodeData(node);
    }
  }
}

void extractXMLData(xml_document<>* doc, svgDetails* svg){
  xml_node<>* node = doc->first_node();

  cout << "Etiqueta: " << node->name() << endl;
  for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
    string attribute=attrib->name();
    if(attribute=="height"){
        svg->setHeight(stod(attrib->value()));
    }
    if(attribute=="width"){
        svg->setWidth(stod(attrib->value()));
    }
  }
  extractNodeData(node);
}


void readFile(svgDetails& svg,file<> file,xml_document<>* myDocument){
    //istringstream archivo(fileName);
    //file<> file(archivo);
    //file<> file("Images/girl-1.svg");
    //xml_document<> myDocument;
    //myDocument.parse<0>(file.data());
    extractXMLData(myDocument, &svg);


}

void saveFile(string fileName, xml_document<>* myDoc){
    ofstream copyFile(fileName); //Nuevo archivo
    stringstream stringStream;
    stringStream << *myDoc->first_node(); //Pasa el nodo raíz a ss
    string stringXML = stringStream.str(); //ss.toString
    copyFile << stringXML;
    copyFile.close(); //Escribe y cierra
}
