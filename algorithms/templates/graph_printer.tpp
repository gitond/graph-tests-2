#include "../../meta.h"

template <typename graph, typename edgeI>void printG(graph g){
	std::pair<edgeI, edgeI> eItrtr;

	std::cout << "New graph with " << g.numVertices() << " vertices, and the following connections: \n";
	for (eItrtr = g.getEdgeIterator(); eItrtr.first != eItrtr.second; eItrtr.first++){
		std::cout
			<< "("
			<< g.source(*eItrtr.first)
			<< ","
			<< g.target(*eItrtr.first)
			<< "); Weight: "
			<< g.getEdgeWeight(*eItrtr.first)
			<< "\n"
		;
	}
}
