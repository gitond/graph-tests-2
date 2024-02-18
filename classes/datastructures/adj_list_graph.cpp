#include "../../meta.h"
#include "adj_list_graph.h"

// listGraph -datatype behavior
// Constructors
/*	TEMPORARILY DISABLED TO MATCH matrixGraph INTERFACE
listGraph::listGraph(){
	listGraphInternal thisGraph;
};
*/

listGraph::listGraph(int VertexAmount){
	listGraphInternal thisGraph(VertexAmount);
};

// Wrappers for boost functions
/*	TEMPORARILY DISABLED DUE TO #14
vertex listGraph::addVertex(int vertexNo){
	vertex thisVert = boost::add_vertex(thisGraph);
	thisVert = vertexNo;
	return thisVert;
};
*/

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

int listGraph::numVertices(){
	// IMPORTANT! boost::num_vertices() returns vertices_size_type which we force to be int here. May cause problems in the future, potential source of debugging
	return boost::num_vertices(thisGraph);
};

// Own functions
double listGraph::maxPrice(std::pair<eIter, eIter> i){ // We expect the appropriate edge iterator as an input
	double maxPr = std::numeric_limits<double>::lowest();
	for (;i.first != i.second; i.first++){
		if (boost::get(boost::edge_weight, thisGraph, *i.first) > maxPr){
			maxPr = boost::get(boost::edge_weight, thisGraph, *i.first);
		}
	}
	return maxPr;
};

// Only for testing within this file
/*
int main() {
	// Relevant tests here
	enum verts { A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P };

	listGraph lg1 = listGraph(16);

	std::pair<edge, bool> AB = lg1.addEdge(A,B,1);
	std::pair<edge, bool> AC = lg1.addEdge(A,C,1);
	std::pair<edge, bool> BD = lg1.addEdge(B,D,2);
	std::pair<edge, bool> BE = lg1.addEdge(B,E,1);
	std::pair<edge, bool> CD = lg1.addEdge(C,D,2);
	std::pair<edge, bool> CF = lg1.addEdge(C,F,1);
	std::pair<edge, bool> DH = lg1.addEdge(D,H,3);
	std::pair<edge, bool> EG = lg1.addEdge(E,G,1);
	std::pair<edge, bool> EH = lg1.addEdge(E,H,2);
	std::pair<edge, bool> FH = lg1.addEdge(F,H,2);
	std::pair<edge, bool> FI = lg1.addEdge(F,I,1);
	std::pair<edge, bool> GJ = lg1.addEdge(G,J,2);
	std::pair<edge, bool> GL = lg1.addEdge(G,L,1);
	std::pair<edge, bool> HJ = lg1.addEdge(H,J,3);
	std::pair<edge, bool> HM = lg1.addEdge(H,M,2);
	std::pair<edge, bool> HK = lg1.addEdge(H,K,3);
	std::pair<edge, bool> IK = lg1.addEdge(I,K,2);
	std::pair<edge, bool> IN = lg1.addEdge(I,N,1);
	std::pair<edge, bool> JO = lg1.addEdge(J,O,2);
	std::pair<edge, bool> KP = lg1.addEdge(K,P,2);
	std::pair<edge, bool> LO = lg1.addEdge(L,O,1);
	std::pair<edge, bool> MO = lg1.addEdge(M,O,1);
	std::pair<edge, bool> MP = lg1.addEdge(M,P,1);
	std::pair<edge, bool> NP = lg1.addEdge(N,P,1);

	double maxPr = lg1.maxPrice(lg1.getEdgeIterator());

	std::cout << maxPr << "\n";

	return 0;
}
*/
