#include "bezier_curves.h"

using namespace std;

Bezier_curve::Bezier_curve() : Calculation(){}

Bezier_curve::~Bezier_curve() {}

void Bezier_curve::Interpolate()
{
    CalcXandY(0.01);
}

long long Bezier_curve::factorial(int n)
{
    return (n == 0 || n == 1) ? 1 : factorial(n-1) * n;
}

void Bezier_curve::CalcResCoeff(int n)
{
    for (int i = 0; i <= n; i++) {
        res_coeff_x.push_back(data->GetX()[i] * factorial(n) / (factorial(i) * factorial(n-i)));
        res_coeff_y.push_back(data->GetY()[i] * factorial(n) / (factorial(i) * factorial(n-i)));
    }
}

void Bezier_curve::CalcXandY(double t)
{
    CalcResCoeff(data->GetX().size() - 1);

    for (double i=0; i<=1; i+=t) {
        double tmp_x = 0;
        double tmp_y = 0;

        for (int j = 0; j < res_coeff_x.size(); j++) {
            tmp_x += res_coeff_x[j] * pow((1-i), res_coeff_x.size()-1-j) * pow(i, j);
            tmp_y += res_coeff_y[j] * pow((1-i), res_coeff_y.size()-1-j) * pow(i, j);
        }

        res_x.push_back(tmp_x);
        res_y.push_back(tmp_y);
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
