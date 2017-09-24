#include "GraphMatrix.h"

using namespace std;

void GraphMatrix::initializeStructure(){

	Graph::initializeStructure();
	this->matrix = new vector< vector<float> >(this->totalVertexes,vector<float>(this->totalVertexes,0));
}

void GraphMatrix::addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor, float const &weight){

	Graph::addEdge(vertex,neighbor,weight);

	(*matrix)[vertex][neighbor] = weight;
	(*matrix)[neighbor][vertex] = weight;
}

void GraphMatrix::printVerbose(){

	Graph::print();

	for (vector< vector<float> >::iterator firstIt= (*this->matrix).begin(); firstIt!= (*this->matrix).end(); ++firstIt){

		for (vector<float>::iterator secondIt= (*firstIt).begin(); secondIt!= (*firstIt).end(); ++secondIt){

			cout<<*secondIt<<" ";			
		}

		cout<<endl;
	}

	cout<<endl;    	
}

vector<float>* GraphMatrix::getNeighbors(vertexLabelType const &node){

	return &(*this->matrix)[node];
}

GraphMatrix::~GraphMatrix(){

	for (vector< vector<float> >::iterator firstIt= (*this->matrix).begin(); firstIt!= (*this->matrix).end(); ++firstIt){

		delete &firstIt;	
	}

	delete this->matrix;
};