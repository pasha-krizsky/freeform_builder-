#ifndef BEZIER_CURVES_H
#define BEZIER_CURVES_H

#include "calculation.h"

using namespace std;

class Bezier_curve : public Calculation
{
private:
    // Store coefficients before t
    QVector<int> res_coeff_x;
    QVector<int> res_coeff_y;

public:
    Bezier_curve();
    ~Bezier_curve();
    // Calculate coefficients before t for N points
    void CalcResCoeff(int n);
    // Strategy
    void Interpolate();
    // Find factorial
    long long factorial(int n);
    // Calculate X and Y coordinates with step t from x to y
    void CalcXandY(double t);
    // Return coefficients
    QVector<double> GetResult();
    // Output eq for x and y
    void OutputResult();
};

#endif // BEZIER_CURVES_H
