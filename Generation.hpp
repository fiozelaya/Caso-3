 #ifndef __GENERATION_HEADER__
 #define __GENERATION_HEADER__

 #include <vector>
 #include "svgPaths.hpp"
 #include <queue>
 #include <thread>
 #include <iostream>
 //#include <unistd.h>


 class Generation: public Subject{
 private:
     Observer* animator;
     //vector<vector<vector<Element>>> elementsByFrame;
     queue<Element> queueOfElements;//Declarando la cola de strings
     xml_document<> myDoc;
     bool createAnotherSVG;
     int currentFrame;
     Element *currentElement;
 public:
     Generation(){createAnotherSVG = false; currentFrame = 0;}
     //void setMyDoc(xml_document<> *pMyDoc){myDoc = pMyDoc;};
     void attach(Observer* pObserver){
         animator = pObserver;
     }
     void detach(Observer* pObserver){

     }
     void notify(void* pCode){
         cout << "generacion" << endl;
         //animator->update(nullptr);
     }

     /*
     Función producer: Procesa los datos que van a ser utilizados por el consumer
     @param: Lista de elementos seleccionados, frames

     Esta función recorre una estructura implícita del siguiente tipo:

         {  { {x,y}, {}, {}, {} }, { {x,y}, {}, {}, {} }, { {x,y}, {}, {}, {} }  } 
         ^  j0  i0   i1  i2  i3    j1 i0    i1  i2  i3    j2  i0   i1  i2  i3    ^

         i = punto del elementos que corresponde al #frame que se está procesando
         j = recorre los elementos de la lista

    
     */
     void producer(vector<Element> &pElementsList, int pFrames){ //producer ????
         int currentElementPointer = 0, auxFrames = pFrames;
         int newX, newY;
         bool createAnotherSVG = true;
         while(true){
             currentElement =  &pElementsList[currentElementPointer];
             newX = currentElement->getMovements()[currentFrame][0]; // se agarra el elemento j de la lista, y se le asigna la coordenada x del punto currentFrame (frame) de la lista de movimientos
             newY = currentElement->getMovements()[currentFrame][1]; // se agarra el elemento j de la lista, y se le asigna la coordenada y del punto i (frame) de la lista de movimientos
             currentElement->setXCoord(newX);
             currentElement->setYCoord(newY);

             queueOfElements.push(*currentElement); //push a la cola de eventos

             if(currentElementPointer != pFrames){ 
                 currentElementPointer++;
                 continue;
             }
             currentFrame++;
             currentElementPointer = currentFrame;
             createAnotherSVG = true; //falta ponerlo de nuevo en false
         }

         currentFrame = -1;
     }
     void generation(){
         if (createAnotherSVG){
             string fileName = "svg";
             fileName.append(to_string(currentFrame));
             fileName.append(".xml");
             ofstream theNewFile(fileName); //Crea el archivo en la ubicación indicada
             stringstream ss;
             ss << myDoc.first_node(); //Convierte el árbol DOM en un stringstream
             string stringXML = ss.str(); //Convierte de stringstream a string
             theNewFile << stringXML; //Escribe el string en el archivo
             theNewFile.close();

             createAnotherSVG = false;
         }
         else{
             string attribute = "";
             //añadir el elemento al del archivo svg actual
             currentElement->createSVGAttribute(&myDoc);

             // if (attribute == "polygon"){
             //     xml_attribute<> *points = myDoc->allocate_attribute("points", "5");
             //     xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");
             // }
             // else if (attribute == "polyline"){
             //     xml_attribute<> *points = myDoc->allocate_attribute("points", "5");
             //     xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");

             // }
             // else if (attribute == "path"){
             //     xml_attribute<> *d = myDoc->allocate_attribute("d", "5");
             //     xml_attribute<> *fill = myDoc->allocate_attribute("fill", "5");

             // }
            
         }
     }

     void consumer(){
         bool finishLoop=false;
         while(!finishLoop){
             //sleep(4);
             if(!queueOfElements.empty()){
                 generation();
             }
             if(currentFrame == -1){
                 break;
             }

         }
     }

     void start(xml_document<> myDoc, vector<Element> &pElementsList, int pFrames){
         //Declarando los hilos
         //thread hilo1(productor);

         thread thread1(&Generation::consumer, this);
         producer(pElementsList, pFrames);

         //join permite que un hilo espere a que otro termine su ejecución
         //hilo1.join();
         thread1.join();
     }
        
 };

 #endif