#include <iostream>
#include <ctime>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

//To compile, just: g++ -std=c++11 -lm case_2.cpp class/*/*.cpp -o executable
//To run: ./executable

int main(){

	/*cout<< "\nRead as Matrix:\n" <<endl;


	Graph *graphMatrix = new GraphMatrix();
	Reader *readerMatrix = new Reader("subdblp.txt",graphMatrix);
	readerMatrix->read();
	delete readerMatrix;

	Search *searchMatrix = new SearchMatrix(graphMatrix); 
 	
 	clock_t beginMatrix = clock();

 	GraphTree *graphTreeMatrix = searchMatrix->breadthFirstSearch(1);
 	//GraphTree *graphTreeMatrix = searchMatrix->depthFirstSearch(1);

	clock_t endMatrix = clock();

	cout<< "Search with Matrix time: " << double(endMatrix - beginMatrix) / CLOCKS_PER_SEC<<endl;


	delete graphTreeMatrix;
	delete searchMatrix;
	delete graphMatrix;*/

	cout<< "\nRead as List:\n" <<endl;

	Graph *graphList = new GraphList();
	Reader *readerList = new Reader("dblp.txt",graphList);
	readerList->read();
	delete readerList; 
 
	Search *searchList = new SearchList(graphList);

	clock_t beginList = clock();

	GraphTree *graphTreeList = searchList->breadthFirstSearch(1);
	//GraphTree *graphTreeList = searchList->depthFirstSearch(1);

	clock_t endList = clock();

	cout<< "Search with List time: " << double(endList - beginList) / CLOCKS_PER_SEC<<endl;

	delete graphTreeList;
	delete searchList;
	delete graphList;
	
	return 0;
}