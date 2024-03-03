#include "../../meta.h"

template <typename graph, typename gVertex, typename neighborI, typename path>path bfs(graph g, gVertex source, gVertex dest){
	std::vector<gVertex> visited;			// initially lengthless vector
	std::vector<gVertex> parents(g.numVertices());	// vector with length matching graph size
	std::vector<gVertex> pathV;
	gVertex current;

	std::pair<neighborI,neighborI> n;		// A pair of out edge iterators used to check for next possible nodes in pathfinding

	std::deque<gVertex> vQueue;
	vQueue.push_back(source);
	parents[source] = -1;

	while(vQueue.size() != 0){
		current = vQueue.front();
		vQueue.pop_front();

		visited.push_back(current);
		if(current == dest){
			while(parents[current] != -1){
				pathV.insert(pathV.begin(), current);
				current = parents[current];
			}
			pathV.insert(pathV.begin(), current);
		} else {
			for(n = g.adjacentVertices(current); n.first != n.second; n.first++){

				// if a vertex adjacent to the current has not already been visited and is not in the queue of vertices to be visited next, add it to the queue
				if( 
					(std::find(vQueue.begin(), vQueue.end(), *n.first) == vQueue.end()) &&
					(std::find(visited.begin(), visited.end(), *n.first) == visited.end()) 
				)	{
						parents[*n.first] = current;
						vQueue.push_back(*n.first);
				} 
			}
		}
	}

	return pathV;
}
