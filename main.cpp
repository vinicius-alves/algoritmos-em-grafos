#include <iostream>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

int main(){

	Graph *graph = new GraphList();
	Reader *reader = new Reader("grafo_1.txt",graph);
	reader->read();
	delete reader; 

	//graph->print();
 
	Search *search = new SearchList(graph);

	search->dijkstra(1);

	delete search;
	delete graph;
	
	return 0;
}