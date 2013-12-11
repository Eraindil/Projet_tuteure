/*
 * main.cpp
 *
 *  Created on: 10 oct. 2013
 *      Author: eraindil
 */

#include "graphUtilities/graphManager.h"

int main()
{
	GraphManager *gm = new GraphManager(7,6);

	return 0;
}
/*
#include <LEDA/graphics/graphwin.h>
#include <LEDA/graph/graph.h>

int main()
{
	leda::GRAPH<int,int> G;
	leda::random_graph(G ,7,6);

	leda::GraphWin gw(G);
	leda::node v; leda::edge e;

	gw.set_node_label_type(leda::data_label);
	gw.set_edge_label_type(leda::data_label);

	gw.display();
	gw.edit();

	return 0;
}
*/
