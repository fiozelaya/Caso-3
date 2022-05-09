#ifndef __ANIMATOR_GENERATOR_HEADER__
#define __ANIMATOR_GENERATOR_HEADER__

#include "IObserverPattern.hpp"
#include "Selection.hpp"
#include "Routing.hpp"
#include "Generation.hpp"
#include "SvgElements.hpp"

/**
 * @brief class AnimatorGenerator it's the observer. It
 *        notifies when one process has finished so another
 *        can start.
 */
class AnimatorGenerator: public Observer{
private:
    Selection* selection;
    Routing* routing;
    Generation* generation;
    SVG svg;
    xml_document<> myDoc;

public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}

    void setSelection(Selection* newSelection){
        selection=newSelection;
    }

    void setRouting(Routing* newRouting){
        routing=newRouting;
    }

    void setGeneration(Generation* newGeneration){
        generation=newGeneration;
    }


    void start(xml_node<>* pNode, vector<string> pColors, vector<vector<double>> pPositions, SVG &pSVGdetails){
         /*
        Functioning: Call the startSelection function with its respective parameters.

        Input:
        -pNode
        -pColors
        -pPositions
        -pSVGdetails

        Output: N/A
        */
        svg = pSVGdetails;
        cout << "Iniciar seleccion..." << endl;
        selection->startSelection(pNode,pColors,pPositions,&pSVGdetails);
        int code = 1;
        int* codePointer = &code;

        selection->setSelectedElements(pSVGdetails.getVectorElements());
        selection->notify(codePointer);
        code = 2;
        routing->notify(codePointer);
        code = 0;
        generation->notify(codePointer);
    }

    void update(void* pCode) {
        /*
        Functioning: It will receive a code and depending on the number it will start with the corresponding function (routing or generation)

        Input:
        -pCode

        Output: N/A
        */
        // (int*) = castear el puntero void a puntero a int
        // *(int*) = valor del int al que apunta
        int value = *(int*)pCode;

        if (value == 0){
            cout << "Terminando..." << endl;
        }
        else if (value == 1){
            cout << "Iniciar enrutamiento..." << endl;
            routing->route(selection->getSelectedElements(), svg.getFrames(), svg.getDegrees(), svg.getHeight(), svg.getWidth());
        }
        else if (value == 2){
            cout << "Iniciar generacion..." << endl;
            generation->setFileName(svg.getFileName());
            generation->start(selection->getSelectedElements(), svg.getFrames());
        }
    }

};

#endif
