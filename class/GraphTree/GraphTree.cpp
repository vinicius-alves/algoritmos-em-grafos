#include "GraphTree.h"

using namespace std;

GraphTree::GraphTree(vertexesTotalLabelType totalVertexes){

	this->fathers = new vector < vertexLabelType >(totalVertexes);
}

GraphTree::~GraphTree(){

	delete this->fathers;
}

void GraphTree::insertRoot(vertexLabelType const &nodeRoot){

	(*this->fathers)[nodeRoot] = 0;
	
}

void GraphTree::insertOrUpdate(vertexLabelType const &nodeParent,vertexLabelType const &nodeChild){

	(*this->fathers)[nodeChild] = nodeParent;

}

vertexLabelType GraphTree::getParent(vertexLabelType const &node){

	return (*this->fathers)[node];
}

int GraphTree::getLevel(vertexLabelType const &node){

	/*tree< vertexLabelType >::iterator nodeIterator = 
	find(this->graphTree->begin(), this->graphTree->end(), node-1);

	int depth = 0;

	if(nodeIterator!= this->graphTree->end()) {

	 	depth = tree< vertexLabelType >::depth(nodeIterator);

	} else{
	 	cout<<"Error: node - "<< node <<" - not found"<<endl;
	 	exit(-2);
	}*/

	return 0;
}

void GraphTree::setDistance(vector<double> &distance){

	this->distance = distance;
}


vector<double>* GraphTree::getDistance(){

	return &this->distance;
}