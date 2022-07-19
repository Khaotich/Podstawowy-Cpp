#include <iostream>
#include <cmath>

using namespace std;

const int n = 30;
float t_a = 1 / sqrt(3), t_b = 1 / sqrt(3);

int main()
{
    cout << endl;
    
    //a
    cout << "Metoda A: " << endl;
    for (int i = 1; i < n+2; i++)
    {
        cout << "i=" << i-1 << ": " << 6 * pow(2, i-1) * t_a << endl;
        t_a = (sqrt(pow(t_a, 2) + 1) - 1) / t_a; 
    }
    
    cout << "-----------------------" << endl;

    //b
    cout << "Metoda B" << endl;
    for (int i = 1; i < n+2; i++)
    {
        cout << "i=" << i-1 << ": " << 6 * pow(2, i-1) * t_b << endl;
        t_b = t_b / (sqrt(pow(t_b, 2) + 1) + 1); 
    }
    
    getchar();
    return 0;
}

// Metoda przestaje działać w pewnym momencie dla danego i.