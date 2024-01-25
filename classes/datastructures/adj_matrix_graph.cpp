#include "../../meta.h"
#include "adj_matrix_graph.h"

//#include <boost/graph/graph_utility.hpp>

// matrixGraph -datatype behavior
// Constructors
matrixGraph::matrixGraph(int VertexAmount):
	thisGraph(boost::adjacency_matrix<boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, double>>(VertexAmount))
	{
	};


/*
int main() {
	// Relevant tests here

	matrixGraph mg1 = matrixGraph(16);

	// Future tests

//	boost::add_edge(2,3,mgU);

	return 0;
}
*/
