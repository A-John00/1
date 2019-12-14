#include "layer.h"

layer::layer(int size){
    for(int i = 0; i < size; i++){
        Neuron *n = new Neuron(0.00);
        neurons.push_back(n);
    }
}

void layer::setVal(int i, double v){
    this->neurons.at(i)->setValue(v);
}

matrix *layer::mfyV(){
    matrix *m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < this->neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->getValue());
    }

    return m;
}

matrix *layer::mfyAV(){
    matrix *m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < this->neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->getValue());
    }

    return m;
}
