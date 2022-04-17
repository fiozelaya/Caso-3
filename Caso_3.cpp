/*

Caso 3
Fiorella Zelaya
Ericka Yu Min Guo Chen

*/

#include "rapidxml/rapidxml_ext.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include <iostream>
#include "functions.hpp"
#include "path.hpp"
#include <vector>
#include "IObserverPattern.hpp"
#include "animatorGenerator.hpp"
#include "seleccion.hpp"
#include "enrutamiento.hpp"
#include "generacion.hpp"
//#include "svgPaths.hpp"

using namespace std;

int grados = 10;
int frames = 40;
int width;
int height;

class Punto
{
public:
	Punto() = default;


private:
	int x;
    int y;
};

int main()
{
  //char nombre='Images/gato1.svg';
    // svgDetails mySvg;
    // readFile(mySvg);
    // cout<<mySvg.getHeight()<<"\n";
    // cout<<mySvg.getWidth();

    AnimatorGenerator* animator = new AnimatorGenerator();

    Seleccion* seleccion = new Seleccion();
    Enrutamiento* enrutamiento = new Enrutamiento();
    Generacion* generacion = new Generacion();

    seleccion->attach(animator);
    enrutamiento->attach(animator);
    generacion->attach(animator);

    seleccion->notify();
    enrutamiento->notify();
    generacion->notify();

    return 0;
}
