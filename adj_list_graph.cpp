#include "adj_list_graph.h"

// This is the definition for the constructor of graph.
// The class definition as well as the declarations are in the header "adj_list_graph.h"
adjListGraph::adjListGraph(){
	adjListGraphInternal thisGraph;
}

// Constructor for graph with predefined number of vertices
adjListGraph::adjListGraph(int VertexAmount){
	adjListGraphInternal thisGraph(VertexAmount);
}

// Vertex adding function
void adjListGraph::addVertex(vertexData d){
	// vertexData is a structure with { int X, int Y }
	boost::add_vertex(d, thisGraph);
}

// Only for testing within this file
int main() {
	adjListGraph refGraphL1 = adjListGraph(16);
	adjListGraph refGraphL2 = adjListGraph();

	refGraphL1.addVertex({ 0,0 });
	refGraphL2.addVertex({ 0,0 });

/*	typedef std::pair<int, int> Edge;
	Edge edge_array[] = { Edge(0,1), Edge(0,2), Edge(0,3), Edge(1,3), Edge(2,3), Edge(2,4), Edge(3,4) };
	const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);

	for (int i = 0; i < num_edges; i++) {
		boost::add_edge(edge_array[i].first, edge_array[i].second, refGraphL2);
	}
*/
	return 0;
}
