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
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "Day : " << age << "\n";
}


void World::update(){
	age ++;
	vector<double> inputs;
	inputs.clear();
	inputs.push_back((double)abs(plant[0] - bunny[0]) / (double) size);
	inputs.push_back((double)abs(plant[1] - bunny[1]) / (double) size);
	bunnyBrain->setInputs(inputs);
	int decision = bunnyBrain->think();
	int secondThought = bunnyBrain->secondThought();
	int tempA[2] = {0, 0};
	int tempB[2] = {0, 0};
	switch (decision){
		case 0: (bunny[0] > 0) ? tempA[0] = bunny[0] - 1 : tempA[0] = bunny[0];
			cout << "Move up" << endl;
			break;
		case 1: (bunny[1] > 0) ? tempA[1] = bunny[1] - 1 : tempA[1] = bunny[1];
			cout << "Move left" << endl;
			break;	
		case 2: (bunny[0] < size - 1) ? tempA[0] = bunny[0] + 1 : tempA[0] = bunny[0];
			cout << "Move down" << endl;
			break;
		case 3: (bunny[1] < size - 1) ? tempA[1] = bunny[1] + 1 : tempA[1] = bunny[1];
			cout << "Move right" << endl;
			break;
	}
	
	switch (secondThought){
		case 0: (bunny[0] > 0) ? tempB[0] = bunny[0] - 1 : tempB[0] = bunny[0];
			break;
		case 1: (bunny[1] > 0) ? tempB[1] = bunny[1] - 1 : tempB[1] = bunny[1];
			break;	
		case 2: (bunny[0] < size - 1) ? tempB[0] = bunny[0] + 1 : tempB[0] = bunny[0];
			break;
		case 3: (bunny[1] < size - 1) ? tempB[1] = bunny[1] + 1 : tempB[1] = bunny[1];
			break;
	}
	
	bunny[0] = tempA[0];
	bunny[1] = tempA[1];
	
	if(abs(tempA[0] - plant[0]) + abs(tempA[1] - plant[1]) > abs(tempB[0] - plant[0]) + abs(tempB[1] - plant[1])){
		cout << "Adapting!" << endl;
		bunnyBrain->adapt();
	}
	
}
