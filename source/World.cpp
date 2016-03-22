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
	actor[0] = rand() % size;
	actor[1] = rand() % size;
	thisBrain = new Brain(4, 1, 1, 4);
}


void World::displayWorld(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(plant[0] == i && plant[1] == j){
				cout << "^";
			}
			else if(actor[0] == i && actor[1] == j){
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
	inputsT[0] = (actor[0] - plant[0] > 0) ? (double)abs(actor[0] - plant[0]) / (double) size : 0;
	inputsT[1] = (actor[1] - plant[1] > 0) ? (double)abs(actor[1] - plant[1]) / (double) size : 0;
	inputsT[2] = (actor[0] - plant[0] < 0) ? (double)abs(actor[0] - plant[0]) / (double) size : 0;
	inputsT[3] = (actor[1] - plant[1] < 0) ? (double)abs(actor[1] - plant[1]) / (double) size : 0;
	inputs.push_back(inputsT[0]);
	inputs.push_back(inputsT[1]);
	inputs.push_back(inputsT[2]);
	inputs.push_back(inputsT[3]);
	thisBrain->setInputs(inputs);
	int decision = thisBrain->think();
	int tempA[2] = {actor[0], actor[1]};
	switch (decision){
		case 0: (actor[0] > 0) ? tempA[0] = actor[0] - 1 : tempA[0] = actor[0];
			break;
		case 1: (actor[1] > 0) ? tempA[1] = actor[1] - 1 : tempA[1] = actor[1];
			break;	
		case 2: (actor[0] < size - 1) ? tempA[0] = actor[0] + 1 : tempA[0] = actor[0];
			break;
		case 3: (actor[1] < size - 1) ? tempA[1] = actor[1] + 1 : tempA[1] = actor[1];
			break;
		default: cout << "What the fuck" << endl;
	}
	
	actor[0] = tempA[0];
	actor[1] = tempA[1];
	
	if(age < 10000){
		int best = 0;
		double largest = 0;
		for(int i = 0; i < 4; i++){
			if(inputsT[i] > largest){
				largest = inputsT[i];
				best = i;
			}
		}
		if(decision != best){
			thisBrain->adapt(best);
		}
	}
	if (actor[0] == plant[0] && actor[1] == plant[1]){
		plant[0] = rand() % size;
		plant[1] = rand() % size;
		actor[0] = rand() % size;
		actor[1] = rand() % size;
	}
	
}
