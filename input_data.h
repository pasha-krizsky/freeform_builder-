#ifndef INPUT_DATA_H
#define INPUT_DATA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "math.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

// Cass to store data
class StoreData
{
private:
    // Coordinaties of the points
    QVector<double> x_values;
    QVector<double> y_values;

public:
    StoreData();
    ~StoreData();

    // Different ways to input data
    void InputPointsFromConsole();
    void InputPointsFromFile(string name_file);

    // Output data
    void OutputPoints();

    // Get methods for the points
    QVector<double> GetX();
    QVector<double> GetY();
};

#endif // INPUT_DATA_H
