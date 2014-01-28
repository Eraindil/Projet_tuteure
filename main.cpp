#include "graphUtilities/graphManager.h"

//il s'agit ici d'un exemple sur comment utilisé la librairie.

int main()
{
	GraphManager gm("Abvt.gml");
	graphChild gtruc = gm.genChild();
	srand(time(NULL));
	ogdf::edge e;
	forall_edges(e,gm.getGraph()){
		if(rand()%50 < 15){
			ogdf::node source = e->source(),target = e->target();
			gm.addNodeChild(gtruc,source);
			gm.addNodeChild(gtruc,target);
			gm.addEdgeChild(gtruc,e);
		}
	}

	gm.graphDefaultView();
	gm.exportSVG("graph.svg", true);

	gm.setChildView(gtruc);
	gm.exportGML("graphSubGraph.gml", true);
	gm.exportSVG("graphSubGraph.svg", true);

	return 0;
}
