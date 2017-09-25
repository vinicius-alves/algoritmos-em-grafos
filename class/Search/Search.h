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
		virtual GraphTree* dijkstra(vertexLabelType const &node) = 0;
		virtual GraphTree* prim(vertexLabelType const &node) = 0;
		void calcAverageDistance();

	protected:
		Graph * graph;

};

#endif