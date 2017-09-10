#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include "../Graph/Graph.h"
#include "../lengthData.cpp"
#include "../libs/tree.hh"

using namespace std;

#ifndef GRAPHTREE_H
#define GRAPHTREE_H

class GraphTree{

	public:
		GraphTree();
		~GraphTree();
		void insert(vertexLabelType const &nodeParent,vertexLabelType const &nodeChild);
		vertexLabelType* getParent(vertexLabelType const &node);
		vertexLabelType* getLevel(vertexLabelType const &node);

	private:
		tree< vertexLabelType > *graphTree;

};

#endif