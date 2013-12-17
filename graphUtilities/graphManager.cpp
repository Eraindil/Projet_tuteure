/*
 * graphManager.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#include "graphManager.h"

template<typename NT, typename ET> GraphManager<NT,ET>::GraphManager(int n,int e){
	ogdf::randomGraph(this->graphO, n, e);
	std::srand(time(NULL));
	ogdf::node v;
	forall_nodes(v,this->graphO);
	ogdf::edge ed;
	forall_edges(ed,this->graphO);
}

template<typename NT, typename ET> GraphManager<NT, ET>::GraphManager(ogdf::String str){

}

template<typename NT, typename ET> GraphManager<NT,ET>::~GraphManager(){

}

template<typename NT, typename ET> void GraphManager<NT, ET>::exportGML(ogdf::String str){

}

template<typename NT, typename ET> void GraphManager<NT,ET>::exportSVG(ogdf::String str){

}

template<typename NT, typename ET> void GraphManager<NT, ET>::shortestPathFrom(int e){

}

