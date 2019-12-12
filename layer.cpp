#include "layer.h"

layer::layer(int size){
    for(int i = 0; i < size; i++){
        Neuron *n = new Neuron(0.00);
        neurons.push_back(n);
    }
}
