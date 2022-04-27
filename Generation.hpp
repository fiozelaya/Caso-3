#ifndef __GENERATION_HEADER__
#define __GENERATION_HEADER__

#include <vector>
#include "svgPaths.hpp"

class Generacion: public Subject{
private:
    Observer* animator;
    vector<vector<vector<Element>>> elementsByFrame;
    //xml_document<> myDoc;
public:
    Generacion() = default;
    ~Generacion(){}
    //void setMyDoc(xml_document<> *pMyDoc){myDoc = pMyDoc;};
    void attach(Observer* pObserver){
        animator = pObserver;
    }
    void detach(Observer* pObserver){

    }
    void notify(){
        cout << "generacion" << endl;
        animator->update(nullptr);
    }
    void start(xml_document<> myDoc, vector<Element> &pElementsList, int pFrames){
        int i = 0, j = 0, auxFrames = frames;
        int newX, newY;
        bool createAnotherSVG = true;
        while(true){
            //parsing / agregar / cambiar coordenadas ??
            newX = pElementsList[j].getMovements()[i][0]; // se agarra el elemento j de la lista, y se le asigna la coordenada x del punto i (frame) de la lista de movimientos
            newY = pElementsList[j].getMovements()[i][1]; // se agarra el elemento j de la lista, y se le asigna la coordenada y del punto i (frame) de la lista de movimientos
            pElementsList[j].setXCoord(newX);
            pElementsList[j].setYCoord(newY);

            //mediante consumer ... generation();
            generation(&myDoc, pElementsList[j], createAnotherSVG);

            if(j != frames){
                j++;
                continue;
            }
            i++;
            j = i;
            createAnotherSVG = true;
        }
    }
    void generation(xml_document<> *myDoc, Element pElement, bool pCreateAnotherSVG){
        if (pCreateAnotherSVG){
            //crear otro archivo
        }
        else{
            //añadir el elemento al del archivo svg actual
            string attribute = pElement.getAttribute();
            xml_node<> *newNode = myDoc->allocate_node(node_element, pElement.getAttribute().c_str());
            myDoc->first_node()->append_node(newNode);

            if (attribute == "circle"){
                xml_attribute<> *cx = myDoc->allocate_attribute("cx", "5");
                xml_attribute<> *cy = myDoc->allocate_attribute("cy", "5");
                xml_attribute<> *r = myDoc->allocate_attribute("r", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");
            }
            else if (attribute == "rect"){
                xml_attribute<> *width = myDoc->allocate_attribute("width", "5");
                xml_attribute<> *height = myDoc->allocate_attribute("height", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");
            }
            else if (attribute == "ellipse"){
                xml_attribute<> *cx = myDoc->allocate_attribute("cx", "5");
                xml_attribute<> *cy = myDoc->allocate_attribute("cy", "5");
                xml_attribute<> *rx = myDoc->allocate_attribute("rx", "5");
                xml_attribute<> *ry = myDoc->allocate_attribute("ry", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");

            }
            else if (attribute == "line"){
                xml_attribute<> *x1 = myDoc->allocate_attribute("x1", "5");
                xml_attribute<> *x2 = myDoc->allocate_attribute("x2", "5");
                xml_attribute<> *y1 = myDoc->allocate_attribute("y1", "5");
                xml_attribute<> *y2 = myDoc->allocate_attribute("y2", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");

            }
            else if (attribute == "polygon"){
                xml_attribute<> *points = myDoc->allocate_attribute("points", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");
            }
            else if (attribute == "polyline"){
                xml_attribute<> *points = myDoc->allocate_attribute("points", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");

            }
            else if (attribute == "path"){
                xml_attribute<> *d = myDoc->allocate_attribute("d", "5");
                xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");

            }

            //xml_attribute<> *newAttr = myDoc->allocate_attribute("age", "5");
            xml_attribute<> *newAttr;
            //pElement.createSVGAttribute(newAttr, &myDoc);
            newNode->append_attribute(newAttr);
        }
    }
};

#endif