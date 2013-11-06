/*
 * main.cpp
 *
 *  Created on: 6 nov. 2013
 *      Author: eraindil
 */
/*
 * main.cpp
 *
 *  Created on: 10 oct. 2013
 *      Author: eraindil
 */

/*
 * main.cpp
 *
 *  Created on: 10 oct. 2013
 *      Author: eraindil
 */

#include <LEDA/graph/graph.h>

using namespace leda;

int main()
{
  graph G;    //define directed graph G

  node center=G.new_node();   //create new node "center" of G

  int i;
  for (i=0;i<100;i++) {
    node v=G.new_node();     //create new node v of G
    G.new_edge(center,v);    //create new edge of G
                             //with source center and target v
  }

  edge e;
  forall_edges(e,G) {           //iterate over all edges e of G
    node source=G.source(e);  //compute source of e
    node target=G.target(e);  //compute target of e

    std::cout << "edge ";
    G.print_edge(e);          //print edge
    std::cout << " has source ";
    G.print_node(source);     //print source
    std::cout << " and target ";
    G.print_node(target);     //print target
    std::cout << std::endl;
  }

  return 0;
}
