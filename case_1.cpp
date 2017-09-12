#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"

//To compile, just: g++ -std=c++11 -lm case_1.cpp class/*/*.cpp -o executable
//To run: ./executable

int main(){

	/*cout<< "\nRead as matrix:" <<endl;

	Graph *graphMatrix = new GraphMatrix();
	Reader *readerMatrix = new Reader("subdblp.txt",graphMatrix);
	readerMatrix->read();

	graphMatrix->print();

	delete readerMatrix; 

	delete graphMatrix;

	cout<< "\nRead as linked list:" <<endl;*/

	Graph *graphList = new GraphList();
	Reader *readerList = new Reader("subdblp.txt",graphList);
	readerList->read();

	graphList->print();

	delete readerList; 

	delete graphList;
	
	return 0;
}