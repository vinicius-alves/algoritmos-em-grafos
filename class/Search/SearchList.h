#include <vector>
#include <forward_list>
#include "Search.h"
#include "../Graph/GraphList.h"

using namespace std;

#ifndef SEARCHLIST_H
#define SEARCHLIST_H

class SearchList : public Search{

	public:
		SearchList(Graph * graph);
		virtual GraphTree* breadthFirstSearch(vertexLabelType const &node);
		virtual GraphTree* depthFirstSearch(vertexLabelType const &node);

};

#endif