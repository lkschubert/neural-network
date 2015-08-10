/**
 * @author Luke Schubert
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Brain.h"

class World {

private :
	int age;
	int[2] plant;
	int[2] bunny;
	Brain bunnyBrain;

public :
	/**
	 * Default constructor
	 */
	World ();

	/**
	 * Update
	 */
	void update ();
	
	/**
	 * Display world
	 */
	void displayWorld ();

};

#endif
