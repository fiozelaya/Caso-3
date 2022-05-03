#ifndef __ROUTING_HEADER__
#define __ROUTING_HEADER__

// #include "IObserverPattern.hpp"
// #include "svgPaths.hpp"
// #include <iostream>
// #include <vector>
// #include <math.h>
#include "routes_functions.hpp"

using namespace std;

class Routing: public Subject{
private:
    Observer* animator;
    vector<Element> vectorElements;
public:
    Routing() = default;
    Routing(vector<Element> pNewVectorElements){vectorElements = pNewVectorElements;};
    ~Routing(){}
    void attach(Observer* observer){
        animator = observer;
    }
    void detach(Observer* observer){

    }
    void route(vector<Element*> pVector, int pFrames, double pDegrees, int pHeight, int pWidth){
        bool rect;
        for (int i = 0; i < pVector.size(); i++){
            if (rand() % 2 == 0){
                rect = true;
            }
            else{
                rect = false;
            }
            pVector.at(i)->setRect(false);

            if(pDegrees <= 90){ //I cuadrante
                determinePoints90(pVector.at(i), pWidth, pDegrees, pFrames);
            }
            else if (pDegrees > 90 && pDegrees <= 180){ //II cuadrante
                determinePoints180(pVector.at(i), pDegrees, pFrames);
            }
            else if (pDegrees > 180 && pDegrees <= 270){ //III cuadrante
                determinePoints270(pVector.at(i), pHeight, pDegrees, pFrames);
            }
            else{ //IV cuadrante
                determinePoints360(pVector.at(i), pWidth, pHeight, pDegrees, pFrames);
            }

            vector<vector<int>> movimientos = pVector.at(i)->getMovements();
            vector<vector<int>> movimientos2 = pVector.at(i)->getMovements2();

            cout << "for" << movimientos.size() << endl;
            for (int i = 0; i < movimientos.size(); i++){
                cout << i + 1 << ". " << movimientos[i][0] << " " << movimientos[i][1] << endl;
                
            }
            cout << pVector.at(i)->getAttribute() << endl;
            cout << movimientos2.size() << endl;
            if (pVector.at(i)->getAttribute() == "line"){
                for (int i = 0; i < movimientos2.size(); i++){
                    cout << i + 1 << ". " << movimientos2[i][0] << " " << movimientos2[i][1] << endl;
                }
            }
        }
    }
    void notify(void* pCode){
        cout << "enrutamiento" << endl;
        animator->update(pCode);
    }
};

#endif