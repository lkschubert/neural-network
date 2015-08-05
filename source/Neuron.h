/**
 * @author Luke Schubert
 */
 
#ifndef NEURON_H
#define NEURON_H

class Neuron {

public:
	virtual double evaluate() = 0;
	
	virtual double getOutput() = 0;
};

#endif