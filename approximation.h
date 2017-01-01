#ifndef APPROXIMATION_H
#define APPROXIMATION_H

#include "input_data.h"
#include "matrix.h"
#include "calculation.h"

class Approximation : public Calculation
{
private:
    QVector<double> res_x;
    QVector<double> res_y;

    QVector<double> start_x;
    QVector<double> start_y;

    vector<vector<double>> A;
    vector<vector<double>> B;

    double minX;
    double maxX;
    double minY;
    double maxY;

public:
    Approximation();

    void approximate(vector<int> powers);
    void findBestFunction(int maxPower, vector<int> all_powers);

    QVector<double> GetX();
    QVector<double> GetY();

    QVector<double> GetStartX();
    QVector<double> GetStartY();

    vector<vector<double>> GetA();
    vector<vector<double>> GetB();

    double GetMinX();
    double GetMaxX();
    double GetMinY();
    double GetMaxY();
};

#endif // APPROXIMATION_H
