#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Writter.h"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

	public:
		virtual void addEdge(unsigned short const &vertex, unsigned short const &neighbor);
		virtual void print();
		virtual void printVerbose() = 0;
		void calcRelativeFrequencyValences();
		void setTotalVertexes(unsigned short total);
		void setTotalEdges(unsigned short total);

	protected:
		virtual void initializeStructure();
		unsigned short totalVertexes;
		unsigned short totalEdges;
		vector<unsigned short> *valences;
		vector<unsigned short> *frequencyOfValences;
};

#endif