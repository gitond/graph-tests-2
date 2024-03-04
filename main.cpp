#include "meta.h"
#include "classes/datastructures/adj_list_graph.h"
#include "classes/datastructures/adj_matrix_graph.h"
#include "algorithms/templates/dijkstra.tpp"
#include "algorithms/templates/bfs.tpp"
#include "algorithms/templates/graph_printer.tpp"
#include "algorithms/templates/random_graph_generator.tpp"

int main() {
	enum verts { A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P };

	// List Graph construction
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

	// Matrix Graph Construction
	matrixGraph mg1 = matrixGraph(16);

	std::pair<mEdge, bool> AB_M = mg1.addEdge(A,B,1);
	std::pair<mEdge, bool> AC_M = mg1.addEdge(A,C,1);
	std::pair<mEdge, bool> BD_M = mg1.addEdge(B,D,2);
	std::pair<mEdge, bool> BE_M = mg1.addEdge(B,E,1);
	std::pair<mEdge, bool> CD_M = mg1.addEdge(C,D,2);
	std::pair<mEdge, bool> CF_M = mg1.addEdge(C,F,1);
	std::pair<mEdge, bool> DH_M = mg1.addEdge(D,H,3);
	std::pair<mEdge, bool> EG_M = mg1.addEdge(E,G,1);
	std::pair<mEdge, bool> EH_M = mg1.addEdge(E,H,2);
	std::pair<mEdge, bool> FH_M = mg1.addEdge(F,H,2);
	std::pair<mEdge, bool> FI_M = mg1.addEdge(F,I,1);
	std::pair<mEdge, bool> GJ_M = mg1.addEdge(G,J,2);
	std::pair<mEdge, bool> GL_M = mg1.addEdge(G,L,1);
	std::pair<mEdge, bool> HJ_M = mg1.addEdge(H,J,3);
	std::pair<mEdge, bool> HM_M = mg1.addEdge(H,M,2);
	std::pair<mEdge, bool> HK_M = mg1.addEdge(H,K,3);
	std::pair<mEdge, bool> IK_M = mg1.addEdge(I,K,2);
	std::pair<mEdge, bool> IN_M = mg1.addEdge(I,N,1);
	std::pair<mEdge, bool> JO_M = mg1.addEdge(J,O,2);
	std::pair<mEdge, bool> KP_M = mg1.addEdge(K,P,2);
	std::pair<mEdge, bool> LO_M = mg1.addEdge(L,O,1);
	std::pair<mEdge, bool> MO_M = mg1.addEdge(M,O,1);
	std::pair<mEdge, bool> MP_M = mg1.addEdge(M,P,1);
	std::pair<mEdge, bool> NP_M = mg1.addEdge(N,P,1);
/*
	// Printing graphs
	printG<listGraph, eIter>(lg1);
	printG<matrixGraph, mEIter>(mg1);
*/
	// Running algorithms and printing results
	const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// BFS
	std::cout << "Running BFS from G to P in list-type reference graph: ";
	for(vertex v : bfs<listGraph, vertex, aIter, std::vector<vertex>>(lg1, G, P)){
		std::cout << alphabet[v] << " ";
	}
	std::cout << "\n";
	std::cout << "Running BFS from G to P in matrix-type reference graph: ";
	for(mVertex v : bfs<matrixGraph, mVertex, mAIter, std::vector<mVertex>>(mg1, G, P)){
		std::cout << alphabet[v] << " ";
	}
	std::cout << "\n";

	// Dijkstra
	std::cout << "Running Dijkstra from G to P in list-type reference graph: ";
	for(vertex v : dijkstra<listGraph, vertex, oEIter, std::vector<vertex>>(lg1, G, P)){
		std::cout << alphabet[v] << " ";
	}
	std::cout << "\n";
	std::cout << "Running Dijkstra from G to P in matrix-type reference graph: ";
	for(mVertex v : dijkstra<matrixGraph, mVertex, mOEIter, std::vector<mVertex>>(mg1, G, P)){
		std::cout << alphabet[v] << " ";
	}
	std::cout << "\n";

	// Experimenting with random graphs
	listGraph lg2 = randomGraphGenerator<listGraph>(16);
	matrixGraph mg2 = randomGraphGenerator<matrixGraph>(16);
	printG<listGraph, eIter>(lg2);
	printG<matrixGraph, mEIter>(mg2);

	return 0;
}
