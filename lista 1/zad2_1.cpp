#include <iostream>

using namespace std;

int main()
{
    const int N = 1000000;
    long double suma = 0;
    
    for (float k = 1; k <= N; k++)
    {
        suma += 1 / (k*k);
    }
     
    cout << suma << endl;

    getchar();
    return 0;
}