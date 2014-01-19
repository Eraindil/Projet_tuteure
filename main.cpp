#include "graphUtilities/graphManager.h"

//il s'agit ici d'un exemple sur comment utilisé la librairie.

int main()
{
	GraphManager gm("Abvtm.gml");
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

	gm.exportChildGml(gtruc,"test.gml");

	std::cout << "END" << endl;

	return 0;
}
