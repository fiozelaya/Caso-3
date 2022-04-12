#include <iostream>
#include <vector>
//#include "path.hpp"


//Falta interface observer

class Path{
    protected:
        vector<int> vectorX, vectorY;
        string color;
    public:
        Path(){};
        Path(int newYValue, int newXValue){};
        void setX(int newXValue){vectorX.push_back(newXValue);};
        void setY(int newYValue){vectorY.push_back(newYValue);};
        void setColor(string newColor){color=newColor;};
        vector<int> getVectorX(){return vectorX;};
        vector<int> getVectorY(){return vectorY;};
        string getColor(){return color;};
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


