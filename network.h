#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include "layer.h"
#include "matrix.h"


class network
{
public:
    network(vector<int> topology);
    void setInput(vector<double> input);
    void printNN();
private:
    int topSize;

    vector<int> topology;

    vector<layer *> layers;
    vector<matrix * > weightMat;
    vector<double> input;
};

#endif // NETWORK_H
