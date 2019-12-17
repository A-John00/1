#include <QCoreApplication>
#include "neuron.h"
#include "layer.h"
#include "matrix.h"
#include "network.h"
#include "math.h"

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
    /*
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
    */


    /*
    layer *l = new layer(4);
    l->setVal(0, 1.2);
    l->setVal(1, 0.8);
    l->setVal(2, 2.0);
    l->setVal(3, 0.4);
    l->activationSoft().printLayer();
    */
    /*
    matrix *m = new matrix(3, 2, true);
    matrix *m2 = new matrix(2, 3, true);
    m->printM();
    cout << "-------------" << endl;
    m2->printM();
    cout << "-------------" << endl;
    m->mult(m, m2).printM();
    */

    vector<double> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(1);
    vector<int> topology;
    topology.push_back(4);
    topology.push_back(2);
    topology.push_back(3);

    network* nn = new network(topology);
    nn->setInput(input);
    nn->feedForward();
    nn->printNN();
    cout << "======" << endl;
    nn->printOutput();

    return 0;
}
