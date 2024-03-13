#include "../../meta.h"

template <typename graph>graph randomGraphGenerator(int vertAm){
	graph g = graph(vertAm);

	int v1;
	int v2;

	double rw;
	int maximumWeight = 3; // Arbitrary choice, might want to change/parametrisize later;

	std::vector<std::vector<int>> connections(vertAm); // Needed to check for duplicate edges (adjacency iterator doesn't work for unpopulated graphs and therefore segfaults)

	for(int i=0; i < int(vertAm * 1.25) + std::rand() % vertAm; i++){
		// Generating random vertices
		v2 = std::rand() % vertAm;

		// We don't want any disconnected graphs. The likelyhood of this happening is minimized by forcing every single vertex to have at least one connection
		if (i < vertAm) {
			v1 = i;
		} else {
			v1 = std::rand() % vertAm;
		}

		// Reject connection from V to itself
		if (v1 == v2) {
			//std::cout << "Rejected edge: " << v1 << "-" << v2 << "\n"; 
			i--;
			continue;
		}

		// Reject connection that's already in graph
		if(
			std::find(connections[v1].begin(), connections[v1].end(), v2) != connections[v1].end()
		)	{
				//std::cout << "Found pre-existing connection: " << v1 << "-" << v2 << "\n";
				i--;
				continue;
		}

		// Saving V-W connection by storing W in connections[V]
		connections[v1].push_back(v2);
		connections[v2].push_back(v1);

		rw = (std::rand() % maximumWeight) +1; // Random wieght

		// Adding connection to graph
		g.addEdge(v1,v2,rw);		
	}

	return g;
}
