#ifndef __POLYGON_HEADER__
#define __POLYGON_HEADER__

/**
 * @brief child class Polygon
 * 
 */
class Polygon:public Element{
    private:
        vector<vector<double>> xyCoords;
    public:
        Polygon(){Element::attribute = "polygon";};
        Polygon(vector<vector<double>> pNewCoords,string pColor){xyCoords=pNewCoords; Element::setColor(pColor); Element::attribute = "polygon";};
        Polygon(vector<vector<double>> pNewCoords){xyCoords=pNewCoords;Element::attribute = "polygon";};
        void setXYCoord(vector<double> pNewxyCoords){xyCoords.push_back(pNewxyCoords);};
        vector<vector<double>> getXYCoord(){return xyCoords;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_attribute<> *newAttr, xml_document<> *pMyDoc){

        }

};

bool Polygon::findMatchPosition(double pXValue, double pYValue){
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

#endif