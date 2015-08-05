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
	firstChoiceStrength = firstStrength;
	secondChoice = secondIndex;
	secondChoiceStrength = secondStrength;
	return firstChoice;
}


int Brain::secondThought(){
	return secondChoice;
}


void Brain::adapt(){
	for(int i = layers.size() - 1; i >= 0; i++){
		for(int j = 0; j < layers[i].size(); j++){
			layers[i][j].clearBackProp();
		}
	}
	double adjustment = (1 + adjustmentFactor) * (firstChoiceStrength - secondChoiceStrength) / 2;
	outputs[firstChoice].adjustWeight(firstChoiceStrength - adjustment, learningRate);
	outputs[secondChoice].adjustWeight(secondChoiceStrength + adjustment, learningRate);
	for(int i = layers.size() - 1; i >= 0; i++){
		for(int j = 0; j < layers[i].size(); j++){
			layers[i][j].adjustWeight();
		}
	}
}


void Brain::setInputs(vector<double> nInputs){
	if(nInputs.size() == inputs.size()){
		for(int i = 0; i < nInputs.size(); i++){
			inputs[i].setValue(nInputs[i]);
		}
	}
}