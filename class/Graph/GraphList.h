#include <iostream>
#include <vector>
#include <forward_list>
#include "Graph.h"

using namespace std;

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

class GraphList: public Graph {

	public:
		~GraphList();
		virtual void addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor, float const &weight);
		virtual void printVerbose();
		forward_list< vertexesTotalLabelType >* getNeighbors(vertexLabelType const &node);
		forward_list< float >* getNeighborsWeight(vertexLabelType const &node);

	private:
		virtual void initializeStructure();
		vector< vertexLabelType > *vertexes;
		vector< forward_list< vertexesTotalLabelType > > *vertexesLinkedLists;
		vector< forward_list< float > > *vertexesWeightLinkedLists;
};

#endif

