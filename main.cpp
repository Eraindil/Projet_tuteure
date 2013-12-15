#include <ogdf/basic/Graph.h>
#include <ogdf/basic/graph_generators.h>
#include <ogdf/layered/DfsAcyclicSubgraph.h>

#include "graphUtilities/graphManager.h"

int main()
{
    GraphManager gm("Abvt.gml");
    gm.shortestPathFrom(2);
}
