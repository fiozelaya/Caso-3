/*

Caso 3 
Fiorella Zelaya
Ericka Yu Min Guo Chen

*/

#include <iostream>

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
}
