#ifndef __CIRCLE_HEADER__
#define __CIRCLE_HEADER__

/**
 * @brief child class Circle
 * 
 */
class Circle:public Element{
    private:
    public:
        Circle(){ Element::attribute = "circle";};
        Circle(double pNewRadio, double pNewXCoord, double pNewYCoord, string pNewColor){Element::setXCoord(pNewXCoord);Element::setYCoord(pNewYCoord);
        Element::setSide(pNewRadio);Element::setColor(pNewColor); Element::attribute = "circle";};
        Circle(double pNewRadio){Element::setSide(pNewRadio); Element::attribute = "circle";};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_document<> *pMyDoc){
            /*
            Function: this function writes the new attributes in the new SVG file.

            parameters:
            -pMyDoc -> it's the DOM of the SVG file.

            output: N/A

            */
            xml_node<> *newNode = pMyDoc->allocate_node(node_element, attribute.c_str());


            string Scx = to_string(coordX);
            string Scy = to_string(coordY);
            string Sside = to_string(coordY);

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
            xml_attribute<> *r = pMyDoc->allocate_attribute("r", cstrR);
            newNode->append_attribute(r);

            xml_attribute<> *opacity = pMyDoc->allocate_attribute("opacity", "0.5");
            newNode->append_attribute(opacity);


            xml_attribute<> *fill = pMyDoc->allocate_attribute("fill", color.c_str());
            newNode->append_attribute(fill);

            pMyDoc->first_node()->append_node(newNode);
        }

};

bool Circle::findMatchPosition(double pXValue,double pYValue){
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
    if(pow((pXValue-(Element::coordX)),2.0)+pow((pYValue-(Element::coordY)),2.0)<=pow(Element::getSide(),2.0)){
        return true;
     }
     else{
        return false;
     }
}

#endif