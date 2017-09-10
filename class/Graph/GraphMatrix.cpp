#include "GraphMatrix.h"

using namespace std;

void GraphMatrix::initializeStructure(){

	Graph::initializeStructure();
	this->matrix = new vector< vector<bool> >(this->totalVertexes,vector<bool>(this->totalVertexes,0));
}

void GraphMatrix::addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor){

	Graph::addEdge(vertex,neighbor);

	(*matrix)[vertex][neighbor] = true;
	(*matrix)[neighbor][vertex] = true;
}

void GraphMatrix::printVerbose(){

	Graph::print();

	for (vector< vector<bool> >::iterator firstIt= (*this->matrix).begin(); firstIt!= (*this->matrix).end(); ++firstIt){

		for (vector<bool>::iterator secondIt= (*firstIt).begin(); secondIt!= (*firstIt).end(); ++secondIt){

			cout<<*secondIt<<" ";			
		}

		cout<<endl;
	}

	cout<<endl;    	
}

vector<bool>* GraphMatrix::getNeighbors(vertexLabelType const &node){

	return &(*this->matrix)[node];
}

GraphMatrix::~GraphMatrix(){

	for (vector< vector<bool> >::iterator firstIt= (*this->matrix).begin(); firstIt!= (*this->matrix).end(); ++firstIt){

		delete &firstIt;	
	}

	delete this->matrix;
};