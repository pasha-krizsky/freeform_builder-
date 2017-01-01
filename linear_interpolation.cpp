#include "linear_interpolation.h"

Linear_interpolation::Linear_interpolation() : Calculation() {}

void Linear_interpolation::Interpolate()
{
    // The number of straight lines
    int size = data->GetX().size();
    for (int i = 1; i < size; i++) {
        a1.push_back((data->GetY()[i] - data->GetY()[i-1]) / (data->GetX()[i] - data->GetX()[i-1]));
        a0.push_back(data->GetY()[i-1] - (a1[i-1] * data->GetX()[i-1]));
    }

    for (int i = 0; i < size; i++) {
        res_x.push_back(data->GetX()[i]);
        res_y.push_back(data->GetY()[i]);
    }

    minY = res_y[0];
    maxY = res_y[0];
    minX = res_x[0];
    maxX = res_x[0];

    for (int i = 0; i < res_x.size(); i++) {
        if (minX > res_x[i]) minX = res_x[i];
        if (maxX < res_x[i]) maxX = res_x[i];
        if (minY > res_y[i]) minY = res_y[i];
        if (maxY < res_y[i]) maxY = res_y[i];
    }
}

void Linear_interpolation::OutputResult()
{
    cout << endl << "Result:" << endl;
    for (int i = 0; i < res_x.size()-1; i++) {
        cout << "(" << i << "): " << a0[i] << "+" << a1[i] << "*x" << endl;
    }
}
