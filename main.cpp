#include <QCoreApplication>
#include "neuron.h"
#include "layer.h"
#include "matrix.h"

int main(int argc, char *argv[])
{
    /*
    Neuron *n = new Neuron(0.9);
    cout << "Val: " << n->getValue() << endl;
    cout << "actVal: " << n->getActValue() << endl;
    return 0;
    */
    matrix *m = new matrix(3, 2, true);
    m->print();
}
