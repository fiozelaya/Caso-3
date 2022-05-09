#ifndef __PATH_HEADER__
#define __PATH_HEADER__

class Path:public Element{
    private:
        int degrees;
        string attributeD;
        vector<vector<double>>curvePositions;
    public:
        Path(){Element::attribute = "path";};
        Path(double pNewXMove, double pNewYMove, vector<vector<double>>pNewCurvePositions,string pColor){Element::setXCoord(pNewXMove);Element::setYCoord(pNewYMove);
        curvePositions=pNewCurvePositions; Element::attribute = "path"; Element::color=pColor;};
        void setCurvePositions(vector<double> pNewCurvePosition){curvePositions.push_back(pNewCurvePosition);};
        void setAttributeD(string newAttributeD){attributeD = newAttributeD;};
        void setDegrees(int pDegrees){degrees = pDegrees;};
        vector<vector<double>> getCurvePositions(){return curvePositions;};
        string getAttributeD(){return attributeD;};
        int getDegrees(){return degrees;};
        bool findMatchPosition(double pXValue, double pYValue);

        xml_node<>* findGNode(xml_node<>* pNode){
            xml_node<>* currentNode = pNode;
            while(true){
                if (currentNode->next_sibling() == NULL){
                    if (currentNode->first_node()->name() == (string)"path"){
                        //cout << "fin" << endl;
                        return currentNode;
                    }
                    else{
                        //cout << "next child" << endl;
                        currentNode = currentNode->first_node();
                    }
                }
                else{
                    //cout << "next sibling" << endl;
                    currentNode = currentNode->next_sibling();
                }
            }
        }

        string getTransformCoords(){
            int currentDegrees = degrees;
            string str = "translate(";
            str = str + to_string(coordX - this->getAuxXCoord()) + ", " + to_string(this->getAuxYCoord() - coordY);
            return str + ")";
        }

        void createSVGAttribute(xml_document<> *pMyDoc){

            string auxAttributeD = attributeD;
            int mIndex = attributeD.find_first_of('m');
            if (mIndex == -1 ){mIndex = attributeD.find_first_of('M');}
            int separatorIndex = attributeD.find_first_of(',');
            int finalIndex = attributeD.find_first_not_of(" m1234567890.,") -1;

            double newXValue = Element::coordX;
            double newYValue = Element::coordY;

            string newX = to_string(newXValue);
            newX.erase( newX.find_last_not_of('0') + 1, std::string::npos );
            newX.erase( newX.find_last_not_of('.') + 1, std::string::npos );
            string newY = to_string(newYValue);
            newY.erase( newY.find_last_not_of('0') + 1, std::string::npos );
            newY.erase( newY.find_last_not_of('.') + 1, std::string::npos );

            auxAttributeD.replace(separatorIndex+1, finalIndex-1-separatorIndex, newY);
            auxAttributeD.replace(mIndex + 1, separatorIndex-1, newX);

            xml_node<> *newNode = pMyDoc->allocate_node(node_element, attribute.c_str());

            char* cstr = new char[attributeD.size() + 1];  // Create char buffer to store string copy
            strcpy (cstr, attributeD.c_str());
            xml_attribute<> *d = pMyDoc->allocate_attribute("d", cstr);
            newNode->append_attribute(d);

            char* cstrColor = new char[color.size() + 1];  // Create char buffer to store string copy
            strcpy (cstrColor, color.c_str());
            xml_attribute<> *fill = pMyDoc->allocate_attribute("fill", cstrColor);
            newNode->append_attribute(fill);

            char* cstrTransform = new char[getTransformCoords().size() + 1];  // Create char buffer to store string copy
            strcpy (cstrTransform, getTransformCoords().c_str());
            xml_attribute<> *transform = pMyDoc->allocate_attribute("transform", cstrTransform);
            newNode->append_attribute(transform);

            xml_node<>* nodeG = findGNode(pMyDoc->first_node());
            nodeG->append_node(newNode);

        }
};

bool Path::findMatchPosition(double pXValue, double pYValue){
    // cout << "entrando a fund match..." << endl;
    // cout << "size: " << curvePositions.size() << endl;
    if(curvePositions.size() == 0){
        return false;
    }
    //double maxYValue=curvePositions[0][1], maxXValue=curvePositions[0][0], minYValue=Element::getYCoord(), minXValue=Element::getXCoord();
    double maxYValue= this->getYCoord(), maxXValue=this->getXCoord(), minYValue=this->getYCoord(), minXValue=this->getXCoord();
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

#endif