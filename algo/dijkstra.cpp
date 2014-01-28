/*
 * dijkstra.cpp
 *
 *  Created on: 27 janv. 2014
 *      Author: eraindil
 */

#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/graphalg/Dijkstra.h>
#include "../graphUtilities/graphManager.h"

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
	gm.addNodeChild(gch,target);
	while(pred != origin){
		ogdf::node n;
		if(predec[pred]->source() != pred){
			n = predec[pred]->source();
			gm.addNodeChild(gch,n);
		}else{
			n = predec[pred]->target();
			gm.addNodeChild(gch,n);
		}
		gm.addEdgeChild(gch,predec[pred]);
		pred = n;
	}
	return gch;
}
