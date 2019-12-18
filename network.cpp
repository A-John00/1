#include <iostream>
#include "network.h"
#include "matrix.h"
#include "layer.h"
#include "stdlib.h"
#include "math.h"

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
        matrix* nm  = getneuronMatrix(i);
        if(i != 0){
            nm      = getactNeuronMatrix(i);
        }

        matrix* nm2 = getweightMatrix(i); //weight matrix size always layer size -1
        matrix* nm3 = matrix::mult(nm, nm2);


        vector<double> tempval;
        for(int j = 0; j < nm3->getNumColumns(); j++){
            tempval.push_back(nm3->getValue(0, j)); //converts nm3 to a vector
            setNV((i + 1), j, nm3->getValue(0, j));
        }
    }
}

void network::setNV(int layer, int neuron, double value){
    layers.at(layer)->setVal(neuron, value);
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
           getweightMatrix(i)->printM();
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

void network::printOutputSize(){
    cout << layers.at(topSize - 1)->mfyV()->getNumColumns() << endl;
}



matrix* network::getneuronMatrix(int i){
    return layers.at(i)->mfyV();
}

matrix* network::getactNeuronMatrix(int i){
    return layers.at(i)->mfyAV();
}
 //(1e)
matrix* network::getweightMatrix(int i){
    return weightMat.at(i);
}



/*=============================*/

void network::setNetworkError(){
    if(target.size() == 0){
        cout << "No loaded errorTargets" << endl;
        exit(1);
    }
    if(target.size() != layers.at(layers.size() - 1)->getNeurons().size()){
         cout << "Number Targets does not match output size" << endl;
         exit(1);
    }
    int outLayerIndex = layers.size() - 1;
    error = 0.00;
    for (int j = 0; j < topology.at(topSize - 1); j++){
        errors.push_back(0.00);
    }
    vector<Neuron *> outputNeurons = layers.at(outLayerIndex)->getNeurons();
    for (int i = 0; i < target.size(); i++){


        // loops through the output neurons values and determines the error
        // in regards to the target errors given
        double neuronError         = (outputNeurons.at(i)->getActValue() - target.at(i));

        errors.at(i)         = neuronError;

        for(int k = 0; k < errors.size(); k++){
            error += 0.5 * pow(errors.at(k), 2);
        }


    }
}


void network::setTargetValues(vector<double> targets){
   target = targets;
}




double network::getCurrentError(){
    return error;
}

vector<double> network::getOutputErrors(){
    return errors;
}

// back prop

void network::backPropagation(){
    vector<matrix *> newWeights;

    int outLayerIndex             = topology.at(topology.size() - 1);

    matrix* derivedOutToHidden    = layers.at(outLayerIndex)->mfyDV();

    matrix* gradienten            = new matrix(1, layers.at(outLayerIndex)->getNeurons().size(), false);
    for (int i = 0; i < errors.size(); i++){
        double val                = derivedOutToHidden->getValue(0, i);
        double er                 = errors.at(i);
        double grad               = val * er;

        gradienten->setValue(0, i, grad);
    }


    int scndToLastLayerIndex      = outLayerIndex - 1;
    layer* scndToLastLayer        = layers.at(scndToLastLayerIndex);
    matrix* outputToHiddenWeights = weightMat.at(outLayerIndex - 1);

    matrix* outputToHiddenMat     = matrix::mult(gradienten->transpose(), scndToLastLayer->mfyAV()->transpose());

    matrix* WeightsOutputToHidden = new matrix(outputToHiddenMat->getNumRows(), outputToHiddenMat->getNumColumns(), false);
    for(int k = 0; k < outputToHiddenMat->getNumRows(); k++){
        for(int l = 0; l < outputToHiddenMat->getNumColumns(); l++){
            double oWeights = outputToHiddenWeights->getValue(k, l);
            double dWeights = outputToHiddenMat->getValue(k, l);
            WeightsOutputToHidden->setValue(k ,l , (oWeights - dWeights));
        }
    }
    newWeights.push_back(WeightsOutputToHidden);

    //cout << "output to hidden new weights" << endl;
    //WeightsOutputToHidden->printM();

    // going backwards from the second to last layer (hidden) to the input layer
    for (int j = outLayerIndex - 1; j >= 0; j--){
    }
}
