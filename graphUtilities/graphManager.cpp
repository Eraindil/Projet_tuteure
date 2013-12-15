/*
 * graphManager.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#include "graphManager.h"

GraphManager::GraphManager(int n,int e){
	ogdf::randomGraph(this->graphO, n, e);
	std::srand(time(NULL));
	this->attributeGraphO.init(this->graphO ,ogdf::GraphAttributes::nodeWeight | ogdf::GraphAttributes::edgeIntWeight );
	ogdf::node v;
	forall_nodes(v,this->graphO)
		this->attributeGraphO.weight(v) = rand() %50;
	forall_nodes(v,this->graphO)
		std::cout << this->attributeGraphO.weight(v) << endl;
	ogdf::edge ed;
	forall_edges(ed,this->graphO)
		this->attributeGraphO.intWeight(ed) = rand() %50;
}

GraphManager::GraphManager(ogdf::String str){
	this->attributeGraphO.init(this->graphO,ogdf::GraphAttributes::nodeGraphics | ogdf::GraphAttributes::edgeGraphics |
			ogdf::GraphAttributes::nodeLabel | ogdf::GraphAttributes::nodeColor |
			ogdf::GraphAttributes::edgeColor | ogdf::GraphAttributes::edgeStyle |
			ogdf::GraphAttributes::nodeStyle | ogdf::GraphAttributes::nodeTemplate);
	this->attributeGraphO.readGML(this->graphO,str);
	std::cout << this->attributeGraphO.attributes() << endl;
}

GraphManager::~GraphManager(){

}

void GraphManager::exportGML(ogdf::String str){
	this->attributeGraphO.writeGML(str);
}

void GraphManager::exportSVG(ogdf::String str){
	this->attributeGraphO.writeSVG(str);
}

void GraphManager::shortestPathFrom(int e){

}

