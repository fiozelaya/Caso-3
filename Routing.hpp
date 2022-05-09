#ifndef __ROUTING_HEADER__
#define __ROUTING_HEADER__

#include "routing_functions.hpp"

using namespace std;

class Routing: public Subject{
private:
    Observer* animator;
    vector<Element> vectorElements;
public:
    //Constructores
    Routing() = default;
    Routing(vector<Element> pNewVectorElements){vectorElements = pNewVectorElements;};
    ~Routing(){}

    void attach(Observer* observer){
        animator = observer;
    }
    
    void detach(Observer* observer){

    }

    void route(vector<Element*> pVector, int pFrames, double pDegrees, int pHeight, int pWidth){
        /*
        Functioning: This function goes through the selected Elements list and gets the X and Y points for each frame
                     that will be generated.

        Input:
        -pVector -> Vector of the selected Elements
        -pFrames -> number of frames
        -pDegrees -> degrees that will be used to calculate the rect inclination
        -pHeight -> height of the svg image
        -pWidth -> width of the svg image


        Output: Each element of the list will have its own vector with the corresponding points (x,y) for each frame.

        */

        bool rect;
        for (int i = 0; i < pVector.size(); i++){ //decides randomly if the elements will move through a straight or curved line.
            if (rand() % 2 == 0){
                rect = true;
            }
            else{
                rect = false;
            }
            pVector.at(i)->setRect(rect);
            pVector.at(i)->setAuxXCoord(pVector.at(i)->getXCoord());
            pVector.at(i)->setAuxYCoord(pVector.at(i)->getYCoord());

            if(pDegrees <= 90){ //I cuadrante
             //cout << "90 degrees " << pVector.at(i)->getAttribute() << endl;
                determinePoints90(pVector.at(i), pWidth, pDegrees, pFrames);
            }
            else if (pDegrees > 90 && pDegrees <= 180){ //II cuadrante
            //cout << "180 degrees" << endl;
                determinePoints180(pVector.at(i), pDegrees, pFrames);
            }
            else if (pDegrees > 180 && pDegrees <= 270){ //III cuadrante
            //cout << "270 degrees" << endl;
                determinePoints270(pVector.at(i), pHeight, pDegrees, pFrames);
            }
            else{ //IV cuadrante
            //cout << "360 degrees" << endl;
                determinePoints360(pVector.at(i), pWidth, pHeight, pDegrees, pFrames);
            }

            //vector<vector<int>> movimientos = pVector.at(i)->getMovements();
            //vector<vector<int>> movimientos2 = pVector.at(i)->getMovements2();

            // cout << "for" << movimientos.size() << endl;
            // for (int i = 0; i < movimientos.size(); i++){
            //     cout << i + 1 << ". " << movimientos[i][0] << " " << movimientos[i][1] << endl;
                
            // }
            // cout << pVector.at(i)->getAttribute() << endl;
            // cout << movimientos2.size() << endl;
            // if (pVector.at(i)->getAttribute() == "line"){
            //     for (int i = 0; i < movimientos2.size(); i++){
            //         cout << i + 1 << ". " << movimientos2[i][0] << " " << movimientos2[i][1] << endl;
            //     }
            // }
        }
    }

    void notify(void* pCode){
        animator->update(pCode);
    }
};

#endif