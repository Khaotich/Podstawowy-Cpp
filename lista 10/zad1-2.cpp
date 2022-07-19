#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

//zadanie 1
template <class T>
ostream& operator<<(ostream& result, const vector<T>& v)
{

   for (unsigned int i = 0; i < v.size(); i++)
   {
      result << v[i];
      if (i != v.size() - 1) result << " ";
   }
   result << "\n";

   return result;
}

int main()
{
    srand(time(NULL));
    vector <int> one(10), two(10);

    iota(one.begin(), one.end(), 0);
    cout << one;
    cout << "Suma: " << accumulate(one.begin(), one.end(), 0) << endl;

    transform(one.begin(), one.end(), one.begin(), [](int e){ return e*e; });
    cout << one;

    generate(two.begin(), two.end(), [](){ return rand() % 15; });
    cout << two;
    cout << "Max = " << *max_element(two.begin(), two.end()) << endl;

    sort(two.begin(), two.end());
    cout << two;

    unique(two.begin(), two.end());
    cout << two;

    sort(two.begin(), two.end() );
    two.erase(unique(two.begin(), two.end() ), two.end());
    cout << two;

    vector <int> inter;
    set_intersection(one.begin(), one.end(), two.begin(), two.end(), back_inserter(inter));
    cout << inter;

    return 0;
}
