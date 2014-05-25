#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "Graph.h"

int main(int argc, char *argv[])
{
	// Graph* test = new Graph(10);
	// test->graphArray[7][12] = 1;
	// test->graphArray[23][5] = 1;
	// test->dijkstra();
	//Gets the first line 
	int numGames;
	cin >> numGames;
	
	for(int i = 1; i <= numGames; i++){
		//For each game gets N, L, S(first line)
		int boardSize;
		cin >> boardSize; 
		Graph* newGraph = new Graph(boardSize);

		int numLadders;
		int numSnakes;
		cin >> numLadders;
		cin >> numSnakes;

		//Get second line, points for ladders
		for(int l = 0; l < numLadders; l++){
			int xLadder;
			int yLadder;
			cin >> xLadder;
			cin >> yLadder;
			newGraph->graphArray[xLadder][yLadder] = 1;
		}
		
		//Get third line, points for snakes
		for(int l = 0; l < numSnakes; l++){
			int xSnake;
			int ySnake;
			cin >> xSnake;
			cin >> ySnake;
			newGraph->graphArray[xSnake][ySnake] = 1;
		}
		cout << "Board Game #" << i << ":" << endl;
		newGraph->dijkstra();
	}

}
