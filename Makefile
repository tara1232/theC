main: main.o
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
main.o: main.cpp
		g++ -c main.cpp
clean:
	rm -f *.o
	rm -f main
