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
	Reader *reader = new Reader("rede_colaboracao.txt",graph);
	reader->read();
	delete reader; 
 
	Search *search = new SearchList(graph);

	GraphTree* graphTree;
	vector<double>* cost;
	vector<unsigned int>* parents;

	vector<unsigned int> grau (graph->getTotalVertexes(),0);

	clock_t beginList = clock();

	graphTree = search->prim(2722 -1);

	cost = graphTree->getDistance();
	parents = graphTree->getParents();

	for (unsigned int j = 0; j< cost->size() ;j++ ){

			grau[j]++;
			grau[(*parents)[j]]++;
	} 

	for (unsigned int k = 1; k< grau.size() ;k++ ){

		if( grau[k] > 135)
			cout<< "Degree of "<<k+1<< " is "<< grau[k] <<endl;
	} 
	cout<<endl;

	cout << "Neighbors of Dijkstra in MST are: \n"<<endl;

	for (unsigned int i = 0; i< parents->size() ;i++ ){

			if((*parents)[i] == 2722 -1)
				cout << i +1 <<", ";
	}

	cout<<endl;

	cout << "\nNeighbors of Daniel in MST are: \n"<<endl;

	for (unsigned int i = 0; i< parents->size() ;i++ ){

			if((*parents)[i] == 107615 -1)
				cout << i +1 <<", ";
	}

	cout<<endl;

	clock_t endList = clock();

	cout<< "Search with List time: " << double(endList - beginList) / CLOCKS_PER_SEC<<"s"<<endl;

	delete search;
	delete graph;
	
	return 0;
}
