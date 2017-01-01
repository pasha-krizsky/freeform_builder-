#include "quadratic_interpolation.h"

Quadratic_interpolation::Quadratic_interpolation() : Calculation() {}

void Quadratic_interpolation::Interpolate()
{
    for (int i = 2; i < data->GetX().size(); i++) {
        a2.push_back((data->GetY()[i] - data->GetY()[i-2])   /
            ((data->GetX()[i] - data->GetX()[i-2])           *
             (data->GetX()[i] - data->GetX()[i-1]))          -
             (data->GetY()[i-1] - data->GetY()[i-2])         /
            ((data->GetX()[i-1] - data->GetX()[i-2])         *
             (data->GetX()[i]   - data->GetX()[i-1])));

        a1.push_back((data->GetY()[i-1] - data->GetY()[i-2]) /
            (data->GetX()[i-1] - data->GetX()[i-2])          -
             a2[i-2]                                         *
            (data->GetX()[i-1] + data->GetX()[i-2]));

        a0.push_back(data->GetY()[i-2] -
            a1[i-2]                    *
            data->GetX()[i-2]          -
            a2[i-2]                    *
            data->GetX()[i-2]          *
            data->GetX()[i-2]);
    }

    // First curve
    for (double j = data->GetX()[0]; j < data->GetX()[2]; j += 0.001) {
        res_x.push_back(j);
        res_y.push_back(a0[0] + a1[0] * j + a2[0] * j * j);
    }

    for (int i = 2; i < data->GetX().size(); i++) {
        if (i < data->GetX().size()-1) {
            for (double j = data->GetX()[i]; j <= data->GetX()[i+1]; j += 0.001) {
                res_x.push_back(j);
                res_y.push_back(a0[i-1] + a1[i-1] * j + a2[i-1] * j * j);
            }
        }
    }

    minX = res_x[0];
    maxX = res_x[0];
    minY = res_y[0];
    maxY = res_y[0];

    for (int i = 0; i < res_x.size(); i++)
    {
        if (minX > res_x[i]) minX = res_x[i];
        if (maxX < res_x[i]) maxX = res_x[i];
        if (minY > res_y[i]) minY = res_y[i];
        if (maxY < res_y[i]) maxY = res_y[i];
    }
}
