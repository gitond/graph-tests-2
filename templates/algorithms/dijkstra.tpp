#include "../../meta.h"

template <typename graph, typename gVertex, typename neighborI, typename path> path dijkstra(graph g, gVertex source, gVertex dest){
	// struct definitions
	struct parentChildStruct {
		gVertex current;
		gVertex parent;
	};

	struct dict {
		parentChildStruct key;
		double val;
	}; // Generic key-value pair, similar to dictionaries in python

	struct {
		gVertex from;
		gVertex to;
		double price;
	} minPrice;


	// Variable definitions
	parentChildStruct examinable;
	std::pair<neighborI,neighborI> n; // A pair of out edge iterators used to check for next possible nodes in pathfinding 


	// Algorithm as described in https://github.com/gitond/bsc_thesis_data_structure/blob/main/latex/thesis.pdf
	examinable.current = source; // Parent undefined here
	std::vector<parentChildStruct> visited;
	std::vector<dict> priceLog;
	priceLog.push_back({ examinable, 0 });

	while( visited.size()!=g.numVertices() ){	// When all vertices have been visited, algorithm ends
		visited.push_back(examinable);		
		minPrice.price = g.maxPrice(g.getEdgeIterator()) + 1;
		for(parentChildStruct v : visited){
			for(n = g.outEdges(v.current); n.first != n.second; n.first++){
			}
		}
	}
	// TEST AREA
	// Terrible way of searching for a struct in a vector
	parentChildStruct b1 = { 3,2 };
	parentChildStruct searchable = { 7,2 };
	parentChildStruct v1 = { 5,1 };

	std::vector<parentChildStruct> of = {b1, {4,2} ,v1, {6,1} };

	bool searchableInStruct = false;
	for(parentChildStruct m : of){
		if((m.current == searchable.current) && (m.parent == searchable.parent)){
			searchableInStruct = true;
		}		
	}

	if (!(searchableInStruct)){
		std::cout << "Where they at? ";
	}
 
	// TEST AREA CLOSE

	return 0;
}
