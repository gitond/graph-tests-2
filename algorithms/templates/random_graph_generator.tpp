#include "../../meta.h"

template <typename graph
//		, typename neighborI
	>graph randomGraphGenerator(int vertAm){
	graph g = graph(vertAm);

	int rv1;
	int rv2;

	std::vector<std::vector<int>> connections(vertAm); // Needed to check for duplicate edges (adjacency iterator doesn't work for unpopulated graphs and therefore segfaults)

//	std::pair<neighborI, neighborI> n;

	std::cout << "New graph with " << vertAm << " vertices \n";
	for(int i=0; i < int(vertAm * 1.25) + std::rand() % vertAm; i++){
		// Generating random vertices
		rv1 = std::rand() % vertAm;
		rv2 = std::rand() % vertAm;

		// Reject connection from V to itself
		if (rv1 == rv2) {
			//std::cout << "Rejected edge: " << rv1 << "-" << rv2 << "\n"; 
			i--;
			continue;
		}

		// Reject connection that's already in graph
		std::cout << "Current connections at " << rv1 << ": ";
		for(int i : connections[rv1]){
			std::cout << i << " ";
		}
		std::cout << "\n";

/*		n = g.adjacentVertices(rv1);
		if(
			(std::find(n.first, n.second, rv2) != n.second) // rv1-rv2 connection is in graph
		)	{
//				std::cout << "Found pre-existing connection: " << rv1 << "-" << rv2 << "\n";
//				i--;
//				continue;
		}
*/
		// Saving V-W connection by storing W in connections[V]
		connections[rv1].push_back(rv2);
		connections[rv2].push_back(rv1);

		std::cout << "New edge: " << rv1 << "-" << rv2 << "\n"; 
	}

	return g;
}
