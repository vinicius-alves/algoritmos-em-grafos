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

#pragma omp parallel private(i,j,distance,graph) reduction(+:sum)
{
	#pragma omp for nowait schedule(dynamic)
	for(i =0; i<totalVertexes-1; i++){

		graph = this->dijkstra(i);
		distance = graph->getDistance();
		for (j =i+1; j<totalVertexes; j++){
			if((*distance)[j]<infinityDouble)
				sum+= (*distance)[j];
		} 
		distance->clear();
		delete graph;
	}

	sum = sum*vertexCombination;
}

	cout << "Distância média = "<<sum<<endl;

}
