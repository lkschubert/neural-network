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
	bunnyBrain = new Brain(4, 3, 5, 4);
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
	
	double inputsT[4];
	inputsT[0] = (bunny[0] - plant[0] > 0) ? (double)abs(bunny[0] - plant[0]) / (double) size : 0;
	inputsT[1] = (bunny[1] - plant[1] > 0) ? (double)abs(bunny[1] - plant[1]) / (double) size : 0;
	inputsT[2] = (bunny[0] - plant[0] < 0) ? (double)abs(bunny[0] - plant[0]) / (double) size : 0;
	inputsT[3] = (bunny[1] - plant[1] < 0) ? (double)abs(bunny[1] - plant[1]) / (double) size : 0;
	inputs.push_back(inputsT[0]);
	inputs.push_back(inputsT[1]);
	inputs.push_back(inputsT[2]);
	inputs.push_back(inputsT[3]);
	bunnyBrain->setInputs(inputs);
	int decision = bunnyBrain->think();
	int tempA[2] = {bunny[0], bunny[1]};
	switch (decision){
		case 0: (bunny[0] > 0) ? tempA[0] = bunny[0] - 1 : tempA[0] = bunny[0];
			break;
		case 1: (bunny[1] > 0) ? tempA[1] = bunny[1] - 1 : tempA[1] = bunny[1];
			break;	
		case 2: (bunny[0] < size - 1) ? tempA[0] = bunny[0] + 1 : tempA[0] = bunny[0];
			break;
		case 3: (bunny[1] < size - 1) ? tempA[1] = bunny[1] + 1 : tempA[1] = bunny[1];
			break;
		default: cout << "What the fuck" << endl;
	}
	
	bunny[0] = tempA[0];
	bunny[1] = tempA[1];
	
	if(age < 1000000){
		int best = 0;
		double largest = 0;
		for(int i = 0; i < 4; i++){
			if(inputsT[i] > largest){
				largest = inputsT[i];
				best = i;
			}
		}
		if(decision != best){
			bunnyBrain->adapt(best);
		}
	}
	if (bunny[0] == plant[0] && bunny[1] == plant[1]){
		plant[0] = rand() % size;
		plant[1] = rand() % size;
		bunny[0] = rand() % size;
		bunny[1] = rand() % size;
	}
	
}
