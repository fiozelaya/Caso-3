Caso_3: Caso_3.o functions.hpp IObserverPattern.hpp path.hpp
	g++ Caso_3.o functions.hpp IObserverPattern.hpp path.hpp -o Caso_3

Caso_3.o: Caso_3.cpp
	g++ -c Caso_3.cpp

