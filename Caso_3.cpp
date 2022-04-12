/*
<<<<<<< HEAD
=======

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
>>>>>>> master

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
//#include "svgPaths.hpp"

using namespace std;

class Punto
{
public:
	Punto() = default;


private:
	int x;
    int y;
};


class Seleccion: public Subject{
private:
    Observer* animator;
public:
    Seleccion() = default;
    ~Seleccion(){}
    void attach(Observer* observer){
        animator = observer;
    }
    void detach(Observer* observer){

    }
    void notify(){
        cout << "seleccion" << endl;
        animator->update();
    }

};

class Enrutamiento: public Subject{
private:
    Observer* animator;
public:
    Enrutamiento() = default;
    ~Enrutamiento(){}
    void attach(Observer* observer){
        animator = observer;
    }
    void detach(Observer* observer){

    }
    void notify(){
        cout << "enrtut" << endl;
        animator->update();
    }
};

class Generacion: public Subject{
private:
    Observer* animator;
public:
    Generacion() = default;
    ~Generacion(){}
    void attach(Observer* observer){
        animator = observer;
    }
    void detach(Observer* observer){

    }
    void notify(){
        cout << "generacion" << endl;
        animator->update();
    }
};

class AnimatorGenerator: public Observer{
private:

public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}
    void update(){
        cout << "nuevo update" << endl;
    }

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
