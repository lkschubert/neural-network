/**
 * @author Luke Schubert
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Brain.h"

class World {

private :
	int size;
	int age;
	int plant[2];
	int bunny[2];
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
