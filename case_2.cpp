#include <iostream>
#include <ctime>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

//// to run: g++ -lm case_2.cpp class/*/*.cpp class/*.cpp -o exec -std=c++11 -fopenmp -O3

int main(){

	Graph *graph = new GraphList();
	Reader *reader = new Reader("grafo_5.txt",graph);
	reader->read();
	delete reader; 
	double result;
	double sum = 0;
 
	Search *search = new SearchList(graph);

	GraphTree* graphTree;
	vector<double>* cost;

	clock_t beginList = clock();

	graphTree = search->prim(10-1);

	cost = graphTree->getDistance();

	for (auto it = cost->begin(); it!=cost->end(); ++it){

			sum+= *it;
	} 

	clock_t endList = clock();

	cout<< "Search with List time: " << double(endList - beginList) / CLOCKS_PER_SEC<<"s"<<endl;
	cout<< "Cost of MST is "<< sum <<endl; 

	delete search;
	delete graph;
	
	return 0;
}
