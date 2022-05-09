#ifndef __SVG_PATHS_HEADER__
#define __SVG_PATHS_HEADER__

#include <math.h>
#include <vector>
#include <cstring>

/**
 * @brief parent class Element
 * 
 */
class Element{
    protected:
        double coordX, coordY, coordX2, coordY2, side, area, finalCoordX, finalCoordY, hypotenuse, displacement, auxCoordX, auxCoordY;
        bool rect,generateElement;
        vector<vector<int>> movements; // { {x,y}, {}, {}, {} }
        vector<vector<int>> movements2;
        string color, attribute;
        int fileName;
    public:
        Element(){};
        Element(double pNewSide){side=pNewSide;};
        Element(double pNewXValue, double pNewYValue){coordX=pNewXValue;coordY=pNewYValue;};
        void setAttribute(string pNewAttribute){attribute = pNewAttribute;};
        void setXCoord(double pNewXValue){coordX=pNewXValue;};
        void setYCoord(double pNewYValue){coordY=pNewYValue;};
        void setAuxXCoord(double pNewAuxXValue){auxCoordX=pNewAuxXValue;};
        void setAuxYCoord(double pNewAuxYValue){auxCoordY=pNewAuxYValue;};
        void setFinalXCoord(double pNewfinalCoordX){finalCoordX = pNewfinalCoordX;};
        void setFinalYCoord(double pNewfinalCoordY){finalCoordY = pNewfinalCoordY;};
        void setHypotenuse(double pNewHypotenuse){hypotenuse = pNewHypotenuse;};
        void setDisplacement(double pNewDisplacement){displacement = pNewDisplacement;};
        void setSide(double pNewSide){side=pNewSide;};
        void setRect(bool pNewRect){rect = pNewRect;};
        virtual void findMatchPosition(){};
        void setColor(string pNewColor){color=pNewColor;};
        double getXCoord(){return coordX;};
        double getYCoord(){return coordY;};
        double getAuxXCoord(){return auxCoordX;};
        double getAuxYCoord(){return auxCoordY;};
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
        void addMovement(int pXValue, int pYValue){
            vector<int> point = {pXValue,pYValue}; movements.push_back(point);
        };

        void setLineEndXValue(double pNewEndXValue){coordX2=pNewEndXValue;};
        void setLineEndYValue(double pNewEndYValue){coordY2=pNewEndYValue;};
        double getLineEndXValue(){return coordX2;};
        double getLineEndYValue(){return coordY2;};
        vector<vector<int>> getMovements2(){return movements2;};
        void addMovement2(int pNewX2, int pNewY2){vector<int> point = {pNewX2,pNewY2}; movements2.push_back(point);}
        void setGenerateElement(bool state){generateElement=state;};
        bool getGenerateElement(){return generateElement;};
        void setNumberFileName(int pFileName){fileName=pFileName;};
        int getNumberFileName(){return fileName;};
        virtual void createSVGAttribute(xml_document<> *pMyDoc){};
};

#endif
