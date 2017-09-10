#include "SearchMatrix.h"

using namespace std;

SearchMatrix::SearchMatrix(Graph * graph):Search(graph){}

void SearchMatrix::breadthFirstSearch(unsigned short const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	register unsigned short totalVertexes = this->graph->getTotalVertexes();

	static vector<bool> markedVertexes(totalVertexes,false);

	markedVertexes[node] = true;

	queue<unsigned short> *deck = new queue<unsigned short>(); 

	vector<bool>* neighbors;

	deck->push(node);

	while (!deck->empty())
  	{	
  		neighbors = ((GraphMatrix *)this->graph)->getNeighbors(deck->front());
 
  		for (unsigned short i =0; i< totalVertexes; i++){

			if((*neighbors)[i] && !markedVertexes[i]){

				markedVertexes[i] = true;
				deck->push(i);			
			}
		}

    	deck->pop();
 	}

 	delete deck;

}