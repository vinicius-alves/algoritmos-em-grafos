#include "GraphTree.h"

using namespace std;

GraphTree::GraphTree(){

	this->graphTree = new tree< vertexLabelType >();
}

GraphTree::~GraphTree(){

	delete this->graphTree;
}

void GraphTree::insert(vertexLabelType const &nodeParent,vertexLabelType const &nodeChild){

	
}

vertexLabelType* GraphTree::getParent(vertexLabelType const &node){


}

vertexLabelType* GraphTree::getLevel(vertexLabelType const &node){


}
