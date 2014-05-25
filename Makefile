all: snl

snl: main.o Graph.o
	g++ main.o Graph.o -o snl

main.o: main.cpp
	g++ main.cpp -c

Graph.o: Graph.cpp
	g++ Graph.cpp -c

clean: 
	rm Graph.o main.o snl