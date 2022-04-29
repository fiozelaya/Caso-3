/*class Plataforma : public Subject {
private:
    list<Observer*> estudiantes;

public:
    Plataforma() {}
    ~Plataforma() {}

    void attach(Observer* est) {
        estudiantes.emplace_back(est);
    }

    void detach(Observer* est) {
        estudiantes.remove(est);
    }

    void notify(void* curso) {
        for (Observer* actual : estudiantes) {
            thread t(&Observer::update, actual, curso); // parametros = (direccionDeMetodo, instancia/objeto, parametro)
            t.join(); // espere a que t termine
        }
    }
};*/

#include <math.h>

class Element{
    protected:
        double coordX, coordY,side, area, finalCoordX, finalCoordY, hypotenuse, displacement;
        bool rect;
        vector<vector<int>> movements; // { {x,y}, {}, {}, {} }
        string color, attribute;
    public:
        Element(){};
        Element(double newSide){side=newSide;};
        Element(double newYValue, double newXValue){};
        void setXCoord(double newXValue){coordX=newXValue;};
        void setYCoord(double newYValue){coordY=newYValue;};
        void setFinalXCoord(double pNewfinalCoordX){finalCoordX = pNewfinalCoordX;};
        void setFinalYCoord(double pNewfinalCoordY){finalCoordY = pNewfinalCoordY;};
        void setHypotenuse(double pNewHypotenuse){hypotenuse = pNewHypotenuse;};
        void setDisplacement(double pNewDisplacement){displacement = pNewDisplacement;};
        void setSide(double newSide){side=newSide;};
        void setRect(bool newRect){rect = newRect;};
        //void setArea(double newArea){area=newArea;};
        //virtual void setArea(){};
        virtual void findMatchPosition(){};
        void setColor(string newColor){color=newColor;};
        double getXCoord(){return coordX;};
        double getYCoord(){return coordY;};
        double getSide(){return side;};
        double getArea(){return area;};
        string getColor(){return color;};
        double getDisplacement(){return displacement;};
        double getFinalXCoord(){return finalCoordX;};
        double getFinalYCoord(){return finalCoordY;};
        double getHypotenuse(){return hypotenuse;};
        string getAttribute(){return attribute;};
        vector<vector<int>> getMovements(){return movements;};
        bool isRect(){return rect;};
        void addMovement(int x, int y){
            vector<int> point = {x,y}; movements.push_back(point);
        };

        virtual void createSVGAttribute(xml_document<> *myDoc){};
};

class Circle:public Element{
    private:
    public:
        Circle(){};
        Circle(double pNewRadio, double pNewXCoord, double pNewYCoord, string pNewColor){Element::setXCoord(pNewXCoord);Element::setYCoord(pNewYCoord);
        Element::setSide(pNewRadio);Element::setColor(pNewColor);};
        Circle(double newRadio){Element::setSide(newRadio);};
        void setArea(){Element::area= (2 * acos(0.0))*pow(Element::side,2.0);};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_document<> *myDoc){
            xml_node<> *newNode = myDoc->allocate_node(node_element, attribute.c_str());
            myDoc->first_node()->append_node(newNode);
            xml_attribute<> *cx = myDoc->allocate_attribute("cx", to_string(coordX).c_str());
            newNode->append_attribute(cx);
            xml_attribute<> *cy = myDoc->allocate_attribute("cy", to_string(coordY).c_str());
            newNode->append_attribute(cy);
            xml_attribute<> *r = myDoc->allocate_attribute("r", to_string(side).c_str());
            newNode->append_attribute(r);
            xml_attribute<> *fill = myDoc->allocate_attribute("fill", color.c_str());
            newNode->append_attribute(fill);
        }

};

 bool Circle::findMatchPosition(double pXValue,double pYValue){

    if(pow((pXValue-(Element::coordX)),2.0)+pow((pYValue-(Element::coordY)),2.0)<=pow(Element::getSide(),2.0)){
        return true;
     }
     else{
        return false;
     }
}


class Rectangle:public Element{
    private:
        int width, height;
    public:
        Rectangle(){Element::attribute = "rect";};
        Rectangle(double pNewWidth){width=pNewWidth;};
        Rectangle(double pNewWidth, double pNewXCoord, double pNewYCoord, string pNewColor, double pNewHeight){width=pNewWidth;Element::setXCoord(pNewXCoord);
        Element::setYCoord(pNewYCoord);Element::setSide(pNewHeight);Element::setColor(pNewColor); Element::attribute = "rect";};
        void setWidth(double pNewWidth){width=pNewWidth;};
        void setHeight(double pNewHeight){height=pNewHeight;};
        int getWidth(){return width;};
        int getHeight(){return height;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_document<> *myDoc){
            xml_node<> *newNode = myDoc->allocate_node(node_element, attribute.c_str());
            myDoc->first_node()->append_node(newNode);
            xml_attribute<> *x = myDoc->allocate_attribute("x", to_string(coordX).c_str());
            newNode->append_attribute(x);
            xml_attribute<> *y = myDoc->allocate_attribute("y", to_string(coordY).c_str());
            newNode->append_attribute(y);
            xml_attribute<> *attrWidth = myDoc->allocate_attribute("width", to_string(width).c_str());
            newNode->append_attribute(attrWidth);
            xml_attribute<> *attrHeight = myDoc->allocate_attribute("height", to_string(height).c_str());
            newNode->append_attribute(attrHeight);
            xml_attribute<> *fill = myDoc->allocate_attribute("fill", color.c_str());
            newNode->append_attribute(fill);
        }

};

bool Rectangle::findMatchPosition(double pXValue, double pYValue){
    double maxWidth=Element::getXCoord()+width, maxLength=Element::getYCoord()+Element::getSide();
    if((pXValue<=maxWidth&&(pXValue>=Element::getXCoord()))&&(pYValue<=maxLength&&(pYValue>=Element::getYCoord()))){
        return true;
    }
    else{
        return false;
    }
}

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

        void createSVGAttribute(xml_attribute<> *newAttr, xml_document<> *myDoc){
            xml_node<> *newNode = myDoc->allocate_node(node_element, attribute.c_str());
            myDoc->first_node()->append_node(newNode);
            xml_attribute<> *cx = myDoc->allocate_attribute("cx", to_string(coordX).c_str());
            newNode->append_attribute(cx);
            xml_attribute<> *cy = myDoc->allocate_attribute("cy", to_string(coordY).c_str());
            newNode->append_attribute(cy);
            xml_attribute<> *rx = myDoc->allocate_attribute("rx", to_string(side).c_str());
            newNode->append_attribute(rx);
            xml_attribute<> *ry = myDoc->allocate_attribute("ry", to_string(yRadio).c_str());
            newNode->append_attribute(ry);
            xml_attribute<> *fill = myDoc->allocate_attribute("fill", color.c_str());
            newNode->append_attribute(fill);
        }
};

bool Ellipse::findMatchPosition(double pXValue, double pYValue){
    if((pXValue>=(Element::getXCoord()-Element::getSide()))&&(pXValue<=(Element::getXCoord()+Element::getSide()))&&
       (pYValue>=(Element::getYCoord()-yRadio))&&(pYValue<=(Element::getYCoord()+yRadio))){
        return true;
       }
    else{
        return false;
    }
}

class Polyline:public Element{
    private:
        vector<vector<double>> xyCoords;
    public:
        Polyline(){Element::attribute = "polyline";};
        Polyline(vector<vector<double>> pNewXYCoords, string pColor){xyCoords=pNewXYCoords; Element::setColor(pColor);};
        Polyline(vector<vector<double>> pNewXYCoords){xyCoords=pNewXYCoords;Element::attribute = "polyline";};
        void setXYCoord(vector<double> pNewxyCoords){xyCoords.push_back(pNewxyCoords);};
        vector<vector<double>> getXYCoord(){return xyCoords;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_attribute<> *newAttr, xml_document<> *myDoc){

        }

};

bool Polyline::findMatchPosition(double pXValue, double pYValue){
    double maxYValue=xyCoords[0][1], maxXValue=xyCoords[0][0], minYValue=xyCoords[0][1], minXValue=xyCoords[0][0];

    for(int posicion=1;posicion<xyCoords.size();posicion++){
        if((xyCoords[posicion][1]>maxYValue)){
            maxYValue=xyCoords[posicion][1];
        }
        if((xyCoords[posicion][1]<minYValue)){
            minYValue=xyCoords[posicion][1];
        }
        if((xyCoords[posicion][0]>minXValue)){
            maxXValue=xyCoords[posicion][0];
        }
        if((xyCoords[posicion][0]<minXValue)){
            minXValue=xyCoords[posicion][0];
        }
    }
    if((pXValue>=minXValue)&&(pXValue<=maxXValue)&&(pYValue>=minYValue)&&(pYValue<=maxYValue)){
        return true;
    }
    else{
        return false;
    }

}

class Polygon:public Element{
    private:
        vector<vector<double>> xyCoords;
    public:
        Polygon(){Element::attribute = "polygon";};
        Polygon(vector<vector<double>> newCoords,string pColor){xyCoords=newCoords; Element::setColor(pColor);};
        Polygon(vector<vector<double>> pNewCoords){xyCoords=pNewCoords;Element::attribute = "polygon";};
        void setXYCoord(vector<double> pNewxyCoords){xyCoords.push_back(pNewxyCoords);};
        vector<vector<double>> getXYCoord(){return xyCoords;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_attribute<> *newAttr, xml_document<> *myDoc){

        }

};

bool Polygon::findMatchPosition(double pXValue, double pYValue){
    double maxYValue=xyCoords[0][1], maxXValue=xyCoords[0][0], minYValue=xyCoords[0][1], minXValue=xyCoords[0][0];

    for(int posicion=1;posicion<xyCoords.size();posicion++){
        if((xyCoords[posicion][1]>maxYValue)){
            maxYValue=xyCoords[posicion][1];
        }
        if((xyCoords[posicion][1]<minYValue)){
            minYValue=xyCoords[posicion][1];
        }
        if((xyCoords[posicion][0]>minXValue)){
            maxXValue=xyCoords[posicion][0];
        }
        if((xyCoords[posicion][0]<minXValue)){
            minXValue=xyCoords[posicion][0];
        }
    }
    if((pXValue>=minXValue)&&(pXValue<=maxXValue)&&(pYValue>=minYValue)&&(pYValue<=maxYValue)){
        return true;
    }
    else{
        return false;
    }
}

class Line:public Element{
    private:
        double endXValue, endYValue;
    public:
        Line(){Element::attribute = "line";};
        Line(double newYCoord, double newXCoord, double newEndXValue,double newEndYValue,string pColor){Element::coordX=newXCoord; Element::coordY=newYCoord;
        endXValue=newEndXValue;endYValue=newEndYValue; Element::setColor(pColor);};
        Line(double pNewYCoord, double pNewXCoord, double pNewEndXValue,double pNewEndYValue){Element::coordX=pNewYCoord; Element::coordY=pNewXCoord;
        endXValue=pNewEndXValue;endYValue=pNewEndYValue; Element::attribute = "line";};
        void setEndXValue(double pNewEndXValue){endXValue=pNewEndXValue;};
        void setEndYValue(double pNewEndYValue){endYValue=pNewEndYValue;};
        double getEndXValue(){return endXValue;};
        double getEndYValue(){return endYValue;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_attribute<> *newAttr, xml_document<> *myDoc){
            xml_node<> *newNode = myDoc->allocate_node(node_element, attribute.c_str());
            myDoc->first_node()->append_node(newNode);
            xml_attribute<> *x1 = myDoc->allocate_attribute("x1", to_string(coordX).c_str());
            newNode->append_attribute(x1);
            xml_attribute<> *y1 = myDoc->allocate_attribute("y1", to_string(coordY).c_str());
            newNode->append_attribute(y1);
            xml_attribute<> *x2 = myDoc->allocate_attribute("x2", to_string(endXValue).c_str());
            newNode->append_attribute(x2);
            xml_attribute<> *y2 = myDoc->allocate_attribute("y2", to_string(endYValue).c_str());
            newNode->append_attribute(y2);
            xml_attribute<> *fill = myDoc->allocate_attribute("fill", color.c_str());
            newNode->append_attribute(fill);
        }

};

bool Line::findMatchPosition(double pXValue, double pYValue){
    if((pXValue>=Element::getXCoord()&&pXValue<=endXValue)&&(pYValue>=Element::getYCoord()&&pYValue<=(endYValue-Element::getXCoord()))){
        return true;
    }
    else{
        return false;
    }
}

class Path:public Element{
    private:
        vector<vector<double>>curvePositions;
    public:
        Path(){};
        Path(double pNewXMove, double pNewYMove, vector<vector<double>>pNewCurvePositions){Element::setXCoord(pNewXMove);Element::setXCoord(pNewYMove);
        curvePositions=pNewCurvePositions;};
        void setCurvePositions(vector<double> pNewCurvePosition){curvePositions.push_back(pNewCurvePosition);};
        vector<vector<double>> getCurvePositions(){return curvePositions;};
        bool findMatchPosition(double pXValue, double pYValue);
};

bool Path::findMatchPosition(double pXValue, double pYValue){
    double maxYValue=curvePositions[0][1], maxXValue=curvePositions[0][0], minYValue=curvePositions[0][1], minXValue=curvePositions[0][0];
    for(int posicion=1;posicion<curvePositions.size();posicion++){
        maxYValue=((curvePositions[posicion][1]>maxYValue)?curvePositions[posicion][1]:maxYValue);
        minYValue=((curvePositions[posicion][1]<minYValue)?curvePositions[posicion][1]:minYValue);
        maxXValue=((curvePositions[posicion][0]>maxXValue)?curvePositions[posicion][0]:maxXValue);
        minXValue=((curvePositions[posicion][0]<minXValue)?curvePositions[posicion][0]:minXValue);
    }
    if((pXValue>=minXValue)&&(pXValue<=maxXValue)&&(pYValue>=minYValue)&&(pYValue<=maxYValue)){
        return true;
    }
    else{
        return false;
    }
}

class SVG{
    private:
        double height, width;
        vector<Element*>selectedElements;
    public:
        SVG(){};
        void setHeight(double pNewHeight){height=pNewHeight;};
        void setWidth(double pNewWidth){width=pNewWidth;};
        void setVectorElements(vector<Element*> pVectorElements){selectedElements=pVectorElements;};
        void setElement(Element* pElement){selectedElements.push_back(pElement);};
        double getHeight(){return height;};
        double getWidth(){return width;};
        vector<Element*> getVectorElements(){return selectedElements;};

};
