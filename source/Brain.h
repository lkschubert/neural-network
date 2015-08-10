/**
 * @author Luke Schubert
 */
 
#ifndef BRAIN_H
#define BRAIN_H

#include <vector>
#include <string>

#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"

class Brain {

private:
	std::vector<InputNeuron*> inputs;
	std::vector<std::vector<HiddenNeuron*> > layers;
	std::vector<OutputNeuron*> outputs;
	
	/**
	 * The learning rate of the propagation function
	 */
	double learningRate;
	
	
	int firstChoice;
	
	
public:
	/**
	 * Default constructor
	 */
	Brain ();
	
	
	/**
	 * Secondary Constructor
	 */
	Brain (int nInputs, int nHiddenLayers, int nHiddenLayersSize, int nOuputs);
	
	
	/**
	 * Returns the choice the brain has made
	 */
	int think ();
	
	
	
	/**
	 * Tell this which output should have fired
	 */
	void adapt (int target);
	
	
	/**
	 * Sets the inputs
	 */
	void setInputs (std::vector<double> nInputs);
	
	
	std::string display();

};

#endif
