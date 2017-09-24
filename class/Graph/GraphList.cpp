#include "GraphList.h"

using namespace std;

void GraphList::initializeStructure(){

	Graph::initializeStructure();
	this->vertexes = new vector< vertexLabelType >(this->totalVertexes);
	this->vertexesLinkedLists = new vector< forward_list< vertexesTotalLabelType > >(this->totalVertexes, forward_list< vertexLabelType >());

	register vertexesTotalLabelType totalVertexes = this->totalVertexes;

	for ( vertexesTotalLabelType i =0; i<totalVertexes; i++){

		(*this->vertexes)[i] = i;	
	}
}

void GraphList::addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor, float const &weight){

	Graph::addEdge(vertex,neighbor,weight);

	(*this->vertexesLinkedLists)[vertex].emplace_front(neighbor);
	(*this->vertexesLinkedLists)[neighbor].emplace_front(vertex);
}


void GraphList::printVerbose(){

	Graph::print();

	register vertexesTotalLabelType totalVertexes = this->totalVertexes;

	for ( vertexesTotalLabelType i =0; i<totalVertexes; i++){

		cout << (*this->vertexes)[i]+1 << " : ";

		for (forward_list< vertexLabelType >::iterator secondIt= ((*this->vertexesLinkedLists)[i]).begin(); 
			secondIt!= ((*this->vertexesLinkedLists)[i]).end(); ++secondIt){

			if(secondIt == ((*this->vertexesLinkedLists)[i]).begin())
				cout << *secondIt + 1; 
			else
				cout <<" -> "<< *secondIt + 1;			
		}

		cout<<endl;
	}

	cout<<endl;  	
}

forward_list< vertexesTotalLabelType >* GraphList::getNeighbors(vertexLabelType const &node){

	return &(*this->vertexesLinkedLists)[node];

}

GraphList::~GraphList(){

	for (vector< forward_list< vertexLabelType > >::iterator firstIt= (*this->vertexesLinkedLists).begin(); firstIt!= (*this->vertexesLinkedLists).end(); ++firstIt){

		delete &firstIt;	
	}

	delete this->vertexesLinkedLists;
	delete this->vertexes;
}