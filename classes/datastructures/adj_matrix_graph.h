#ifndef ALMGRAPH
#define ALMGRAPH

#include <boost/graph/adjacency_matrix.hpp>


// Graph
typedef boost::adjacency_matrix<boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, double>> matrixGraphInternal;
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
		// Functions
//		mVertex addVertex(int vertexNo);	// TEMPORARILY DISABLED DUE TO #14
		// Wrappers for boost functions
		std::pair<mEdge, bool> addEdge(mVertex V1, mVertex V2, double weight);
		std::pair<mVIter,mVIter> getVertexIterator();
		std::pair<mEIter,mEIter> getEdgeIterator();
		std::pair<mOEIter,mOEIter> outEdges(mVertex v);
		std::pair<mAIter,mAIter> adjacentVertices(mVertex v);
		mVertexIndexMap getVertexIndexMap();
		mVertex source(mEdge e);
		mVertex target(mEdge e);
		double getEdgeWeight(mEdge e);
		int numVertices();
};

#endif
