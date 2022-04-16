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
