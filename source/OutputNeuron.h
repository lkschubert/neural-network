/**
 * @author Luke Schubert
 */

#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

#include <vector>

#include "Neuron.h"

class OutputNeuron : public Neuron {

private:
	std::vector<Neuron*> inputs;
	std::vector<int> inputWeights;
	
	
	double output;
public:
	/**
	 * Default Constructor
	 */
	OutputNeuron ();

	
	/**
	 * Evaluates the OutputNeuron and its inputs
	 */
	double evaluate ();
	
	
	/**
	 * Adjusts the weight of this Neuron and hands the necessary information
	 * to all of its inputs 
	 */
	void adjustWeight (double target, double learningRate);
	
	
	/**
	 * Gets the last output without the cost of reevaluate
	 */
	double getOutput();


};

#endif