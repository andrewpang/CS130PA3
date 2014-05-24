#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;
#include "Graph.h"
#include <stack>

Graph::Graph(int size){
	boardSize = size*size +1;
	graphArray = new int*[boardSize];
	for(int i = 0; i < boardSize; i++){
		graphArray[i] = new int[boardSize];
		//Sets all the distances to 0
		for(int j = 0; j < boardSize; j++)
			graphArray[i][j] = 0;
	}
	//Set row 0 to numbers for ease of use
	for(int d = 0; d < boardSize; d++){
		graphArray[0][d] = d;
		graphArray[d][0] = d;
	}
	//Set distances for dice roll
	for(int k = 1; k < boardSize; k++)
		for(int m = k+1; m < k+7; m++)
			if(m < boardSize)
				graphArray[k][m] = 2;
}

int Graph::minDistance(int dist[], bool visit[]){
	int min = INT_MAX, min_index;

	for(int i = 1; i < boardSize; i++){
		if(visit[i] == false && dist[i] <= min){
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

int Graph::printSolution(int dist[], int pred[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 1; i < boardSize; i++)
      printf("%d \t\t %d\t %d\n", i, dist[i], pred[i]);
}

void Graph::dijkstra(){
	int distance[boardSize];
	bool visited[boardSize];
	int pred[boardSize];

	for(int i = 1; i < boardSize; i++){
		distance[i] = INT_MAX;
	 	visited[i] = false;
	}	
	distance[1] = 0;
	pred[1] = 0;
	for(int count = 1; count < boardSize-1; count++){
		int u = minDistance(distance, visited);
		visited[u] = true;
		for(int v = 1; v<boardSize; v++)
		{
			 if (!visited[v] && graphArray[u][v] && distance[u] != INT_MAX
                                       && distance[u]+graphArray[u][v] < distance[v]){
				distance[v] = distance[u]+graphArray[u][v];
				pred[v] = u;
				}

		}

	}
	//printSolution(distance, pred, boardSize);

	stack <int> ordered;
	int x = boardSize-1;
	ordered.push(x);
	while(pred[x] != 0){
		ordered.push(pred[x]);
		x = pred[x];
	}

	while (ordered.empty() != true){
		int top = ordered.top();
		if(top == 1)
			cout << top << "";
		else if (graphArray[pred[top]][top] == 1 && pred[top] > top)
			cout << "-" << top << "";
		else if (graphArray[pred[top]][top] == 1 && pred[top] < top)
			cout << "+" << top << "";
		else
			cout << " " << top << "";

		ordered.pop();
	}



}

void Graph::print(){
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			cout << graphArray[i][j] << "\t";
		}
		cout << endl;
	}
}
