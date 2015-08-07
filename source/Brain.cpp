/**
 * @author Luke Schubert
 */
 
#include "Brain.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"

using namespace std;


Brain::Brain(){
	//Generation phase
	inputs.clear();
	for(int i = 0; i < 4; i++){
		inputs.push_back(new InputNeuron());
	}
	
	layers.clear();
	for(int i = 0; i < 1; i++){
		vector<HiddenNeuron*> temp;
		for(int j = 0; j < 5; j++){
			temp.push_back(new HiddenNeuron());
		}
		layers.push_back(temp);
	}
	outputs.clear();
	for(int i = 0; i < 4; i++){
		outputs.push_back(new OutputNeuron());
	}
	
	
	//Linking phase
	vector<Neuron*> tempA(layers[0].begin(), layers[0].end());
	for(int i = 0; i < outputs.size(); i++){
		outputs[i]->setInputs(tempA);
	}
	
	for(int i = 0; i < layers.size() - 1; i++){
		vector<Neuron*> tempB(layers[i + 1].begin(), layers[i + 1].end());
		for(int j = 0; i < layers[i].size(); j++){
			layers[i][j]->setInputs(tempB);
		}
	}
	
	vector<Neuron*> tempC(inputs.begin(), inputs.end());
	for(int i = 0; i < layers[layers.size() - 1].size(); i++){
		layers[layers.size() - 1][i]->setInputs(tempC);
	}
	
	//Randomize weights
	srand(time(NULL));
	
	for(int i = 0; i < outputs.size(); i++){
		outputs[i]->generateWeights();
	}
	
	for(int i = 0; i < layers.size(); i++){
		for(int j = 0; j < layers[i].size(); j++){
			layers[i][j]->generateWeights();
		} 
	}
	
	learningRate = 10.0;
	
	adjustmentFactor = 0.75;
	
	
}


Brain::Brain(int nInputs, int nHiddenLayers, int nHiddenLayersSize, int nOuputs){
	//Generation phase
	inputs.clear();
	for(int i = 0; i < nInputs; i++){
		inputs.push_back(new InputNeuron());
	}
	
	layers.clear();
	for(int i = 0; i < nHiddenLayers; i++){
		vector<HiddenNeuron*> temp;
		for(int j = 0; j < nHiddenLayersSize; j++){
			temp.push_back(new HiddenNeuron());
		}
		layers.push_back(temp);
	}
	outputs.clear();
	for(int i = 0; i < nOuputs; i++){
		outputs.push_back(new OutputNeuron());
	}
	
	
	//Linking phase
	vector<Neuron*> tempA(layers[0].begin(), layers[0].end());
	for(int i = 0; i < outputs.size(); i++){
		outputs[i]->setInputs(tempA);
	}
	
	for(int i = 0; i < layers.size() - 1; i++){
		vector<Neuron*> tempB(layers[i + 1].begin(), layers[i + 1].end());
		for(int j = 0; i < layers[i].size(); j++){
			layers[i][j]->setInputs(tempB);
		}
	}
	
	vector<Neuron*> tempC(inputs.begin(), inputs.end());
	for(int i = 0; i < layers[layers.size() - 1].size(); i++){
		layers[layers.size() - 1][i]->setInputs(tempC);
	}
	
	//Randomize weights
	srand(time(NULL));
	
	for(int i = 0; i < outputs.size(); i++){
		outputs[i]->generateWeights();
	}
	
	for(int i = 0; i < layers.size(); i++){
		for(int j = 0; j < layers[i].size(); j++){
			layers[i][j]->generateWeights();
		} 
	}
	
	learningRate = 10.0;
	
	adjustmentFactor = 0.75;
	
	
}


int Brain::think(){
	int firstIndex = 0;
	double firstStrength = 0.0;
	int secondIndex = 0;
	double secondStrength = 0.0;
	
	for(int i = 0; i < outputs.size(); i++){
		double temp = outputs[i]->evaluate();
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
	for(int i = 0; i < layers.size(); i++){
		for(int j = 0; j < layers[i].size(); j++){
			layers[i][j]->clearBackProp();
		}
	}
	double adjustment = (1 + adjustmentFactor) * (firstChoiceStrength - secondChoiceStrength) / 2;
	outputs[firstChoice]->adjustWeight(firstChoiceStrength - adjustment, learningRate);
	outputs[secondChoice]->adjustWeight(secondChoiceStrength + adjustment, learningRate);
	for(int i = 0; i < layers.size(); i++){
		for(int j = 0; j < layers[i].size(); j++){
			
			layers[i][j]->adjustWeight(learningRate);
		}
	}
}


void Brain::setInputs(vector<double> nInputs){
	if(nInputs.size() == inputs.size()){
		for(int i = 0; i < nInputs.size(); i++){
			inputs[i]->setValue(nInputs[i]);
		}
	}
}



string Brain::display(){
	string temp = "";
	for(int i = 0; i < layers[0].size(); i++){
		temp += layers[0][i]->printWeights() + "\n";	
	}
	return temp;
}
