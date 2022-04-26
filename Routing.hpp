#ifndef __ROUTING_HEADER__
#define __ROUTING_HEADER__

// #include "IObserverPattern.hpp"
// #include "svgPaths.hpp"
// #include <iostream>
// #include <vector>
// #include <math.h>
#include "routes_functions.hpp"

using namespace std;

class Enrutamiento: public Subject{
private:
    Observer* animator;
    vector<void*> vectorElements;
public:
    Enrutamiento() = default;
    ~Enrutamiento(){}
    void attach(Observer* observer){
        animator = observer;
    }
    void detach(Observer* observer){

    }
    void enrutar(vector<Element> &pVector, int pFrames, double pDegrees, int pHeight, int pWidth){
        bool rect;
        for (int i = 0; i < pVector.size(); i++){
            if (rand() % 2 == 0){
                rect = true;
            }
            else{
                rect = false;
            }
            pVector[i].setRect(false);

            if(pDegrees <= 90){ //I cuadrante
                determinePoints90(pVector[i], pWidth, pDegrees, pFrames);
            }
            else if (pDegrees > 90 && pDegrees <= 180){ //II cuadrante
                determinePoints180(pVector[i], pDegrees, pFrames);
            }
            else if (pDegrees > 180 && pDegrees <= 270){ //III cuadrante
                determinePoints270(pVector[i], pHeight, pDegrees, pFrames);
            }
            else{ //IV cuadrante
                determinePoints360(pVector[i], pWidth, pHeight, pDegrees, pFrames);
            }

            vector<vector<int>> movimientos = pVector[i].getMovements();
            cout << "for" << movimientos.size() << endl;
            for (int i = 0; i < movimientos.size(); i++){
                cout << i + 1 << ". " << movimientos[i][0] << " " << movimientos[i][1] << endl;
            }
        }
    }
    void notify(void* element){
        cout << "enrtut" << endl;
        animator->update(nullptr);
    }
};

#endif