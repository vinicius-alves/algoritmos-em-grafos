#include "GraphList.h"

using namespace std;

void GraphList::initializeStructure(){

	this->vertexes = new vector<unsigned short>(this->totalVertexes);
	this->vertexesLinkedLists = new vector< forward_list<unsigned short> >(this->totalVertexes, forward_list<unsigned short>());

	register unsigned short totalVertexes = this->totalVertexes;

	for ( unsigned short i =0; i<totalVertexes; i++){

		(*this->vertexes)[i] = i;	
	}
}

void GraphList::addEdge(unsigned short const &vertex, unsigned short const &neighbor){
	(*this->vertexesLinkedLists)[vertex].emplace_front(neighbor);
	(*this->vertexesLinkedLists)[neighbor].emplace_front(vertex);
}

void GraphList::print(){

	register unsigned short totalVertexes = this->totalVertexes;

	for ( unsigned short i =0; i<totalVertexes; i++){

		cout << (*this->vertexes)[i] << " : ";

		for (forward_list<unsigned short>::iterator secondIt= ((*this->vertexesLinkedLists)[i]).begin(); secondIt!= ((*this->vertexesLinkedLists)[i]).end(); ++secondIt){

			if(secondIt == ((*this->vertexesLinkedLists)[i]).begin())
				cout << *secondIt; 
			else
				cout <<" -> "<< *secondIt;			
		}

		cout<<endl;
	}
    	
}

GraphList::~GraphList(){

	for (vector< forward_list<unsigned short> >::iterator firstIt= (*this->vertexesLinkedLists).begin(); firstIt!= (*this->vertexesLinkedLists).end(); ++firstIt){

		delete &firstIt;	
	}

	delete this->vertexesLinkedLists;
	delete this->vertexes;
}