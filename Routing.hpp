#ifndef __ROUTING_HEADER__
#define __ROUTING_HEADER__
# define M_PI 3.14159265358979323846

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
    void enrutar(vector<Element> pVector, int frames, double degrees, int height, int width){
        bool lineaRecta;
        for (int i = 0; i < pVector.size(); i++){
            if (rand() % 2 == 0){
                lineaRecta = true;
            }
            else{
                lineaRecta = false;
            }
            if(degrees <= 90){ //I cuadrante
                determinePoints90(pVector[i], width, degrees, frames);
            }
            else if (degrees > 90 && degrees <= 180){ //II cuadrante
                determinePoints180(pVector[i], degrees, frames);
            }
            else if (degrees > 180 && degrees <= 270){ //III cuadrante
                determinePoints270(pVector[i], height, degrees, frames);
            }
            else{ //IV cuadrante
                determinePoints360(pVector[i], width, height, degrees, frames);
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