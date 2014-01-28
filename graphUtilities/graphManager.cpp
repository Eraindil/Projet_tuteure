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

void GraphManager::genRandomGraph(int n, int e){
	ogdf::randomGraph(this->graph,n,e);
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

void GraphManager::graphDefaultView(void){
	ogdf::node n;
	ogdf::edge e;
	forall_nodes(n,this->graph){
		this->graphAttribute.colorNode(n) = "black";
	}
	forall_edges(e,this->graph){
		this->graphAttribute.colorEdge(e) = "black";
	}
}

void GraphManager::exportGML(ogdf::String path, bool defaultLayout){
	if(defaultLayout){
		ogdf::node n;
		forall_nodes(n,this->graph){
			this->graphAttribute.width(n) = this->graphAttribute.height(n) = 10.0;
		}
		ogdf::FMMMLayout fmmm;
		fmmm.useHighLevelOptions(true);
		fmmm.unitEdgeLength(15.0);
		fmmm.newInitialPlacement(true);
		fmmm.qualityVersusSpeed(ogdf::FMMMLayout::qvsGorgeousAndEfficient);
		fmmm.call(this->graphAttribute);
		this->graphAttribute.writeGML(path);
	}else{
		this->graphAttribute.writeGML(path);
	}
}

void GraphManager::exportSVG(ogdf::String path, bool defaultLayout){
	if(defaultLayout){
		ogdf::node n;
		forall_nodes(n,this->graph){
			this->graphAttribute.width(n) = this->graphAttribute.height(n) = 10.0;
		}
		ogdf::FMMMLayout fmmm;
		fmmm.useHighLevelOptions(true);
		fmmm.unitEdgeLength(15.0);
		fmmm.newInitialPlacement(true);
		fmmm.qualityVersusSpeed(ogdf::FMMMLayout::qvsGorgeousAndEfficient);
		fmmm.call(this->graphAttribute);
		this->graphAttribute.writeSVG(path);
	}else{
		this->graphAttribute.writeSVG(path);
	}
}

void GraphManager::setChildView(graphChild &gC, ogdf::String c){
	ogdf::node n;
	forall_nodes(n,gC.graph){
		this->graphAttribute.colorNode(gC.nodeOrigin[n]) = c;
	}
	ogdf::edge e;
	forall_edges(e,gC.graph){
		this->graphAttribute.colorEdge(gC.edgeOrigin[e]) = c;
	}
}
