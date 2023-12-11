#include "../../meta.h"
#include "adj_matrix_graph.h"

//#include <boost/graph/graph_utility.hpp>

// matrixGraph -datatype behavior
// Constructors
matrixGraph::matrixGraph(int VertexAmount):
	thisGraph(boost::adjacency_matrix(16))
	{
	//	thisGraph = boost::adjacency_matrix(16);
	//	matrixGraphInternal mg1 = boost::adjacency_matrix(16, boost::directedS);
	};


/*
int main() {
	// Relevant tests here
//	matrixGraph mg1 = matrixGraph(16);
//	matrixGraphInternal thisGraph(16);
	matrixGraph mg1 = matrixGraph(16);
/*
	boost::add_edge(2,3,mg1);
	boost::add_edge(2,6,mg1);
	boost::add_edge(3,1,mg1);

	std::cout << "vertex set: ";

	std::pair<mVIter,mVIter> vSet;
	for (vSet = boost::vertices(mg1); vSet.first != vSet.second; vSet.first++){
		std::cout << *vSet.first << " ";
	}

	std::cout << std::endl;

	return 0;
}
*/
