#include "meta.h"
#include "classes/datastructures/adj_list_graph.h"
#include "classes/datastructures/adj_matrix_graph.h"

int main() {
	// Crating a graph
	listGraph lg1 = listGraph(16);
	matrixGraph mg1 = matrixGraph(16);

	// Adding vertices
	vertex A = lg1.addVertex(0);
	vertex B = lg1.addVertex(1);
	vertex C = lg1.addVertex(2);
	vertex D = lg1.addVertex(3);
	vertex E = lg1.addVertex(4);
	vertex F = lg1.addVertex(5);
	vertex G = lg1.addVertex(6);
	vertex H = lg1.addVertex(7);
	vertex I = lg1.addVertex(8);
	vertex J = lg1.addVertex(9);
	vertex K = lg1.addVertex(10);
	vertex L = lg1.addVertex(11);
	vertex M = lg1.addVertex(12);
	vertex N = lg1.addVertex(13);
	vertex O = lg1.addVertex(14);
	vertex P = lg1.addVertex(15);

	mVertex mA = mg1.addVertex(0);
	mVertex mB = mg1.addVertex(1);
	mVertex mC = mg1.addVertex(2);
	mVertex mD = mg1.addVertex(3);
	mVertex mE = mg1.addVertex(4);
	mVertex mF = mg1.addVertex(5);
	mVertex mG = mg1.addVertex(6);
	mVertex mH = mg1.addVertex(7);
	mVertex mI = mg1.addVertex(8);
	mVertex mJ = mg1.addVertex(9);
	mVertex mK = mg1.addVertex(10);
	mVertex mL = mg1.addVertex(11);
	mVertex mM = mg1.addVertex(12);
	mVertex mN = mg1.addVertex(13);
	mVertex mO = mg1.addVertex(14);
	mVertex mP = mg1.addVertex(15);

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

	std::pair<mEdge, bool> AB_M = mg1.addEdge(mA,mB,1);
	std::pair<mEdge, bool> AC_M = mg1.addEdge(mA,mC,1);
	std::pair<mEdge, bool> BD_M = mg1.addEdge(mB,mD,2);
	std::pair<mEdge, bool> BE_M = mg1.addEdge(mB,mE,1);
	std::pair<mEdge, bool> CD_M = mg1.addEdge(mC,mD,2);
	std::pair<mEdge, bool> CF_M = mg1.addEdge(mC,mF,1);
	std::pair<mEdge, bool> DH_M = mg1.addEdge(mD,mH,3);
	std::pair<mEdge, bool> EG_M = mg1.addEdge(mE,mG,1);
	std::pair<mEdge, bool> EH_M = mg1.addEdge(mE,mH,2);
	std::pair<mEdge, bool> FH_M = mg1.addEdge(mF,mH,2);
	std::pair<mEdge, bool> FI_M = mg1.addEdge(mF,mI,1);
	std::pair<mEdge, bool> GJ_M = mg1.addEdge(mG,mJ,2);
	std::pair<mEdge, bool> GL_M = mg1.addEdge(mG,mL,1);
	std::pair<mEdge, bool> HJ_M = mg1.addEdge(mH,mJ,3);
	std::pair<mEdge, bool> HM_M = mg1.addEdge(mH,mM,2);
	std::pair<mEdge, bool> HK_M = mg1.addEdge(mH,mK,3);
	std::pair<mEdge, bool> IK_M = mg1.addEdge(mI,mK,2);
	std::pair<mEdge, bool> IN_M = mg1.addEdge(mI,mN,1);
	std::pair<mEdge, bool> JO_M = mg1.addEdge(mJ,mO,2);
	std::pair<mEdge, bool> KP_M = mg1.addEdge(mK,mP,2);
	std::pair<mEdge, bool> LO_M = mg1.addEdge(mL,mO,1);
	std::pair<mEdge, bool> MO_M = mg1.addEdge(mM,mO,1);
	std::pair<mEdge, bool> MP_M = mg1.addEdge(mM,mP,1);
	std::pair<mEdge, bool> NP_M = mg1.addEdge(mN,mP,1);

	vertexIndexMap lg1vIndices = lg1.getVertexIndexMap(); // For easier loopthrough

	// Iterating through vertices
	const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::pair<vIter, vIter> vItrtr; // where the data structure used for iterating through the vertex data is stored
	std::pair<aIter, aIter> aItrtr; // where the data structure used for iterating through the adjacency data is stored
	std::pair<oEIter, oEIter> oEItrtr; // where the data structure used for iterating through each edge leaving the vertex
	for (vItrtr = lg1.getVertexIterator(); vItrtr.first != vItrtr.second; vItrtr.first++){
		std::cout << alphabet[lg1vIndices[*vItrtr.first]] << " Connected to: \n" ;
		//std::cout << alphabet[i] << " " ; // This can also be used to iterate through vertices (no map)

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
