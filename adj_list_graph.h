#ifndef ALGRAPH
#define ALGRAPH

#include "vertex_data.h" // used elsewhere -> might cause problems later

#include <iostream>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vertexData> adjListGraphInternal;
typedef boost::graph_traits<adjListGraphInternal>::vertex_descriptor vertex;
typedef boost::property_map<adjListGraphInternal, boost::vertex_index_t>::type vertexIndexMap;

class adjListGraph {
	private:
		adjListGraphInternal thisGraph;
	public:
		// Constructors
		adjListGraph();
		adjListGraph(int VertexAmount);

		// Wrappers for boost funcions
		void addVertex(vertexData d);
};

#endif
