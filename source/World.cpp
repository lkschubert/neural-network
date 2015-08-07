/**
 * @author Luke Schubert
 */

#include "World.h"

#include <iostream>

using namespace std;


World::World(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			map[i][j] = 'x';
		}
	}
	age = 0;
}


void World::displayWorld(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "Move : " << age << endl;
}