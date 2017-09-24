#include <vector>
#include "Search.h"
#include "../Graph/GraphMatrix.h"

using namespace std;

#ifndef SEARCHMATRIX_H
#define SEARCHMATRIX_H

class SearchMatrix : public Search{

	public:
		SearchMatrix(Graph * graph);
		virtual GraphTree* breadthFirstSearch(vertexLabelType const &node);
		virtual GraphTree* depthFirstSearch(vertexLabelType const &node);
		virtual GraphTree* dijkstra(vertexLabelType const &node);
		virtual GraphTree* prim(vertexLabelType const &node);

};

#endif