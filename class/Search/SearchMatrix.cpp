#include "SearchMatrix.h"

using namespace std;

SearchMatrix::SearchMatrix(Graph * graph):Search(graph){}

void SearchMatrix::breadthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	static vector<bool> markedVertexes(totalVertexes,false);

	markedVertexes[node] = true;

	queue< vertexLabelType > *deck = new queue< vertexLabelType >(); 

	vector<bool>* neighbors;

	deck->push(node);

	while (!deck->empty())
  	{	
  		neighbors = ((GraphMatrix *)this->graph)->getNeighbors(deck->front());
 
  		for (vertexesTotalLabelType i =0; i< totalVertexes; i++){

			if((*neighbors)[i] && !markedVertexes[i]){

				markedVertexes[i] = true;
				deck->push(i);			
			}
		}

    	deck->pop();
 	}

 	delete deck;

}