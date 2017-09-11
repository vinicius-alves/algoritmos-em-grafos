#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include "../Graph/Graph.h"
#include "../GraphTree/GraphTree.h"
#include "../lengthData.cpp"

using namespace std;

#ifndef SEARCH_H
#define SEARCH_H

class Search{

	public:
		Search(Graph * graph);
		virtual GraphTree* breadthFirstSearch(vertexLabelType const &node) = 0;
		virtual GraphTree* depthFirstSearch(vertexLabelType const &node) = 0;

	protected:
		Graph * graph;

};

#endif