#include "input_data.h"

StoreData::StoreData() {}
StoreData::~StoreData(){}

void StoreData::InputPointsFromConsole()
{
    cout << "Amount of points: ";
    int amount;
    cin >> amount;
    double x;
    double y;
    x_values.reserve(amount);
    y_values.reserve(amount);

    for (int i = 0; i < amount; i++) {
        cout << "Point(" << i << ")" << endl << "X = ";
        cin  >> x;
        cout << "Y = ";
        cin  >> y;
        x_values.push_back(x);
        y_values.push_back(y);
        cout << endl;
    }

    cout << "Thanks!" << endl;
}

void StoreData::InputPointsFromFile(string name_file)
{
    ifstream in(name_file);
    int   amount;
    in >> amount;

    x_values.reserve(amount);
    y_values.reserve(amount);

    while (!in.eof()) {
        double read_value;
        in >> read_value;
        x_values.push_back(read_value);
        in >> read_value;
        y_values.push_back(read_value);
    }

    cout << "Loaded from file!" << endl;
}

void StoreData::OutputPoints()
{
    cout << endl << "All " << x_values.size() << " points:" << endl;
    for (int i = 0; i < x_values.size(); i++)
        cout << "X=" << x_values[i] << " Y=" << y_values[i] << endl;
}

// get-methods
QVector<double> StoreData::GetX()
{
    return x_values;
}

QVector<double> StoreData::GetY()
{
    return y_values;
}


