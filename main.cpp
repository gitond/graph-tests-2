#include "meta.h"
#include "classes/datastructures/adj_list_graph.h"

int main() {
	// Crating a graph
	listGraph lg1 = listGraph();
	listGraph lg2 = listGraph(16);

	const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // For easier printing during tests
	vertexIndexMap lg1vIndices = lg1.getVertexIndexMap(); // For easier loopthrough
	vertexIndexMap lg2vIndices = lg2.getVertexIndexMap(); // For easier loopthrough

	// Adding vertices
/*	vertex A = lg1.addVertex();
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
*/
	// Adding edges
/*	std::pair<edge, bool> AB = lg2.addEdge(A,B,1);
	std::pair<edge, bool> AC = lg2.addEdge(A,C,1);
	std::pair<edge, bool> BD = lg2.addEdge(B,D,2);
	std::pair<edge, bool> BE = lg2.addEdge(B,E,1);
	std::pair<edge, bool> CD = lg2.addEdge(C,D,2);
	std::pair<edge, bool> CF = lg2.addEdge(C,F,1);
	std::pair<edge, bool> DH = lg2.addEdge(D,H,3);
	std::pair<edge, bool> EG = lg2.addEdge(E,G,1);
	std::pair<edge, bool> EH = lg2.addEdge(E,H,2);
	std::pair<edge, bool> FH = lg2.addEdge(F,H,2);
	std::pair<edge, bool> FI = lg2.addEdge(F,I,1);
	std::pair<edge, bool> GJ = lg2.addEdge(G,J,2);
	std::pair<edge, bool> GL = lg2.addEdge(G,L,1);
	std::pair<edge, bool> HJ = lg2.addEdge(H,J,3);
	std::pair<edge, bool> HM = lg2.addEdge(H,M,2);
	std::pair<edge, bool> HK = lg2.addEdge(H,K,3);
	std::pair<edge, bool> IK = lg2.addEdge(I,K,2);
	std::pair<edge, bool> IN = lg2.addEdge(I,N,1);
	std::pair<edge, bool> JO = lg2.addEdge(J,O,2);
	std::pair<edge, bool> KP = lg2.addEdge(K,P,2);
	std::pair<edge, bool> LO = lg2.addEdge(L,O,1);
	std::pair<edge, bool> MO = lg2.addEdge(M,O,1);
	std::pair<edge, bool> MP = lg2.addEdge(M,P,1);
	std::pair<edge, bool> NP = lg2.addEdge(N,P,1);
/*

	// Vertex references to std::vector test
	std::vector<vertex> vSet = lg2.getVertexReferenceVector(); // Creation
	// Iteration
/*	for (auto vecItrtr = vSet.begin(); vecItrtr != vSet.end(); vecItrtr++){
		std::cout << alphabet[lg2vIndices[*vecItrtr]] << " ";
	}
	std::cout << "\n";
*/

	// Adding edges
/*	std::pair<edge, bool> AB = lg1.addEdge(A,B,1);
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
*/

	// Iterating through vertices
	std::pair<vIter, vIter> vItrtr; // where the data structure used for iterating through the vertex data is stored
	std::pair<aIter, aIter> aItrtr; // where the data structure used for iterating through the adjacency data is stored
	std::pair<oEIter, oEIter> oEItrtr; // where the data structure used for iterating through each edge leaving the vertex
	for (vItrtr = lg2.getVertexIterator(); vItrtr.first != vItrtr.second; vItrtr.first++){
		std::cout << alphabet[lg2vIndices[*vItrtr.first]] << " Connected to: \n" ;
//		std::cout << alphabet[i] << " " ; // This can also be used to iterate through vertices (no map)

/*
		// Iterating through vertices adjacent to this one
		for (aItrtr = lg1.adjacentVertices(*vItrtr.first); aItrtr.first != aItrtr.second; aItrtr.first++){
			std::cout << alphabet[lg1vIndices[*aItrtr.first]] << " " ;
		}
		std::cout << "Through: \n" ;

		// Iterating through edges leaving this vertex
		for (oEItrtr = lg1.outEdges(*vItrtr.first); oEItrtr.first != oEItrtr.second; oEItrtr.first++){
			std::cout
			<< "("
			<< alphabet[
				lg1vIndices[
					lg1.source(*oEItrtr.first)
				]
			   ]
			<< ","
			<< alphabet[
				lg1vIndices[
					lg1.target(*oEItrtr.first)
				]
			   ]
			<< ") : "
			<< lg1.getEdgeWeight(*oEItrtr.first)
			<< "\n"
			;
		}
*/
	}
	std::cout << "\n";

	// Iterating through all edges of graph
/*	std::pair<eIter, eIter> eItrtr; // where the data structure used for iterating through the edge data is stored
	for (eItrtr = lg1.getEdgeIterator(); eItrtr.first != eItrtr.second; eItrtr.first++){
		std::cout
			<< "("
			<< alphabet[
				lg1vIndices[
					lg1.source(*eItrtr.first)
				]
			   ]
			<< ","
			<< alphabet[
				lg1vIndices[
					lg1.target(*eItrtr.first)
				]
			   ]
			<< ") : "
			<< lg1.getEdgeWeight(*eItrtr.first)
			<< "\n"
		;
	}
*/

	return 0;
}
