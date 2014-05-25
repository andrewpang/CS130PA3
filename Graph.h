#ifndef GRAPH_H
#define GRAPH_H

class Graph{
	public:
		int **graphArray;
		int boardSize;
		Graph();
		Graph(int);
		~Graph();
		void print();
		void dijkstra();
		//void output(int []);
		int minDistance(int[], bool[]);
		int printSolution(int[]);

};

#endif