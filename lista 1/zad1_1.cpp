#include <iostream>

using namespace std;

int suma = 1;

int main()
{
    cout << suma << endl;
    
    for (int i = 1; i < 41; i++)
    {
        suma *= i;
        cout << suma << endl;
    }
    
    getchar();
    return 0;
}

// Typ int został przeciążony i nie mieści już tak dużych wartości.