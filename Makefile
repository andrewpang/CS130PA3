all: prog1

prog1: main.o Graph.o
	g++ main.o Graph.o -o prog1

main.o: main.cpp
	g++ main.cpp -c

Graph.o: Graph.cpp
	g++ Graph.cpp -c

clean: 
	rm Graph.o main.o prog1