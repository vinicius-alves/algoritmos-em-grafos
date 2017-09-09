#include <iostream>
#include "Reader.h"
#include "GraphMatrix.h"
#include "GraphList.h"

int main(){

	Graph *graph = new GraphList();
	Reader *rd = new Reader("as_graph.txt",graph);
	rd->read();
	
	graph->print();

	delete rd; 
	delete graph;
	
	return 0;
}