#ifndef ALGRAPH
#define ALGRAPH

#include <utility>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, double>> listGraphInternal;
typedef boost::graph_traits<listGraphInternal>::vertex_descriptor vertex;
typedef boost::graph_traits<listGraphInternal>::edge_descriptor edge;
typedef boost::graph_traits<listGraphInternal>::vertex_iterator vIter;
typedef boost::graph_traits<listGraphInternal>::edge_iterator eIter;
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
		vertexIndexMap getVertexIndexMap();
		vertex source(edge e);
		vertex target(edge e);
		double getEdgeWeight(edge e);
};

#endif
