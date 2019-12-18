#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


class Neuron
{
typedef vector<Neuron> Layer;
public:
    // (1a)
    Neuron(double val, string fct); //string fct in order to choose between activation fct


    // (1a)
    void activationSigm(); // Sigmoid activation Fct
    void activationSigmDer();
    void activationTanh();
    void activationTanhDer();
    void setValue(double val); // sets the value of a Neuron and activates it




    double getValue(); // gets the Neurons Value
    double getActValue(); // gets the activated Neurons Value
    double getDerVal();
    double getDerivedSoftVal(); // gets the derived Softmax value
private:
    double value; // non-activated Neuron value
    double actValue; // value used after activation fct
    double derVal;
    double derivedSoftVal; // derived Softmax value
};


#endif // NEURON_H
