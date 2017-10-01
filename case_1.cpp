#include <iostream>
#include <ctime>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

// to run: g++ -lm case_1.cpp class/*/*.cpp class/*.cpp -o exec -std=c++11 -fopenmp -O3

int main(){

	Graph *graph = new GraphList();
	Reader *reader = new Reader("grafo_5.txt",graph);
	reader->read();
	delete reader; 
	double result;
 
	Search *search = new SearchList(graph);

	GraphTree* graphTree;

	clock_t beginList = clock();

	graphTree = search->dijkstra(10-1);

	clock_t endList = clock();

	cout<< "Search with List time: " << double(endList - beginList) / CLOCKS_PER_SEC<<"s"<<endl;
	cout<< "Distance between "<< 10<< " and "<< 1<< " is "<< (*(graphTree->getDistance()))[0]<<endl; 

	clock_t begin = clock();
	result = search->calcAverageDistance();
	clock_t end = clock();

	cout<< "Average distance is "<< result<<endl;
	cout<< "Calc time: " << double(end - begin) / CLOCKS_PER_SEC<<endl<<"s"<<endl;

	delete search;
	delete graph;
	
	return 0;
}
