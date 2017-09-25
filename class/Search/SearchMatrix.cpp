#include "SearchMatrix.h"

using namespace std;

SearchMatrix::SearchMatrix(Graph * graph):Search(graph){}

GraphTree* SearchMatrix::breadthFirstSearch(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	GraphTree* graphTree = new GraphTree(totalVertexes);

	static vector<float> markedVertexes(totalVertexes,0);

	markedVertexes[node] = true;

	queue< vertexLabelType > *fifo = new queue< vertexLabelType >(); 

	vector<float>* neighbors;

	fifo->push(node);

	graphTree->insertRoot(node);

	vertexLabelType father;


	while (!fifo->empty())
  	{	
  		father = fifo->front();

  		fifo->pop();

  		neighbors = ((GraphMatrix *)this->graph)->getNeighbors(father);
 
  		for (vertexesTotalLabelType i =0; i< totalVertexes; i++){

			if((*neighbors)[i]>0 && !markedVertexes[i]){

				markedVertexes[i] = true;
				fifo->push(i);
				graphTree->insertOrUpdate(father,i);			
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

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	GraphTree* graphTree = new GraphTree(totalVertexes);

	static vector<float> markedVertexes(totalVertexes,0);

	vector< vertexLabelType > *vertexFather = new vector< vertexLabelType >(totalVertexes,0); 

	stack< vertexLabelType > *lifo = new stack< vertexLabelType >(); 

	vector<float>* neighbors;

	//bool lifoWasPushed = false;

	lifo->push(node);

	graphTree->insertRoot(node);

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

				if((*neighbors)[i]>0){ //&& ((*vertexFather)[father]!= i || father == node-1)){

					//lifoWasPushed = true;
				    //cout<< "(*vertexFather)["<<father<<"] = " << (*vertexFather)[father] << endl;
					//cout<<i <<" was pushed"<<endl;
					//(*vertexFather)[i] = father;
					lifo->push(i);
					
				}			

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

GraphTree* SearchMatrix::dijkstra(vertexLabelType const &node){

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

   	vector<float>* neighbors;

    distance[node] = 0;

    while (!minHeap.empty()){

        unsigned int uLabel = minHeap.top().second;
        minHeap.pop();

        neighbors = ((GraphMatrix *)this->graph)->getNeighbors(uLabel);
 
        unsigned int i;
        for (i = 0; i < (*neighbors).size(); i++){

        	if((*neighbors)[i] >0){

		        int v = i;
		        float weight = (*neighbors)[i];

		        if (distance[v] > distance[uLabel] + weight){

		            distance[v] = distance[uLabel] + weight;
		            minHeap.push(make_pair(distance[v], v));
		            graphTree->insertOrUpdate(uLabel,v);
		        }
            }
        }
    }

    graphTree->setDistance(distance);

 	return graphTree;

}

GraphTree* SearchMatrix::prim(vertexLabelType const &node){

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

   	vector<float>* neighbors;

    cost[node] = 0;

    while (!minHeap.empty()){

        unsigned int uLabel = minHeap.top().second;
        minHeap.pop();

        neighbors = ((GraphMatrix *)this->graph)->getNeighbors(uLabel);
 
        unsigned int i;
        for (i = 0; i < (*neighbors).size(); i++){

        	if((*neighbors)[i] >0){

		        int v = i;
		        float weight = (*neighbors)[i];

		        if (cost[v] > weight){

		            cost[v] =  weight;
		            minHeap.push(make_pair(cost[v], v));
		            graphTree->insertOrUpdate(uLabel,v);
		        }
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < totalVertexes; i++)
        printf("%d \t\t %f\n", i+1, cost[i]);

    graphTree->setDistance(cost);

 	return graphTree;

}


