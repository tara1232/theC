main: main.o Entity.o
	g++ -std=c++11 main.o Entity.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
main.o: main.cpp Entity.hpp Entity.cpp
		g++ -std=c++11 -c main.cpp
Entity.o: Entity.cpp Entity.hpp
	g++ -std=c++11 -c Entity.cpp
clean:
	rm -f *.o
	rm -f main
