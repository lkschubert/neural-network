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
	int actor[2];
	Brain* thisBrain;

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

	/**
	 * Returns the age
	 */
	int getAge (){return age;};
};

#endif
