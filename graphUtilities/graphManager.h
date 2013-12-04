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

template<typename tE,typename tN> class GraphManager{

public:

	GraphManager(int , int);
	GraphManager(string);
	~GraphManager(void);

	leda::graph getGraphO(void);
	std::list<leda::graph> getChild(void);

	void afficheGraphO(void);
	void afficheChild(void);
	void afficheSpecificChild(int);

private:

	leda::ugraph<tN,tE> graphO;
	std::list<leda::graph> child;

	/**
	 * \todo
	 * -Liste de chemin d'un point A à un point B
	 * -Liste des plus court chemin
	 *
	 */

	/**
	 * \fn genRandomGraph(int n, int e)
	 * \brief This creates a random undirected graph with n nodes and e edge.
	 * @param n the number of node
	 * @param e the number of edge
	 * @return ugraph
	 */
	leda::ugraph genRandomGraph(int , int);

	/**
	 * \fn genGraphFromFile
	 * \brief This creates a undirected graph from a GML graph.
	 * @param place
	 * @return ugraph
	 */
	leda::ugraph genGraphFromFile(string);

	tN genRandomStructNode(void);

	tE genRandomStructEdge(void);




};



#endif /* GRAPHMANAGER_H_ */
