/**
 * @author Luke Schubert
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Objects.h"

class World {

private :
	int age;
	std::vector<std::vector<Objects> > objects;
public :
	/**
	 * Default constructor
	 */
	World ();


	/**
	 * Display world
	 */
	void displayWorld ();

};

#endif
