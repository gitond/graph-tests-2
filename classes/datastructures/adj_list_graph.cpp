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

// Only for testing within this file

/*
int main() {
	// Relevant tests here

//	listGraphInternal thisGraph(16);

/*	vertex A = boost::add_vertex(thisGraph);
	vertex B = boost::add_vertex(thisGraph);
	vertex C = boost::add_vertex(thisGraph);
	vertex D = boost::add_vertex(thisGraph);
	vertex E = boost::add_vertex(thisGraph);
	vertex F = boost::add_vertex(thisGraph);
	vertex G = boost::add_vertex(thisGraph);
	vertex H = boost::add_vertex(thisGraph);
	vertex I = boost::add_vertex(thisGraph);
	vertex J = boost::add_vertex(thisGraph);
	vertex K = boost::add_vertex(thisGraph);
	vertex L = boost::add_vertex(thisGraph);
	vertex M = boost::add_vertex(thisGraph);
	vertex N = boost::add_vertex(thisGraph);
	vertex O = boost::add_vertex(thisGraph);
	vertex P = boost::add_vertex(thisGraph);
*//*

	enum verts { A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P };

/*	std::pair<edge, bool> AB = boost::add_edge(A,B,1,thisGraph);
	std::pair<edge, bool> AC = boost::add_edge(A,C,1,thisGraph);
	std::pair<edge, bool> BD = boost::add_edge(B,D,2,thisGraph);
	std::pair<edge, bool> BE = boost::add_edge(B,E,1,thisGraph);
	std::pair<edge, bool> CD = boost::add_edge(C,D,2,thisGraph);
	std::pair<edge, bool> CF = boost::add_edge(C,F,1,thisGraph);
	std::pair<edge, bool> DH = boost::add_edge(D,H,3,thisGraph);
	std::pair<edge, bool> EG = boost::add_edge(E,G,1,thisGraph);
	std::pair<edge, bool> EH = boost::add_edge(E,H,2,thisGraph);
	std::pair<edge, bool> FH = boost::add_edge(F,H,2,thisGraph);
	std::pair<edge, bool> FI = boost::add_edge(F,I,1,thisGraph);
	std::pair<edge, bool> GJ = boost::add_edge(G,J,1,thisGraph);
	std::pair<edge, bool> GL = boost::add_edge(G,L,1,thisGraph);
	std::pair<edge, bool> HJ = boost::add_edge(H,J,3,thisGraph);
	std::pair<edge, bool> HM = boost::add_edge(H,M,2,thisGraph);
	std::pair<edge, bool> HK = boost::add_edge(H,K,3,thisGraph);
	std::pair<edge, bool> IK = boost::add_edge(I,K,2,thisGraph);
	std::pair<edge, bool> IN = boost::add_edge(I,N,1,thisGraph);
	std::pair<edge, bool> JO = boost::add_edge(J,O,1,thisGraph);
	std::pair<edge, bool> KP = boost::add_edge(K,P,2,thisGraph);
	std::pair<edge, bool> LO = boost::add_edge(L,O,1,thisGraph);
	std::pair<edge, bool> MO = boost::add_edge(M,O,1,thisGraph);
	std::pair<edge, bool> MP = boost::add_edge(M,P,1,thisGraph);
	std::pair<edge, bool> NP = boost::add_edge(N,P,1,thisGraph);

	std::cout << boost::num_vertices(thisGraph) << "\n";
*//*

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

	return 0;
}
*/
