#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include "../Graph/Graph.h"
#include "../lengthData.cpp"

using namespace std;

#ifndef SEARCH_H
#define SEARCH_H

class Search{

	public:
		Search(Graph * graph);
		virtual void breadthFirstSearch(edgesTotalLabelType const &node) = 0;

	protected:
		Graph * graph;

};

#endif