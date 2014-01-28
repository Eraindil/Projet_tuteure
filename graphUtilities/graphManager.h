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
#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/basic/String.h>
#include <vector>
#include <iostream>

/**
 * \struct graphChild
 * \brief graphChild is a struct that contain a graph link to an other graph.
 */
struct graphChild{
	ogdf::Graph graph;
	ogdf::NodeArray<ogdf::node> nodeOrigin;
	ogdf::EdgeArray<ogdf::edge> edgeOrigin;

	graphChild();
};

/**
 * \class GraphManager
 * \brief GraphManager is a class that create and manage some graph. This class can create paramethized undirected graph from a file or randomly.
 */
class GraphManager{

public:

	/**
	 * \fn GraphManager
	 * \brief This constructor init the object with an empty graph and graphAttributes relative to the graph.
	 */
	GraphManager(void);

	/**
	 * \fn GraphManager
	 * \brief This constructor init the object with graph and graphAttributes from a gml file.
	 * @param path is the path to the gml file.
	 */
	GraphManager(ogdf::String path);

	/**
	 *
	 */
	~GraphManager(void);

	/**
	 * \fn genRandomGraph
	 * \brief This method can generate a random graph.
	 * @param n is the number of nodes.
	 * @param e is the number of edges.
	 */
	void genRandomGraph(int n, int e);

	/**
	 * \fn addNode
	 * \brief this method add a node to the main graph
	 */
	void addNode(void);

	/**
	 * \fn addEdge
	 * \brief this method add an edge to the main graph
	 */
	void addEdge(void);

	/**
	 * \fn getGraph
	 * @return this->graph
	 */
	ogdf::Graph& getGraph(void);

	/**
	 * \fn getGraphAttribute
	 * @return this->graphAttribute
	 */
	ogdf::GraphAttributes& getGraphAttribute(void);

	/**
	 * \fn genChild
	 * \brief this function generate a graph and push it in the list of graph child.
	 * @return the graphChild generated
	 */
	graphChild genChild(void);


	/**
	 * \fn addNodeChild
	 * \brief This method add a node to a graph corresponding to a node of the main graph
	 * @param gC the graph child target
	 * @param n node from the main graph
	 */
	void addNodeChild(graphChild &gC, ogdf::node &n);

	/**
	 * \fn addEdgeChild
	 * \brief This method add an edge to a graph corresponding to an edge of the main graph
	 * @param gC the graph child target
	 * @param e	edge from the main graph
	 */
	void addEdgeChild(graphChild & gC, ogdf::edge &e);

	/**
	 * \fn getChildren
	 * @return this->children
	 */
	std::vector<graphChild> getChildren(void);

	/**
	 * \fn graphDeafultView
	 * \brief This method set default color on the graph.
	 */
	void graphDefaultView(void);

	/**
	 * \fn exportGML
	 * \brief this method export the current graph and its attributes to a gml file.
	 * @param path is the destination path
	 * @param defaultLayout define if the default layout will be use.
	 */
	void exportGML(ogdf::String path, bool defaultLayout);

	/**
	 * \fn exportSVG
	 * \brief this method export the current graph and its attributes to a svg file.
	 * @param path is the destination path
	 * @param defaultLayout define if the default layout will be use.
	 */
	void exportSVG(ogdf::String path, bool defaultLayout);

	/**
	 * \fn setChildView
	 * \brief this method set the current graph with some color on the edges and nodes that correspond of the nodes and edges of the graph child.
	 * @param gC is the graph child
	 * @param c is the color use to show the graph child. Red by default.
	 */
	void setChildView(graphChild & gC, ogdf::String c = "red");



private:

	/**
	 * \fn init
	 * \brief This method permit to share the default constructor code.
	 */
	void init(void);

	ogdf::Graph graph; /**< Contains the graph */
	ogdf::GraphAttributes graphAttribute; /**< Contains the attributes of the graph */
	std::vector<graphChild> children; /**< Contains all children of the current graph */


};


#endif /* GRAPHMANAGER_H_ */
