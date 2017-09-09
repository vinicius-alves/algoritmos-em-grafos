#include "GraphMatrix.h"

using namespace std;

void GraphMatrix::initializeStructure(){

	this->matrix = new vector< vector<bool> >(this->totalVertexes,vector<bool>(this->totalVertexes));
}

void GraphMatrix::addEdge(unsigned short const &vertex, unsigned short const &neighbor){
	(*matrix)[vertex-1][neighbor-1] = true;
	(*matrix)[neighbor-1][vertex-1] = true;
}

void GraphMatrix::print(){

	cout<<"Graph in Matrix \n"<<"Total of vertexes: "<< this->totalVertexes<<endl;

	for (vector< vector<bool> >::iterator firstIt= (*matrix).begin(); firstIt!= (*matrix).end(); ++firstIt){

		for (vector<bool>::iterator secondIt= (*firstIt).begin(); secondIt!= (*firstIt).end(); ++secondIt){

			cout<<*secondIt<<" ";			
		}

		cout<<endl;
	}
    	
};

GraphMatrix::~GraphMatrix(){

	for (vector< vector<bool> >::iterator firstIt= (*matrix).begin(); firstIt!= (*matrix).end(); ++firstIt){

		delete &firstIt;
		
	}

	delete matrix;
};