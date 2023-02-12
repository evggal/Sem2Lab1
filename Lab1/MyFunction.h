#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const double dx = 0.00001;


double OpisanieUrav(double a, double b, double c, 
    double x)
{
    return (a * x * x + b * x + c);
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

double Integral(double func(double, double, double, double), 
    double a, double b, double c, double x1, double x2)
{
    double square = 0;
    for (double x = x1+dx; x <= x2; x+=dx)
    {
        square += dx * (func(a, b, c, x) + func(a, b, c, x-dx)) / 2;
    }
    return square;
}

double Integral(double func(double, double, double, double),
    double a1, double b1, double c1, double a2, double b2, double c2,
    double x1, double x2)
{
    double square = 0;
    for (double x = x1 + dx; x <= x2; x += dx)
    {
        square += dx * (abs(func(a1, b1, c1, x) - func(a2, b2, c2, x)) + 
            abs(func(a1, b1, c1, x-dx) - func(a2, b2, c2, x-dx))) / 2;
    }
    return square;
}
