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
mVertex matrixGraph::addVertex(int vertexNo){
	mVertex thisVert;
	thisVert = vertexNo;
	return thisVert;
};

// Wrappers for boost functions
std::pair<mEdge, bool> matrixGraph::addEdge(mVertex V1, mVertex V2, double weight){
	return boost::add_edge(V1,V2,weight,thisGraph);
};

std::pair<mVIter, mVIter> matrixGraph::getVertexIterator(){
	return vertices(thisGraph);
};

/*
int main() {
	// Relevant tests here

	// Experiments with matrix graphs
	matrixGraph mg1 = matrixGraph(16);	// Constructor ok, this works

	// addVertex() command works, no problem here
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

	// addEdge() works fine too, issue with segfaulting has been fixed
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

	// Attempt at looping through vertices
	// Helping variables:
	const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // For printing
	int i = 0; // Loop count variable
	std::pair<mVIter,mVIter> vItrtr;  // where the data structure used for iterating through the vertex data is stored

	// Looping through vertices
	for(vItrtr = mg1.getVertexIterator(); vItrtr.first != vItrtr.second; vItrtr.first++){
		std::cout << alphabet[i]  << " " ; // This can also be used to iterate through vertices (no map)
		i++;
	}

	std::cout << "\n";
	return 0;
}
*/
