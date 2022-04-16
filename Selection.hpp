#include <thread>
#include <list>
class Selection: public Subject{
private:
    Observer* animator;
    list<Observer*> elementsList;

public:
    Selection() = default;
    ~Selection(){}
    void attach(Observer* element){
        elementsList.push_back(element);
    }
    void detach(Observer* whichElement){
        elementsList.remove(whichElement);
    }
    void notify(void* curso){
        cout << "seleccion" << endl;
        for (Observer* actual : elementsList) {
            thread t(&Observer::update, actual, curso); // parametros = (direccionDeMetodo, instancia/objeto, parametro)
            t.join(); // espere a que t termine
        }
        //animator->update(curso);
    }

};
