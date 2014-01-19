/*
 * graphManager.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#include "graphManager.h"

graphChild::graphChild(){
	this->nodeOrigin.init(this->graph);
	this->edgeOrigin.init(this->graph);
}

GraphManager::GraphManager(){
	this->init();
}

GraphManager::GraphManager(ogdf::String path){
	this->init();
	this->graphAttribute.readGML(this->graph,path);
}

GraphManager::~GraphManager(){

}

void GraphManager::init(void){
	this->graphAttribute.init(this->graph, ogdf::GraphAttributes::nodeGraphics | ogdf::GraphAttributes::edgeGraphics |
				ogdf::GraphAttributes::nodeLabel | ogdf::GraphAttributes::nodeColor | ogdf::GraphAttributes::nodeId |
				ogdf::GraphAttributes::edgeColor | ogdf::GraphAttributes::nodeWeight |
				ogdf::GraphAttributes::edgeStyle | ogdf::GraphAttributes::nodeStyle);
}

ogdf::Graph& GraphManager::getGraph(void){
	return this->graph;
}

ogdf::GraphAttributes& GraphManager::getGraphAttribute(void){
	return this->graphAttribute;
}

graphChild GraphManager::genChild(void){
	graphChild gchild;
	this->children.push_back(gchild);
	return gchild;
}

void GraphManager::addNodeChild(graphChild &gC, ogdf::node &n){
	ogdf::node nod = gC.graph.newNode();
	gC.nodeOrigin[nod]=n;
}

void GraphManager::addEdgeChild(graphChild &gC, ogdf::edge &e){
	ogdf::node source, target, curs;
	bool src=false,tar=false;
	forall_nodes(curs, gC.graph){
		if(gC.nodeOrigin[curs]==e->source()){
			source = curs;
			src = true;
		}
		else if(gC.nodeOrigin[curs]==e->target()){
			target = curs;
			tar=true;
		}
	}
	if(src && tar){
		ogdf::edge ed = gC.graph.newEdge(source,target);
		gC.edgeOrigin[ed] = e;
	}
}

std::vector<graphChild> GraphManager::getChildren(void){
	return this->children;
}

void GraphManager::exportGML(ogdf::String str){

}

void GraphManager::exportChildGml(graphChild &gC, ogdf::String path){
	ogdf::node n;
	forall_nodes(n,gC.graph){
		this->graphAttribute.colorNode(gC.nodeOrigin[n]) = "red";
	}
	ogdf::edge e;
	forall_edges(e,gC.graph){
		this->graphAttribute.colorEdge(gC.edgeOrigin[e]) = "red";
	}
	this->graphAttribute.writeGML(path);
}
