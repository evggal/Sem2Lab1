#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const double dx = 0.00001;

vector <double> OpisanieUrav(double, double, double, double, double);
tuple <double, double> Grani(double, double, double, double, double, double);
tuple <double, double> Grani(double, double, double);
double Integral(vector <double> (double, double, double, double, double), double, double, double, double, double);

int main()
{
    /*double a1 = -1, b1 = 0, c1 = 4;
    double a2 = 1, b2 = -2, c2 = 0;*/

    double a1, a2, b1, b2, c1, c2;
    cout << "Введите коеффициенты первого графика a1, b1, c1" << endl;
    cin >> a1 >> b1 >> c1;
    cout << "Введите коеффициенты первого графика a2, b2, c2" << endl;
    cin >> a2 >> b2 >> c2;

    double x1, x2, x11, x12, x21, x22;
    tie(x1, x2) = Grani(a1, b1, c1, a2, b2, c2);
    tie(x11, x12) = Grani(a1, b1, c1);
    tie(x21, x22) = Grani(a2, b2, c2);
    double square1, square2;
    if ((x11<=x1 || x11>=x2) && (x12<=x1 || x12>=x2))
    {
        square1 = Integral(OpisanieUrav, a1, b1, c1, x1, x2);
    }
    else if ((x11>=x1 && x11<=x2) && (x12>=x1 && x12<=x2))
    {
        square1 = Integral(OpisanieUrav, a1, b1, c1, x1, min(x11,x12))+
            Integral(OpisanieUrav, a1, b1, c1, min(x11, x12), max(x11, x12))+
            Integral(OpisanieUrav, a1, b1, c1, max(x11, x12), x2);
    }
    else
    {
        if (x11 > x1 && x11 < x2)
        {
            square1 = Integral(OpisanieUrav, a1, b1, c1, x1, x11) +
            Integral(OpisanieUrav, a1, b1, c1, x11, x2);
        }
        else
        {
            square1 = Integral(OpisanieUrav, a1, b1, c1, x1, x12) +
                Integral(OpisanieUrav, a1, b1, c1, x12, x2);
        }
    }

    if ((x21<=x1 || x21>=x2) && (x22<=x1 || x22>=x2))
    {
        square2 = Integral(OpisanieUrav, a2, b2, c2, x1, x2);
    }
    else if ((x21 > x1 && x21 < x2) && (x22 > x1 && x22 < x2))
    {
        square2 = Integral(OpisanieUrav, a2, b2, c2, x1, min(x21, x22)) +
            Integral(OpisanieUrav, a2, b2, c2, min(x21, x22), max(x21, x22)) +
            Integral(OpisanieUrav, a2, b2, c2, max(x21, x22), x2);
    }
    else
    {
        if (x21 > x1 && x21 < x2)
        {
            square2 = Integral(OpisanieUrav, a2, b2, c2, x1, x21) +
                Integral(OpisanieUrav, a2, b2, c2, x21, x2);
        }
        else
        {
            square2 = Integral(OpisanieUrav, a2, b2, c2, x1, x22) +
                Integral(OpisanieUrav, a2, b2, c2, x22, x2);
        }
    }
    cout << abs(square1 - square2);
    /*cout << abs(abs(square1) - abs(square2));*/
}

vector <double> OpisanieUrav(double a, double b, double c, double x1, double x2)
{
    vector <double> mas;
    for (double x = x1; x <= x2; x += dx)
    {
        mas.push_back(a * x * x + b * x + c);
    }
    return mas;
}

tuple <double, double> Grani(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double a = a1 - a2, b = b1 - b2, c = c1 - c2;
    double d, x1, x2;
    d = b * b - 4 * a * c;
    x1 = min((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    x2 = max((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    return make_tuple(x1, x2);
}

tuple <double, double> Grani(double a, double b, double c)
{
    double d, x1, x2;
    d = b * b - 4 * a * c;
    if (d < 0)
    {
        x1 = -1000000;
        x2 = x1;
    }
    else
    {
        x1 = min((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
        x2 = max((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    }
    
    return make_tuple(x1, x2);
}

double Integral(vector <double> func(double, double, double, double, double), double a, double b, double c, double x1, double x2)
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