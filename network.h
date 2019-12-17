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
    void printNN();
    void feedForward();
    void setNV(int layer,int neuron , double value);
    void printWeights();
    void printOutput();


    matrix* neuronMatrix(int i);
    matrix* actNeuronMatrix(int i);
    matrix* weightMatrix(int i);

private:
    int topSize;

    // (2a)
    vector<int> topology;

    vector<layer *> layers;
    vector<matrix * > weightMat;
    vector<double> input;
};

#endif // NETWORK_H
