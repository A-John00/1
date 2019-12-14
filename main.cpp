#include <QCoreApplication>
#include "neuron.h"
#include "layer.h"
#include "matrix.h"
#include "network.h"

int main(int argc, char *argv[])
{
    /*
    Neuron *n = new Neuron(0.9);
    cout << "Val: " << n->getValue() << endl;
    cout << "actVal: " << n->getActValue() << endl;
    return 0;
    */
    /*
    matrix *m = new matrix(3, 2, true);
    m->print();
    */
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    network *nn = new network(topology);
    nn->setInput(input);
    nn->printNN();

    return 0;
}
