#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "../IO/Writter.h"
#include "../lengthData.cpp"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

	public:
		virtual void addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor);
		virtual void print();
		virtual void printVerbose() = 0;
		void calcRelativeFrequencyValences();
		void setTotalVertexes(vertexesTotalLabelType total);
		void setTotalEdges(edgesTotalLabelType total);
		edgesTotalLabelType getTotalVertexes();

	protected:
		virtual void initializeStructure();
		vertexesTotalLabelType totalVertexes;
		edgesTotalLabelType totalEdges;
		vector< vertexesTotalLabelType > *valences;
		vector< edgesTotalLabelType > *frequencyOfValences;
};

#endif