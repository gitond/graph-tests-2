#include "../../meta.h"

template <typename graph, typename gVertex, typename path> path dijkstra(graph g, gVertex source, gVertex dest){
	// struct definitions
	struct {
		gVertex current;
		gVertex parent;
	} examinable;

	struct dict {
		gVertex key;
		double val;
	}; // Generic key-value pair, similar to dictionaries in python

	// Algorithm as described in https://github.com/gitond/bsc_thesis_data_structure/blob/main/latex/thesis.pdf
	examinable.current = source; // Parent undefined here
	std::vector<gVertex> visited;
	std::vector<dict> priceLog;
	priceLog.push_back({ source, 0 });

	return 0;
}
