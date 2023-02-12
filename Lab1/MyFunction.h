#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const double dx = 0.00001;


vector <double> OpisanieUrav(double a, double b, double c, 
    double x1, double x2)
{
    vector <double> mas;
    for (double x = x1; x <= x2; x += dx)
    {
        mas.push_back(a * x * x + b * x + c);
    }
    return mas;
}

tuple <double, double> Integral(double a1, double b1, double c1,
    double a2, double b2, double c2)
{
    double a = a1 - a2, b = b1 - b2, c = c1 - c2;
    double d, x1, x2;
    d = b * b - 4 * a * c;
    x1 = min((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    x2 = max((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    return make_tuple(x1, x2);
}

tuple <double, double> Integral(double a, double b, double c, bool flag)
{
    double d, x1, x2;
    d = b * b - 4 * a * c;
    if (d < 0)
    {
        flag = true;
    }
    else if (a==0)
    {
        x1 = -c / b;
        x2 = x1;
        if (b == 0)
        {
            flag = true;
        }
    }
    else
    {
        x1 = min((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
        x2 = max((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    }

    return make_tuple(x1, x2);
}

double Integral(vector <double> func(double, double, double, double, double), 
    double a, double b, double c, double x1, double x2)
{
    vector <double> dlina;
    dlina = func(a, b, c, x1, x2);
    double square = 0;
    for (double i = 1; i < dlina.size(); i++)
    {
        square += dx * (dlina[i] + dlina[i - 1]) / 2;
    }
    return square;
}

double Integral(vector <double> func(double, double, double, double, double),
    double a1, double b1, double c1, double a2, double b2, double c2,
    double x1, double x2)
{
    vector <double> y1, y2, dlina;
    double square = 0;
    y1 = func(a1, b1, c1, x1, x2);
    y2 = func(a2, b2, c2, x1, x2);
    for (double i = 0; i < y1.size(); i++)
    {
        dlina.push_back(abs(y1[i] - y2[i]));
        if (i > 0)
        {
            square += dx * (dlina[i] + dlina[i - 1]) / 2;
        }
    }
    return square;
}
