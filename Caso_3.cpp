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
#include "AnimatorGenerator.hpp"
#include "Selection.hpp"
//#include "Routing.hpp"
//#include "Generation.hpp"
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

/*
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

};*/

/*
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
*/

/*
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

*/

/*
class AnimatorGenerator: public Observer{
private:

public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}
    void update(){
        cout << "nuevo update" << endl;
    }

};
*/



#include <vector>
#include <queue>


void prueba2(queue<string> &cola){
    if(cola.empty()){
        cout<<"vacia";
    }
    else{cout<<"con algo";}
}

int main()
{
  //char nombre='Images/gato1.svg';
    // svgDetails mySvg;
    // readFile(mySvg);
    // cout<<mySvg.getHeight()<<"\n";
    // cout<<mySvg.getWidth();
    //AnimatorGenerator* animator=new AnimatorGenerator();
    //Subject* seleccion = new Selection();
    int curso = 2;
    int* cursoPointer = &curso;
    //animator->notify(cursoPointer);

/*
    Circle* circulo=new Circle();
    circulo->setXCoord(3);
    cout<<circulo->getXCoord();*/

    AnimatorGenerator* animator = new AnimatorGenerator();

    Selection* seleccion = new Selection();
    seleccion->attach(animator);
    seleccion->notify(cursoPointer);
    curso=1;
    seleccion->notify(cursoPointer);

    //queue<string> cola;
    //cola.push("h");
    //prueba2(cola);
    //cola.push("hola");
    //prueba2(cola);
   /* Enrutamiento* enrutamiento = new Enrutamiento();
    Generacion* generacion = new Generacion();

    seleccion->attach(animator);
    enrutamiento->attach(animator);
    generacion->attach(animator);

    seleccion->notify();
    enrutamiento->notify();
    generacion->notify();*/
/*
    Circle circulo(55);
    circulo.setArea();
    cout<<circulo.getString();

    Rectangle rectangulo;
    rectangulo.setSide(5);
    rectangulo.setWidth(5);
    rectangulo.setArea();
    cout<<rectangulo.getString();*/
/*
    vector<vector<int>> vectorPrueba;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vectorPrueba.push_back(a);

    cout<<vectorPrueba.at(0)[1];*/
    //circulo->setSide(132);
    //cout<<circulo->getSide();


    return 0;
}
