#include <sstream>
#include "main.hpp"
#include "svgPaths.hpp"
#include <iostream>


void extractNodeData(xml_node<>* node){
  node->previous_sibling();
  /*for (node = node->first_node(); node != NULL; node = node->next_sibling()){
    if (node->type() == node_element){
      cout << "Etiqueta: " << node->name() << endl;

      for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
        cout << "\tAtributo: " << attrib->name() << endl;
        cout << "\t-Valor: " << attrib->value() << endl;
      }

      extractNodeData(node);
    }
  }*/
}

void extractXMLData(xml_document<>* doc, svgDetails* svg){
  xml_node<>* node = doc->first_node();

  cout << "Etiqueta: " << node->name() << endl;
  for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
    /*cout << " Atributo: " << attrib->name() << endl;
    cout << "\tValor: " << attrib->value() << endl;*/
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


void readFile(svgDetails& svg){
    //istringstream archivo(fileName);
    //file<> file(archivo);
    file<> file("Images/girl-1.svg");
    xml_document<> myDocument;
    myDocument.parse<0>(file.data());
    extractXMLData(&myDocument, &svg);


}
