#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "Graph.h"

Graph::Graph(int size){
	boardSize = size*size +1;
	graphArray = new int*[boardSize];
	for(int i = 0; i < boardSize; i++){
		graphArray[i] = new int[boardSize];
		//Sets all the distances to 0
		for(int j = 0; j < boardSize; j++)
			graphArray[i][j] = 0;
	}
	//Set distances for first dice roll
	for(int k = 2; k <= 7; k++)
		graphArray[1][k] = 1;

}

void Graph::print(){
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			cout << graphArray[i][j] << " ";
		}
		cout << endl;
	}
}