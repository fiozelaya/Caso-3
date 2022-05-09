#ifndef __RECT_HEADER__
#define __RECT_HEADER__

/**
 * @brief child class Rectangle
 * 
 */
class Rectangle:public Element{
    private:
        int width, height;
    public:
        Rectangle(){Element::attribute = "rect";};
        Rectangle(double pNewWidth){width=pNewWidth; Element::attribute = "rect";};
        Rectangle(double pNewWidth, double pNewXCoord, double pNewYCoord, string pNewColor, double pNewHeight){width=pNewWidth;Element::setXCoord(pNewXCoord);
        Element::setYCoord(pNewYCoord);Element::setSide(pNewHeight);Element::setColor(pNewColor); Element::attribute = "rect";};
        void setWidth(double pNewWidth){width=pNewWidth;};
        void setHeight(double pNewHeight){height=pNewHeight;};
        int getWidth(){return width;};
        int getHeight(){return height;};
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
            xml_attribute<> *x = pMyDoc->allocate_attribute("x", to_string(coordX).c_str());
            newNode->append_attribute(x);
            xml_attribute<> *y = pMyDoc->allocate_attribute("y", to_string(coordY).c_str());
            newNode->append_attribute(y);
            xml_attribute<> *attrWidth = pMyDoc->allocate_attribute("width", to_string(width).c_str());
            newNode->append_attribute(attrWidth);
            xml_attribute<> *attrHeight = pMyDoc->allocate_attribute("height", to_string(height).c_str());
            newNode->append_attribute(attrHeight);
            xml_attribute<> *fill = pMyDoc->allocate_attribute("fill", color.c_str());
            newNode->append_attribute(fill);
        }

};

bool Rectangle::findMatchPosition(double pXValue, double pYValue){
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
    double maxWidth=Element::getXCoord()+width, maxLength=Element::getYCoord()+Element::getSide();
    if((pXValue<=maxWidth&&(pXValue>=Element::getXCoord()))&&(pYValue<=maxLength&&(pYValue>=Element::getYCoord()))){
        return true;
    }
    else{
        return false;
    }
}

#endif