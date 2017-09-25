#include "Search.h"

using namespace std;

Search::Search(Graph * graph):graph(graph){};

void Search::calcAverageDistance(){

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	vector < vector<double>* > distances(totalVertexes);

	GraphTree *graph;

	

	for(unsigned int i =0; i<totalVertexes; i++){

		graph = this->dijkstra(i);
		distances[i] = (graph->getDistance());

	}

	double sum = 0;

	for ( auto distance = distances.begin(); distance != distances.end(); ++distance ){

		for ( auto dist = (*distance)->begin(); dist != (*distance)->end(); ++dist ){

			//if(sum)
			cout<< *dist << " ";
			sum+= *dist;

		}

		cout<<endl;

	}

	cout << "Distância média = "<<sum/(totalVertexes*(totalVertexes-1))<<endl;

	distances.clear();
	delete graph;
}