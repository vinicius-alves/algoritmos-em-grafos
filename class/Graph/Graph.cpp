#include "Graph.h"

void Graph::setTotalVertexes(vertexesTotalLabelType total){

	this->totalVertexes = total;
	this->initializeStructure();
}

void Graph::setTotalEdges(edgesTotalLabelType total){

	this->totalEdges = total;
}

edgesTotalLabelType Graph::getTotalVertexes(){

	return this->totalVertexes;
}

void Graph::initializeStructure(){
	this->valences = new vector< vertexesTotalLabelType >(this->totalVertexes,0);
	this->frequencyOfValences = new vector< edgesTotalLabelType >(this->totalVertexes-1,0);
}

void Graph::addEdge(vertexLabelType const &vertex, vertexLabelType const &neighbor){

	(*valences)[vertex] += 1;
	(*valences)[neighbor] += 1;
}

void Graph::calcRelativeFrequencyValences(){

	for (vector< vertexesTotalLabelType >::iterator firstIt = (*this->valences).begin(); 
		firstIt!= (*this->valences).end(); ++firstIt){

		(*frequencyOfValences)[*firstIt]++;			
	}

}

void Graph::print(){

	this->calcRelativeFrequencyValences();

	Writter *writter = new Writter("results.txt");

	(*writter->content) << "\nGraph Information"<< endl;
	(*writter->content) << "Total of vertexes: "<< this->totalVertexes << endl;
	(*writter->content) << "Total of edges: "<< this->totalEdges << endl;
	(*writter->content) << "Average Valence: "<< setprecision(3) << fixed << this->totalEdges*1.0/this->totalVertexes<< endl;
	(*writter->content) << endl;

	cout<< "\nGraph Information" << endl;
	cout<< "Total of vertexes: "<< this->totalVertexes << endl;
	cout<< "Total of edges: "<< this->totalEdges << endl;
	cout<< "Average Valence: "<< setprecision(3) << fixed << this->totalEdges*1.0/this->totalVertexes<< endl;
	cout<< endl;

	for (edgesTotalLabelType i = 0; i< frequencyOfValences->size(); i++){

		if((*this->frequencyOfValences)[i] >0){
			cout << "Frequency of valence " << i << " : "<< setprecision(6) << (*this->frequencyOfValences)[i]*1.0/this->totalVertexes << endl;
			(*writter->content) << "Frequency of valence " << i << " : "<< setprecision(6) << (*this->frequencyOfValences)[i]*1.0/this->totalVertexes << endl;
		} 			
	}
	cout << "\nThe others have frequency = 0\n"<<endl;
	(*writter->content) << "\nThe others have frequency = 0\n"<<endl;

	writter->closeFile();
	delete writter;

	cout<< endl;

}