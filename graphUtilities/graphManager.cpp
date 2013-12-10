/*
 * graphManager.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#include "graphManager.h"

GraphManager::GraphManager(int e,int n){
	leda::random_graph(this->graphO, e, n);
	std::srand(1);
	leda::node v;
	forall_nodes(v,this->graphO){
		this->graphO[v].push_back(rand()%100);
	}
	leda::edge ed;
	forall_edges(ed,this->graphO){
		this->graphO[ed].push_back(rand()%100);
	}

	leda::GraphWin gw(this->graphO);

	gw.display();
	gw.edit();
}

GraphManager::GraphManager(std::string n){

}

