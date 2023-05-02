main: Funkcijos.o Laboratorinis_v1.2.cpp
	g++ -O3 -o main Laboratorinis_v1.2.cpp Funkcijos.o
Funkcijos.o: Funkcijos.cpp
	g++ -O3 -c Funkcijos.cpp
clean:
	del*.o main
