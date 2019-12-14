#include "layer.h"
#include "neuron.h"
#include "math.h"
#include <iostream>

layer::layer(int size){
    this->size = size;
    for(int i = 0; i < size; i++){
        Neuron *n = new Neuron(0.00);
        neurons.push_back(n);
    }
}

void layer::setVal(int i, double v){
    this->neurons.at(i)->setValue(v);
}

layer layer::activationSoft(){
    layer *l1 = new layer(size);
    double fullNSum = 0.00;  // placeholder for sum
    for (int i = 0; i < neurons.size(); i++){
        fullNSum = fullNSum + exp(neurons.at(i)->getValue());
    }
    for (int j = 0; j < neurons.size(); j++){
        l1->setVal(j, (exp(this->neurons.at(j)->getValue()) / fullNSum));
    }
    return *l1;
}

void layer::printLayer(){
    for(int i = 0; i < size; i++){
        cout << this->neurons.at(i)->getValue() << endl;
    }
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
