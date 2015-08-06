/**
 * @author Luke Schubert
 */
 
#include "OutputNeuron.h"

#include <cmath>
#include <cstdlib>

using namespace std;

OutputNeuron::OutputNeuron(){
	
}


double OutputNeuron::evaluate(){
	double sum = 0;
	for(int i = 0; i < inputs.size(); i++){
		sum += inputs[i]->evaluate() * inputWeights[i];
	}
	
	output =  1.0/(1.0 + exp(-1.0 * sum));
	return output;
}


void OutputNeuron::adjustWeight(double target, double learningRate){
	double error = output * (1 - output) * (target - output);
	
	//Adjusts the weights
	for(int i = 0; i < inputs.size(); i++){
		inputWeights[i] += learningRate * error * inputs[i]->getOutput();
		inputs[i]->addBackProp(error, inputWeights[i]);
	}
}


double OutputNeuron::getOutput(){
	return output;
}


void OutputNeuron::setInputs(std::vector<Neuron*> nInputs){
	inputs = nInputs;
}


void OutputNeuron::generateWeights(){
	inputWeights.clear();
	inputWeights.resize(inputs.size());
	for(int i = 0; i < inputs.size(); i++){
		inputWeights[i] = (double)rand() * 2 /(double)RAND_MAX - 1;
	}
}

string OutputNeuron::printWeights(){
	string temp = "";
	for (int i = 0; i < inputWeights.size(); i++){
		temp += " " + to_string(inputWeights[i]) + " ";
	}
	return temp;
}
