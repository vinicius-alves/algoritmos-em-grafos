#include "GraphTree.h"

using namespace std;

GraphTree::GraphTree(){

	this->graphTree = new tree< vertexLabelType >();
}

GraphTree::~GraphTree(){

	delete this->graphTree;
}

void GraphTree::insertRoot(vertexLabelType const &nodeRoot){

	this->graphTree->insert(this->graphTree->begin(), nodeRoot);
	
}

void GraphTree::insert(vertexLabelType const &nodeParent,vertexLabelType const &nodeChild){

	tree< vertexLabelType >::iterator nodeParentIterator = 
	find(this->graphTree->begin(), this->graphTree->end(), nodeParent);

	 if(nodeParentIterator!= this->graphTree->end()) {

	 	this->graphTree->append_child(nodeParentIterator,nodeChild);

	 } else{
	 	cout<<"Error: parent node - "<< nodeParent+1 <<" - not found"<<endl;
	 	exit(-2);
	 }

}

vertexLabelType GraphTree::getParent(vertexLabelType const &node){

	tree< vertexLabelType >::iterator nodeIterator = 
	find(this->graphTree->begin(), this->graphTree->end(), node-1);


	if(nodeIterator!= this->graphTree->end()) {

	 	return *(tree< vertexLabelType >::parent(nodeIterator))+1;		

	} else{
	 	cout<<"Error: node - "<< node <<" - not found"<<endl;
	 	exit(-2);
	}

	return 0;
}

int GraphTree::getLevel(vertexLabelType const &node){

	tree< vertexLabelType >::iterator nodeIterator = 
	find(this->graphTree->begin(), this->graphTree->end(), node-1);

	int depth = 0;

	if(nodeIterator!= this->graphTree->end()) {

	 	depth = tree< vertexLabelType >::depth(nodeIterator);

	} else{
	 	cout<<"Error: node - "<< node <<" - not found"<<endl;
	 	exit(-2);
	}

	return depth;
}
