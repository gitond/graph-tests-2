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
	bool searchableInStruct;

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
				// n is now an out edge iterator, dereferencing n.first gives us an edge from v.current (source) to adjacent vertex (target)

				/* Is { g.target(*n.first) , v.current } in visited?
				 * where 
				 * v.current		: the vertex we're currently examining
				 * g.target(*n.first)	: any vertex adjacent to it
				 */
				// This is a very inoptimal way for searching for a struct in a vector, a better should be found
				searchableInStruct = false;
				for(parentChildStruct w : visited){
					if((w.current == g.target(*n.first)) && (w.parent == v.current)){
						searchableInStruct = true;
						std::cout << "Found! ";
						break;
					}
				}

//				if (!(searchableInStruct)){
//					std::cout << "Where they at? ";
//				}
			}
		}
	}

	// TEST AREA
	if (visited.size() == 15) {
		examinable.parent = 11;
		std::cout << "ADDED! \n";
	}
	// TEST AREA CLOSE

	return 0;
}
