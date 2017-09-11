#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

int main(){

	Graph *graph = new GraphList();
	Reader *reader = new Reader("as_graph.txt",graph);
	reader->read();
	delete reader; 

	//graph->print();
 
	Search *search = new SearchList(graph);

	//GraphTree graphTree = search->breadthFirstSearch(1);
	GraphTree *graphTree = search->breadthFirstSearch(1);

	cout<<"Level of 1 is "<< graphTree->getLevel(1)<<endl;
	cout<<"Level of 3 is "<< graphTree->getLevel(3)<<endl;
	cout<<"Father of 3 is "<< graphTree->getParent(3)<<endl;

	delete graphTree;
	delete search;
	delete graph;
	
	return 0;
}