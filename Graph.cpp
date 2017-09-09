#include "Graph.h"

using namespace std;

void Graph::setTotalVertexes(unsigned short total){

	this->totalVertexes = total;
	this->initializeStructure();
};