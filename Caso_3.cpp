#include <iostream>
#include "functions.hpp"
#include "path.hpp"
#include <vector>
//#include "svgPaths.hpp"

using namespace std;



int main()
{
  //char nombre='Images/gato1.svg';
    svgDetails mySvg;
    readFile(mySvg);
    cout<<mySvg.getHeight()<<"\n";
    cout<<mySvg.getWidth();

    return 0;
}
