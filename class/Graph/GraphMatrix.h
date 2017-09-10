#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

class GraphMatrix: public Graph {

	public:
		~GraphMatrix();
		virtual void addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor);
		virtual void printVerbose();
		vector<bool>* getNeighbors(vertexLabelType const &node);

	private:
		virtual void initializeStructure();
		vector< vector<bool> > *matrix;

};

#endif

