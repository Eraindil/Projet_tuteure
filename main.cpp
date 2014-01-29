#include "graphUtilities/graphManager.h"
#include "algo/dijkstra.h"

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
	gm.exportGML("graphSubGraph.gml", false);
	gm.exportSVG("graphSubGraph.svg", false);

	graphChild gdij = dijkstraSubGraph(gm, gm.getGraph().firstNode(),gm.getGraph().lastNode(),true);
	gm.setChildView(gdij, "blue");
	gm.exportSVG("dijSubGraph.svg", false);
	gm.exportGML("dijSubGraph.gml", false);

	return 0;
}
