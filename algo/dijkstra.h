/*
 * dijkstra.h
 *
 *  Created on: 29 janv. 2014
 *      Author: eraindil
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/graphalg/Dijkstra.h>
#include "../graphUtilities/graphManager.h"

graphChild dijkstraSubGraph(GraphManager gm, ogdf::node origin, ogdf::node target, bool weightInit);



#endif /* DIJKSTRA_H_ */
