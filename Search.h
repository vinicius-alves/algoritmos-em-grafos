#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include "Graph.h"
#include "libs/tree.hh"

using namespace std;

#ifndef SEARCH_H
#define SEARCH_H

class Search{

	public:
		Search(Graph * graph);
		virtual void breadthFirstSearch(unsigned short const &node) = 0;

	protected:
		Graph * graph;

};

#endif