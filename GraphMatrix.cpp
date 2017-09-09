#include "GraphMatrix.h"

using namespace std;

void GraphMatrix::initializeStructure(){

	this->matrix = new vector< vector<bool> >(this->totalVertexes,vector<bool>(this->totalVertexes));
}

void GraphMatrix::addEdge(unsigned short const &vertex, unsigned short const &neighbor){
	(*matrix)[vertex][neighbor] = true;
	(*matrix)[neighbor][vertex] = true;
}

void GraphMatrix::print(){

	cout<<"Graph in Matrix \n"<<"Total of vertexes: "<< this->totalVertexes<<endl;

	for (vector< vector<bool> >::iterator firstIt= (*this->matrix).begin(); firstIt!= (*this->matrix).end(); ++firstIt){

		for (vector<bool>::iterator secondIt= (*firstIt).begin(); secondIt!= (*firstIt).end(); ++secondIt){

			cout<<*secondIt<<" ";			
		}

		cout<<endl;
	}
    	
};

GraphMatrix::~GraphMatrix(){

	for (vector< vector<bool> >::iterator firstIt= (*this->matrix).begin(); firstIt!= (*this->matrix).end(); ++firstIt){

		delete &firstIt;	
	}

	delete this->matrix;
};