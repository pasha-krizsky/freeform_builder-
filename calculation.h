#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "input_data.h"

using namespace std;

// Strategy pattern

// Class "Interpolation" stores a strategy
// Concrete strategies:
// 1. Lagrange_polynomial
// 2. Bezier_curves,
// 3. Linear_interpolation
// 4. Quadratic_interpolation

class Calculation
{
protected:
    StoreData* data;

    // result
    QVector<double> res_x;
    QVector<double> res_y;

    double minX;
    double maxX;
    double minY;
    double maxY;

public:

    StoreData* GetData()
    {
       return data;
    }

    // return calculated coord for painting
    QVector<double> GetX();
    QVector<double> GetY();

    double GetMinX();
    double GetMaxX();
    double GetMinY();
    double GetMaxY();

    void Interpolate();

protected:
    Calculation();
};

#endif
