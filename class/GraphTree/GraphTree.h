#include <iostream>
#include <vector>
#include "../Graph/Graph.h"
#include "../lengthData.cpp"

using namespace std;

#ifndef GRAPHTREE_H
#define GRAPHTREE_H

class GraphTree{

	public:
		GraphTree(vertexesTotalLabelType totalVertexes);
		~GraphTree();
		void insertRoot(vertexLabelType const &nodeRoot);
		void insertOrUpdate(vertexLabelType const &nodeParent,vertexLabelType const &nodeChild);
		vertexLabelType getParent(vertexLabelType const &node);
		int getLevel(vertexLabelType const &node);
		void setDistance(vector<unsigned int> distance);
		unsigned int getDistance(unsigned int &node);

	private:
		vector < vertexLabelType > *fathers;
		vector<unsigned int> distance;

};

#endif