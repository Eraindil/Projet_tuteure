/*
 * structEdge.h
 *
 *  Created on: 27 nov. 2013
 *      Author: eraindil
 */

#ifndef VIRTUALEDGEDEAFULT_H_
#define VIRTUALEDGEDEAFULT_H_

#include <iostream>;

using namespace std;

/**
 * \struct structEdge
 * \brief Contains parameters of Edge.
 */
struct VirtualEdgeDefault{
	int quality; /*!<Representation of the quality of the real line */
	int length; /*!< Representation of the length of the real line*/

	string name; /*!<Name of the line (name of source node + name of next node) */
};


#endif /* VIRTUALEDGEDEAFULT_H_ */
