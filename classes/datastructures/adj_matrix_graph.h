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

class listGraph {
	private:
		matrixGraphInternal thisGraph;
		mVertex nullNode; // Explanation below

	       /**
		* In order to make this class work generically (in a template-
		* based environment) it has to match the listGraph class (have
		* all the same functions that do the same kind of stuff.
		* However boost::adjacency_matrix does not have an
		* add_vertex() function but we still have to provide one here
		* to match the listGraph class. The solution here is to add
		* a nullNode and add new vertices by adding an edge between
		* null and the new vertex, that has the biggest supported
		* weight so it does not affect pathfinding.
		*
		* CONSTRAINTS:
		* All vertices must be connected to NullNode
		* (NullNode, v) connection weight must be DoubleMax
		*/
}

#endif
