/**
 * @author Luke Schubert
 */

#include "World.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


World::World(){
	age = 0;
	size = 10;
	plant[0] = rand() % size;
	plant[1] = rand() % size;
	bunny[0] = rand() % size;
	bunny[1] = rand() % size;
	bunnyBrain = new Brain(2, 2, 4, 4);
}


void World::displayWorld(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(plant[0] == i && plant[1] == j){
				cout << "^";
			}
			else if(bunny[0] == i && bunny[1] == j){
				cout << "&";
			}
		}
	}
}


void World::update(){
	
}
