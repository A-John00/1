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
    /*
    string actFct;
    double weight;
    double getOutput();
    void setWeight(unsigned, double);
    void feedForward(const Layer &);
    void backPropaagate();
    string setActFct(string Fct);
    */
    Neuron(double val);
    void activationSigm(); // Sigmoid activation Fct
    void setValue(double val); // sets the value of a Neuron and activates it
    double getValue(); // gets the Neurons Value
    double getActValue(); // gets the activated Neurons Value
    double getDerivedSoftVal(); // gets the derived Softmax value
private:
    /*
    double output;
    double outputSum;
    double randomWeight(double);
    double Sigmoid(double);
    double tanh(double);
    double ReLU(double);
    double Softmax(double);
    */
    double value; // non-activated Neuron value
    double actValue; // value used after activation fct
    double derivedSoftVal; // derived Softmax value
};


#endif // NEURON_H
