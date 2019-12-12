#ifndef LAYER_H
#define LAYER_H
#include "neuron.h"

using namespace std;

class layer
{
public:
    layer(int size);

private:
    int size;
    vector<Neuron *> neurons;
};

#endif // LAYER_H
