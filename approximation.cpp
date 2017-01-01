#include "approximation.h"

Approximation::Approximation() : Calculation() {
    A.resize(data->GetX().size());

    start_y.resize(data->GetX().size());
    start_y = data->GetY();

    start_x.resize(data->GetX().size());
    start_x = data->GetX();

    B.resize(data->GetX().size());
    for (int i = 0; i < data->GetX().size(); i++)
        B[i].push_back(data->GetY()[i]);
}

void Approximation::approximate(vector<int> powers) {
    A.clear();
    A.resize(data->GetX().size());

    for (int i = 0; i < powers.size(); i++) {
        for (int j = 0; j < A.size(); j++)
            A[j].push_back(pow(start_x[j], powers[i]));
    }

    Matrix *m = new Matrix();
    vector<vector<double>> d;
    d.resize(powers.size());
    d = m->multiply(m->multiply(m->inverse(m->multiply(m->transposition(A), A)), m->transposition(A)), B);
    m->output(d);

    double step = 0.001;
    for (double X = data->GetX()[0]; X <= data->GetX()[data->GetX().size()-1]; X += step) {
        if (minX > X) minX = X;
        if (maxX < X) maxX = X;
        res_x.push_back(X);

        double y = 0;
        for (int i = 0; i < d.size(); i++)
            y += d[i][0] * pow(X, powers[i]);

        if (maxY < y) maxY = y;
        if (minY > y) minY = y;
        res_y.push_back(y);
    }

    double sum_mistake = 0;
    for (int i = 0; i < B.size(); i++) {
        double y = 0;
        for (int j = 0; j < d.size(); j++)
            y += d[j][0] * pow(A[i][0], powers[j]);
        sum_mistake += abs(B[i][0] - y);
    }

    sum_mistake /= B.size();
    sum_mistake *= 100;
    std::cout << std::endl << "Mistake=" << sum_mistake;
    std::cout << std::endl;
}

void Approximation::findBestFunction(int maxPower, vector<int> all_powers)
{
    A.clear();
    A.resize(data->GetX().size());

    for (int i = 0; i < all_powers.size(); i++) {
        for (int j = 0; j < A.size(); j++)
            A[j].push_back(pow(start_x[j], all_powers[i]));
    }

    vector<double> powers;
    vector<double> allMistakes;

    for (int power = 1; power <= maxPower; power++) {
        powers.clear();
        A.clear();
        A.resize(data->GetX().size());

        for (int k  = 1; k<= power; k++)
            powers.push_back(k);

        for (int i = 0; i < powers.size(); i++) {
            for (int j = 0; j < A.size(); j++)
                A[j].push_back(pow(start_x[j], powers[i]));
        }

        Matrix *m = new Matrix();
        vector<vector<double>> d;
        d.resize(powers.size());

        d = m->multiply(m->multiply(m->inverse(m->multiply(m->transposition(A), A)), m->transposition(A)), B);

        double step = 0.001;
        for (double X = data->GetX()[0]; X <= data->GetX()[data->GetX().size()]; X += step) {
            res_x.push_back(X);
            double y = 0;
            for (int i = 0; i < d.size(); i++)
                y += d[i][0] * pow(X, powers[i]);
            res_y.push_back(y);
        }

        double sum_mistake = 0;
        for (int i = 0; i < B.size(); i++) {
            double y = 0;
            for (int j = 0; j < d.size(); j++)
                y += d[j][0] * pow(A[i][0], powers[j]);
            sum_mistake += abs(B[i][0] - y);
        }

        sum_mistake /= B.size();
        sum_mistake *= 100;
        allMistakes.push_back(sum_mistake);

    }
    double min = allMistakes[0];
    int minIndex = 0;
    for (int i = 0; i < allMistakes.size(); i++) {
        if (min > allMistakes[i]) {
            min = allMistakes[i];
            minIndex = i;
        }
    }
    std::cout << std::endl << "Min mistake=" << min;
    std::cout << std::endl << "i=" << minIndex;

}

QVector<double> Approximation::GetX() {
    return res_x;
}
QVector<double> Approximation::GetY() {
    return res_y;
}
double Approximation::GetMinX() {
    return minX;
}
double Approximation::GetMaxX() {
    return maxX;
}
double Approximation::GetMinY() {
    return minY;
}
double Approximation::GetMaxY() {
    return maxY;
}
vector<vector<double>> Approximation::GetA() {
    return A;
}
vector<vector<double> > Approximation::GetB() {
    return B;
}
QVector<double> Approximation::GetStartX() {
    return start_x;
}
QVector<double> Approximation::GetStartY() {
    return start_y;
}
