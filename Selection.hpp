#ifndef __SELECTION_HEADER__
#define __SELECTION_HEADER__

#include <thread>
#include <list>
class Selection: public Subject{
private:
    Observer* animator;
    list<Observer*> elementsList;

public:
    Selection() = default;
    ~Selection(){}
    void attach(Observer* pElement){
        elementsList.push_back(pElement);
    }
    void detach(Observer* pWhichElement){
        elementsList.remove(pWhichElement);
    }
    void notify(void* pCurso){
        cout << "seleccion" << endl;
        for (Observer* actual : elementsList) {
            thread t(&Observer::update, actual, pCurso); // parametros = (direccionDeMetodo, instancia/objeto, parametro)
            t.join(); // espere a que t termine
        }
        //animator->update(pCurso);
    }

};

#endif