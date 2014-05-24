#ifndef GRAPH_H
#define GRAPH_H

class Graph{
	public:
		int **graphArray;
		int boardSize;
		Graph(int);
		void print();
		void dijkstra();
		int minDistance(int[], bool[]);
		int printSolution(int[], int[], int);

};

#endif