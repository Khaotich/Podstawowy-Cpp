#include <iostream>
#include <vector>
#include <algorithm> // count_if, sort

using namespace std;

struct Zliczaj_5
{
    bool operator()(int k) const { return k == 5; }
};

struct Sortuj
{
    bool operator()(int i, int j) const {return i % 10 <= j % 10;}
};

int main()
{
    vector<int> v = {1, 12, 13, 35, 45, 5, 5, 6, 16, 8};

    cout << count_if(begin(v), end(v), Zliczaj_5()) << "\n";
    cout << count_if(begin(v), end(v), [](int k) { return k == 5; }) << "\n";

    //sort(v.begin(), v.end(), Sortuj());
    //for(int i = 0; i < v.size(); i++) cout << v[i] << endl;

    sort(v.begin(), v.end(), [](int i, int j){return i % 10 <= j % 10;});
    for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

