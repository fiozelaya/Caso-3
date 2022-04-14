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
