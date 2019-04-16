main: main.o Entity.o
	g++ main.o Entity.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
main.o: main.cpp Entity.hpp Entity.cpp
		g++ -c main.cpp
Entity.o: Entity.cpp Entity.hpp
	g++ -c Entity.cpp
clean:
	rm -f *.o
	rm -f main
