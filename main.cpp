#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

int main(){

	Graph *graph = new GraphMarix();
	Reader *reader = new Reader("grafo_1.txt",graph);
	reader->read();
	delete reader; 

	//graph->print();
 
	Search *search = new SearchMatrix(graph);

	search->djikstra(1);

	delete search;
	delete graph;
	
	return 0;
}