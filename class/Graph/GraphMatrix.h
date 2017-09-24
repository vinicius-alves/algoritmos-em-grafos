#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

class GraphMatrix: public Graph {

	public:
		~GraphMatrix();
		virtual void addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor, float const &weight);
		virtual void printVerbose();
		vector<float>* getNeighbors(vertexLabelType const &node);

	private:
		virtual void initializeStructure();
		vector< vector<float> > *matrix;

};

#endif

