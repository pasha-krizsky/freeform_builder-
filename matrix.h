#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>

using namespace std;

// Class with 3 main operations:
// 1. multiplication
// 2. transposition
// 3. finding inverse matrix
class Matrix
{
public:
    Matrix();
    vector<vector<double>> multiply(vector<vector<double> > arr1,
                                    vector<vector<double> > arr2);
    vector<vector<double>> transposition(vector<vector<double> > arr);
    vector<vector<double>> inverse(vector<vector<double>> arr);
    void output(vector<vector<double>> arr);
};

#endif
