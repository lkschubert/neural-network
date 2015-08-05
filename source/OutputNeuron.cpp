/**
 * @author Luke Schubert
 */
 
#include "OutputNeuron.h"

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