#ifndef ALGRAPH
#define ALGRAPH

#include <utility>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>

// Graph
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, double>> listGraphInternal;
// Descriptors
typedef boost::graph_traits<listGraphInternal>::vertex_descriptor vertex;
typedef boost::graph_traits<listGraphInternal>::edge_descriptor edge;
// Iterators
typedef boost::graph_traits<listGraphInternal>::vertex_iterator vIter;
typedef boost::graph_traits<listGraphInternal>::edge_iterator eIter;
typedef boost::graph_traits<listGraphInternal>::out_edge_iterator oEIter;
typedef boost::graph_traits<listGraphInternal>::adjacency_iterator aIter;
// Maps
typedef boost::property_map<listGraphInternal, boost::vertex_index_t>::type vertexIndexMap;

class listGraph {
	private:
		listGraphInternal thisGraph;
	public:
		// Constructors
		listGraph();
		listGraph(int VertexAmount);

		// Wrappers for boost funcions
		vertex addVertex();
		std::pair<edge, bool> addEdge(vertex V1, vertex V2, double weight);
		std::pair<vIter, vIter> getVertexIterator();
		std::pair<eIter, eIter> getEdgeIterator();
		std::pair<oEIter, oEIter> outEdges(vertex v);
		std::pair<aIter, aIter> adjacentVertices(vertex v);
		vertexIndexMap getVertexIndexMap();
		vertex source(edge e);
		vertex target(edge e);
		double getEdgeWeight(edge e);
};

#endif
