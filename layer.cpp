#include "layer.h"
#include "neuron.h"
#include "math.h"
#include <iostream>

// (1c)
//creates a layer which defaults to the sigmoid function.
layer::layer(int size){
    this->size = size;
    for(int i = 0; i < size; i++){
        Neuron *n = new Neuron(0.00, "Sigmoid");
        neurons.push_back(n);
    }
}

//=====================================

// (1b)
// creates a new layer *l1 and fills it with the values
// corresponding to the softmax equation
layer layer::activationSoft(){
    layer* l1 = new layer(size);
    double fullNSum = 0.00;  // placeholder for sum
    for (int i = 0; i < neurons.size(); i++){
        fullNSum = fullNSum + exp(neurons.at(i)->getValue());
    }
    for (int j = 0; j < neurons.size(); j++){
        l1->setVal(j, (exp(neurons.at(j)->getValue()) / fullNSum));
    }
    return *l1;
}

//=====================================

void layer::setVal(int i, double v){
    neurons.at(i)->setValue(v);
}


void layer::printLayer(){
    for(int i = 0; i < size; i++){
        cout << neurons.at(i)->getValue() << endl;
    }
}


vector<Neuron *> layer::getNeurons(){
    return neurons;
}


matrix *layer::mfyV(){
    matrix* m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < neurons.size(); i++){
        m->setValue(0, i, neurons.at(i)->getValue());
    }

    return m;
}


matrix *layer::mfyAV(){
    matrix* m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < neurons.size(); i++){
        m->setValue(0, i, neurons.at(i)->getActValue());
    }

    return m;
}

matrix *layer::mfyDV(){
    matrix* m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < neurons.size(); i++){
        m->setValue(0, i, neurons.at(i)->getDerVal());
    }

    return m;
}













