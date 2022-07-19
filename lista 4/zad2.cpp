#include <iostream>
#include <math.h>

using namespace std;

// równianie cos(x) = x
double f_a(double x)
{
    return cos(x) - x;
}

// równanie cos(x) = 0.5
double f_b(double x)
{
    return cos(x) - 0.5;
}

//funkcja do rozwiązywania równań
double find_root(double (*f)(double), double a, double b, double tolerance = 1e-10)
{
    while(abs(a - b) > tolerance)
    {
        double x1 = (a + b) / 2;
        double fx = f(x1);
        double fa = f(a);

        if(abs(fx) <= tolerance) break;
        else if(fx * fa < 0) b = x1;
        else a = x1;
    }
    return (a + b) / 2;
}

int main()
{
    //test pierwszego rownania
    cout << "Rozwiazanie rownania cos(x) = x: " << find_root(f_a, 0, 2, 1e-6) << endl;

    //test drugiego rownania
    cout << "Rozwiazanie rownania cos(x) = 0.5: " << find_root(f_b, 0, 1.5, 1e-6) << endl;

    return 0;
}
