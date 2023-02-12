/*Вспомогательный файл*/
vector <double> OpisanieUrav(double, double, double, double, double);
tuple <double, double> Grani(double, double, double, double, double, double);
tuple <double, double> Grani(double, double, double);
double Integral(vector <double>(double, double, double, double, double), double, double, double, double, double);



vector <double> OpisanieUrav(double a, double b, double c, double x1, double x2)
{
    vector <double> mas;
    for (double v vbx = x1; x <= x2; x += dx)
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