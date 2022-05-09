#ifndef __SVG_HEADER__
#define __SVG_HEADER__

#include "SvgElements.hpp"

/**
 * @brief class SVG. It saves important aspects of the SVG file.
 * 
 */
class SVG{
    private:
        double height, width;
        int frames, degrees;
        string filename;
        vector<Element*>selectedElements;
        xml_document<> *document;
    public:
        SVG(){};
        void setHeight(double pNewHeight){height=pNewHeight;};
        void setWidth(double pNewWidth){width=pNewWidth;};
        void setVectorElements(vector<Element*> pVectorElements){selectedElements=pVectorElements;};
        void setElement(Element* pElement){selectedElements.push_back(pElement);};
        void setFrames(int pNewFrames){frames = pNewFrames;};
        void setDegrees(int pNewDegrees){degrees = pNewDegrees;};
        void setDoc(xml_document<> *pNewDocument){document = pNewDocument;};
        void setFileName(string pNewFileName){filename = pNewFileName;}
        double getHeight(){return height;};
        double getWidth(){return width;};
        int getFrames(){return frames;};
        int getDegrees(){return degrees;};
        xml_document<>* getDoc(){return document;};
        vector<Element*> getVectorElements(){return selectedElements;};
        string getFileName(){return filename;}

};

#endif