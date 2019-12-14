#ifndef LAYER_H
#define LAYER_H
#include "neuron.h"
#include "matrix.h"

using namespace std;

class layer
{
public:
    layer(int size);
    void setVal(int i, double v);
    matrix *mfyV();
    matrix *mfyAV();

private:
    int size;
    vector<Neuron *> neurons;
};

#endif // LAYER_H
