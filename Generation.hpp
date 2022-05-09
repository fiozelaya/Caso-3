 #ifndef __GENERATION_HEADER__
 #define __GENERATION_HEADER__

 #include <vector>
 #include "SvgElements.hpp"
 #include <queue>
 #include <thread>
 #include <iostream>
 #include <chrono>
 //#include <Windows.h>
 //#include <unistd.h>


 class Generation: public Subject{
 private:
     string filename;
     Observer* animator;
     queue<Element*> queueOfElements;//Declarando la cola de strings
     bool createAnotherSVG;
     int currentFrame;
     xml_document<> myDoc;
     Element *currentElement;
 public:
     Generation(){createAnotherSVG = false; currentFrame = 0;}
     void attach(Observer* pObserver){
         animator = pObserver;
     }
     void detach(Observer* pObserver){

     }
     void notify(void* pCode){
        animator->update(pCode);
     }

     void setFileName(string pNewFileName){filename = pNewFileName;}

     
     void producer(vector<Element*> &pElementsList, int pFrames){ 
         /*
        Función producer: Process the data that is going to be use by the consumer.
                        This functions goes through the points of each elements, so
                        it selects only the points that correspond to the current frame.
                            It has the following structure:

            {  { {x,y}, {}, {}, {} }, { {x,y}, {}, {}, {} }, { {x,y}, {}, {}, {} }  }
            ^  j0  i0   i1  i2  i3    j1 i0    i1  i2  i3    j2  i0   i1  i2  i3    ^

            i = points to the element in a certain frame
            j = goes through all the points of all elements

        parameters:
        -pElementsList -> list of selected elements
        -pFrames -> frames

        Output: N/A


        */
         int currentElementPointer = 0, auxFrames = pFrames;
         int newX, newY;
         if (pElementsList.size() == 0){
            currentFrame = -1;
            return;
         }

         while(currentFrame < pFrames){
                currentElement =  pElementsList.at(currentElementPointer);
                vector<vector<int>> movimientos = currentElement->getMovements();
                if(movimientos.size() == 0){
                    currentElementPointer++;
                    continue;
                }

                newX = currentElement->getMovements().at(currentFrame).at(0); // se agarra el elemento j de la lista, y se le asigna la coordenada x del punto currentFrame (frame) de la lista de movimientos
                newY = currentElement->getMovements().at(currentFrame).at(1); // se agarra el elemento j de la lista, y se le asigna la coordenada y del punto i (frame) de la lista de movimientos

                currentElement->setXCoord(newX);
                currentElement->setYCoord(newY);


             if(currentElementPointer != pFrames){
                if (currentElementPointer+1 >= pElementsList.size()){
                    currentElementPointer = 0;
                    currentFrame++;
                    Generation::createAnotherSVG = true;
                    generation();
                    //queueOfElements.push(currentElement); //push a la cola de eventos
                    continue;
                }
                else{
                    currentElementPointer++;
                    generation();
                    //queueOfElements.push(currentElement); //push a la cola de eventos
                    continue;
                }


             }

             currentFrame++;
             currentElementPointer = currentFrame;
             createAnotherSVG = true; //falta ponerlo de nuevo en false
             //queueOfElements.push(currentElement); //push a la cola de eventos
             generation();
         }

         currentFrame = -1;
     }

     
     void generation(){
         /*
        Function: This function generates de XML file, or adds the current element
                  to the XML file that it's going to be generated.
        
        parameters: N/A

        Output: N/A

        */

        currentElement->createSVGAttribute(&myDoc); //añade el elemento actual

        if (createAnotherSVG){
             string fileName = "svg";
             fileName.append(to_string(currentFrame));
             fileName.append(".xml");
             fileName = "svganimation/images/svg/" + fileName;

             ofstream theNewFile(fileName); //Crea el archivo en la ubicación indicada
             stringstream ss;
             ss << *myDoc.first_node(); //Convierte el árbol DOM en un stringstream
             string stringXML = ss.str(); //Convierte de stringstream a string
             theNewFile << stringXML; //Escribe el string en el archivo
             theNewFile.close();

             createAnotherSVG = false;
         }
     }

     void consumer(){
          /*
        Function: This function is the consumer. It calls the function generation() when
                  there's something in the queue.
        
        parameters: N/A

        Output: N/A

        */
         bool finishLoop=false;
         while(!finishLoop){
             std::this_thread::sleep_for(std::chrono::milliseconds(100));
             //sleep(1);
             if(!queueOfElements.empty()){
                 Generation::generation();
                 queueOfElements.pop();
             }
             if(currentFrame == -1 && queueOfElements.empty()){
                 break;
             }

         }
     }

     void start(vector<Element*> pElementsList, int pFrames){
          /*
        Function: This function starts the generation process. It reads the
                  SVG file and saves it so it can be modified. 
        
        parameters: 
        -pElementsList -> list of selected elements
        -pFrames -> frames

        Output: N/A

        */
         char* svgFileName = new char[filename.size() + 1];  // Create char buffer to store string copy
         strcpy (svgFileName, filename.c_str());
         file<> file(svgFileName);
         Generation::myDoc.parse<0>(file.data());

         //thread thread1(&consumer, this);
         producer(pElementsList, pFrames);

        // //join permite que un hilo espere a que otro termine su ejecución
        // //hilo1.join();
         //thread1.join();

     }

 };

 #endif
