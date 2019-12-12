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
                r = this->genRdm();
            }
            colValues.push_back(r);
        }
        this->values.push_back(colValues);
    }


}

void matrix::print(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << this->values.at(i).at(j) << "\t\t";
        }
        cout << endl;
    }
}

int matrix::getNumRows(){
    return rows;
}

int matrix::getNumColumns(){
    return columns;
}


double matrix::genRdm(){
    static random_device rd;
    static mt19937 eng(rd());
    uniform_real_distribution<> distr(0, 1);

    return distr(eng);
}
