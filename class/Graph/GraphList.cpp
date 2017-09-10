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

void GraphList::addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor){

	Graph::addEdge(vertex,neighbor);

	(*this->vertexesLinkedLists)[vertex].emplace_front(neighbor);
	(*this->vertexesLinkedLists)[neighbor].emplace_front(vertex);
}


void GraphList::printVerbose(){

	Graph::print();

	register vertexesTotalLabelType totalVertexes = this->totalVertexes;

	for ( vertexesTotalLabelType i =0; i<totalVertexes; i++){

		cout << (*this->vertexes)[i] << " : ";

		for (forward_list< vertexLabelType >::iterator secondIt= ((*this->vertexesLinkedLists)[i]).begin(); 
			secondIt!= ((*this->vertexesLinkedLists)[i]).end(); ++secondIt){

			if(secondIt == ((*this->vertexesLinkedLists)[i]).begin())
				cout << *secondIt; 
			else
				cout <<" -> "<< *secondIt;			
		}

		cout<<endl;
	}

	cout<<endl;  	
}

GraphList::~GraphList(){

	for (vector< forward_list< vertexLabelType > >::iterator firstIt= (*this->vertexesLinkedLists).begin(); firstIt!= (*this->vertexesLinkedLists).end(); ++firstIt){

		delete &firstIt;	
	}

	delete this->vertexesLinkedLists;
	delete this->vertexes;
}