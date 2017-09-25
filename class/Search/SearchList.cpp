#include "SearchList.h"

using namespace std;

SearchList::SearchList(Graph * graph):Search(graph){}

GraphTree* SearchList::breadthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	GraphTree* graphTree = new GraphTree(totalVertexes);

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
				graphTree->insertOrUpdate(father,*it);			
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

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	GraphTree* graphTree = new GraphTree(totalVertexes);

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
				//graphTree->insertOrUpdate((*vertexFather)[lifo->top()],lifo->top());
			//}

			//lifoWasPushed = false;

		}

 	}

 	delete vertexFather;

 	delete lifo;

 	return graphTree;

}

GraphTree* SearchList::dijkstra(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	GraphTree* graphTree = new GraphTree(totalVertexes);

	graphTree->insertRoot(node);

	vector<double> distance(totalVertexes,numeric_limits< vertexesTotalLabelType >::infinity());

	priority_queue< iPair, vector <iPair> , greater<iPair> > minHeap;

   	minHeap.push(make_pair(0, node));

   	forward_list< vertexesTotalLabelType >* neighbors;
   	forward_list< float >* neighborsWeight;

    distance[node] = 0;

    while (!minHeap.empty()){

        unsigned int uLabel = minHeap.top().second;
        minHeap.pop();

        neighbors = ((GraphList *)this->graph)->getNeighbors(uLabel);
        neighborsWeight = ((GraphList *)this->graph)->getNeighborsWeight(uLabel);

        forward_list< vertexLabelType >::iterator itNeighbors;
        forward_list< float >::iterator itNeighborsWeight;

        itNeighborsWeight = neighborsWeight->begin();

        for ( itNeighbors = neighbors->begin(); itNeighbors != neighbors->end(); ++itNeighbors ){

        	int v = *itNeighbors;
		    float weight = *itNeighborsWeight;

		    if (distance[v] > distance[uLabel] + weight){

		            distance[v] = distance[uLabel] + weight;
		            minHeap.push(make_pair(distance[v], v));
		            graphTree->insertOrUpdate(uLabel,v);
		    }

			++itNeighborsWeight;
		}

    }

    graphTree->setDistance(distance);

 	return graphTree;

}

GraphTree* SearchList::prim(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	GraphTree* graphTree = new GraphTree(totalVertexes);

	graphTree->insertRoot(node);

	vector<double> cost(totalVertexes,numeric_limits< vertexesTotalLabelType >::infinity());

	priority_queue< iPair, vector <iPair> , greater<iPair> > minHeap;

   	minHeap.push(make_pair(0, node));

   	forward_list< vertexesTotalLabelType >* neighbors;
   	forward_list< float >* neighborsWeight;

    cost[node] = 0;

    while (!minHeap.empty()){

        unsigned int uLabel = minHeap.top().second;
        minHeap.pop();

        neighbors = ((GraphList *)this->graph)->getNeighbors(uLabel);
        neighborsWeight = ((GraphList *)this->graph)->getNeighborsWeight(uLabel);

        forward_list< vertexLabelType >::iterator itNeighbors;
        forward_list< float >::iterator itNeighborsWeight;

        itNeighborsWeight = neighborsWeight->begin();

        for ( itNeighbors = neighbors->begin(); itNeighbors != neighbors->end(); ++itNeighbors ){

        	int v = *itNeighbors;
		    float weight = *itNeighborsWeight;

		    if (cost[v] > weight){

		            cost[v] = weight;
		            minHeap.push(make_pair(cost[v], v));
		            graphTree->insertOrUpdate(uLabel,v);
		    }

			++itNeighborsWeight;
		}

    }

    graphTree->setDistance(cost);

 	return graphTree;

}