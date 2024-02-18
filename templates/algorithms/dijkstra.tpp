#include "../../meta.h"

template <typename graph, typename gVertex, typename path> path dijkstra(graph g, gVertex source, gVertex dest){
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



	// Algorithm as described in https://github.com/gitond/bsc_thesis_data_structure/blob/main/latex/thesis.pdf
	examinable.current = source; // Parent undefined here
	std::vector<parentChildStruct> visited;
	std::vector<dict> priceLog;
	priceLog.push_back({ examinable, 0 });

	while( visited.size()!=g.numVertices() ){	// When all vertices have been visited, algorithm ends
		visited.push_back(examinable);		
	}

	return 0;
}
