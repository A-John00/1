#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

using namespace std;

class matrix
{
public:
    matrix(int r, int c, bool rdm);
    double genRdm();
    void setValue(int row, int column, double value);
    double getValue(int row, int column);
    int getNumRows();
    int getNumColumns();
    void print();

private:
    int rows; // number rows
    int columns; // number columns
    vector<vector<double>> values;

};

#endif // MATRIX_H
