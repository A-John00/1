#include "neuron.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// (1a)

Neuron::Neuron(double val, string fct){
    value = val;
    if(fct == "Sigmoid"){
        activationSigm();
    }
}

// (1a)

void Neuron::activationSigm(){
    actValue = (1 / (1 + pow(exp(1.0), -value)));
}




// sets a single neurons non activated value
void Neuron::setValue(double val){
    value = val;
    activationSigm();
}




double Neuron::getValue(){
    return value;
}

double Neuron::getActValue(){
    return actValue;
}

double Neuron::getDerivedSoftVal(){
    return derivedSoftVal;
}




/*
double Neuron::Softmax(double x){
    return(pow(exp(1.0), x) / )
*/

