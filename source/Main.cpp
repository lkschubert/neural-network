/**
 * @author Luke Schubert
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "World.h"

using namespace std;

int main(int argc, char** argv){
	World myWorld;
	while(true){
		if(myWorld.getAge() > 9995){
			system("clear");
			myWorld.displayWorld();
			cin.get();
		}
		myWorld.update();
	}
	return EXIT_SUCCESS;

}
