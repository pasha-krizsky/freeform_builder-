#include "matrix.h"
#include <exception>
#include <cmath>

using namespace std;

Matrix::Matrix() {}

vector<vector<double>> Matrix::multiply(vector<vector<double>> arr1,
                                vector<vector<double>> arr2) {

    if (arr1[0].size() != arr2.size()) {
        cout << "Wrong!" << endl;
        return arr1;
    }

    int width_result = arr2[0].size();
    int height_result = arr1.size();

    vector<vector<double>> result;
    result.resize(height_result);

    for (int i = 0; i < arr1.size(); i++) {
        for (int k = 0; k < arr2[0].size(); k++) {
            double res = 0;
            for (int j = 0; j < arr1[0].size(); j++) {
                res += arr1[i][j] * arr2[j][k];
            }
            result[i].push_back(res);
        }
    }

    return result;
}

vector<vector<double>> Matrix::transposition(vector<vector<double>> arr) {

    int width_result  = arr.size();
    int height_result = arr[0].size();

    vector<vector<double>> result;
    result.resize(height_result);

    for (int i = 0; i < arr[0].size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            result[i].push_back(arr[j][i]);
        }
    }

    return result;
}

void Matrix::output(vector<vector<double>> arr) {

    cout << "Result:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> Matrix::inverse(vector<vector<double>> arr) {
    vector<vector<double>> result(arr);
    vector<vector<double>> res;
    res.resize(result.size());

    cout.precision(5);
    for (int i = 0; i < res.size(); i++) {
        res[i].resize(res.size());
    }

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res.size(); j++) {
            if (i == j)
                res[i][j] = 1;
            else
                res[i][j] = 0;
        }
    }

    int N = arr.size();

    // ---------------------------------------------
    for (int i = 0; i < N; i++) {

        double d = result[i][i];
        if (abs(d) <= 1e-7) throw std::runtime_error("matrix hasn't be inversed!");
        for (int j = 0; j < N; j++) {
            result[i][j] = result[i][j] / d;
            res[i][j] = res[i][j] / d;
        }

        for (int k = i+1; k < N; k++) {
            double tmp = result[k][i];
            for (int m = 0; m < N; m++) {
                result[k][m] = result[k][m] - result[i][m] * tmp;
                res[k][m] = res[k][m] - res[i][m] * tmp;
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            double tmp = result[k][i];
            for (int m = 0; m < N; m++) {
                result[k][m] = result[k][m] - result[i][m] * tmp;
                res[k][m] = res[k][m] - res[i][m] * tmp;
            }
        }
    }

    return res;
}


