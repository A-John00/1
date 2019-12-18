#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>

using namespace std;

matrix::matrix(int r, int c, bool rdm){
    rows = r;
    columns = c;
    for (int i = 0; i < rows; i++){
        vector<double> colValues;
        for (int j = 0; j < columns; j++){
            double r = 0.00;
            if(rdm){
                r = matrix::genRdm();
            }
            colValues.push_back(r);
        }
        values.push_back(colValues);
    }


}


double matrix::genRdm(){
    static random_device rd; // static required for different doubles
    static mt19937 eng(rd());
    uniform_real_distribution<> distr(0, 1);

    return distr(eng);
}


matrix* matrix::mult(matrix* a, matrix* b){
    if(a->getNumColumns() != b->getNumRows()){
        cout << "Matrix multiplikation kann nicht durchgeführt werden." << endl;

    }
    matrix* c = new matrix(a->getNumRows(), b->getNumColumns(), false);

    for(int i = 0; i < a->getNumRows(); i++){
        for(int j = 0; j < b->getNumColumns(); j++){
            for(int k = 0; k < b->getNumRows(); k++){
                double tempVal1 = a->getValue(i, k) * b->getValue(k, j);
                double tempVal2 = c->getValue(i, j) + tempVal1;
                c->setValue(i, j, tempVal2);
            }
        }
    }
    return c;
}


matrix* matrix::transpose(){
    matrix* m = new matrix(columns, rows, false);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j ++){
            m->setValue(j, i, getValue(i, j));

        }
    }
    return m;
}


double matrix::getValue(int row, int column){
    return values.at(row).at(column);
}

int matrix::getNumRows(){
    return rows;
}


int matrix::getNumColumns(){
    return columns;
}


void matrix::setValue(int row, int column, double value){
    values.at(row).at(column) = value;
}

void matrix::printM(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << values.at(i).at(j) << "\t\t";
        }
        cout << endl;
    }
}




