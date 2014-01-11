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
	//this->edgeAttribute.init(this->graph); --remove--
	//this->nodeAttribute.init(this->graph); --remove--

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

/*
void GraphManager::wizard(){
	std::cout << "Welcome in the manual graph'creation." << endl;
	std::string choix;
	while(choix!="q"){
		std::cout << "Would like to create a random graph a), create a graph from a file b), erase current graph c), d the answer d), "<< endl << "add a node e), add an edge f), export the current graph to gml g) or quit the wizard q) ";
		char choice;
		std::cin >> choice;
		switch(choice){
		case 'a':
			int n,e;
			std::cout << "Enter the number of node : " << endl;
			std::cin >> n;
			std::cout << "Enter the number of edge: " << endl;
			std::cin >> e;
			if(n>e) ogdf::randomGraph(this->graph,n,e);
			else std::cout << "Please, the number of nodes need to be bigger than edge";
			break;
		case 'g':
			std::cout << "Enter the path to the file" << endl;
			std::string path;
			std::cin >> path;
			this->graph.writeGML(path.c_str());
			break;
		}
	}
}
*/

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
		if(gC.nodeOrigin[curs]==e->target()){
			target = curs;
			tar=true;
		}
	}
	if(src && tar){
		ogdf::edge ed = gC.graph.newEdge(source,target);
		gC.edgeOrigin[ed] = e;
	}
}

void GraphManager::exportGML(ogdf::String str){

}

void GraphManager::exportChildGml(graphChild &gC, ogdf::String path){
	ogdf::node n;
	forall_nodes(n,gC.graph){
	}
	ogdf::edge e;
	forall_edges(e,gC.graph){
		this->graphAttribute.colorEdge(gC.edgeOrigin[e]) = "red";
	}
	this->graphAttribute.writeGML(path);
}
