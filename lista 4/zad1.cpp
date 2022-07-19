#include <iostream>
#include <vector>

using namespace std;

double operator *(const vector <double> & a , const vector <double> & b)
{
    if((a.size() != b.size()) or a.size() == 0 or b.size() == 0) return 0;
    else
    {
        double sum = 0;
        for(int x = 0; x < a.size(); x++)
        {
            sum += a[x] * b[x];
        }
        return sum;
    }
}


int main()
{
    vector <double> a = {1, 2, 3};
    vector <double> b = {2.5, 3.5, 4.5};

    cout << a*b << endl;

    return 0;
}
