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
			// Placeholder!!!
			std::cout << " Lopussa ollaan! \n";
			break;

			// Body here later
		} else {
			for(n = g.adjacentVertices(current); n.first != n.second; n.first++){
				std::cout << *n.first << " ";
//				vQueue.push(*n.first);
//				if( 
//					std::find(visited.begin(), .end(), item) != vec.end() 
//				)
			}
		}
	}

	std::cout << "\n";



	// TEST AREA //

	std::vector<int> fibonacci{ 1, 1, 2, 3, 5, 8, 13, 21 };
	std::deque<int> evenN;
	for(int i = 1; i <= 4; i++){
		evenN.push_back(2*i);
	}

	// True if 8 not even
	if( std::find(evenN.begin(), evenN.end(), 8) == evenN.end() ){
		std::cout << " 8 is not an even number! \n" ;
	} else {
		std::cout << " 8 is an even number! \n" ;
	}

	// True if 8 not fibonacci number
	if( std::find(fibonacci.begin(), fibonacci.end(), 8) == fibonacci.end() ){
		std::cout << " 8 is not a Fibonacci number! \n" ;
	} else {
		std::cout << " 8 is a Fibonacci number! \n" ;
	}

	// True if 8 not even & not fibonacci number
	if( 
		(std::find(evenN.begin(), evenN.end(), 8) == evenN.end()) &&
		(std::find(fibonacci.begin(), fibonacci.end(), 8) == fibonacci.end()) 
	)	{
			std::cout << " 8 passed! \n" ;
	} else	{
			std::cout << " 8 ain't passing! \n" ;
	}

	return 0;
}
