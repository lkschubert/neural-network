/**
 * @author Luke Schubert
 */
 
#include "InputNeuron.h"

using namespace std;

InputNeuron::InputNeuron(){
	value = 0;
}


double InputNeuron::evaluate(){
	return value;
}


void InputNeuron::setValue(double nValue){
	value = nValue;
}


double InputNeuron::getOutput(){
	return value;
}

