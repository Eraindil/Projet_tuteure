/*
 * dijkstra.cpp
 *
 *  Created on: 27 janv. 2014
 *      Author: eraindil
 */

#include "dijkstra.h"

graphChild dijkstraSubGraph(GraphManager gm, ogdf::node origin, ogdf::node target, bool weightInit){
	ogdf::EdgeArray<double> weight(gm.getGraph());
	ogdf::NodeArray<ogdf::edge> predec(gm.getGraph());
	ogdf::NodeArray<double> dist(gm.getGraph());
	if(weightInit){
		ogdf::edge e;
		forall_edges(e,gm.getGraph()){

			weight[e] = 10.0;
		}
	}else{
		ogdf::edge e;
		forall_edges(e,gm.getGraph()){
			weight[e] = gm.getGraphAttribute().doubleWeight(e);
		}
	}
	ogdf::Dijkstra<double> dij;
	dij.call(gm.getGraph(),weight,origin,predec,dist);

	graphChild gch = gm.genChild();

	ogdf::node pred = target;
	gm.addNodeChild(gch,pred);
	while(predec[pred] != predec[origin]){
		ogdf::node n;
		if(predec[predec[pred]->source()] != predec[pred]){
			n = predec[pred]->source();
		}else{
			n = predec[pred]->target();
		}
		gm.addNodeChild(gch,n);
		gm.addEdgeChild(gch,predec[pred]);
		pred = n;
	}
	return gch;
}
