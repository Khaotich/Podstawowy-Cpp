#include <iostream>
#include <cmath>

using namespace std;

const int n = 1000000;
float suma_a = 0, suma_b = 1, suma_c = 0;

int main()
{
    //a
    for (int i = 1; i < n+1; i++)
    {
        suma_a += pow(-1, i + 1) / ((2 * i) -1); 
    }
    suma_a *= 4;
    cout << "A: " << suma_a << ", roznica: " << M_PI - suma_a << endl;

    //b
    for (int i = 1; i < n+1; i++)
    {
        suma_b *= (4 * pow(i, 2)) / ((4 * pow(i, 2)) -1); 
    }
    suma_b *= 2;
    cout << "B: " << suma_b << ", roznica: " << M_PI - suma_b << endl;

    //c
    for (int i = 1; i < n+1; i++)
    {
        suma_c += 1 / pow((2 * i) - 1, 2); 
    }
    suma_c = sqrt(suma_c * 8);
    cout << "C: " << suma_c << ", roznica: " << M_PI - suma_b << endl;
    
    getchar();
    return 0;
}
