// Źródło: https://en.cppreference.com/w/cpp/language/operators

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;


int fact(int n)
{
  return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

class Fraction
{

    long long int gcd(long long int a, long long int b) { return b == 0 ? a : gcd(b, a % b); }
    long long int n, d;

    public:
    Fraction(long long int n, long long int d = 1) : n(n/gcd(n, d)), d(d/gcd(n, d)) { }
    long long int num() const { return n; }
    long long int den() const { return d; }

    Fraction& operator*=(const Fraction& rhs)
    {
        long long int new_n = n * rhs.n/gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d/gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }

    //zadanie 1 a +=
    Fraction & operator+=(const Fraction & rhs)
    {
        if(d != rhs.den())
        {
           long long int n1 = 1, n2 = 1;

           n1 *= n * rhs.den();
           n2 *= rhs.num() * d;
           d *= rhs.den();
           n = n1 + n2;

        }
        else
        {
            n += rhs.num();
            d = rhs.den();
        }

        return *this;
    }

    //zadanie 1 a -=
    Fraction & operator-=(const Fraction & rhs)
    {
        if(d != rhs.den())
        {
           long long int n1 = 1, n2 = 1;

           n1 *= n * rhs.den();
           n2 *= rhs.num() * d;
           d *= rhs.den();
           n = n1 - n2;

        }
        else
        {
            n -= rhs.num();
            d = rhs.den();
        }

        return *this;
    }

    //zadanie 1 a /=
    Fraction & operator/=(const Fraction & rhs)
    {
        n *= rhs.den();
        d *= rhs.num();

        return *this;
    }

    //zadanie 1 a to_double
    double to_double()
    {
        double n1 = n;
        double d1 = d;
        return n1 / d1;
    }

    //zwraca część całkowitą ułamka
    int c()
    {
        return floor(n/d);
    }

    //obraca ułamek
    void rot()
    {
        int t = n, t1 = d;
        n = t1;
        d = t;
    }

};

ostream& operator<<(ostream& out, const Fraction& f)
{
   return out << f.num() << '/' << f.den() ;
}

bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !(lhs == rhs);
}

Fraction operator*(Fraction lhs, const Fraction& rhs)
{
    return lhs *= rhs;
}


// zadanie 1a +
Fraction operator+(Fraction lhs, Fraction rhs)
{

    if(lhs.den() != rhs.den())
    {
        long long int n1 = lhs.num(), n2 = rhs.num(), d1 = lhs.den(), d2 = rhs.den();

        n1 *= rhs.den();
        n2 *= lhs.den();
        d1 *= rhs.den();
        d2 *= lhs.den();

        return Fraction(n1 + n2, d1);
    }
    else
    {
        return Fraction(lhs.num() + rhs.num(), rhs.den());
    }

}

// zadanie 1a -
Fraction operator-(Fraction lhs, Fraction rhs)
{

    if(lhs.den() != rhs.den())
    {
        long long int n1 = lhs.num(), n2 = rhs.num(), d1 = lhs.den(), d2 = rhs.den();

        n1 *= rhs.den();
        n2 *= lhs.den();
        d1 *= rhs.den();
        d2 *= lhs.den();

        return Fraction(n1 - n2, d1);
    }
    else
    {
        return Fraction(lhs.num() - rhs.num(), rhs.den());
    }

}

// zadanie 1a /
Fraction operator/(Fraction lhs, Fraction rhs)
{
    return Fraction(lhs.num() * rhs.den(), lhs.den() * rhs.num());
}

// funkcja do zadania 2 do wyznaczania ułamków łańcuchowych
void continued_fraction(Fraction e)
{
    vector <int> F;

    int i = 1;
    int k = 10;
    Fraction x = e;
    int q = x.c();
    F.push_back(q);
    x = x - Fraction(q, 1);

    while((x != 0) and (i < k))
    {
        q = Fraction(x.den(), x.num()).c();
        F.push_back(q);
        x = Fraction(1,1) / x - Fraction(q, 1);
        i++;
    }

    vector <Fraction> f;
    for(int i = 0; i < F.size(); i++)
    {
        if(i == 0)
        {
            Fraction x(F[0], 1);
            f.push_back(x);
        }
        else if(i < 2)
        {
            Fraction x(F[i] * F[i-1] + 1, F[i]);
            f.push_back(x);
        }
        else
        {
            Fraction x(F[i] * f[i-1].num() + f[i-2].num(), F[i] * f[i-1].den() + f[i-2].den());
            f.push_back(x);
        }
    }

    for(int i = 0; i<f.size(); i++) cout << f[i] << " " << f[i].to_double() << setprecision(16) << endl;
}

int main()
{

    //zadanie 1 b.1
    cout << "Zadanie 1b.1" << endl;

    Fraction b1(1, 2);
    cout << 1 << " " << b1 << " " << b1.to_double() << endl;
    for(int i = 2; i < 101; i++)
    {
        Fraction tmp(1, i * (i + 1));
        b1 = b1 + tmp;
        cout << i << " " << b1 << " " << b1.to_double() << endl;
    }

    //zadanie 1 b.2
    cout << endl << "Zadanie 1b.2" << endl;

    Fraction b2(1, 1);
    cout << 1 << " " << b2 << " " << b2.to_double() << endl;
    for(int i = 2; i < 21; i++)
    {
        Fraction tmp(pow(-1, i+1), i);
        b2 = b2 + tmp;
        cout << i << " " << b2 << " " << b2.to_double() << endl;
    }

    //zadanie 1 b.3
    cout << endl << "Zadanie 1b.3" << endl;

    Fraction b3(1, 2);
    cout << 1 << " " << b3 << " " << b3.to_double() << endl;
    for(int i = 2; i < 16; i++)
    {
        Fraction tmp(1, pow(2, i) * i);
        b3 = b3 + tmp;
        cout << i << " " << b3 << " " << b3.to_double() << endl;
    }

    //zadanie 2 a
    cout << endl << "Zadanie 2a" << endl;
    Fraction a(pow(5, 0.5) + 1, 2);
    continued_fraction(a);

    //zadanie 2 b
    cout << endl << "Zadanie 2b" << endl;

    //generuje e
    Fraction e(1, 1);
    for(int i = 1; i < 12; i++)
    {
        e = e + Fraction(1, fact(i));
    }
    continued_fraction(e);

    return 0;
}
