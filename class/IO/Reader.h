#include <fstream>
#include "../Graph/Graph.h"
#include "../lengthData.cpp"

using namespace std;

#ifndef READER_H
#define READER_H

class Reader{

	public:
		Reader(const char * path, Graph * graph);
		void read();

	private:
		const char * path;
		Graph * graph;

};

#endif