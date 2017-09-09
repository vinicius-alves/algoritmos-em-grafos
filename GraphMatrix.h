#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

class GraphMatrix: public Graph {

	public:
		~GraphMatrix();
		virtual void addEdge(unsigned short const &vertex, unsigned short const &neighbor);
		virtual void print();

	private:
		virtual void initializeStructure();
		vector< vector<bool> > *matrix;

};

#endif

