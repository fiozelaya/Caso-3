#ifndef __ANIMATOR_GENERATOR_HEADER__
#define __ANIMATOR_GENERATOR_HEADER__

#include "IObserverPattern.hpp"
#include "Selection.hpp"
#include "Routing.hpp"
#include <iostream>

#include "svgPaths.hpp"

class AnimatorGenerator: public Observer{
private:
    Selection* selection;
    Routing* routings;
    string hola;

public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}
    /*void update(){
        cout << "nuevo update" << endl;
    }*/

    void setSelection(Selection* newSelection){
        selection=newSelection;
        selection->prueba();
    }

    string getSelection(){
        return selection->prueba2();
    }

    void setSelectedPoints(string pSelectedPoints){
        hola=pSelectedPoints;
        cout<<hola;
    }

    void update(void* curso) {
        // (int*) = castear el puntero void a puntero a int
        // *(int*) = valor del int al que apunta
        int value = *(int*)curso;

        if (value == 0)
            cout << "Se ha publicado una nueva tarea del curso Analisis de Algoritmos" << endl;
        else if (value == 1)
            cout << "Se ha publicado una nueva tarea del curso Bases de Datos 1" << endl;

        else if (value == 2)
            cout << "Se ha publicado una nueva tarea del curso Ambiente Humano" << endl;
    }

};

/*
class AnimatorGenerator: public Observer{
private:
    // Selection *seleccion;
    // Routing *enrutamiento;
    // Generation *generacion;
public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}
    /*void update(){
        cout << "nuevo update" << endl;
    }*/
    /*void update(void* curso) {
        // (int*) = castear el puntero void a puntero a int
        // *(int*) = valor del int al que apunta
        int value = *(int*)curso;

        if (value == 0)
            cout << "Se ha publicado una nueva tarea del curso Analisis de Algoritmos" << endl;
        else if (value == 1)
            //cout << "Se ha publicado una nueva tarea del curso Bases de Datos 1" << endl;
            prueba();
        else if (value == 2)
            cout << "Se ha publicado una nueva tarea del curso Ambiente Humano" << endl;
    }

};*/

#endif
