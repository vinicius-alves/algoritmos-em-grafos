#include <iostream>
#include "Reader.h"

int main(){


	Reader *rd = new Reader("as_graph.txt");
	vector<vector<bit > > matrix = rd->getMatrix();

	matrix.clear(); 
	
	return 0;
}