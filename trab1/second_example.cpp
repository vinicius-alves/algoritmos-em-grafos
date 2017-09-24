#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

//To compile, just: g++ -std=c++11 -lm second_example.cpp class/*/*.cpp -o executable
//To run: ./executable

int main(){

	cout<< "\nRead as Matrix:\n" <<endl;


	Graph *graphMatrix = new GraphMatrix();
	Reader *readerMatrix = new Reader("first_graph_example.txt",graphMatrix);
	readerMatrix->read();
	delete readerMatrix; 
 
	Search *searchMatrix = new SearchMatrix(graphMatrix);

	GraphTree *graphTreeMatrix = searchMatrix->breadthFirstSearch(1);

	for(edgeLabelType i =1; i != graphMatrix->getTotalVertexes(); i++){
		cout<<"Level  of "<<i<<" is "<< graphTreeMatrix->getLevel(i)<<endl;
		if(graphTreeMatrix->getLevel(i) > 0)
			cout<<"Father of "<< i <<" is "<< graphTreeMatrix->getParent(i)<<endl;
	}

	cout<<endl;

	delete graphTreeMatrix;
	delete searchMatrix;
	delete graphMatrix;


	cout<< "\nRead as List:\n" <<endl;

	Graph *graphList = new GraphList();
	Reader *readerList = new Reader("first_graph_example.txt",graphList);
	readerList->read();
	delete readerList; 
 
	Search *searchList = new SearchList(graphList);

	GraphTree *graphTreeList = searchList->breadthFirstSearch(1);

	for(edgeLabelType i =1; i != graphList->getTotalVertexes(); i++){
		cout<<"Level  of "<<i<<" is "<< graphTreeList->getLevel(i)<<endl;
		if(graphTreeList->getLevel(i) > 0)
			cout<<"Father of "<< i <<" is "<< graphTreeList->getParent(i)<<endl;
	}

	cout<<endl;

	delete graphTreeList;
	delete searchList;
	delete graphList;
	
	return 0;
}