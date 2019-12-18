#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

using namespace std;

class matrix
{
public:
    matrix(int r, int c, bool rdm);
    static double genRdm(); // generates a random double between 0.00 and 1.00
    static matrix* mult(matrix* a, matrix* b); // implements matrix multiplication
    matrix* transpose(); // implements a function that transposes a matrix

    double getValue(int row, int column);
    int getNumRows();
    int getNumColumns();

    void setValue(int row, int column, double value);
    void printM(); // prints out the matrix



private:
    int rows; // number rows
    int columns; // number columns

    vector<vector<double>> values;

};

#endif // MATRIX_H
