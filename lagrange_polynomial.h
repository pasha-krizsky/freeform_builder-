#ifndef LAGRANGE_POLYNOMIAL_H
#define LAGRANGE_POLYNOMIAL_H

#include "calculation.h"

// Concrete strategy: Lagrange interpolation polynomial
class Lagrange_polynomial : public Calculation
{
private:
    // Polynomial coefficients
    QVector<double> res_coeff;
    QVector<double> res_const;
    // Result coefficients before X
    QVector<double> result;

public:
    Lagrange_polynomial();
    ~Lagrange_polynomial();
    // Calculate the coefficients before X for j polynomial
    void CalculateCoeff(int j);
    // Get polynomial such as: a0+a1x+...+anx^n
    QVector<double> Multiplication();
    // Strategy
    void Interpolate();
    QVector<double> GetResult();
    void OutputResult();
    // To build a plot
    void CalculateXandY(double step);
};

#endif // LAGRANGE_POLYNOMIAL_H
