/**
 * @author Luke Schubert
 */

#ifndef WORLD_H
#define WORLD_H

class World {

private :
	char map[10][10];
	int age;
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