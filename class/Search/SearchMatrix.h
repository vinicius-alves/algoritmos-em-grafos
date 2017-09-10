#include <vector>
#include "Search.h"
#include "../Graph/GraphMatrix.h"

using namespace std;

#ifndef SEARCHMATRIX_H
#define SEARCHMATRIX_H

class SearchMatrix : public Search{

	public:
		SearchMatrix(Graph * graph);
		virtual void breadthFirstSearch(vertexLabelType const &node);

};

#endif