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

/**
 * \struct graphChild
 * \brief is a struct that contain a graph link to an other graph.
 */
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

	GraphManager(ogdf::String path);

	~GraphManager(void);

	/**
	 * \fn addNode
	 * \brief add a node to the main graph
	 */
	void addNode(void);

	/**
	 * \fn addEdge
	 * \brief add an edge to the main graph
	 */
	void addEdge(void);

	ogdf::Graph& getGraph(void);

	ogdf::GraphAttributes& getGraphAttribute(void);

	/**
	 * \fn genChild
	 * \brief generate a graph and push it in the list of graph child.
	 * @return the graphChild generated
	 */
	graphChild genChild(void);


	/**
	 * \fn addNodeChild
	 * \brief add a node to a graph corresponding to a node of the main graph
	 * @param gC the graph child target
	 * @param n node from the main graph
	 */
	void addNodeChild(graphChild &gC, ogdf::node &n);

	/**
	 * \fn addEdgeChild
	 * \brief add an edge to a graph corresponding to an edge of the main graph
	 * @param gC the graph child target
	 * @param e	edge from the main graph
	 */
	void addEdgeChild(graphChild & gC, ogdf::edge &e);

	/**
	 * \fn getChildren
	 * @return the vector containing all the children of the current graph.
	 */
	std::vector<graphChild> getChildren(void);

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

	/**
	 * \fn init
	 * \brief permit to share the default constructor code.
	 */
	void init(void);

	void readNetwork(ogdf::String path);

	ogdf::Graph graph; /**< Contains the graph */
	ogdf::GraphAttributes graphAttribute; /**< Contains the attributes of the graph */
	std::vector<graphChild> children; /**< Contains all children of the current graph */


};


#endif /* GRAPHMANAGER_H_ */
