#include "../../meta.h"
#include "adj_matrix_graph.h"

//#include <boost/graph/graph_utility.hpp>

// matrixGraph -datatype behavior
// Constructors
matrixGraph::matrixGraph(int VertexAmount):
	thisGraph(boost::adjacency_matrix<boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, double>>(VertexAmount))
	{
	};

// Functions
/*	TEMPORARILY DISABLED DUE TO #14
mVertex matrixGraph::addVertex(int vertexNo){
	mVertex thisVert;
	thisVert = vertexNo;
	return thisVert;
};
*/

// Wrappers for boost functions
std::pair<mEdge, bool> matrixGraph::addEdge(mVertex V1, mVertex V2, double weight){
	return boost::add_edge(V1,V2,weight,thisGraph);
};

std::pair<mVIter, mVIter> matrixGraph::getVertexIterator(){
	return vertices(thisGraph);
};

std::pair<mEIter, mEIter> matrixGraph::getEdgeIterator(){
	return edges(thisGraph);
};

std::pair<mOEIter, mOEIter> matrixGraph::outEdges(mVertex v){
	return boost::out_edges(v, thisGraph);
};

std::pair<mAIter, mAIter> matrixGraph::adjacentVertices(mVertex v){
	return boost::adjacent_vertices(v, thisGraph);
};

mVertexIndexMap matrixGraph::getVertexIndexMap(){
	return boost::get(boost::vertex_index, thisGraph);
};

mVertex matrixGraph::source(mEdge e){
	return boost::source(e, thisGraph);
};

mVertex matrixGraph::target(mEdge e){
	return boost::target(e, thisGraph);
};

double matrixGraph::getEdgeWeight(mEdge e){
	return boost::get(boost::edge_weight, thisGraph, e);
};

int matrixGraph::numVertices(){
	// IMPORTANT! boost::num_vertices() returns vertices_size_type which we force to be int here. May cause problems in the future, potential source of debugging
	return boost::num_vertices(thisGraph);
};

/*
int main() {
  // Relevant tests here

  return 0;
}
*/
