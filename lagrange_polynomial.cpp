#include "lagrange_polynomial.h"

using namespace std;

Lagrange_polynomial::Lagrange_polynomial() : Calculation() {}

Lagrange_polynomial::~Lagrange_polynomial() {}

void Lagrange_polynomial::CalculateCoeff(int j)
{
    double denominator = 1;
    res_coeff.clear();
    res_const.clear();
    res_coeff.reserve(data->GetX().size());
    res_const.reserve(data->GetX().size());

    for (int i = 0; i < data->GetX().size(); i++) {
        if (i == j) continue;

        denominator = data->GetX()[j] - data->GetX()[i];
        res_coeff.push_back(1 / denominator);
        res_const.push_back(-1*data->GetX()[i]/denominator);
    }
}

QVector<double> Lagrange_polynomial::Multiplication()
{
    int amount = res_coeff.size();
    QVector<double> out;
    out.reserve(amount+1);
    for (int i = 0; i < amount+1; i++)
        out.push_back(0);

    for (int x = 0; x < pow(2, amount); x++) {
        int cur = x;
        double accum = 1;
        int i = 0;

        for (int iter = 0; iter < amount; iter++) {
            if (cur % 2 == 1) {
                i++;
                accum *= res_coeff[iter];
            }
            else
                accum *= res_const[iter];
            cur = cur / 2;
        }
        out[i] += accum;
    }

    return out;
}

void Lagrange_polynomial::Interpolate()
{
    // Time check
    unsigned int start_time = clock();

    result.reserve(data->GetX().size());
    for (int i = 0; i < data->GetX().size(); i++)
        result.push_back(0);

    for (int i = 0; i < data->GetX().size(); i++)
    {
        CalculateCoeff(i);
        QVector<double> tmp = Multiplication();
        for (int j = 0; j < data->GetX().size(); j++) {
            tmp[j] = data->GetY()[i] * tmp[j];
            result[j] += tmp[j];
        }
    }

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Time: " << search_time << endl;
}

void Lagrange_polynomial::CalculateXandY(double step)
{
    // Find min and max values
    minX = data->GetX()[0];
    maxX = data->GetX()[0];
    minY = data->GetY()[0];
    maxY = data->GetY()[0];

    for (int i = 1; i < data->GetX().size(); i++) {
        if (data->GetX()[i] < minX) minX = data->GetX()[i];
        if (data->GetX()[i] > maxX) maxX = data->GetX()[i];
    }

    double a = minX;
    double b = maxX;

    int i = 0;
    for (double X = a; X <= b; X += step) {
        res_x.push_back(X);
        res_y.push_back(0);
        for (int j = 0; j < result.size(); j++) {
            res_y[i] += result[j]*pow(X, j);
        }
        i++;
    }

    minY = res_y[0];
    maxY = res_y[0];

    for (int i = 1; i < res_y.size(); i++) {
        if (res_y[i] < minY) minY = res_y[i];
        if (res_y[i] > maxY) maxY = res_y[i];
    }
}

void Lagrange_polynomial::OutputResult()
{
    cout << fixed;
    cout.precision(20);

    cout << endl << "Result:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "X^" << i << ": " << result[i] << endl;
    }
}

QVector<double> Lagrange_polynomial::GetResult()
{
    return result;
}
