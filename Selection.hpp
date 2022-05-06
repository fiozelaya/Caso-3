#ifndef __SELECTION_HEADER__
#define __SELECTION_HEADER__

#include <thread>
#include <list>
#include <vector>
class Selection: public Subject{
private:
    Observer* animator;
    list<Observer*> elementsList;
    vector<Element*> selectedElements;
    string hola;

public:
    Selection() = default;
    ~Selection(){}
    void attach(Observer* pAnimator){
        animator=pAnimator;
    }
    void detach(Observer* pWhichElement){

    }
    void notify(void* pCode){
        //cout << "seleccion" << endl;
         //int value = *(int*)pCode;
        ////cout<<value;
        // for (Observer* actual : elementsList) {
        //     thread t(&Observer::update, actual, pCode); // parametros = (direccionDeMetodo, instancia/objeto, parametro)
        //     t.join(); // espere a que t termine
        // }
        //animator->setSelectedPoints("holass");
        animator->update(pCode);
        //thread t(&Observer::update, pCode);
        //animator.update();
        //t.join();
    }

    void prueba(){
        hola="Holi";
    }

    string prueba2(){
        return hola;
    }

    vector<int> colorConverterHexToRBG(char const*pHexColor){
        int curso = 2;
        int* cursoPointer = &curso;
        int r, g, b;
        sscanf(pHexColor, "#%02x%02x%02x", &r, &g, &b);
        //notify(cursoPointer);
        //std:://cout << r << ',' << g << ',' << b<<endl;
        return {r,g,b};
    }

    vector<Element*> getSelectedElements(){
        return selectedElements;
    }

    void setSelectedElements(vector<Element*> pNewSelectedElements){
        selectedElements = pNewSelectedElements;
        //cout << "imprimiendo vector..." << endl;
        for (int i = 0; i < selectedElements.size(); i++){
            //cout << selectedElements[i]->getAttribute() << " " << selectedElements[i]->getXCoord() << " " << selectedElements[i]->getYCoord() << endl;
        }
    }

    vector<vector<double>> getPoints(string pPoints){
        vector<vector<double>> vectorPoints;
        vector<double> vectorXYPoints;
        while(!pPoints.empty()){
            vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.find(","))));
            pPoints.erase(0,pPoints.find(",")+1);
            if(pPoints.find(" ")!= string::npos){
                vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.find(" "))));
                pPoints.erase(0,pPoints.find(" ")+1);
            }
            else{
                vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.length())));
                pPoints.erase(0,pPoints.length());
            }
            vectorPoints.push_back(vectorXYPoints);
            vectorXYPoints.clear();
        }
        return vectorPoints;
    }

    void getMaxMinValues(double& pMaxXValue, double& pMinXValue, double& pMaxYValue, double& pMinYValue,vector<vector<double>>pPoints){
        pMaxYValue=pPoints[0][1], pMaxXValue=pPoints[0][0], pMinYValue=pPoints[0][1], pMinXValue=pPoints[0][0];
        for(int posicion=0;posicion<pPoints.size();posicion++){
            pMaxYValue=((pPoints[posicion][1]>=pMaxYValue)?pPoints[posicion][1]:pMaxYValue);
            pMinYValue=((pPoints[posicion][1]<=pMinYValue)?pPoints[posicion][1]:pMinYValue);
            pMaxXValue=((pPoints[posicion][0]>=pMinXValue)?pPoints[posicion][0]:pMaxXValue);
            pMinXValue=((pPoints[posicion][0]<=pMinXValue)?pPoints[posicion][0]:pMinXValue);
        }

    }

    // void getMoveValues(double& pXvalue, double& pYValue, string pPath){
    //     int commandPosition;
    //     commandPosition=pPath.find_first_of("Mm");
    //     pPath.erase(0,commandPosition+1);
    //     //cout << pPath.substr(0,pPath.find(" ")) << endl;
    //     //pXvalue=stod(pPath.substr(0,pPath.find(" ")));
    //     pPath.erase(0,pPath.find(" ")+1);
    //     //cout << pPath.substr(0,pPath.find(" ")) << endl;
    //     //pYValue=stod(pPath.substr(0,pPath.find(" ")));
    // }

    void getMoveValues(double& pXvalue, double& pYValue, string pPath){
        int commandPosition;
        commandPosition=pPath.find_first_of("Mm");
        pPath.erase(0,commandPosition+2);
        pXvalue=stod(pPath.substr(0,pPath.find(",")));
        pPath.erase(0,pPath.find(",")+1);
        pYValue=stod(pPath.substr(0,pPath.find(",")));
    }

    bool verifyElementPosition(vector<vector<double>>pInputPoints, xml_node<>*pNode){
        if(string(pNode->name())=="circle"||string(pNode->name())=="rect"||string(pNode->name())=="ellipse"||string(pNode->name())=="polyline"||
           string(pNode->name())=="polygon"||string(pNode->name())=="line"||string(pNode->name())=="path"){
            return true;
        }
        else{
            return false;
        }

        return true;
    }


    // void selectPathPoints(vector<vector<double>>* pAllPoints, string pPoints){
    //     vector<double> vectorXYPoints;
    //     while(!pPoints.empty()){
    //         vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.find(" "))));
    //         pPoints.erase(0,pPoints.find(" ")+1);
    //         if(pPoints.find(",")!= string::npos){
    //             vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.find(","))));
    //             pPoints.erase(0,pPoints.find(",")+2);
    //         }
    //         else{
    //             vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.length())));
    //             pPoints.erase(0,pPoints.length());
    //         }
    //         pAllPoints->push_back(vectorXYPoints);
    //         vectorXYPoints.clear();
    //     }
    // }

    void selectPathPoints(vector<vector<double>>* pAllPoints, string pPoints){
        vector<double> vectorXYPoints;
        //cout<<pPoints<<endl<<endl;
        while(!pPoints.empty()){
            vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.find(","))));
            pPoints.erase(0,pPoints.find(",")+1);
            if(pPoints.find(" ")!= string::npos){
                vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.find(" "))));
                pPoints.erase(0,pPoints.find(" ")+1);
            }
            else{
                vectorXYPoints.push_back(stoi(pPoints.substr(0, pPoints.length())));
                pPoints.erase(0,pPoints.length());
            }
            pAllPoints->push_back(vectorXYPoints);
            vectorXYPoints.clear();
        }
    }

    vector<vector<double>> selectPathRange(string pPath){
        vector<vector<double>> solution;
        vector<string>pathCommands={"Cc","Ll","Hh","Vv"};
        string tempPath;
        int commandPosition;
        for(int position=0;position<pathCommands.size();position++){
                tempPath=pPath;
                commandPosition=tempPath.find_first_of(pathCommands[position]);
            while(commandPosition!=std::string::npos){
                tempPath.erase(0,commandPosition+2);
                commandPosition=tempPath.find_first_of("ZzCcLlHhVvSsQqTtAa");
                if(pathCommands[position]=="Hh"){
                    selectPathPoints(&solution,tempPath.substr(0,commandPosition).append("0"));
                }
                else if(pathCommands[position]=="Vv"){
                    selectPathPoints(&solution,"0 "+tempPath.substr(0,commandPosition));
                }
                else{
                    selectPathPoints(&solution,tempPath.substr(0,commandPosition-1));
                }
                tempPath.erase(0,commandPosition);
                commandPosition=tempPath.find_first_of(pathCommands[position]);
            }
        }

        return solution;
    }

    // vector<vector<double>> selectPathRange(string pPath){
    //     vector<vector<double>> solution;
    //     vector<string>pathCommands={"Cc","Ll","Hh","Vv"};
    //     string tempPath;
    //     int commandPosition;
    //     for(int position=0;position<pathCommands.size();position++){
    //             tempPath=pPath;
    //             commandPosition=tempPath.find_first_of(pathCommands[position]);
    //         while(commandPosition!=std::string::npos){
    //             tempPath.erase(0,commandPosition+1);
    //             commandPosition=tempPath.find_first_of("ZzCcLlHhVvSsQqTtAa");
    //             if(pathCommands[position]=="Hh"){
    //                 selectPathPoints(&solution,tempPath.substr(0,commandPosition).append("0"));
    //             }
    //             else if(pathCommands[position]=="Vv"){
    //                 selectPathPoints(&solution,"0 "+tempPath.substr(0,commandPosition));
    //             }
    //             else{
    //                 selectPathPoints(&solution,tempPath.substr(0,commandPosition));
    //             }
    //             tempPath.erase(0,commandPosition);
    //             commandPosition=tempPath.find_first_of(pathCommands[position]);
    //         }
    //     }

    //     return solution;
    // }

    void matchPosition(xml_node<>* pNode, vector<string>pColors, vector<vector<double>>pPositions,string pMatchColor,SVG* pSVG){
        if(string(pNode->name())=="circle"){
            Circle* newCircle=new Circle(atof(pNode->first_attribute("r")->value()), atof(pNode->first_attribute("cx")->value()),atof(pNode->first_attribute("cy")->value()),
                                        pMatchColor);
            //cout << "EL CIRCULO: " << newCircle->getXCoord() << " " << newCircle->getYCoord() << pNode->first_attribute("r")->value() << endl;
            for(int position=0;position<pPositions.size();position++){
                if(newCircle->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                    pSVG->setElement(newCircle);
                    break;
                }
            }
        }
        else if(string(pNode->name())=="rect"){
            Rectangle* newRectangle=new Rectangle(atof(pNode->first_attribute("width")->value()),atof(pNode->first_attribute("x")->value()),
                                         atof(pNode->first_attribute("y")->value()),pMatchColor,atof(pNode->first_attribute("height")->value()));
            for(int position=0;position<pPositions.size();position++){
                if(newRectangle->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                    pSVG->setElement(newRectangle);
                    break;
                }
            }
        }
        else if(string(pNode->name())=="ellipse"){
            Ellipse* newEllipse=new Ellipse(atof(pNode->first_attribute("rx")->value()),atof(pNode->first_attribute("ry")->value()),
                                         atof(pNode->first_attribute("cx")->value()),atof(pNode->first_attribute("cy")->value()),pMatchColor);
            for(int position=0;position<pPositions.size();position++){
                if(newEllipse->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                    pSVG->setElement(newEllipse);
                    break;
                }
            }
        }
        else if(string(pNode->name())=="polyline"){
            vector<vector<double>> points=getPoints(pNode->first_attribute("points")->value());
            Polyline* newPolyline=new Polyline(points,pMatchColor);
            for(int position=0;position<pPositions.size();position++){
                if(newPolyline->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                    pSVG->setElement(newPolyline);
                    break;
                }
            }
        }
        else if(string(pNode->name())=="polygon"){
            vector<vector<double>> points=getPoints(pNode->first_attribute("points")->value());
            Polygon* newPolygon=new Polygon(points,pMatchColor);
            for(int position=0;position<pPositions.size();position++){
                if(newPolygon->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                   pSVG->setElement(newPolygon);
                   break;
                }
            }
        }
        else if(string(pNode->name())=="line"){
            Line* newLine=new Line(atof(pNode->first_attribute("y1")->value()),atof(pNode->first_attribute("x1")->value()),
                                         atof(pNode->first_attribute("x2")->value()),atof(pNode->first_attribute("y2")->value()),pMatchColor);
            //cout << newLine->getXCoord() << " " << newLine->getYCoord() << " " << newLine->getFinalXCoord() << " " << newLine->getFinalYCoord() << endl;
            for(int position=0;position<pPositions.size();position++){
                if(newLine->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                    pSVG->setElement(newLine);
                    break;
                }
            }
        }
        else if(string(pNode->name())=="path"){
            string pathValue=pNode->first_attribute("d")->value();
            cout << pNode->first_attribute("d")->value() << endl;
            double pathXValue, pathYValue;
            getMoveValues(pathXValue,pathYValue,pathValue);
            Path* newPath=new Path(pathXValue,pathYValue,selectPathRange(pathValue),pMatchColor);
            newPath->setAttributeD(pNode->first_attribute("d")->value());
            for(int position=0;position<pPositions.size();position++){
                if(newPath->findMatchPosition(pPositions[position][0],pPositions[position][1])){
                    pSVG->setElement(newPath);
                    cout<<"ENCONTRE PATH";
                    //exit(0);
                    break;
                }
            }
        }
    }

    bool matchColor(string pInputColor, string pElementColor){

        vector<int> inputColor=colorConverterHexToRBG(pInputColor.c_str()),elementColor=colorConverterHexToRBG(pElementColor.c_str());
        ////cout<<inputColor[0]<<","<<inputColor[1]<<","<<inputColor[2]<<endl;
        ////cout<<elementColor[0]<<","<<elementColor[1]<<","<<elementColor[2]<<endl<<endl;

        if(inputColor[0]==elementColor[0]&&inputColor[1]==elementColor[1]&&inputColor[2]==elementColor[2]){
            //cout<<"IGUALES" << endl;
            return true;
        }
        else if(inputColor[0]>=50&&inputColor[0]<=255&&elementColor[0]>=50&&elementColor[0]<=255&&inputColor[1]>=0&&inputColor[1]<=190&&elementColor[1]>=0&&elementColor[1]<=190&&
           inputColor[2]>=0&&inputColor[2]<=190&&elementColor[2]>=0&&elementColor[2]<=190){
            //cout<<"ROJO" << endl;
            return true;
        }
        else if(inputColor[0]>=170&&inputColor[0]<=255&&elementColor[0]>=170&&elementColor[0]<=255&&inputColor[1]>=50&&inputColor[1]<=190&&
                elementColor[1]>=50&&elementColor[1]<=190&&inputColor[2]>=0&&inputColor[2]<=80&&elementColor[2]>=0&&elementColor[2]<=80){
            //cout<<"NARANJA" << endl;
            return true;
        }
        else if(inputColor[0]>=170&&inputColor[0]<=255&&elementColor[0]>=170&&elementColor[0]<=255&&inputColor[1]>=160&&inputColor[1]<=255&&
                elementColor[1]>=160&&elementColor[1]<=255&&inputColor[2]>=0&&inputColor[2]<=190&&elementColor[2]>=0&&elementColor[2]<=190){
            //cout<<"AMARILLO" << endl;
            return true;
        }
        else if(inputColor[0]>=0&&inputColor[0]<=200&&elementColor[0]>=0&&elementColor[0]<=200&&inputColor[1]>=170&&inputColor[1]<=255&&elementColor[1]>=170&&
                elementColor[1]<=255&&inputColor[2]>=0&&inputColor[2]<=190&&elementColor[2]>=0&&elementColor[2]<=190){
            //cout<<"VERDE" << endl;
            return true;
        }
        else if(inputColor[0]>=0&&inputColor[0]<=200&&elementColor[0]>=0&&elementColor[0]<=200&&inputColor[1]>=0&&inputColor[1]<=250&&
                elementColor[1]>=0&&elementColor[1]<=250&&inputColor[2]>=140&&inputColor[2]<=255&&elementColor[2]>=140&&elementColor[2]<=255||
                inputColor[0]>=150&&inputColor[0]<=255&&elementColor[0]>=150&&elementColor[0]<=255&&inputColor[1]>=0&&inputColor[1]<=90&&
                elementColor[1]>=0&&elementColor[1]<=90&&inputColor[2]>=90&&inputColor[2]<=255&&elementColor[2]>=90&&elementColor[2]<=255){
            //cout<<"AZUL" << endl;
            return true;
        }
        else if(inputColor[0]>=80&&inputColor[0]<=150&&elementColor[0]>=80&&elementColor[0]<=150&&inputColor[1]>=25&&inputColor[1]<=50&&
                elementColor[1]>=25&&elementColor[1]<=50&&inputColor[2]==0&&elementColor[2]==0){
            //cout<<"CAFE" << endl;
            return true;
        }
        else if(inputColor[0]>=0&&inputColor[0]<=230&&elementColor[0]>=0&&elementColor[0]<=230&&inputColor[1]>=0&&inputColor[1]<=230&&
                elementColor[1]>=0&&elementColor[1]<=230&&inputColor[2]>=0&&inputColor[2]<=230&&elementColor[2]>=0&&elementColor[2]<=230
                &&inputColor[0]==elementColor[0]&&inputColor[1]==elementColor[1]&&inputColor[2]==elementColor[2]){
            //cout<<"GRIS" << endl;
            return true;
        }
        else if(inputColor[0]>=230&&inputColor[0]<=250&&elementColor[0]>=230&&elementColor[0]<=250&&inputColor[1]>=230&&inputColor[1]<=250&&
                elementColor[1]>=230&&elementColor[1]<=250&&inputColor[2]>=230&&inputColor[2]<=250&&elementColor[2]>=230&&elementColor[2]<=250
                &&inputColor[0]==elementColor[0]&&inputColor[1]==elementColor[1]&&inputColor[2]==elementColor[2]){
            //cout<<"BLANCO" << endl;
            return true;
        }
        else{
            //cout<<"NO HAY MATCH" << endl;
            return false;
        }

    }

    void seleccion(xml_node<>* node, vector<string> pColors, vector<vector<double>>pPositions,SVG *pSVG){
        vector<int> inputColorConverted, elementColorConverted;
        for (node = node->first_node(); node != NULL; node = node->next_sibling()){
            if (node->type() == node_element){
                    for(int position=0;position<pColors.size();position++){
                        //cout << "entra al for" << endl;
                        if(node->first_attribute("fill")){
                            if(matchColor(pColors[position],node->first_attribute("fill")->value())){
                                //cout<<"MATCHED COLOR: "<<node->first_attribute("fill")->value()<<endl << endl;
                                matchPosition(node,pColors,pPositions,pColors[position],pSVG);
                            }
                        }
                        else if(node->first_attribute("stroke")){
                            if(matchColor(pColors[position],node->first_attribute("fill")->value())){
                                //cout<<"MATCHED COLOR" << endl;
                                matchPosition(node,pColors,pPositions,pColors[position],pSVG);
                            }
                        }
                        else if(node->first_attribute("style")){
                            //cout << "style" << endl;
                            string styleValue=node->first_attribute("style")->value();
                            if(styleValue.find_first_of("#")!=string::npos){
                                string hexColor=styleValue.substr(styleValue.find_first_of("#"),styleValue.find_first_of(";")-styleValue.find_first_of("#"));
                                if(matchColor(pColors[position],hexColor)){
                                    //cout<<"MATCHED COLOR";
                                    matchPosition(node,pColors,pPositions,pColors[position],pSVG);
                                }
                            }
                            // else{
                            //     seleccion(node,pColors,pPositions,pSVG);
                            // }
                        }
                        // else{
                        //     seleccion(node,pColors,pPositions,pSVG);
                        // }
                }
                seleccion(node,pColors,pPositions,pSVG);
            }
      }

    }
};

/*class Selection : public Observer {
private:
    AnimatorGenerator* subject;

public:
    Selection() {}
    ~Selection() {}

    Selection(AnimatorGenerator* pNewSubject){
        subject=pNewSubject;
    }

    void update(){
        //cout<<"Nuevo elemento fue seleccionado\n";
        Routing* newRouting=new Routing();
        ////cout<<subject->getSelectedElements().size();
        newRouting->start(subject->getSelectedElements());
    }
};*/

#endif
