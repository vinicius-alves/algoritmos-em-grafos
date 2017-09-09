#include "Graph.h"
#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

class GraphList: public Graph {

	public:
		~GraphList();
		virtual void addEdge(unsigned short const &vertex, unsigned short const &neighbor);
		virtual void print();

	private:
		virtual void initializeStructure();
		vector<unsigned short> *vertexes;
		vector< forward_list<unsigned short> > *vertexesLinkedLists;

};

#endif
