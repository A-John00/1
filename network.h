#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include "layer.h"
#include "matrix.h"

// (2a)

class network
{
public:
    network(vector<int> topology);


    void setInput(vector<double> input);

    void feedForward();
    void setNV(int layer,int neuron , double value);

    void printNN();
    void printWeights();
    void printOutput();


    void printOutputSize(); // testing purposes
    void printToFile(string str, ostream & output); // not implemented


    matrix* getneuronMatrix(int i);
    matrix* getactNeuronMatrix(int i);
    matrix* getweightMatrix(int i);



    // learning functions

    void setTargetValues(vector<double> targets);
    void setNetworkError();

    double getCurrentError();
    vector<double> getOutputErrors();


    //back pro
    void backPropagation();


private:
    int topSize;

    // (2a)
    vector<int> topology; // vector to indicate the topology

    vector<layer *> layers; // vector to keep all the layers

    vector<matrix * > weightMat;

    vector<double> input; // vector for the input layer of neurons


    //learning variables

    // target for the errors
    vector<double> target;

    // total error of network
    double error;

    // vector of output errors
    vector<double> errors;

    //back pro
    double bias = 1;
    vector<matrix *> gradientMat;


};

#endif // NETWORK_H
