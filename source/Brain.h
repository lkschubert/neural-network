/**
 * @author Luke Schubert
 */
 
#ifndef BRAIN_H
#define BRAIN_H

#include <vector>

#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"

class Brain {

private:
	std::vector<InputNeuron> inputs;
	std::vector<std::vector<HiddenNeuron> > layers;
	std::vector<OutputNeuron> outputs;
	
	/**
	 * The learning rate of the propagation function
	 */
	double learningRate;
	
	/**
	 * The amount of kneejerk reaction the system has when the secondary
	 * thought would have produced the greatest outcome
	 */
	double adjustmentFactor;
	
	int firstChoice;
	int secondChoice;
	
public:
	/**
	 * Default constructor
	 */
	Brain ();
	
	
	/**
	 * Returns the choice the brain has made
	 */
	int think ();
	
	
	/**
	 * Returns the secondary choice
	 */
	int secondThought ();
	
	
	/**
	 * This is the real big part of the operation
	 * Only call if second option is better
	 */
	void adapt ();
	
	
	/**
	 * Sets the inputs
	 */
	void setInputs (std::vector<double> nInputs);

};

#endif