/*
 * graphManager.h
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#ifndef GRAPHMANAGER_H_
#define GRAPHMANAGER_H_

#include <LEDA/graph/graph.h>
#include <LEDA/graph/ugraph.h>
#include <iostream>
#include <map>
#include <vector>
#include <LEDA/graphics/graphwin.h>

/**
 * \class GraphManager
 * \brief is a class that create an manage some graph. This class can create paramethized ugraph from a file or randomly.
 */
class GraphManager{

public:

	GraphManager(int e, int n);
	GraphManager(std::string n);
	~GraphManager(void);

	leda::graph getGraphO(void);
	std::vector<leda::GRAPH<leda::node,leda::edge> > getChild(std::string n);

	//void afficheGraphO(void);
	//void afficheChild(void);
	//void afficheSpecificChild(int);

private:

	leda::UGRAPH<std::vector<int>,std::vector<int> > graphO;
	std::map<std::string,std::vector<leda::GRAPH<leda::node,leda::edge> > > child;

};



#endif /* GRAPHMANAGER_H_ */
