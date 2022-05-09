#ifndef __LINE_HEADER__
#define __LINE_HEADER__

/**
 * @brief child class Line
 * 
 */
class Line:public Element{
    private:
        double endXValue, endYValue;
    public:
        Line(){Element::attribute = "line";};
        Line(double newYCoord, double newXCoord, double newEndXValue,double newEndYValue,string pColor){Element::coordX=newXCoord; Element::coordY=newYCoord;
        endXValue=newEndXValue;endYValue=newEndYValue; Element::setColor(pColor); Element::attribute = "line";};
        Line(double pNewYCoord, double pNewXCoord, double pNewEndXValue,double pNewEndYValue){Element::coordX=pNewYCoord; Element::coordY=pNewXCoord;
        endXValue=pNewEndXValue;endYValue=pNewEndYValue; Element::attribute = "line";};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_document<> *pMyDoc){
            /*
            Function: this function writes the new attributes in the new SVG file.

            parameters:
            -pMyDoc -> it's the DOM of the SVG file.

            output: N/A

            */
            xml_node<> *newNode = pMyDoc->allocate_node(node_element, attribute.c_str());
            pMyDoc->first_node()->append_node(newNode);

            char* cstrx1 = new char[to_string(coordX).size() + 1];  
            strcpy (cstrx1, to_string(coordX).c_str());
            xml_attribute<> *x1 = pMyDoc->allocate_attribute("x1", cstrx1);
            newNode->append_attribute(x1);

            char* cstry1 = new char[to_string(coordY).size() + 1];  
            strcpy (cstry1, to_string(coordY).c_str());
            xml_attribute<> *y1 = pMyDoc->allocate_attribute("y1", cstry1);
            newNode->append_attribute(y1);

            char* cstrx2 = new char[to_string(endXValue).size() + 1];  
            strcpy (cstrx2, to_string(endXValue).c_str());
            xml_attribute<> *x2 = pMyDoc->allocate_attribute("x2", cstrx2);
            newNode->append_attribute(x2);

            char* cstry2 = new char[to_string(endYValue).size() + 1];  
            strcpy (cstry2, to_string(endYValue).c_str());
            xml_attribute<> *y2 = pMyDoc->allocate_attribute("y2", cstry2);
            newNode->append_attribute(y2);

            char* cstrcolor = new char[color.size() + 1];  
            strcpy (cstrcolor, color.c_str());
            xml_attribute<> *fill = pMyDoc->allocate_attribute("fill", cstrcolor);
            newNode->append_attribute(fill);
        }

};

bool Line::findMatchPosition(double pXValue, double pYValue){
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
    if((pXValue>=Element::getXCoord()&&pXValue<=endXValue)&&(pYValue>=Element::getYCoord()&&pYValue<=(endYValue-Element::getXCoord()))){
        return true;
    }
    else{
        return false;
    }
}

#endif