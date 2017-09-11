#include "SearchList.h"

using namespace std;

SearchList::SearchList(Graph * graph):Search(graph){}

GraphTree* SearchList::breadthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	GraphTree* graphTree = new GraphTree();

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	static vector<bool> markedVertexes(totalVertexes,false);

	markedVertexes[node-1] = true;

	queue< vertexLabelType > *fifo = new queue< vertexLabelType >(); 

	forward_list< vertexesTotalLabelType >* neighbors;

	fifo->push(node-1);

	graphTree->insertRoot(node-1);

	vertexLabelType father;

	while (!fifo->empty())
  	{	
  		father = fifo->front();

  		fifo->pop();

  		neighbors = ((GraphList *)this->graph)->getNeighbors(father);
 
  		for ( auto it = neighbors->begin(); it != neighbors->end(); ++it ){

			if(!markedVertexes[*it]){

				markedVertexes[*it] = true;
				fifo->push(*it);
				graphTree->insert(father,*it);			
			}
		}

 	}

 	delete fifo;

 	return graphTree;

}

GraphTree* SearchList::depthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	GraphTree* graphTree = new GraphTree();

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	static vector<bool> markedVertexes(totalVertexes,false);

	vector< vertexLabelType > *vertexFather = new vector< vertexLabelType >(totalVertexes,0); 

	stack< vertexLabelType > *lifo = new stack< vertexLabelType >(); 

	forward_list< vertexesTotalLabelType >* neighbors;

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

 			neighbors = ((GraphList *)this->graph)->getNeighbors(father);

  			for ( auto it = neighbors->begin(); it != neighbors->end(); ++it ){

				//&& ((*vertexFather)[father]!= i || father == node-1)){

					//lifoWasPushed = true;
				    //cout<< "(*vertexFather)["<<father<<"] = " << (*vertexFather)[father] << endl;
					//cout<<i <<" was pushed"<<endl;
					//(*vertexFather)[i] = father;
					lifo->push(*it);
					
						

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