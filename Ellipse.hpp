#ifndef __ELLIPSE_HEADER__
#define __ELLIPSE_HEADER__


/**
 * @brief child class Ellipse
 * 
 */
class Ellipse:public Element{
    private:
        double yRadio;
    public:
        Ellipse(){Element::attribute = "ellipse";};//FALTA CAMBIAR LOS XRADIO POR SETSIDE
        Ellipse(double pNewXRadio,double pNewYRadio, double pNewXCoord, double pNewYCoord, string pNewColor){Element::setSide(pNewXRadio);yRadio=pNewYRadio;
        Element::setColor(pNewColor);Element::setXCoord(pNewXCoord);Element::setYCoord(pNewYCoord); Element::attribute = "ellipse";};
        void setXRadio(double pNewXRadio){Element::setSide(pNewXRadio);};
        void setYRadio(double pNewYRadio){yRadio=pNewYRadio;};
        double getXRadio(){return Element::getSide();};
        double getYRadio(){return yRadio;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_document<> *pMyDoc){
            /*
            Function: this function writes the new attributes in the new SVG file.

            parameters:
            -pMyDoc -> it's the DOM of the SVG file.

            output: N/A

            */
            xml_node<> *newNode = pMyDoc->allocate_node(node_element, attribute.c_str());
            xml_node<> *parentNode = pMyDoc->first_node();

            char* cstrX = new char[to_string(coordX).size() + 1];  
            strcpy (cstrX, to_string(coordX).c_str());
            xml_attribute<> *cx = pMyDoc->allocate_attribute("cx", cstrX);
            newNode->append_attribute(cx);

            char* cstrY = new char[to_string(coordY).size() + 1];  
            strcpy (cstrY, to_string(coordY).c_str());
            xml_attribute<> *cy = pMyDoc->allocate_attribute("cy", cstrY);
            newNode->append_attribute(cy);

            char* cstrR = new char[to_string(side).size() + 1];  
            strcpy (cstrR, to_string(side).c_str());
            xml_attribute<> *rx = pMyDoc->allocate_attribute("rx", cstrR);
            newNode->append_attribute(rx);

            char* cstrRY = new char[to_string(yRadio).size() + 1];  
            strcpy (cstrRY, to_string(yRadio).c_str());
            xml_attribute<> *ry = pMyDoc->allocate_attribute("ry", cstrRY);
            newNode->append_attribute(ry);

            char* cstrColor = new char[color.size() + 1];  
            strcpy (cstrColor, color.c_str());
            xml_attribute<> *fill = pMyDoc->allocate_attribute("fill", cstrColor);
            newNode->append_attribute(fill);
        }
};

bool Ellipse::findMatchPosition(double pXValue, double pYValue){
    /*
    Function: this function finds out if the position of the current element matches
              any of the positions given.

    parameters:
    -pXValue -> X coordenate
    -pYValue -> Y coordenate

    output:
    -true -> if there's a match
    -false -> if there's no match

    */
    if((pXValue>=(Element::getXCoord()-Element::getSide()))&&(pXValue<=(Element::getXCoord()+Element::getSide()))&&
       (pYValue>=(Element::getYCoord()-yRadio))&&(pYValue<=(Element::getYCoord()+yRadio))){
        return true;
       }
    else{
        return false;
    }
}

#endif