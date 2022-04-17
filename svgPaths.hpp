#include <iostream>
#include <vector>
//#include "path.hpp"


//Falta interface observer

class Path{
    protected:
        vector<int> vectorX, vectorY;
        int posxInicial;
        int posyInicial;
        int posxFinal;
        int posyFinal;
        int posxActual;
        int posyActual;
        string color;
    public:
        Path(){};
        Path(int newYValue, int newXValue){};
        void setX(int newXValue){vectorX.push_back(newXValue);};
        void setY(int newYValue){vectorY.push_back(newYValue);};
        int setPosxInicial(int n){posxInicial = n;};
        int setPosxFinal(int n){posxFinal = n;};
        int setPosxActual(int n){posxActual = n;};
        int setPosyInicial(int n){posyInicial = n;};
        int setPosyFinal(int n){posyFinal = n;};
        int setPosyActual(int n){posyActual = n;};
        void setColor(string newColor){color=newColor;};
        vector<int> getVectorX(){return vectorX;};
        vector<int> getVectorY(){return vectorY;};
        string getColor(){return color;};
        int getPosxInicial(){return posxInicial;};
        int getPosxFinal(){return posxFinal;};
        int getPosxActual(){return posxActual;};
        int getPosyInicial(){return posyInicial;};
        int getPosyFinal(){return posyFinal;};
        int getPosyActual(){return posyActual;};
};

class svgDetails{
    protected:
        vector<Path> vectorPath;
        double width, height;
    public:
        svgDetails(){width=0; height=0;};
        void setWidth(double newWidth){width=newWidth;};
        void setHeight(double newHeight){height=newHeight;};
        void setPath(Path newPath){vectorPath.push_back(newPath);};
        double getWidth(){return width;};
        double getHeight(){return height;};

};


