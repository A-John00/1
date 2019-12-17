#include <iostream>
#include "network.h"
#include "matrix.h"
#include "layer.h"

using namespace std;

// (2a)
// creates a new network which consists of different layer(input, hidden, output)
// takes in a vector called topology, in which the number of neurons for the correspoding layer are declared
//
//
//
// vector<int> topology;
// topology.push_back(3);
// topology.push_back(2);
// topology.push_back(1);
// network* nn = new network(topology);
//
// creates a new network with an input layer size of 3, hidden layer size of 2 and and output layer size of 1
network::network(vector<int> topology){
    this->topology = topology;
    topSize = topology.size();
    for(int i = 0; i < topology.size(); i++){
        layer *l = new layer(topology.at(i));
        layers.push_back(l);

    }
    // takes a random weight matrix for the corresponding layer for it to multiply
    for(int i = 0; i < (topSize - 1); i++){
        matrix* m = new matrix(topology[i], topology[i+1], true);
        weightMat.push_back(m);
    }
}


// takes an input vector and sets the first/input layer to that input vector
void network::setInput(vector<double> input){
    this->input = input;
    for(int i = 0; i < input.size(); i++){
        layers.at(0)->setVal(i, input.at(i));
    }

}

// (1c)
// (1d)
// (2c)
//
void network::feedForward(){
    for(int i = 0; i < (layers.size() - 1); i++){ // -1 hiddenlayer
        matrix* nm = neuronMatrix(i);
        if(i != 0){
            nm = actNeuronMatrix(i);
        }
        matrix* nm2 = weightMatrix(i); //weight matrix size always layer size -1
        matrix nm3 = matrix::mult(nm, nm2);
        vector<double> tempval;
        for(int j = 0; j < nm3.getNumColumns(); j++){
            tempval.push_back(nm3.getValue(0, j)); //converts nm3 to a vector
            setNV((i + 1), j, nm3.getValue(0, j));
        }
    }
}


// prints out the whole network with its layers
void network::printNN(){
    for(int i = 0; i < layers.size(); i++){
        cout << "Layer: " << i << endl;
        if(i == 0){
            // prints out the neurons non activated values as the input layer doesn't show the activated ones
            matrix* m = layers.at(i)->mfyV();
            m->printM();
        }
        else{
            // prints out the following layer neurons activated values
            matrix* m = layers.at(i)->mfyAV();
            m->printM();
        }
        // to be deleted
        cout << "=================" << endl;
        if (i < layers.size() - 1){
            cout << "Weight Matrix: " << i << endl;
           weightMatrix(i)->printM();
        }
        cout << "=================" << endl;
    }
}

// (2b)
// prints out only the output layer neurons values
void network::printOutput(){
    matrix* m = layers.at(topSize - 1)->mfyAV();
    m->printM();
}



matrix* network::neuronMatrix(int i){
    return layers.at(i)->mfyV();
}

matrix* network::actNeuronMatrix(int i){
    return layers.at(i)->mfyAV();
}

matrix* network::weightMatrix(int i){
    return weightMat.at(i);
}


void network::setNV(int layer, int neuron, double value){
    layers.at(layer)->setVal(neuron, value);
}



