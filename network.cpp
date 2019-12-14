#include <iostream>
#include "network.h"
#include "matrix.h"
#include "layer.h"

using namespace std;


network::network(vector<int> topology){
    this->topology = topology;
    this->topSize = topology.size();
    for(int i = 0; i < topology.size(); i++){
        layer *l = new layer(topology.at(i));
        this->layers.push_back(l);

    }
    for(int i = 0; i < (topSize - 1); i++){
        matrix *m = new matrix(topology[i], topology[i+1], true);
        this->weightMat.push_back(m);
    }
}

void network::setInput(vector<double> input){
    this->input = input;
    for(int i = 0; i < input.size(); i++){
        this->layers.at(0)->setVal(i, input.at(i));
    }

}

void network::printNN(){
    for(int i = 0; i < this->layers.size(); i++){
        cout << "Layer: " << i << endl;
        if(i == 0){
            matrix *m = this->layers.at(i)->mfyV();
            m->printM();
        }
        else{
            matrix *m = this->layers.at(i)->mfyAV();
            m->printM();
        }
    }
}
