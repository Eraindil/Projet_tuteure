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
#include <vector>
#include <iostream>

struct graphChild{
	ogdf::Graph graph;
	ogdf::NodeArray<ogdf::node> nodeOrigin;
	ogdf::EdgeArray<ogdf::edge> edgeOrigin;

	graphChild();
};

/**
 * \class GraphManager
 * \brief is a class that create and manage some graph. This class can create paramethized undirected graph from a file or randomly.
 */
class GraphManager{

public:

	GraphManager(void);

	~GraphManager(void);

	void wizard(void);

	void addNode(void);

	void addEdge(void);

	/**
	 * \fn genChild
	 * \brief generate a graph and push it in the list of graph child.
	 * @return the graphChild generated
	 */
	graphChild genChild(void);


	void addNodeChild(graphChild &gC, ogdf::node &n);

	void addEdgeChild(graphChild & gC, ogdf::edge &e);

	/**
	 * \fn exportGML
	 * \brief export the current graph and its attributes to a gml file.
	 * @param path is the destination path
	 */
	void exportGML(ogdf::String path);

	/**
	 * \fn exportChildGml
	 * \brief export the current graph with some color on the edges and nodes that correspond of the nodes and edges of the graph child.
	 * @param gC is the graph child
	 * @param path is the path of the output destination
	 */
	void exportChildGml(graphChild & gC, ogdf::String path);



private:

	ogdf::Graph graph; /**< Contains the graph */
	ogdf::NodeArray<int> nodeAttribute; /**< Contains the graph's nodes' attributes */
	ogdf::EdgeArray<int> edgeAttribute; /**< Contains the graph's edges' attributes */
	std::vector<graphChild> children; /**< Contains all children of the current graph */


};


#endif /* GRAPHMANAGER_H_ */
