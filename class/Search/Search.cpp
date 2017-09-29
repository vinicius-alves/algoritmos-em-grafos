#include "Search.h"

using namespace std;

Search::Search(Graph * graph):graph(graph){};

void Search::calcAverageDistance(){

	register const vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	vector<double>* distance;

	register const double infinityDouble = numeric_limits< double >::infinity();
	register const double vertexCombination = 2.0/(totalVertexes*(totalVertexes-1));
	unsigned int i;
	unsigned int j;
	double sum = 0;
	GraphTree *graph;
	vector<double>::iterator it;

#pragma omp parallel private(i,j,distance,graph,it) reduction(+:sum)
{
	#pragma omp for nowait schedule(dynamic)
	for(i =0; i<totalVertexes-1; i++){

		graph = this->dijkstra(i);
		distance = graph->getDistance();
		
		it = distance->begin();
		advance(it,i+1);

		for (it; it!=distance->end(); ++it){

			if(*it<infinityDouble)
				sum+= *it;
		} 

		distance->clear();
		delete graph;
	}

	sum = sum*vertexCombination;
}

	cout << "Distância média = "<<sum<<endl;

}
