/*
 * graphManager.h
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#ifndef GRAPHMANAGER_H_
#define GRAPHMANAGER_H_

#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/basic/graph_generators.h>
#include <ogdf/basic/String.h>

/**
 * \class GraphManager
 * \brief is a class that create an manage some graph. This class can create paramethized undirected graph from a file or randomly.
 */
template<typename NT =int,typename ET=int> class GraphManager{

public:

	GraphManager(int n, int e);
	GraphManager(ogdf::String str);
	~GraphManager(void);

	void exportGML(ogdf::String str);
	void exportSVG(ogdf::String str);
	void shortestPathFrom(int e);

private:

	ogdf::Graph graphO;
	ogdf::NodeArray<NT> nodeAttribute;
	ogdf::EdgeArray<ET> edgeAttribute;
	//std::vector<ogdf::Graph> childGraph;
	//std::vector<ogdf::GraphAttributes> childGraphAttribute;

};



#endif /* GRAPHMANAGER_H_ */
