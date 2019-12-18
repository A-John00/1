#ifndef LAYER_H
#define LAYER_H
#include "neuron.h"
#include "matrix.h"

using namespace std;

class layer
{
public:
    layer(int size);


    layer activationSoft(); // softmax activation function ( not implemented into the neural net) though works when fed with a layer


    void setVal(int i, double v); // sets a neurons value at index i to value v
    void printLayer(); // prints out the layer

    vector<Neuron *> getNeurons(); // returns the neurons vector


    matrix *mfyV();
    matrix *mfyAV(); // mfy functions allow for layers to be converted to matrices, so matrix::mult and matrix::transpose work on them
    matrix *mfyDV();



private:
    int size;
    vector<Neuron *> neurons;
};

#endif // LAYER_H
