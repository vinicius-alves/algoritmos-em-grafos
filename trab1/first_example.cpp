#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"

//To compile, just: g++ -std=c++11 -lm first_example.cpp class/*/*.cpp -o executable
//To run: ./executable

int main(){

	cout<< "\nRead as matrix:" <<endl;

	Graph *graphMatrix = new GraphMatrix();
	Reader *readerMatrix = new Reader("first_graph_example.txt",graphMatrix);
	readerMatrix->read();

	graphMatrix->printVerbose();

	delete readerMatrix; 

	delete graphMatrix;

	cout<< "\nRead as linked list:" <<endl;

	Graph *graphList = new GraphList();
	Reader *readerList = new Reader("first_graph_example.txt",graphList);
	readerList->read();

	graphList->printVerbose();

	delete readerList; 

	delete graphList;
	
	return 0;
}