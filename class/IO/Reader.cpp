#include <stdexcept>
#include "Reader.h"

using namespace std;

Reader::Reader(const char * path, Graph * graph):path(path),graph(graph){};

void Reader::read(){

ifstream file;
file.open(this->path);

if (file.is_open()){

	vertexesTotalLabelType totalVertexes;
	edgesTotalLabelType totalEdges =0;

	file >> totalVertexes;

    this->graph->setTotalVertexes(totalVertexes);


	vertexLabelType vertex, neighbor;
	while (file >> vertex >> neighbor)
	{

		this->graph->addEdge(vertex-1, neighbor-1);
		totalEdges++;
	}

	this->graph->setTotalEdges(totalEdges);

	file.close();

} else{
	throw invalid_argument( "File not found!" );
}




};