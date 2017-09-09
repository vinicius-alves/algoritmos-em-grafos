#include <iostream>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

	public:
		virtual void addEdge(unsigned short const &vertex, unsigned short const &neighbor) = 0;
		virtual void print() = 0;
		void setTotalVertexes(unsigned short total);

	protected:
		virtual void initializeStructure() =0;
		unsigned short totalVertexes;

};

#endif