/*

Caso 3 
Fiorella Zelaya
Ericka Yu Min Guo Chen

*/

#include <iostream>
#include "rapidxml/rapidxml_ext.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;

class Punto
{
public:
	Punto() = default;


private:
	int x;
    int y;
};


class Path
{
public:
    Path() = default;


private:
    string id;
    string opacity;
    string fill; //color
    string datos; //puntos y líneas
    string posInicial;
    string posDestino;
};

class AnimatorGenerator{
private:

public:
    AnimatorGenerator() = default;
};

class Seleccion{
private:

public:
    Seleccion() = default;

};

class Enrutamiento{
private:

public:
    Enrutamiento() = default;
};

class Generacion{
private:

public:
    Generacion() = default;
};


void main(){

}
