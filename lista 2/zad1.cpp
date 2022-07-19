#include <iostream>
#include <iterator>

using namespace std;

//a
int suma(const int tab[], unsigned size)
{
    int suma_ = 0;
    for (int i = 0; i < size; i++) suma_ += tab[i];
    return suma_;
}

//b
void suma_(const int tab[], unsigned size, int* result)
{
    for (int i = 0; i < size; i++) *result += tab[i];
}

//c
void pisz(const int* tab, size_t size, ostream & out)
{
    for (int i = 0; i < size; i++)
    {
        out << tab[i] << endl;
    }
}

//d
void iota(int tab[], unsigned size)
{
    for (int i = 0; i < size; i++) tab[i] = i;
}

//e
void reverse(int* tab, size_t size)
{
    size -= 1;
    for (int i = 0; i < size; i++)
    {
        swap(tab[i], tab[size]);
        size--;
    }
}

//f
int dot_product(const int* tab1, const int* tab2, size_t size)
{
    int iloczyn = 0;
    for (int i = 0; i < size; i++)
    {
        iloczyn += tab1[i] * tab2[i];   
    }
    return iloczyn;
}

int main()
{
    int tab1[5]={1,2,3,4,5};
    int tab2[5]={1,2,3,4,5};
    
    //test a
    cout << endl << "Zadanie 1a: " << endl;
    cout << suma(tab1, 3) << endl;

    //test b
    int result = 0;
    int* result_ = &result;
    suma_(tab1, 4, result_);
    cout << endl << "Zadanie 1b: " << endl;
    cout << result << endl;

    //test c
    cout << endl << "Zadanie 1c:" << endl;
    pisz(tab1, 5, cout);
    

    //test d
    int tab3[5];
    iota(tab3, 5);
    cout << endl << "Zadanie 1d: " << endl;
    copy(begin(tab3), end(tab3), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    //test e
    cout << endl << "Zadanie 1e: " << endl;
    copy(begin(tab1), end(tab1), ostream_iterator<int>(cout, " "));
    cout << endl << "Po wywolaniu funkcji reverse: " << endl;
    reverse(tab1, 5);
    copy(begin(tab1), end(tab1), ostream_iterator<int>(cout, " "));
    cout << endl;

    //test f
    cout << endl << "Zadanie 1f: " << endl;
    cout << dot_product(tab1, tab2, 5);

    return 0;
}