#include "../../meta.h"

template <typename graph, typename gVertex, typename neighborI, typename path> path dijkstra(graph g, gVertex s, gVertex d){
	// Variable setups
	std::vector<bool> unvisited(g.numVertices(), true);		// a vector with a true value for each vertex (all of them are unvisited at this point)
	std::vector<double> distances(g.numVertices(), std::numeric_limits<double>::max());
	distances[s] = 0.0d;
	std::vector<gVertex> parents(g.numVertices(), -2);		// we use the default value -2 for all parents that are not calculated yet
	parents[s] = -1;						// we use -1 to mark the source vertex in the parent data
	std::vector<gVertex> pathV;

	std::pair<neighborI,neighborI> n;				// A pair of out edge iterators used to check for next possible nodes in pathfinding
	double nWeight;
	double minDist;
	gVertex minDistInd;

	gVertex previous;

	gVertex current = s;
	int i = 0;

	// Dijkstra's algorithm
	while(i <= g.numVertices()) {
		// Iterating through all neighbors of current
		for(n = g.outEdges(current); n.first != n.second; n.first++){
			/*
			 *	Here
			 *	g.target(*n.first)
			 *	loops through all neighbors of the current vertex
			 */
			if(unvisited[g.target(*n.first)]) {
			// If neighbor of current vertex is unvisited:
				nWeight = distances[current] + g.getEdgeWeight(*n.first);
				if(distances[g.target(*n.first)] > nWeight){
					distances[g.target(*n.first)] = nWeight;
					parents[g.target(*n.first)] = current;
				}
			}
		}
		// Calculating vertex to be examined next
		// Variable setup
		unvisited[current] = false;
		minDist = std::numeric_limits<double>::max();
		minDistInd = -1;
		for(int u = 0; u < g.numVertices(); u++){
			if(unvisited[u]){
				if(distances[u] < minDist){
					minDist = distances[u];
					minDistInd = u;
				}
			}
		}
		current = minDistInd;
		if(current == d){
			break;
		}
		i++;
	}

	// Returning path
	previous = parents[current];
	while(previous != -1){
		pathV.insert(pathV.begin(), current);
		current = previous;
		previous = parents[current];
	}
	pathV.insert(pathV.begin(), s);

	return pathV;
}
