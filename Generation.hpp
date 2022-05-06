 #ifndef __GENERATION_HEADER__
 #define __GENERATION_HEADER__

 #include <vector>
 #include "svgPaths.hpp"
 #include <queue>
 #include <thread>
 #include <iostream>
 //#include <Windows.h>
 //#include <unistd.h>


 class Generation: public Subject{
 private:
     Observer* animator;
     //vector<vector<vector<Element>>> elementsByFrame;
     queue<Element> queueOfElements;//Declarando la cola de strings
     bool createAnotherSVG;
     int currentFrame;
     xml_document<> myDoc;
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


     xml_node<>* findGNode(xml_node<>* pNode){
            xml_node<>* currentNode = pNode;
            while(true){
                if (currentNode->next_sibling() == NULL){
                    if (currentNode->first_node()->name() == (string)"path"){
                        //cout << "fin" << endl;
                        return currentNode;
                    }
                    else{
                        //cout << "next child" << endl;
                        currentNode = currentNode->first_node();
                    }
                }
                else{
                    //cout << "next sibling" << endl;
                    currentNode = currentNode->next_sibling();
                }
            }
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
     void producer(vector<Element*> &pElementsList, int pFrames){ //producer ????
         int currentElementPointer = 0, auxFrames = pFrames;
         int newX, newY;

         while(currentFrame < pFrames){
                cout << "while " << currentFrame << " " << currentElementPointer << endl;
                currentElement =  pElementsList.at(currentElementPointer);
                cout << currentElement->getAttribute() << endl;
                vector<vector<int>> movimientos = currentElement->getMovements();

                newX = currentElement->getMovements().at(currentFrame).at(0); // se agarra el elemento j de la lista, y se le asigna la coordenada x del punto currentFrame (frame) de la lista de movimientos
                newY = currentElement->getMovements().at(currentFrame).at(1); // se agarra el elemento j de la lista, y se le asigna la coordenada y del punto i (frame) de la lista de movimientos

                currentElement->setXCoord(newX);
                currentElement->setYCoord(newY);

                
                //Sleep(1000);
             

             if(currentElementPointer != pFrames){ 
                if (currentElementPointer+1 >= pElementsList.size()){
                    currentElementPointer = 0;
                    currentFrame++;
                    Generation::createAnotherSVG = true;
                    // initDocument();
                    generation();
                    cout << "agregando aqueue" << endl;
                    //queueOfElements.push(*currentElement); //push a la cola de eventos
                    cout << "limite" << endl;
                    continue;
                }
                else{
                    currentElementPointer++;
                    generation();
                    //queueOfElements.push(*currentElement); //push a la cola de eventos
                    continue;
                }

                
             }

             currentFrame++;
             currentElementPointer = currentFrame;
             createAnotherSVG = true; //falta ponerlo de nuevo en false
             cout << "true!!!" << endl;
             generation();
         }

         currentFrame = -1;
     }
     void generation(){
        //  xml_document<> myDoc;
        //  file<> file("Images/passenger-1.svg");
        //  myDoc.parse<0>(file.data());

        cout << "bandera: " << createAnotherSVG << endl;
        string attribute = "";
        //añadir el elemento al del archivo svg actual

        currentElement->createSVGAttribute(&myDoc);

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
             cout << "crear" << endl;

            //  string strXML;
            // print(back_inserter(strXML), myDoc, 0); //Copia el texto del Document en la variable
            // cout << strXML << endl;

             createAnotherSVG = false;
         }
     }

     void consumer(){
         bool finishLoop=false;
         while(!finishLoop){
             //sleep(4);
             if(!queueOfElements.empty()){
                 cout << "entro al queue" << endl;
                 Generation::generation();
                 queueOfElements.pop();
             }
             if(currentFrame == -1){
                 cout << "stop while" << endl;
                 break;
             }

         }
     }

     void start(vector<Element*> pElementsList, int pFrames){
         //Declarando los hilos
         //thread hilo1(productor);
         file<> file("Images/passenger-1.svg");
         Generation::myDoc.parse<0>(file.data());
        //  extractXMLData(&myDoc);

        //  return;
         //thread thread1(&consumer, this);
         producer(pElementsList, pFrames);

         //join permite que un hilo espere a que otro termine su ejecución
         //hilo1.join();
         //thread1.join();
     }
        
 };

 #endif