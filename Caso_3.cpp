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
//#include "svgPaths.hpp"

using namespace std;

int main()
{
  //char nombre='Images/gato1.svg';
    svgDetails mySvg;
    file<> file("Images/girl-1.svg");
    xml_document<> myDocument;
    myDocument.parse<0>(file.data());
    //extractXMLData(&myDocument,&mySvg);//readFile

    readFile(mySvg,file,&myDocument);

    cout<<mySvg.getHeight()<<"\n";
    cout<<mySvg.getWidth();

    return 0;
}
class Punto
{
public:
	Punto() = default;


private:
	int x;
    int y;
};

/*
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
};*/

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

