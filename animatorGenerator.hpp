#ifndef __ANIMATOR_GENERATOR_HEADER__
#define __ANIMATOR_GENERATOR_HEADER__

#include "IObserverPattern.hpp"
#include "Selection.hpp"
#include "Routing.hpp"
#include "Generation.hpp"
#include <iostream>

#include "svgPaths.hpp"

class AnimatorGenerator: public Observer{
private:
    Selection* selection;
    Routing* routing;
    Generation* generation;
    SVG svg;
    xml_document<> myDoc;
    string hola;

public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}
    /*void update(){
        cout << "nuevo update" << endl;
    }*/

    void setSelection(Selection* newSelection){
        selection=newSelection;
        //selection->prueba();
    }

    void setRouting(Routing* newRouting){
        routing=newRouting;
        //routing->route();
    }

    void setGeneration(Generation* newGeneration){
        generation=newGeneration;
        //generation->start();
    }

    string getSelection(){
        return selection->prueba2();
    }

    void setSelectedPoints(string pSelectedPoints){
        hola=pSelectedPoints;
        cout<<hola;
    }

    void start(xml_node<>* pNode, vector<string> pColors, vector<vector<double>> pPositions, SVG &pSVGdetails){
        svg = pSVGdetails;
        cout << "seleccion" << endl;
        selection->seleccion(pNode,pColors,pPositions,&pSVGdetails);
        int code = 1;
        int* codePointer = &code;

        selection->setSelectedElements(pSVGdetails.getVectorElements());
        selection->notify(codePointer);
        code = 2;
        routing->notify(codePointer);
        // code = 0;
        // generation->notify(codePointer);*/
    }

    void update(void* curso) {
        // (int*) = castear el puntero void a puntero a int
        // *(int*) = valor del int al que apunta
        int value = *(int*)curso;

        if (value == 0){
            cout << "Terminando..." << endl;
        }
        else if (value == 1){
            cout << "Iniciar enrutamiento..." << endl;
            routing->route(selection->getSelectedElements(), svg.getFrames(), svg.getDegrees(), svg.getHeight(), svg.getWidth());
        }
        else if (value == 2){
            cout << "Iniciar generacion..." << endl;
            generation->start(selection->getSelectedElements(), svg.getFrames());
        }
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
