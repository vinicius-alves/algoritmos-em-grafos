#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

//To compile, just: g++ -std=c++11 -lm case_3.cpp class/*/*.cpp -o executable
//To run: ./executable

int main(){


	cout<< "\nRead as List:\n" <<endl;

	Graph *graphList = new GraphList();
	Reader *readerList = new Reader("as_graph.txt",graphList);
	readerList->read();
	delete readerList; 
 
	Search *searchList = new SearchList(graphList);


	GraphTree *graphTree = searchList->breadthFirstSearch(5);
	

	cout<<"Father of "<<10<<" is "<< graphTree->getParent(10)<<endl;
	cout<<"Father of "<<20<<" is "<< graphTree->getParent(20)<<endl;
	cout<<"Father of "<<30<<" is "<< graphTree->getParent(30)<<endl;
	cout<<"Father of "<<40<<" is "<< graphTree->getParent(40)<<endl;
	cout<<"Father of "<<50<<" is "<< graphTree->getParent(50)<<endl;

	cout<<endl;

	delete graphTree;
	delete searchList;
	delete graphList;
	
	return 0;
}