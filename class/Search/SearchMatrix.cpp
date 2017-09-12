#include "SearchMatrix.h"

using namespace std;

SearchMatrix::SearchMatrix(Graph * graph):Search(graph){}

GraphTree* SearchMatrix::breadthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	GraphTree* graphTree = new GraphTree();

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	static vector<bool> markedVertexes(totalVertexes,false);

	markedVertexes[node-1] = true;

	queue< vertexLabelType > *fifo = new queue< vertexLabelType >(); 

	vector<bool>* neighbors;

	fifo->push(node-1);

	graphTree->insertRoot(node-1);

	vertexLabelType father;


	while (!fifo->empty())
  	{	
  		father = fifo->front();

  		fifo->pop();

  		neighbors = ((GraphMatrix *)this->graph)->getNeighbors(father);
 
  		for (vertexesTotalLabelType i =0; i< totalVertexes; i++){

			if((*neighbors)[i] && !markedVertexes[i]){

				markedVertexes[i] = true;
				fifo->push(i);
				graphTree->insert(father,i);			
			}
		}

 	}

 	delete fifo;

 	return graphTree;

}

GraphTree* SearchMatrix::depthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	GraphTree* graphTree = new GraphTree();

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	static vector<bool> markedVertexes(totalVertexes,false);

	vector< vertexLabelType > *vertexFather = new vector< vertexLabelType >(totalVertexes,0); 

	stack< vertexLabelType > *lifo = new stack< vertexLabelType >(); 

	vector<bool>* neighbors;

	bool lifoWasPushed = false;

	lifo->push(node-1);

	graphTree->insertRoot(node-1);

	vertexLabelType father;

	while (!lifo->empty())
  	{	

 		father = lifo->top();

 		lifo->pop();


 		//cout<<"\n lifo-> father = "<< father<<endl;

 		if(!markedVertexes[father]){

 			//cout<<"father entrou no if, father = " <<father <<"\n"<<endl;

 			markedVertexes[father] = true;

 			neighbors = ((GraphMatrix *)this->graph)->getNeighbors(father);

  			for (vertexesTotalLabelType i =0; i< totalVertexes; i++){

				if((*neighbors)[i]){ //&& ((*vertexFather)[father]!= i || father == node-1)){

					//lifoWasPushed = true;
				    //cout<< "(*vertexFather)["<<father<<"] = " << (*vertexFather)[father] << endl;
					//cout<<i <<" was pushed"<<endl;
					//(*vertexFather)[i] = father;
					lifo->push(i);
					
				}			

			}

			//if(lifoWasPushed){
				//cout << "father = " << father << " son = " << lifo->top()<<endl;
				//graphTree->insert((*vertexFather)[lifo->top()],lifo->top());
			//}

			//lifoWasPushed = false;

		}

 	}

 	delete vertexFather;

 	delete lifo;

 	return graphTree;

}