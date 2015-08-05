/**
 * @author Luke Schubert
 */
 
#include "Brain.h"

#include <vector>

#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"

using namespace std;


Brain::Brain(){
	
}


int Brain::think(){
	int firstIndex = 0;
	double firstStrength = 0.0;
	int secondIndex = 0;
	double secondStrength = 0.0;
	
	for(int i = 0; i < inputs.size(); i++){
		double temp = inputs[i].evaluate();
		if(temp > firstStrength){
			secondIndex = firstIndex;
			secondStrength = firstStrength;
			firstIndex = i;
			firstStrength = temp;
		}
		else if(temp > secondStrength){
			secondIndex = i;
			secondStrength = temp;
		}
	}
	firstChoice = firstIndex;
	secondChoice = secondIndex;
	return firstChoice;
}


int Brain::secondThought(){
	return secondChoice;
}


void Brain::adapt(){
	
}


void Brain::setInputs(vector<double> nInputs){
	if(nInputs.size() == inputs.size()){
		for(int i = 0; i < nInputs.size(); i++){
			inputs[i].setValue(nInputs[i]);
		}
	}
}