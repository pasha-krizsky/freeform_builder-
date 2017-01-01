#ifndef QUADRATIC_INTERPOLATION_H
#define QUADRATIC_INTERPOLATION_H

#include "calculation.h"

using namespace std;

class Quadratic_interpolation : public Calculation
{
private:
    QVector<double> a0;
    QVector<double> a1;
    QVector<double> a2;

public:
    Quadratic_interpolation();
    void Interpolate();
};

#endif // QUADRATIC_INTERPOLATION_H
