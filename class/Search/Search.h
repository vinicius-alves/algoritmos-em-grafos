#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <utility> 
#include "../Graph/Graph.h"
#include "../GraphTree/GraphTree.h"
#include "../lengthData.cpp"

using namespace std;

#ifndef SEARCH_H
#define SEARCH_H

typedef pair< vertexLabelType,vertexLabelType > iPair;

class Search{

	public:
		Search(Graph * graph);
		virtual GraphTree* breadthFirstSearch(vertexLabelType const &node) = 0;
		virtual GraphTree* depthFirstSearch(vertexLabelType const &node) = 0;
		virtual GraphTree* djikstra(vertexLabelType const &node) = 0;

	protected:
		Graph * graph;

};

#endif