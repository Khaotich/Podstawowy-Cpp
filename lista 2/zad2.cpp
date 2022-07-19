#include <iostream>
#include <cstdlib>
#include <iterator>
#include <string>


using namespace std;

int compare(const void* i, const void* j)
{
    string a = *(string*)i;
    string b = *(string*)j;

    int al = a.length();
    int bl = b.length();

    if (al == bl)
    {
        int aa = int(a.at(0));
        int bb = int(b.at(0));

        if (aa > bb) return 1;
        else if (aa < bb) return -1;
        else return 0;
    }
    else if (al > bl) return 1;
    else if (al < bl) return -1;
}

int main()
{
    string tab[5] = { "aa","car","dar","eaww","fa" };
    qsort(tab, 5, sizeof(string), compare);
    copy(begin(tab), end(tab), ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0;
}
