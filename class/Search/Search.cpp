#include "Search.h"

using namespace std;

Search::Search(Graph * graph):graph(graph){};

void Search::calcAverageDistance(){

	register const vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	vector < vector<double>* > distances(totalVertexes);

	register const double infinityDouble = numeric_limits< double >::infinity();
	unsigned int i;
	unsigned int j;
	double sum = 0;

#pragma omp parallel private(i,j) shared(distances) reduction(+:sum)
{
	#pragma omp for
	for(i =0; i<totalVertexes; i++){

		GraphTree *graph;
		graph = this->dijkstra(i);
		distances[i] = (graph->getDistance());

	}

	#pragma omp for
	for (i =0; i<totalVertexes; i++){

		for (j =0; j<totalVertexes; j++){

			if((*distances[i])[j]<infinityDouble)
				sum+= (*distances[i])[j];
		}
		cout<<endl;
	}

	#pragma omp for nowait
	for (i =0; i<totalVertexes; i++){

			(*distances[i]).clear();
	}
}

	cout << "Distância média = "<<sum/(totalVertexes*(totalVertexes-1))<<endl;

	distances.clear();
	delete graph;
}