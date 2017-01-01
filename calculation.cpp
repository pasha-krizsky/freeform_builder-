#include "calculation.h"

using namespace std;
Calculation::Calculation()
{
    data = new StoreData();
    // A path to file
    data->InputPointsFromFile("D:\\cpp_projects\\interpolation_project\\tests\\freeform1.txt");
}
QVector<double> Calculation::GetX()
{
    return res_x;
}
QVector<double> Calculation::GetY()
{
    return res_y;
}

double Calculation::GetMinX()
{
    return minX;
}
double Calculation::GetMaxX()
{
    return maxX;
}
double Calculation::GetMinY()
{
    return minY;
}
double Calculation::GetMaxY()
{
    return maxY;
}
