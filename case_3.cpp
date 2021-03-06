#include <iostream>
#include <ctime>
#include "class/IO/Reader.h"
#include "class/Graph/GraphMatrix.h"
#include "class/Graph/GraphList.h"
#include "class/Search/SearchMatrix.h"
#include "class/Search/SearchList.h"
#include "class/GraphTree/GraphTree.h"

//// to run: g++ -lm case_3.cpp class/*/*.cpp class/*.cpp -o exec -std=c++11 -fopenmp -O3

int main(){

	Graph *graph = new GraphList();
	Reader *reader = new Reader("rede_colaboracao.txt",graph);
	reader->read();
	delete reader; 
	double result;
	unsigned const root = 107615; 
	unsigned const target = 2722; 
	unsigned parent;
 
	Search *search = new SearchList(graph);

	GraphTree* graphTree;
	vector<double>* distance;

	clock_t beginList = clock();

	graphTree = search->dijkstra(root-1);

	parent = target-1;

	cout<< "Path from Dijkstra until Daniel:"<<endl;
	while( parent != root-1){

		cout<< parent+1 <<" -> ";
		parent = graphTree->getParent(parent);

	} 

	cout<<" "<< root <<endl;

	distance = graphTree->getDistance();

	cout << "\nDistance between Dijkstra and: \n"<<endl;
	cout << "Turing"    << " is " << (*distance)[11365-1]  << endl;
	cout << "Kruskal"   << " is " << (*distance)[509510-1] << endl;
	cout << "Kleinberg" << " is " << (*distance)[5709-1]   << endl;
	cout << "Tardos"    << " is " << (*distance)[11386-1]  << endl;
	cout << "Daniel"    << " is " << (*distance)[2722-1]   << endl;
	cout<<endl;

	clock_t endList = clock();

	cout<< "Search with List time: " << double(endList - beginList) / CLOCKS_PER_SEC<<"s"<<endl;

	delete search;
	delete graph;
	
	return 0;
}
