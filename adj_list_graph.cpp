#include "adj_list_graph.h"

// listGraph -datatype behavior
// Constructors
listGraph::listGraph(){
	listGraphInternal thisGraph;
};

listGraph::listGraph(int VertexAmount){
	listGraphInternal thisGraph(VertexAmount);
};

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

// Only for testing within this file
int main() {
	// Crating a graph
	listGraph lg1 = listGraph();

	// Adding vertices
	vertex A = lg1.addVertex();
	vertex B = lg1.addVertex();
	vertex C = lg1.addVertex();
	vertex D = lg1.addVertex();
	vertex E = lg1.addVertex();
	vertex F = lg1.addVertex();
	vertex G = lg1.addVertex();
	vertex H = lg1.addVertex();
	vertex I = lg1.addVertex();
	vertex J = lg1.addVertex();
	vertex K = lg1.addVertex();
	vertex L = lg1.addVertex();
	vertex M = lg1.addVertex();
	vertex N = lg1.addVertex();
	vertex O = lg1.addVertex();
	vertex P = lg1.addVertex();

	// Adding edges
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

	vertexIndexMap lg1vIndices = lg1.getVertexIndexMap(); // For easier loopthrough

	// Iterating through vertices
	const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::pair<vIter, vIter> vItrtr; // where the data structure used for iterating through the data is stored
	for (vItrtr = lg1.getVertexIterator(); vItrtr.first != vItrtr.second; vItrtr.first++){
		std::cout << alphabet[lg1vIndices[*vItrtr.first]] << " " ;
		//std::cout << alphabet[i] << " " ;
	}
	std::cout << "\n";

	// Iterating through vertices
//	std::pair<eIter, eIter>

	return 0;
}
