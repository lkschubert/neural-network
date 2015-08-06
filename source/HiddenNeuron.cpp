/**
 * @author Luke Schubert
 */
 
#include "HiddenNeuron.h"

#include <cmath>
#include <cstdlib>

using namespace std;

HiddenNeuron::HiddenNeuron(){
	
}


double HiddenNeuron::evaluate(){
	double sum = 0;
	for(int i = 0; i < inputs.size(); i++){
		sum += inputs[i]->evaluate() * inputWeights[i];
	}
	
	output =  1.0/(1.0 + exp(-1.0 * sum));
	return output;
}


void HiddenNeuron::clearBackProp(){
	outputErrors.clear();
	outputWeights.clear();
}


void HiddenNeuron::addBackProp(double error, double weight){
	outputErrors.push_back(error);
	outputWeights.push_back(weight);
}


void HiddenNeuron::adjustWeight(double learningRate){
	//Computes the error of this node
	double sumOfOutputs = 0;
	for(int i = 0; i < outputErrors.size(); i++){
		sumOfOutputs += outputErrors[i]*outputWeights[i];
	}
	double error = output * (1 - output) * sumOfOutputs;
	
	//Adjusts the weights
	for(int i = 0; i < inputs.size(); i++){
		inputWeights[i] += learningRate * error * inputs[i]->getOutput();
		inputs[i]->addBackProp(error, inputWeights[i]);
	}	
}


double HiddenNeuron::getOutput(){
	return output;
}


void HiddenNeuron::setInputs(std::vector<Neuron*> nInputs){
	inputs = nInputs;
}


void HiddenNeuron::generateWeights(){
	inputWeights.clear();
	inputWeights.resize(inputs.size());
	for(int i = 0; i < inputs.size(); i++){
		inputWeights[i] = (double)rand() * 2 /(double)RAND_MAX - 1;
	}
}


string HiddenNeuron::printWeights(){
	string temp = "";
	for (int i = 0; i < inputWeights.size(); i++){
		temp += " " + to_string(inputWeights[i]) + " ";
	}
	return temp;
}
