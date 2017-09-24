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

	static vector<float> markedVertexes(totalVertexes,0);

	markedVertexes[node-1] = true;

	queue< vertexLabelType > *fifo = new queue< vertexLabelType >(); 

	vector<float>* neighbors;

	fifo->push(node-1);

	graphTree->insertRoot(node-1);

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

	static vector<float> markedVertexes(totalVertexes,0);

	vector< vertexLabelType > *vertexFather = new vector< vertexLabelType >(totalVertexes,0); 

	stack< vertexLabelType > *lifo = new stack< vertexLabelType >(); 

	vector<float>* neighbors;

	//bool lifoWasPushed = false;

	lifo->push(node-1);

	graphTree->insertRoot(node-1);

	vertexLabelType father;

	while (!lifo->empty())
  	{	

 		father = lifo->top();

 		lifo->pop();


 		//cout<<"\n lifo-> father = "<< father<<endl;

 		if(markedVertexes[father]<=0){

 			//cout<<"father entrou no if, father = " <<father <<"\n"<<endl;

 			markedVertexes[father] = 1;

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
				//graphTree->insert((*vertexFather)[lifo->top()],lifo->top());
			//}

			//lifoWasPushed = false;

		}

 	}

 	delete vertexFather;

 	delete lifo;

 	return graphTree;

}

GraphTree* SearchMatrix::djikstra(vertexLabelType const &node){

	if (node >= this->graph->getTotalVertexes()){
		cout<<"Error : Node doesn't belong to graph"<<endl;
		exit(-1);
	}

	GraphTree* graphTree = new GraphTree();

	register vertexesTotalLabelType totalVertexes = this->graph->getTotalVertexes();

	vector<unsigned int> distance(totalVertexes,numeric_limits< vertexesTotalLabelType >::max());

	priority_queue< iPair, vector <iPair> , greater<iPair> > minHeap;

   	minHeap.push(make_pair(0, node));

   	vector<float>* neighbors;

    distance[node] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!minHeap.empty()){

        unsigned int uLabel = minHeap.top().second;
        minHeap.pop();

        neighbors = ((GraphMatrix *)this->graph)->getNeighbors(uLabel);
 
        // 'i' is used to get all adjacent vertices of a vertex
        unsigned int i;
        for (i = 0; i < (*neighbors).size(); i++){

        	if((*neighbors)[i] >0){
		        // Get vertex label and weight of current adjacent
		        // of u.
		        int v = i;
		        float weight = (*neighbors)[i];

		        //  If there is shorted path to v through u.
		        if (distance[v] > distance[uLabel] + weight){
		            // Updating distance of v
		            distance[v] = distance[uLabel] + weight;
		            minHeap.push(make_pair(distance[v], v));
		        }
            }
        }
    }

        // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < totalVertexes; i++)
        printf("%d \t\t %d\n", i, distance[i]);


















 	return graphTree;

}