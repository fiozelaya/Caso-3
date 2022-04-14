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
