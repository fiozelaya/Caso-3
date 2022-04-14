class AnimatorGenerator: public Observer{
private:

public:
    AnimatorGenerator() = default;
    ~AnimatorGenerator(){}
    void update(){
        cout << "nuevo update" << endl;
    }

};
