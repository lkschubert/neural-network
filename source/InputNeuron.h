/**
 * @author Luke Schubert
 */

#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include <vector>

#include "Neuron.h"

class InputNeuron : public Neuron {

private:
	double value;

public:
	/**
	 * Default Constructor
	 */
	InputNeuron ();

	
	/**
	 * Evaluates the InputNeuron and its inputs
	 */
	double evaluate ();
	
	
	/**
	 * Sets the InputNeuron's value
	 */
	void setValue (double nValue);
	
	
	/**
	 * Gets the last output without the cost of reevaluate
	 */
	double getOutput();

};

#endif