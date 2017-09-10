#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"

int main(){

	Graph *graph = new GraphMatrix();
	Reader *reader = new Reader("as_graph.txt",graph);
	reader->read();
	delete reader; 

	//graph->print();
 
	Search *search = new SearchMatrix(graph);

	search->breadthFirstSearch(1);

	delete search;
	delete graph;
	
	return 0;
}