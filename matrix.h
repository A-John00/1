#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

using namespace std;

class matrix
{
public:
    matrix(int r, int c, bool rdm);
    static double genRdm();
    void setValue(int row, int column, double value);
    double getValue(int row, int column);
    int getNumRows();
    int getNumColumns();
    void printM();
    static matrix mult(matrix *a, matrix *b);

private:
    int rows; // number rows
    int columns; // number columns
    vector<vector<double>> values;

};

#endif // MATRIX_H
