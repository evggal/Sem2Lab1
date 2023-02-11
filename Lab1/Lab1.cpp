#include <iostream>
#include <vector>
#include <tuple>
#include "MyFunction.h"

using namespace std;

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
    f();
    /*cout << abs(abs(square1) - abs(square2));*/
}