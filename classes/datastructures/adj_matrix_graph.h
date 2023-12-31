#ifndef ALMGRAPH
#define ALMGRAPH

#include <boost/graph/adjacency_matrix.hpp>


// Graph
typedef boost::adjacency_matrix <boost::directedS> matrixGraphInternal;
//typedef boost::adjacency_matrix<boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, double>> matrixGraphInternal;
// Descriptors
typedef boost::graph_traits<matrixGraphInternal>::vertex_descriptor mVertex;
typedef boost::graph_traits<matrixGraphInternal>::edge_descriptor mEdge;
// Iterators
typedef boost::graph_traits<matrixGraphInternal>::vertex_iterator mVIter;
typedef boost::graph_traits<matrixGraphInternal>::edge_iterator mEIter;
typedef boost::graph_traits<matrixGraphInternal>::out_edge_iterator mOEIter;
typedef boost::graph_traits<matrixGraphInternal>::adjacency_iterator mAIter;
// Maps
typedef boost::property_map<matrixGraphInternal, boost::vertex_index_t>::type mVertexIndexMap;

class matrixGraph {
	private:
		matrixGraphInternal thisGraph;
	public:
		// Constructors
		matrixGraph(int VertexAmount);
};

#endif
