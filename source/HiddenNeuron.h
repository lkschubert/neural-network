/**
 * @author Luke Schubert
 */

#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H

#include <vector>

#include "Neuron.h"

class HiddenNeuron : public Neuron {

private:
	std::vector<Neuron*> inputs;
	std::vector<int> inputWeights;
	
	std::vector<double> outputErrors;
	std::vector<double> outputWeights;
	
	double output;
public:
	/**
	 * Default Constructor
	 */
	HiddenNeuron ();

	
	/**
	 * Evaluates the HiddenNeuron and its inputs
	 */
	double evaluate ();
	
	
	/**
	 * clears the values used for backwards propagation
	 */
	void clearBackProp();
	
	
	/**
	 * Adds what is required for backwards propagation
	 */
	void addBackProp(double error, double weight);
	
	
	/**
	 * Adjusts the weight of this Neuron and hands the necessary information
	 * to all of its inputs 
	 */
	void adjustWeight (double learningRate);
	
	
	/**
	 * Gets the last output without the cost of reevaluate
	 */
	double getOutput();


};

#endif