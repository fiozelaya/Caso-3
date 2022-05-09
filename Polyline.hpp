#ifndef __POLYLINE_HEADER__
#define __POLYLINE_HEADER__

class Polyline:public Element{
    private:
        vector<vector<double>> xyCoords;
    public:
        Polyline(){Element::attribute = "polyline";};
        Polyline(vector<vector<double>> pNewXYCoords, string pColor){xyCoords=pNewXYCoords; Element::setColor(pColor); Element::attribute = "polyline";};
        Polyline(vector<vector<double>> pNewXYCoords){xyCoords=pNewXYCoords;Element::attribute = "polyline";};
        void setXYCoord(vector<double> pNewxyCoords){xyCoords.push_back(pNewxyCoords);};
        vector<vector<double>> getXYCoord(){return xyCoords;};
        bool findMatchPosition(double pXValue, double pYValue);

        void createSVGAttribute(xml_attribute<> *newAttr, xml_document<> *pMyDoc){

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

#endif