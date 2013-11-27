/*
 * graphManager.h
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#ifndef GRAPHMANAGER_H_
#define GRAPHMANAGER_H_

#include <LEDA/graph/graph.h>;
#include <LEDA/graph/ugraph.h>;
#include <structEdge.h>;
#include <structNode.h>;
#include <iostream>;

/**
 * \class GraphManager
 * \brief is a class that create an manage some graph. This class can create paramethized ugraph from a file or randomly.
 */
class GraphManager{

public:

	/**
	 * \fn genRandomGraph(int n, int e)
	 * \brief This creates a random undirected graph with n nodes and e edge.
	 * @param n the number of node
	 * @param e the number of edge
	 * @return ugraph
	 */
	ugraph genRandomGraph(int n, int e);

	/**
	 * \fn genGraphFromFile
	 * \brief This creates a undirected graph from a GML graph.
	 * @param place
	 * @return ugraph
	 */
	ugraph genGraphFromFile(string place);

};



#endif /* GRAPHMANAGER_H_ */
