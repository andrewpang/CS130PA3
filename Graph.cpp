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

void Graph::print(){
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			cout << graphArray[i][j] << " ";
		}
		cout << endl;
	}
}