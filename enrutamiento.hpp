#include <vector>
#include <math.h>

class Enrutamiento: public Subject{
private:
    Observer* animator;
    vector<Path> vectorElementos;
public:
    Enrutamiento() = default;
    ~Enrutamiento(){}
    void attach(Observer* observer, vector<Path> pVector){
        animator = observer;
        vectorElementos = pVector;
    }
    void detach(Observer* observer){

    }
    void enrutar(vector<Path> vector){
        bool lineaRecta;
        int movimientoX, movimientoY;
        for (int i = 0; i < vector.size(); i++){
            if (rand() % 2 == 0){
                lineaRecta = true;
            }
            else{
                lineaRecta = false;
            }

            if (lineaRecta){
                vector[i].setPosxActual(vector[i].getPosyInicial() + (width - vector[i].getPosxInicial()) / frames); //FALTA TOMAR EN CUENTA LOS GRADOS 
                vector[i].setPosyActual(vector[i].getPosyInicial() + (width - vector[i].getPosxInicial()) / frames); // puede funcionar f(x) = x (se multiplica por idk)
            }
            else{

            }
        }
    }
    void notify(){
        cout << "enrtut" << endl;
        enrutar(vectorElementos);
        animator->update();
    }
};
