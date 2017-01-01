#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H
#include "calculation.h"

using namespace std;

// Simplest way to interpolate the points, no explanations!
class Linear_interpolation : public Calculation
{
private:
    QVector<double> a0;
    QVector<double> a1;

public:
    Linear_interpolation();
    void Interpolate();
    void OutputResult();
};

#endif // LINEAR_INTERPOLATION_H
