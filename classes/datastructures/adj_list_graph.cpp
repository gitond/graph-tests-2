#include "../../meta.h"
#include "adj_list_graph.h"

// listGraph -datatype behavior
// Constructors
listGraph::listGraph(){
	listGraphInternal thisGraph;
};

listGraph::listGraph(int VertexAmount){
	listGraphInternal thisGraph(VertexAmount);
};

// Wrappers for boost functions
vertex listGraph::addVertex(){
	return boost::add_vertex(thisGraph);
};

std::pair<edge, bool> listGraph::addEdge(vertex V1, vertex V2, double weight){
	return boost::add_edge(V1,V2,weight,thisGraph);
};

std::pair<vIter, vIter> listGraph::getVertexIterator(){
	return vertices(thisGraph);
};

std::pair<eIter, eIter> listGraph::getEdgeIterator(){
	return edges(thisGraph);
};

vertexIndexMap listGraph::getVertexIndexMap(){
	return boost::get(boost::vertex_index, thisGraph);
};

vertex listGraph::source(edge e){
	return boost::source(e, thisGraph);
};

vertex listGraph::target(edge e){
	return boost::target(e, thisGraph);
};

double listGraph::getEdgeWeight(edge e){
	return boost::get(boost::edge_weight, thisGraph, e);
};

std::pair<oEIter, oEIter> listGraph::outEdges(vertex v){
	return boost::out_edges(v, thisGraph);
};

std::pair<aIter, aIter> listGraph::adjacentVertices(vertex v){
	return boost::adjacent_vertices(v, thisGraph);
};

// Other functions
std::vector<vertex> listGraph::getVertexReferenceVector(){
	std::vector<vertex> v;

	// Looping through vertices and putting them each into v
	std::pair<vIter, vIter> iterator;
	for (iterator = vertices(thisGraph); iterator.first != iterator.second; iterator.first++){
		v.push_back(*iterator.first);
	}
	v.shrink_to_fit();
	return v;
};

// Only for testing within this file
/*
int main() {
	// Relevant tests here
	return 0;
}
*/
