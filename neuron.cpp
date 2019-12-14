#include "neuron.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

Neuron::Neuron(double val){
    value = val;
    activationSigm();
}

void Neuron::setValue(double val){
    value = val;
    activationSigm();
}

double Neuron::getValue(){
    return this->value;
}

double Neuron::getActValue(){
    return this->actValue;
}

double Neuron::getDerivedSoftVal(){
    return this->derivedSoftVal;
}

void Neuron::activationSigm(){
    actValue = (1 / (1 + pow(exp(1.0), -value)));
}


/*
double Neuron::Softmax(double x){
    return(pow(exp(1.0), x) / )
*/

